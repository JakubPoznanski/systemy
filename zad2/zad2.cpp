// Jakub Poznanski
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    for (int i = 0; i < 3; i++)
    {
        switch (fork())
        {
        case -1:
            perror("fork error");
            exit(1);

        case 0:
            // akcja dla procesu potomnego
            execlp(argv[1], argv[2], NULL);
            std::cout << "nigdy nie zostanie wyświetlone" << std::endl;
            // ponieważ execlp kończy aktualny proces i rozpoczyna nowy,który dotyczy innego pliku
            perror("execlp error");
            break;

        default:
            // akcja dla procesu macierzystego
            // funkcja wait sprawi , że proces macierzysty poczeka na skończenie procesów potomnych
            wait(NULL);
        };
    }
}