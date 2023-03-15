#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i;
    pid_t pid;

    for (i = 0; i < 3; i++) {
        pid = fork();

        if (pid < 0) {
            // błąd podczas tworzenia procesu potomnego
            printf("Błąd podczas tworzenia procesu potomnego!\n");
            return 1;
        } else if (pid == 0) {
            // kod procesu potomnego
            printf("UID: %d\n", getuid());
            printf("GID: %d\n", getgid());
            printf("PID: %d\n", getpid());
            printf("PPID: %d\n", getppid());
            printf("PGID: %d\n", getpgid(getpid()));
            return 0;
        } else {
            // kod procesu macierzystego
            printf("Proces macierzysty - PID: %d, utworzył proces potomny - PID: %d\n", getpid(), pid);
        }
    }
    printf("Początek pętli z waitem");
    // czekanie na zakończenie wszystkich procesów potomnych
    for (i = 0; i < 3; i++) {
        wait(NULL);
    }

    return 0;
}
