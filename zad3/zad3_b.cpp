// Jakub Poznański
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int child_pid;
    int status;
    switch (child_pid = fork())
    {
    case -1:
        perror("fork error");
        exit(1);
    case 0:
        execlp("./zad3_a", "zad3_a", argv[1], NULL);
        perror("execlp error");
    default:
        sleep(1);
        // sprawdzenie czy proces do którego wysyłamy sygnał istnieje
        if (kill(child_pid, 0) == -1)
        {
            perror("dziecko nie istnieje");
            exit(1);
        }
        if (kill(child_pid, atoi(argv[1])) == -1)
        {
            perror("kill error");
            exit(1);
        }
        wait(&status);
        // WIFSIGNALED zwraca true gdy proces został zakończony przez sygnał
        // WTERMSIG zwraca numer sygnału
        if (WIFSIGNALED(status))
        {
            int signalNumber = WTERMSIG(status);
            std::cout << "Proces został zakończony przez sygnał nr:\n"
                      << signalNumber << "\nRodzaj sygnału:\n"
                      << strsignal(signalNumber) << std::endl;
            exit(0);
        }
    };
}
