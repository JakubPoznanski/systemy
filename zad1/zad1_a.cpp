//Jakub Poznanski
#include <iostream>
#include <unistd.h>
using namespace std; 
int main() {
    cout << "UID: " << getuid() << endl;
    cout << "GID: " << getgid() << endl;
    cout << "PID: " << getpid() << endl;
    cout << "PPID: " << getppid() << endl;
    //getpgid(0) zwraca PGID procesu o podanym PID (w tym przypadku bieżącego procesu)
    cout << "PGID: " << getpgid(0) << endl; 
    return 0;
}