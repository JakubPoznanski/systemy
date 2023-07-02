#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include "queueLib.h"

mqd_t queueCreate(const char *name, int oflag)
{
	struct mq_attr attr;
	attr.mq_maxmsg = MAX_WIADOMOSCI;
	attr.mq_msgsize = DLUGOSC_KOMUNIKATU;
	mqd_t descriptor = mq_open(name, O_CREAT | O_EXCL | oflag, 0644, &attr);
	if (descriptor == -1)
	{
		perror("błąd tworzenia kolejki");
		exit(EXIT_FAILURE);
	}
	return descriptor;
}

mqd_t queueOpen(const char *name, int oflag)
{
	mqd_t descriptor = mq_open(name, oflag);
	if (descriptor == -1)
	{
		perror("błąd otwierania kolejki");
		exit(EXIT_FAILURE);
	}
	return descriptor;
}

void queueSend(mqd_t mq_des, const char *msg_ptr, unsigned int msg_prio)
{
	if (mq_send(mq_des, msg_ptr, DLUGOSC_KOMUNIKATU, msg_prio) == -1)
	{
		perror("błąd wysyłania komunikatu");
		exit(EXIT_FAILURE);
	}
}

void queueTake(mqd_t mq_des, char *msg_ptr, unsigned int *msg_prio)
{
	if (mq_receive(mq_des, msg_ptr, DLUGOSC_KOMUNIKATU, msg_prio) == -1)
	{
		perror("błąd odbierania komunikatu");
		exit(EXIT_FAILURE);
	}
}

void queueClose(mqd_t mq_des)
{
	if (mq_close(mq_des) == -1)
	{
		perror("błąd zamykania kolejki");
		exit(EXIT_FAILURE);
	}
}

void queueDel(const char *name)
{
	if (mq_unlink(name) == -1)
	{
		perror("błąd usuwania kolejki");
		exit(EXIT_FAILURE);
	}
}

struct mq_attr queueGetAttr(mqd_t mq_des)
{
	struct mq_attr attrs;
	if (mq_getattr(mq_des, &attrs) == -1)
	{
		perror("błąd pobierania atrybutów kolejki");
		exit(EXIT_FAILURE);
	}
	return attrs;
}