#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int inFileDescriptor, mfDescriptor, bytesread;
    char buffer[10];
    char *inFile = argv[1];
    char *myfifo = argv[2];

    inFileDescriptor = open(inFile, O_RDONLY, 0666);
    mfDescriptor = open(myfifo, O_WRONLY);
    do
    {
        bytesread = read(inFileDescriptor, &buffer, 5);
        if (bytesread == -1)
        {
            perror("read error\n");
            _exit(0);
        };
        write(STDOUT_FILENO, &buffer, bytesread);
        if (-1 == write(mfDescriptor, &buffer, bytesread))
        {
            perror("write error\n");
            _exit(0);
        }
    } while (bytesread == 5);

    close(*inFile);
    _exit(0);
}