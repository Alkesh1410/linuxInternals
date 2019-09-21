//	Prepared By Alkesh Shah

//	PIPE provides a unidirectional interprocess communication channel. A pipe has a read end and a write end.
//	Data written to the write end of a pipe can be read from the read end of the pipe.
//	Pipes are useful only for communication between related process.
//	We can read/write from either child or parent 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int p[2];
	if(pipe(p))
	{
		perror("Pipe:");
		return 0;
	}
	if(fork() == 0)
	{
		//	Child
		printf("You are in child\n");
		char data1[10];
		printf("Write the Data from child\t:");
		gets(data1);
		write(p[1],data1,strlen(data1)+1);
	}
	else
	{
		//	Parent
		printf("You are in parent\n");
		char data[10];
		read(p[0],data,sizeof(data));
		printf("Parent has read %s\n",data);
	}
	return 0;
}
