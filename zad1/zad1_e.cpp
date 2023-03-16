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
            // funcja setgid()zostaje wywołana nawet gdy jest umieszczona w warunku if()
            if (setpgid(0, 0) == -1)
            {
                perror("setpgid error");
                exit(1);
            }
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