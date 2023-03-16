// Jakub Poznanski
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include "display.h"
int main()
{
	// zapisanie ID procesu macierzystego
	pid_t parentId = getpid();
	std::cout << "Proces macierzysty" << std::endl;
	// wyświetlenie procesu macierzystego funkcją display
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
			// akcja dla procesu macierzystego, np. wywolanie funkcji wait
			// w kazdej iteracji zaczeka sekundę to w zupełności wystarczy aby inne procesy go "wyprzedziły"
			sleep(1);
		}
	}
	// Jeżeli Id aktualnego procesu jest rowne id procesu macierzystego kończymy działanie programu
	if (parentId == getpid())
	{
		return 0;
	}
	// Sleep(15) zadziala tylko na procesy potomne
	// zatem kiedy proces macierzysty dobiegnie końca zostaną one adoptowane przez proces init
	// widoczne w pliku pstree.png
	sleep(15);
	_exit(0);
}
