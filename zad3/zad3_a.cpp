// Jakub Poznanski
#include <iostream>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
// SIGQUIT - Sekwencja wyjścia z klawiatury
// SIGINT - Przerwanie z klawiatury
// SIGTSTP - Sekwencja zatrzymania z klawiatury
// kill -9 <PID> można użyć z innego terminalu
void custom(int sig)
{
    std::cout << "\nPrzechwycono sygnał SIGTSTP" << std::endl;
};

int main()
{
    std::cout << " PID:" << getpid() << std::endl;
    // Dla sygnału SIGQUIT wykonaj operację domyślą [ctrl+\]
    signal(SIGQUIT, SIG_DFL);
    // Zignoruj sygnał SIG_IGN [ctrl+c]
    signal(SIGINT, SIG_IGN);
    // Dla sygnału SIGTSTP wykonaj funkcję custom [ctrl+z]
    signal(SIGTSTP, custom);

    // Czekaj na sygnały
    while (1)
    {
        pause();
    }

    return 0;
}