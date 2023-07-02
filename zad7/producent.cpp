// #include <sys/types.h>
// #include <sys/wait.h>
// #include <sys/stat.h>
// #include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include "semLib.h"
#include "memoryLib.h"

#define NELE 10 // Rozmiar elementu bufora [bajty]
#define NBUF 5	// Liczba elementow bufora

// Segment pamieci dzielonej
typedef struct
{
	char bufor[NBUF][NELE]; // Wspolny bufor danych
	int buff_save;
	int buff_read;
} SegmentPD;

// argumenty [0] nazwa_programu [1] SEMAFOR_PRODUCENT [2] SEMAFOR_KONSUMENT [3] NAZWA_PD [4] PLIK_WE
int main(int argc, char *argv[])
{

	int file;
	int fd; // deskryptor pamięci dzielonej
	SegmentPD *wpd;
	sem_t *sem_p;
	sem_t *sem_c;
	int realReadNumber;

	srand(time(NULL));

	if ((file = open(argv[4], O_RDONLY, 0644)) == -1)
	{
		std::cout << "File open ERR" << std::endl;
		exit(0);
	}

	sem_p = semOpen(argv[1]);
	std::cout << "[producent]: otwarto SEM " << argv[1] << std::endl;
	sem_c = semOpen(argv[2]);
	std::cout << "[producent]: otwarto SEM " << argv[1] << std::endl;

	fd = openMemory(argv[3]);

	std::cout << "[producent]: Otwarto MEMORY " << argv[3] << std::endl;
	// definicja wskaźnika pamieci dzielonej
	wpd = (SegmentPD *)map(fd, sizeof(SegmentPD));
	wpd->buff_save = 0;
	while (1)
	{
		sleep((double)(rand() % 2));

		std::cout << "[producent]: Przed SK SEM: " << semValue(sem_p) << std::endl;

		realReadNumber = read(file, wpd->bufor[wpd->buff_save], NELE);

		if (realReadNumber != NELE)
		{
			wpd->bufor[wpd->buff_save][realReadNumber] = '\0';
			std::cout << "[producent] wpisuje ====>" << wpd->bufor[wpd->buff_save] << std::endl;
			std::cout << "[producent]: koniec pliku\n"
					  << std::endl;
			semV(sem_c);
			std::cout << "[producent]: Po SK SEM: " << semValue(sem_c) << std::endl;
			break;
		}
		else
		{
			write(STDOUT_FILENO, "\t[producent] produkt ====> ", 26) == -1;
			write(STDOUT_FILENO, wpd->bufor[wpd->buff_save], NELE) == -1;
			std::cout << "Indeks buff_save" << wpd->buff_save << std::endl;
		}
		wpd->buff_save = (wpd->buff_save + 1) % NBUF;

		// podnieś semafor konsumenta
		semV(sem_c);
		std::cout << "[producent]: Po SK SEM: " << semValue(sem_c) << std::endl;
	}

	close(file);

	mumMap(wpd, sizeof(SegmentPD));

	closeMemory(fd);
	semClose(sem_p);
	semClose(sem_c);

	std::cout << "Koniec procesu" << wpd->buff_save << std::endl;

	return 0;
}