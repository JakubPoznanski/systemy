
// Jakub Poznanski
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int status;
    for (int i = 0; i < 3; i++)
    {
        switch (fork())
        {
        case -1:
            perror("fork error");
            exit(1);

        case 0:
            execlp("./zad3_a", "zad3_a", argv[1], argv[2], (char *)NULL);
            perror("execlp error");
            break;

        default:

            std::cout << "Proces zakończył działanie normalnie\n"
                      << std::endl;
            break;
        }
    }
    wait(&status);
    if (WIFSIGNALED(status))
    {
        int signalNumber = WTERMSIG(status);
        signalNumber = atoi(argv[1]);
        std::cout
            << "Proces został zakończony przez sygnał:\nNumer: " << signalNumber << "\nRodzaj: " << strsignal(signalNumber) << "\n"
            << std::endl;
    }
    std::cout << "Drugi macierzysty PID:" << getpid() << "\n"
              << std::endl;
}