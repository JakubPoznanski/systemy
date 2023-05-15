#ifndef MYLIB_H
#define MYLIB_H

sem_t *stworz_semafor (const char *name);
sem_t *otworz_semafor (const char *name);
void semClose (sem_t *sem_t);
void semValue (sem_t *sem, int *sval);
void semV (sem_t *sem);
void semP(sem_t *sem);
void semDel(const char *name);

#endif