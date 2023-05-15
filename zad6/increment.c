#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include "mylib.h"
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main (int argc, char *argv[]) {
	
	int readCheck;
	char bufor[100];
	char stringBuf[200];
	int liczba;
	int ilosc_sekcji_krytycznych;
	sem_t *semafor;
	int semvalue;
	int file;
	double max_dlugosc_czekania = 1.0;
	//get data from argv
	ilosc_sekcji_krytycznych = atoi(argv[1]);
	if(atoi(argv[4]))
		semafor = otworz_semafor (argv[3]);

	for (int i = 0; i < ilosc_sekcji_krytycznych; i++) {	
		srand(time(NULL));
		double time = (double)(rand() % (int)(max_dlugosc_czekania * 100+i)) / 100;
		sleep(time);
		printf("\n       Sleep(%.2f) przed wejściem w sekcję krytyczną\n",time);
		printf("SEKCJA[%d]\n",i);
		
		// opuść semafor - operacja P
		if(atoi(argv[4]))
		{
			semValue(semafor, &semvalue);
			printf ("PID %d wartość SEM: %d\n", getpid(), semvalue);
			semP(semafor);
			semValue(semafor, &semvalue);
			printf("Operacja P zajęcie SEM--\n");
		}
		
		/* Sekcja krytyczna */
		
		if ((file = open (argv[2], O_RDONLY, 0644)) == -1) {
			printf ("Błąd otwarcia pliku %s do odczytu", argv[2]);
			perror ("File ERR");
			_exit (0);
		}
		
		readCheck = read(file, &bufor, 10);
		if (readCheck == -1) {
			printf("Read file ERR\n");
			_exit(0);
		} else if (readCheck == 0) {
			break;
		} else {
			bufor [readCheck] = '\0';
			if(atoi(argv[4]))
				semValue(semafor, &semvalue);
			sprintf (stringBuf, "PID %d wartość SEM: %d\nODCZYTANA LICZBA [%s]", getpid(), semvalue, bufor);
			printf ("%s\n", stringBuf);
		}
		
		if (close (file) == -1) {
			perror ("File close ERR");
			exit (0);
		}
		
		liczba = atoi (bufor);
		liczba++;
		sprintf (bufor, "%d", liczba);
		printf ("liczba++\nODCZYTANA LICZBA [%d] \n", liczba);
		
		sleep ((double)(rand() % (int)(max_dlugosc_czekania * 100)) / 100);
		
		if ((file = open (argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
			printf ("Błąd otwarcia pliku %s do zapisu", argv[1]);
			perror ("File open ERR");
			_exit (0);
		}
		
		if (write (file, &bufor, strlen(bufor)) == -1){
			perror("Write ERR");
			_exit(0);
		}
		
		if (close (file) == -1) {
			perror ("File close ERR");
			exit (0);
		}
		if(atoi(argv[4])){
			semV (semafor);
			printf("Operacja V zwolnienie SEM++\n");
			semValue(semafor, &semvalue);
			printf ("PID %d wartość SEM: %d\n", getpid(),semvalue);
		}
	}
	semClose(semafor);
	
	return 0;
}