// Jakub Poznanski
#include <iostream>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
// Przykładowe sygnały i ich numery
//  2 - SIGINT - Przerwanie z klawiatury [ctrl+c]
//  3 - SIGQUIT - Sekwencja wyjścia z klawiatury [ctrl+\]
//  20 - SIGTSTP - Sekwencja zatrzymania z klawiatury [ctrl+z]
//  kill -9 <PID> można użyć z innego terminalu
void custom(int sig)
{
    std::cout << "Przechwycenie sygnału:\nNumer: " << sig << "\nRodzaj: " << strsignal(sig) << std::endl;
};
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Brak argumentów wywołania\nPodaj numer sygnału , sposób obsługi" << std::endl;
        exit(0);
    }
    int action = atoi(argv[2]);
    int number = atoi(argv[1]);
    std::cout << " PID:" << getpid() << std::endl;

    switch (action)
    {
    case 1:
        if (signal(number, SIG_DFL) == SIG_ERR)
        {
            perror("signal err");
            exit(0);
        }
        std::cout << "Operacja domyślna dla sygnału:\nNumer: " << number << "\nRodzaj: " << strsignal(number) << std::endl;
        break;
    case 2:
        if (signal(number, SIG_IGN) == SIG_ERR)
        {
            perror("signal err");
            exit(0);
        }
        std::cout << "Ignorowanie sygnału:\nNumer: " << number << "\nRodzaj: " << strsignal(number) << std::endl;
        break;
    case 3:
        if (signal(number, custom) == SIG_ERR)
        {
            perror("signal err");
            exit(0);
        }
        break;
    default:
        std::cout << "błędne podanie rodzaju sygnału\n1-operacja domyślna\n2-ignorowanie\n3-operacja przechwycenia" << std::endl;
        exit(0);
        break;
    }
    while (1)
    {
        pause();
    }

    return 0;
}