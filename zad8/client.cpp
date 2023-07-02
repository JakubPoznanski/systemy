#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <mqueue.h>
#include "queueLib.h"
#include <iostream>
mqd_t queueDescriptor;

void displayAttr(mq_attr attr)
{
	std::cout << "Utworzono kolejkę\n"
			  << std::endl;
	std::cout << "mq_flags:" << attr.mq_flags << " mq_maxmsg: " << attr.mq_maxmsg << "\n"
			  << std::endl;
	std::cout << "mq_msgsize:" << attr.mq_msgsize << "mq_curmsgs:" << attr.mq_curmsgs << "\n"
			  << std::endl;
}

void queueDelete(void)
{
	queueClose(queueDescriptor);
}

void signalExit(int signal)
{
	queueDelete();
	exit(0);
}

int main()
{

	char serverAnswerString[10];
	mqd_t serverAnswer;
	char readBuffor[DLUGOSC_KOMUNIKATU];
	char string[DLUGOSC_KOMUNIKATU + 10];
	sleep(2);
	sprintf(serverAnswerString, "/%d", getpid());

	queueDescriptor = queueOpen(KOLEJKA_NAZWA, O_WRONLY);

	struct mq_attr attr = queueGetAttr(queueDescriptor);
	displayAttr(attr);
	atexit(queueDelete);

	if (signal(SIGINT, signalExit) == SIG_ERR)
	{
		perror("Błąd signal");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		std::cout << "podaj działanie" << std::endl;
		if (scanf("%s", readBuffor) == EOF)
		{
			std::cout << "koniec działania programu wyłącz okienko" << std::endl;
			exit(0);
		}

		sprintf(string, "%d %s", getpid(), readBuffor);

		queueSend(queueDescriptor, string, 1);

		std::cout << "\nWysłano wiadomość do serwera" << std::endl;
		serverAnswer = queueCreate(serverAnswerString, O_RDONLY);

		queueTake(serverAnswer, string, NULL);
		printf("Odpowiedź z serwera: %s\n\n", string);
		queueClose(serverAnswer);
		queueDel(serverAnswerString);
	}
	queueClose(queueDescriptor);

	return 0;
}