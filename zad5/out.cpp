#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int outFileDescriptor, mfDescriptor, bytesread;
    char buffer[10];
    char *outFile = argv[1];
    char *myfifo = argv[2];

    outFileDescriptor = open(outFile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    mfDescriptor = open(myfifo, O_RDONLY);
    do
    {
        bytesread = read(mfDescriptor, &buffer, 5);
        if (-1 == bytesread)
        {
            perror("read error\n");
            _exit(0);
        }
        if (-1 == write(STDOUT_FILENO, &buffer, bytesread))
        {
            perror("write error\n");
            _exit(0);
        }
        if (-1 == write(outFileDescriptor, &buffer, bytesread))
        {
            perror("write error\n");
            _exit(0);
        }
    } while (bytesread == 5);
    _exit(0);
}