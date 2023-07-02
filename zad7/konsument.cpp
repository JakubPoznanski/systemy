#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include "semLib.h"
#include "memoryLib.h"
#include <iostream>

#define NELE 10 // Rozmiar elementu bufora (jednostki towaru) w bajtach
#define NBUF 5	// Liczba elementow bufora

// Segment pamieci dzielonej
typedef struct
{
	char bufor[NBUF][NELE]; // Wspolny bufor danych
	int buff_save;
	int buff_read;
} SegmentPD;

int isLast(SegmentPD *wpd)
{
	int i;
	for (i = 0; i < NELE; i++)
	{
		if (wpd->bufor[wpd->buff_read][i] == '\0')
		{
			return 1;
		}
	}
	return 0;
}

// argumenty [0] nazwa_programu [1] SEMAFOR_PRODUCENT [2] SEMAFOR_KONSUMENT [3] NAZWA_PD [4] PLIK_WY
int main(int argc, char *argv[])
{

	int file;
	int fd;
	SegmentPD *wpd;
	sem_t *sem_p;
	sem_t *sem_v;

	srand(time(NULL));

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	sem_p = semOpen(argv[1]);
	std::cout << "[konsument]: otwarto SEM " << argv[1] << std::endl;
	sem_v = semOpen(argv[2]);
	std::cout << "[konsument]: otwarto SEM " << argv[1] << std::endl;
	fd = openMemory(argv[3]);
	std::cout << "[producent]: Otwarto MEMORY" << argv[3] << std::endl;

	wpd = (SegmentPD *)map(fd, sizeof(SegmentPD));

	wpd->buff_read = 0;
	while (1)
	{
		sleep((double)(rand() % 2));
		std::cout << "[konsument]: Przed SK SEM: " << semValue(sem_p) << std::endl;
		semP(sem_v);
		if (!isLast(wpd))
		{
			write(file, wpd->bufor[wpd->buff_read], NELE);
			write(STDOUT_FILENO, "\tKonsumuje <====", 26);
			write(STDOUT_FILENO, wpd->bufor[wpd->buff_save], NELE);
			std::cout << "Indeks buff_read" << wpd->buff_save << std::endl;
		}
		else
		{
			write(file, wpd->bufor[wpd->buff_read], strlen(wpd->bufor[wpd->buff_read]));
			std::cout << "\tKonsumuje <====" << wpd->bufor[wpd->buff_read] << std::endl;
			std::cout << "[konsument]: koniec pliku\n"
					  << std::endl;
			semV(sem_p);
			std::cout << "[konsument]: Po SK SEM: " << semValue(sem_p) << std::endl;
			break;
		}
		wpd->buff_read = (wpd->buff_read + 1) % NBUF;
		semV(sem_p);
		std::cout << "[konsument]: Po SK SEM: " << semValue(sem_p) << std::endl;
	}
	close(file);
	mumMap(wpd, sizeof(SegmentPD));
	closeMemory(fd);
	semClose(sem_v);
	semClose(sem_p);
	std::cout << "Koniec procesu" << wpd->buff_save << std::endl;
	return 0;
}