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
    int outFileDescriptor, mf, bytes;
    int bytesForBuff = 3;
    char buffer[10];
    char *outFileName = argv[1];
    char *myfifo = argv[2];
    // otworzenie pliku wejściowego
    // otworzenie potoku chyba ?
    outFileDescriptor = open(outFileName, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    mf = open(myfifo, O_RDONLY);
    do
    {
        // Odczyt bitów z pliku wejściowego i zapis w buforze
        bytes = read(mf, &buffer, bytesForBuff);
        // wpis z bufora do wejscia potoku
        if (-1 == bytes)
        {
            perror("read error 1\n");
            _exit(EXIT_FAILURE);
        }
        if (-1 == write(STDOUT_FILENO, buffer, bytes))
        {
            perror("write error\n");
            _exit(EXIT_FAILURE);
        }
        if (-1 == write(outFileDescriptor, buffer, bytes))
        {
            perror("write error\n");
            _exit(EXIT_FAILURE);
        }

    } while (bytes == bytesForBuff);
    close(outFileDescriptor);
    _exit(0);
}