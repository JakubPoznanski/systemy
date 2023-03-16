//Jakub Poznanski 
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main () {
	
	cout << "\nProces macierzysty" <<endl;
	cout << "UID:  " << getuid() << endl;
	cout << "GID:  " << getgid() << endl;
	cout << "PID:  " << getpid() << endl;
    cout << "PPID: " << getppid() << endl;
	for (int i = 0; i < 3; i++) {
		
		switch (fork ()) {
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
			wait(NULL);
		}
	}
}