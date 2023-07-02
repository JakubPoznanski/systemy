#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int createMemory(const char *name)
{
	int deskryptor = shm_open(name, O_EXCL | O_RDWR | O_CREAT, 0644);
	if (deskryptor == -1)
	{
		perror("błąd tworzenia pamieci dzielonej");
		exit(EXIT_FAILURE);
	}
	else
	{
		return deskryptor;
	}
}

int openMemory(const char *name)
{
	int deskryptor = shm_open(name, O_RDWR, 0644);
	if (deskryptor == -1)
	{
		perror("błąd otwierania pamieci dzielonej");
		exit(EXIT_FAILURE);
	}
	else
	{
		return deskryptor;
	}
}

void setSize(int fd, off_t length)
{
	if (ftruncate(fd, length) == -1)
	{
		perror("błąd inicjowania pamieci dzielonej");
		exit(EXIT_FAILURE);
	}
}

void closeMemory(int fd)
{
	if (close(fd) == -1)
	{
		perror("błąd zamykania pamieci dzielonej");
		exit(EXIT_FAILURE);
	}
}

void deleteMemory(const char *name)
{
	if (shm_unlink(name) == -1)
	{
		perror("błąd usuwania pamieci dzielonej");
		exit(EXIT_FAILURE);
	}
}

// odwzorowanie pamięci
void *map(int fd, size_t length)
{
	void *adres = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (adres == MAP_FAILED)
	{
		perror("błąd odwzorowania pamieci dzielonej");
		exit(EXIT_FAILURE);
	}
	else
	{
		return adres;
	}
}

void mumMap(void *addr, size_t length)
{
	if (munmap(addr, length) == -1)
	{
		perror("błąd usuwania odwzorowania pamieci dzielonej");
		exit(EXIT_FAILURE);
	}
}