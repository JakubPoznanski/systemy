// Jakub Poznanski
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include "display.h"
int main()
{
	std::cout << "Proces macierzysty" << std::endl;
	display();
	for (int i = 0; i < 3; i++)
	{
		switch (fork())
		{
		case -1:
			perror("fork error");
			exit(1);

		case 0:
			// akcja dla procesu potomnego
			display();
			break;

		default:
			// akcja dla procesu macierzystego
			// funkcja wait sprawi , że proces macierzysty poczeka na skończenie procesów potomnych
			wait(NULL);
		}
	}
}