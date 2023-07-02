#ifndef KOLEJKI_H
#define KOLEJKI_H
#define KOLEJKA_NAZWA "/kolejka_komunikatow"
#define MAX_WIADOMOSCI 10
#define DLUGOSC_KOMUNIKATU 30
#include <mqueue.h>
mqd_t queueOpen(const char *name, int oflag);
void queueTake(mqd_t mq_des, char *msg_ptr, unsigned int *msg_prio);
mqd_t queueCreate(const char *name, int oflag);
void queueDel(const char *name);
void queueClose(mqd_t mq_des);
void queueSend(mqd_t mq_des, const char *msg_ptr, unsigned int msg_prio);
struct mq_attr queueGetAttr(mqd_t mq_des);

#endif