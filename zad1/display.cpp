
#include <iostream>
#include <unistd.h>
#include "display.h"
void display()
{
    std::cout << "UID:" << getuid() << " GID:" << getgid() << " PID:" << getpid() << " PPID:" << getppid() << std::endl;
};
