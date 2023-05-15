#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

sem_t *stworz_semafor (const char *name) {
	sem_t *adres_semafora;
	if ((adres_semafora = sem_open(name,O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED) {
		perror ("Semaphore Create ERR");
		exit (0);
	} else {
		return adres_semafora;
	}
}

sem_t *otworz_semafor (const char *name) {
	sem_t *adres_semafora;
	if ((adres_semafora = sem_open(name, 0)) == SEM_FAILED) {
		perror ("Semaphore Open ERR");
		exit (0);
	} else {
		return adres_semafora;
	}
}

void semClose (sem_t *sem_t) {
	if (sem_close (sem_t) == -1) {
		perror ("Semahpore close ERR");
		exit (EXIT_FAILURE);
	}
}

void semValue (sem_t *sem, int *sval) {
	if (sem_getvalue(sem, sval) == -1) {
		perror ("Semahpore Read value ERR");
		exit (EXIT_FAILURE);
	}
}
//podnieś_semafor
void semV (sem_t *sem) {
	if (sem_post(sem) == -1) {
		perror ("Semaphore post ERR");
		exit (EXIT_FAILURE);
	}
}
//opusc_semafor dawniej semV
void semP (sem_t *sem) {
	if (sem_wait(sem) == -1) {
		perror ("Semaphore wait ERR");
		exit (EXIT_FAILURE);
	}
}
//usun_semafor
void semDel(const char *name) {
	if (sem_unlink(name) == -1) {
		perror ("Semaphore inlink(delete) ERR");
		exit (0);
	}
}