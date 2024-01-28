#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"
void terminal(int pid)
{
	printf(BGRN"          _                             _               _ \n"COLOR_RESET);
	printf(BGRN"         | |                           | |             | |\n"COLOR_RESET);
	printf(BGRN"  _ __   | | __   __ _   _ __    __ _  | |__    _   _  | |\n"COLOR_RESET);
	printf(BGRN" | '_ \\  | |/ /  / _` | | '__|  / _` | | '_ \\  | | | | | |\n"COLOR_RESET);
	printf(BRED" | | | | |   <  | (_| | | |    | (_| | | |_) | | |_| | | |\n"COLOR_RESET);
	printf(BRED" |_| |_| |_|\\_\\  \\__,_| |_|     \\__,_| |_.__/   \\__,_| |_|\n"COLOR_RESET);
	printf(BCYN"\nProcces ID : %d "COLOR_RESET BRED" github.com/cankarabulut-db\n"COLOR_RESET,pid);
	printf("Message awaited...\n");
}

void handler(int signal)
{
    static int bit;
    static char c;

    if (signal == SIGUSR1)
        c = ((1 << bit) | c);
    if (signal == SIGUSR2)
        c = ((0 << bit) | c);
    bit++;

    if (bit == 8)
    {
        printf("%c", c);
        bit = 0;
        c = 0;
    }
}

int main(int ac,char **av)
{
	int pid;
	
	pid = getpid();
	if (ac != 1)
	{
		printf(BRED"Error: wrong format. Try this : ./server\n"COLOR_RESET);
		return (0);
	}
	terminal(pid);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
    while (1)
			pause();

    return (0);
}
