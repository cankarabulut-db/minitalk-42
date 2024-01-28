#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

void SendChar_To_Server(int pid_id,char msj)
{
	int bit;

	bit = 0;
	while(bit <= 7)
	{
		if((msj >> bit) & 1)
			kill(pid_id,SIGUSR1);
		else
			kill(pid_id,SIGUSR2);
		usleep(500);
		bit++;
	}
}
int main(int ac,char **av)
{
	int pid_name;
	int i;

	i = 0;
	pid_name = 0;
	if(ac != 3)
		{
		printf(BYEL"Wrong format, try this : ./client <PID> <MESSAGE>"COLOR_RESET);
		}
		
	if(ac == 3)
	{
		pid_name = atoi(av[1]);
		while(av[2][i] != '\0')
			SendChar_To_Server(pid_name,av[2][i++]);
		SendChar_To_Server(pid_name,'\n');
		SendChar_To_Server(pid_name,'\0');
	}
	return (0);
}