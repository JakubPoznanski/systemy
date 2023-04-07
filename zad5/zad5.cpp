// Jakub Poznanski
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#define myfifo "/tmp/myfifo"
// filedes[0] służy do czytania z potoku
// filedes[1] służy do zapisywania do potoku.
void removepipe(void)
{
    if (remove(myfifo) != 0)
    {
        perror("Error deleting pipe file\n");
        exit(EXIT_FAILURE);
    }
};
int main(int argc, char *argv[])
{
    int id, id2;
    atexit(removepipe);
    mkfifo(myfifo, 0666);
    id = fork();
    switch (id)
    {
    case -1:
        perror("fork error");
        exit(1);
    case 0:
        execlp("./in", "in", argv[1], myfifo, NULL);
        perror("execlp error\n");
    default:
        id2 = fork();
        switch (id2)
        {
        case -1:
            perror("fork error");
            exit(1);
        case 0:
            execlp("./out", "out", argv[2], myfifo, NULL);
            perror("execlp error\n");
        default:
            wait(NULL);
        }
        wait(NULL);
    }
    close(*myfifo);
    exit(0);
}