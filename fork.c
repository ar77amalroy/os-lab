#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	pid_t childpid=fork();
	if(childpid==-1)
	{
		printf("Child creation unsuccessfull\n");
	}
	else if(childpid==0)
	{
		printf("Child creation successfull\n");
		printf("PID%d\n",getpid());
		printf("Parent PID %d\n",getppid());
	}
	else
	{
		printf("Parent process\n");
		printf("PID %d\n",getpid());
		printf("Child PID %d\n",childpid);
		wait(NULL);
		printf("Child finished");
		exit(0);
	}
	return 0;
}
