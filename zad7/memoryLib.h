#ifndef DZIELONA_H
#define DZIELONA_H
// stworz_PD
int createMemory(const char *name);
int openMemory(const char *name);
void setSize(int fd, off_t length);
void closeMemory(int fd);
void deleteMemory(const char *name);
void *map(int fd, size_t length);
void mumMap(void *addr, size_t length);

#endif