#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include "mylib.h"
#include <time.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

char nazwa_semafora[20];

void deleteSemaphore(void) {
	semDel (nazwa_semafora);
}

void breakSignal(int signal) {
	printf("Sygnał przerwania, usuwanie semafora\n");
	semDel (nazwa_semafora);
	_exit(0);
}

int main (int argc, char *argv[]) {

	if (atexit (deleteSemaphore) != 0) {
		perror("atexit error");
		exit(0);
	}

	if (signal (SIGINT, breakSignal) == SIG_ERR) {
		perror("Błąd signal");
		exit(0);
	}

	int forkNumber;
	int file;
	forkNumber = atoi(argv[2]);
	strcpy (nazwa_semafora, argv[5]);

	// stwórz file
	if ((file = open (argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
		printf ("Błąd otwarcia pliku %s do zapisu", argv[1]);
		perror ("Błąd pliku");
		exit (0);
	}
	
	if (write (file, "0", 2) == -1){
		perror("Błąd write do pliku");
		exit(0);
	}
	
	if (close (file) == -1) {
		perror ("Błąd zamknięcia pliku");
		exit (0);
	}
	
	sem_t *semafor = stworz_semafor (nazwa_semafora);
	int semvalue;
	semValue(semafor, &semvalue);
	printf ("Utworzono semafor %s (%p) o wartości %d\n", nazwa_semafora, (void *)semafor, semvalue);
	
	for (int i = 0; i < forkNumber; i++) {
		switch (fork ()) {
			case -1:
				perror("fork error");
				exit(0);
			case 0:
				execl ("increment.x", argv[1], argv[3], argv[4], argv[5], NULL);// uruchom inkrementator
				perror ("execl error");
				exit(0);
				
				break;
			default:
				sleep(forkNumber);
				break;
		}
	}
	return 0;
}