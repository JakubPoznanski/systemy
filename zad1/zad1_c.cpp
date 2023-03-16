// Jakub Poznanski
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main()
{
	pid_t parentId = getpid();

	cout << "\nProces macierzysty" << endl;
	cout << "UID:  " << getuid() << endl;
	cout << "GID:  " << getgid() << endl;
	cout << "PID:  " << getpid() << endl;
	cout << "PPID: " << getppid() << endl;
	for (int i = 0; i < 3; i++)
	{
		switch (fork())
		{
		case -1:
			perror("fork error");
			exit(1);
		case 0:
			cout << "\nUID:  " << getuid() << endl;
			cout << "GID:  " << getgid() << endl;
			cout << "PID:  " << getpid() << endl;
			cout << "PPID: " << getppid() << endl;
			break;

		default:
			sleep(1);
		}
	}
	if (parentId == getpid())
	{
		return 0;
	}
	// Dzięki sleep 15 mamy czas na wpisanie komenty pstree
	sleep(15);
	_exit(0);
}