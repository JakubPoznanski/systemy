// Jakub Poznanski
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include "display.h"
pid_t parentId = getpid();

int main()
{
    display();
    for (int i = 0; i < 3; i++)
    {
        switch (fork())
        {
        case -1:
            perror("fork error");
            exit(1);

        case 0:
            display();
        default:
            sleep(1);
            break;
        }
        sleep(4);
    }
    if (parentId == getpid())
    {
        return 0;
    }
    _exit(0);
}