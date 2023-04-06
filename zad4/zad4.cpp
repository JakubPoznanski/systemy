
// Jakub Poznanski
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
// filedes[0] służy do czytania z potoku
// filedes[1] służy do zapisywania do potoku.
int main(int argc, char *argv[])
{
    int bytesForBufP = 3;
    int bytesForBufC = 3;
    int id, filedes[2], nobytes, inFileDescriptor, outFileDescriptor, random_value;
    char bufferP[bytesForBufP], bufferC[bytesForBufC];
    char bytesNumber[2];

    if (pipe(filedes) == -1)
    {
        perror("pipe error\n");
        exit(0);
    }

    id = fork();
    switch (id)
    {
    case -1:
        perror("fork error");
        exit(1);
    case 0:
        // otworzenie pliku wyjsciowego
        outFileDescriptor = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 9999);
        close(filedes[1]);
        do
        {
            random_value = rand() % 3;
            std::cout << "\n Oczekiwanie przez: " << random_value + 1 << " sekundy \n " << std::endl;
            sleep(random_value + 1);
            // Odczyt bitów z wyjścia potoku i zapis w buforze
            nobytes = read(filedes[0], &bufferC, bytesForBufC);
            // Wpis do pliku wyjściowego
            if (write(outFileDescriptor, &bufferC, nobytes) == -1)
            {
                perror("write error\n");
                exit(0);
            }
            // wpis bufora na standardowe wyjście
            if (write(STDOUT_FILENO, &bufferC, nobytes) == -1)
            {
                perror("write error\n");
                exit(0);
            }
            sprintf(bytesNumber, "%d", nobytes);
            if (write(STDOUT_FILENO, &bytesNumber, nobytes) == -1)
            {
                perror("write error\n");
                exit(EXIT_FAILURE);
            }
        } while (nobytes == bytesForBufC);
        close(outFileDescriptor);
        exit(0);

    default:
        // otworzenie pliku wejściowego
        inFileDescriptor = open(argv[1], O_RDONLY, 0666);
        close(filedes[0]);
        do
        {
            random_value = rand() % 3;
            sleep(random_value + 1);
            // Odczyt bitów z pliku wejściowego i zapis w buforze
            nobytes = read(inFileDescriptor, &bufferP, bytesForBufP);
            // wpis z bufora do wejscia potoku
            if (write(filedes[1], &bufferP, nobytes) == -1)
            {
                perror("write error\n");
                exit(0);
            }
            // wpis bufora na standardowe wyjście
            if (write(STDOUT_FILENO, &bufferP, nobytes) == -1)
            {
                perror("write error\n");
                exit(0);
            }

        } while (nobytes == bytesForBufP);
        close(inFileDescriptor);
        exit(0);
    }
    return 0;
}