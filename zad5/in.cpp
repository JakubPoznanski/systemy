#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int inFileDescriptor, mf, bytes;
    int bytesForBuff = 3;
    char buffer[10];
    char *inFileName = argv[1];
    char *myfifo = argv[2];
    // otworzenie pliku wejściowego
    inFileDescriptor = open(inFileName, O_RDONLY, 0666);
    mf = open(myfifo, O_WRONLY);
    do
    {
        // Odczyt bitów z pliku wejściowego i zapis w buforze
        bytes = read(inFileDescriptor, &buffer, bytesForBuff);
        // wpis z bufora do wejscia potoku
        if (write(mf, &buffer, bytes) == -1)
        {
            perror("write error\n");
            exit(0);
        }
        // wpis bufora na standardowe wyjście
        if (write(STDOUT_FILENO, &buffer, bytes) == -1)
        {
            perror("write error\n");
            exit(0);
        }

    } while (bytes == bytesForBuff);
    close(inFileDescriptor);
    _exit(0);
}