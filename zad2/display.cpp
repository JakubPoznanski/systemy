
#include <iostream>
#include <unistd.h>

int main()
{
    std::cout << "UID:" << getuid() << " GID:" << getgid() << " PID:" << getpid() << " PPID:" << getppid() << " PGID:" << getpgid(0) << std::endl;
};
