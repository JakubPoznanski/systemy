#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <mqueue.h>
#include "queueLib.h"
#include <iostream>

int calc(char symbol, int num1, int num2)
{
	if (symbol == '+')
		return num1 + num2;
	if (symbol == '-')
		return num1 - num2;
	if (symbol == '*')
		return num1 * num2;
	if (symbol == '/')
		return num1 / num2;
};

void queueDelete(void)
{
	queueDel(KOLEJKA_NAZWA);
	exit(0);
}

void signalExit(int signal)
{
	std::cout << "signal" << std::endl;
	queueDelete();
	exit(0);
}

void displayAttr(mq_attr attr)
{
	std::cout << "Utworzono kolejkę\n"
			  << std::endl;
	std::cout << "mq_flags:" << attr.mq_flags << " mq_maxmsg: " << attr.mq_maxmsg << "\n"
			  << std::endl;
	std::cout << "mq_msgsize:" << attr.mq_msgsize << "mq_curmsgs:" << attr.mq_curmsgs << "\n"
			  << std::endl;
}

int main()
{
	atexit(queueDelete);

	int pid;
	char string[DLUGOSC_KOMUNIKATU];
	int num1;
	int num2;
	char symbol;
	char resultString[DLUGOSC_KOMUNIKATU];
	mqd_t queueDescriptor;
	mqd_t serverAnswer;

	queueDescriptor = queueCreate(KOLEJKA_NAZWA, O_RDONLY);

	struct mq_attr attr = queueGetAttr(queueDescriptor);

	displayAttr(attr);

	if (signal(SIGINT, signalExit) == SIG_ERR)
	{
		perror("Błąd signal");
		exit(EXIT_FAILURE);
	}

	while (1)

	{
		queueTake(queueDescriptor, string, NULL);
		// Pobranie danych
		sscanf(string, "%d %d%c%d", &pid, &num1, &symbol, &num2);
		///////
		std::cout << "Pid klienta" << pid << std::endl;
		std::cout << " Działanie:" << num1 << symbol << &num2 << std::endl;
		///////
		sprintf(resultString, "%d", calc(symbol, num1, num2));
		sprintf(string, "/%d", pid);
		serverAnswer = queueOpen(string, O_WRONLY);
		queueSend(serverAnswer, resultString, 1);
		queueClose(serverAnswer);
	}
	return 0;
}