#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include "memoryLib.h"
#include "semLib.h"
#include <iostream>

#define NELE 20 // Rozmiar elementu bufora (jednostki towaru) w bajtach
#define NBUF 5	// Liczba elementow bufora
#define SCIEZKA "./"

typedef struct
{
	char bufor[NBUF][NELE]; // Wspolny bufor danych
	int zapis;
	int odczyt;
} SegmentPD;

void delMemory(void)
{
	deleteMemory("memory");
	semDel("/sem_producent");
	semDel("/sem_konsument");
}

void endSignal(int signal)
{
	printf("\nSygnał przerwania, usuwanie semaforów i pamięci dzielonej\n");
	exit(EXIT_SUCCESS);
}

// argumenty [0] nazwa_programu [1] program_producent [2] program_konsument
int main(int argc, char *argv[])
{

	int fd;
	sem_t *semafor;

	semafor = semCreate("/sem_producent", NBUF);
	std::cout << "Utworzono semafor producenta o wartości :" << NBUF << std::endl;
	semafor = semCreate("/sem_konsument", 0);
	std::cout << "Utworzono semafor producenta o wartości :0" << std::endl;
	fd = createMemory("memory");
	setSize(fd, sizeof(SegmentPD));

	if (atexit(delMemory) != 0)
	{
		perror("atexit error");
		_exit(EXIT_FAILURE);
	}

	if (signal(SIGINT, endSignal) == SIG_ERR)
	{
		perror("Błąd signal");
		exit(EXIT_FAILURE);
	}

	srand(time(NULL));

	for (int i = 0; i < 2; i++)
	{
		switch (fork())
		{
		case -1:
			perror("fork error");
			exit(EXIT_FAILURE);
		case 0:

			if (i == 0)
			{
				char temp[20];
				sprintf(temp, "%s%s", SCIEZKA, argv[1]);
				execl(temp, argv[1], "/sem_producent", "/sem_konsument", "memory", "zasoby", NULL);
				perror("błąd execl");
				exit(EXIT_FAILURE);
			}
			else
			{
				char temp[20];
				sprintf(temp, "%s%s", SCIEZKA, argv[2]);
				execl(temp, argv[2], "/sem_producent", "/sem_konsument", "memory", "skopiowane", NULL);
				perror("błąd execl");
				exit(EXIT_FAILURE);
			}

			break;

		default:
			break;
		}
	}
	wait(0);
	sleep(2);
	closeMemory(fd);

	printf("\n\nProgram główny: koniec procesu\n");

	return 0;
}