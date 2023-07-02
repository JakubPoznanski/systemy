#ifndef SEMAFORY_H
#define SEMAFORY_H

#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

sem_t *semCreate(const char *name, int value);
sem_t *semOpen(const char *name);
void semClose(sem_t *sem_t);
int semValue(sem_t *sem);
void semV(sem_t *sem);
void semP(sem_t *sem);
void semDel(const char *name);

#endif
