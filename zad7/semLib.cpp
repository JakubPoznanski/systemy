#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

sem_t *semCreate(const char *name, int value)
{
	sem_t *adres_semafora;
	if ((adres_semafora = sem_open(name, O_CREAT | O_EXCL, 0644, value)) == SEM_FAILED)
	{
		perror("błąd tworzenia semafora");
		exit(EXIT_FAILURE);
	}
	else
	{
		return adres_semafora;
	}
}

sem_t *semOpen(const char *name)
{
	sem_t *adres_semafora;
	if ((adres_semafora = sem_open(name, 0)) == SEM_FAILED)
	{
		perror("błąd otworzenia semafora");
		exit(EXIT_FAILURE);
	}
	else
	{
		return adres_semafora;
	}
}

void semClose(sem_t *sem_t)
{
	if (sem_close(sem_t) == -1)
	{
		perror("błąd zamykania semafora");
		exit(EXIT_FAILURE);
	}
}

int semValue(sem_t *sem)
{
	int sval;
	if (sem_getvalue(sem, &sval) == -1)
	{
		perror("błąd odczytywania wartości semafora");
		exit(EXIT_FAILURE);
	}
	else
	{
		return sval;
	}
}

void semV(sem_t *sem)
{
	if (sem_post(sem) == -1)
	{
		perror("błąd podnoszenia semafora");
		exit(EXIT_FAILURE);
	}
}

void semP(sem_t *sem)
{
	if (sem_wait(sem) == -1)
	{
		perror("błąd opuszczania semafora");
		exit(EXIT_FAILURE);
	}
}

void semDel(const char *name)
{
	if (sem_unlink(name) == -1)
	{
		perror("błąd usuwania semafora");
		exit(EXIT_FAILURE);
	}
}