
// Jakub Poznański
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int status;
    int child_pid;
    child_pid = fork();
    int signalNumber = atoi(argv[1]);
    switch (child_pid)
    {
    case -1:
        perror("fork error");
        exit(1);
    case 0:
        if (setpgid(child_pid, 0) == -1)
        {
            perror("setpgid error");
            exit(0);
        }
        // petla sprawia , że macierzysty 2 ignoruje sygnały
        for (int i = 1; i < NSIG; i++)
        {
            signal(i, SIG_IGN);
        }
        execlp("./sub_c", "sub_c", argv[1], argv[2], NULL);
    default:
        sleep(1);
        pid_t pgid = child_pid;
        if (kill(-pgid, 0) == -1)
        {
            perror("kill error");
            exit(0);
        }
        for (int i = 0; i < 1; i++)
        {
            sleep(1);
            if (kill(-pgid, signalNumber) == -1)
            {
                perror("kill error");
                exit(1);
            }
        }
        wait(&status);
        if (WIFSIGNALED(status))
        {
            int signalNumber = WTERMSIG(status);
            std::cout << "Proces został zakończony przez sygnał:\nNumer: " << signalNumber << "\nRodzaj: " << strsignal(signalNumber) << "\n"
                      << std::endl;
            break;
        }
        std::cout << "Proces zakończył działanie normalnie\n"
                  << std::endl;
        break;
    }
}