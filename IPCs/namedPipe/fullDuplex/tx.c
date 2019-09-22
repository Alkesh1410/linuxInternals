//	Prepared by Alkesh Shah
//	This file demonstrates transmitter part of fullduplex communication using named pipe(FIFO)
//	NOTE: Both tx and rx needs to be executed in parallel (using seperate terminal if you are working on linux terminal).

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	char data[20];
	int fileDescriptor1, fileDescriptor2;

	if(mkfifo("fifoFile1",0644))
	{
		perror("MKFIFO_fileDescriptor1");
		return 0;
	}
	if(mkfifo("fifoFile2",0644))
	{
		perror("MKFIFO_fileDescriptor2");
		return 0;
	}

	fileDescriptor1 = open("fifoFile1",O_WRONLY);
	if(fileDescriptor1 < 0)
	{
		perror("OPEN_fifoFile1");
		return 0;
	}
	fileDescriptor2 = open("fifoFile1",O_RDONLY);
	if(fileDescriptor2 < 0)
	{
		perror("OPEN_fifoFile2");
		return 0;
	}

	if(fork())
	{	//	parent
		while(1)
		{
			scanf("%s",data);
			write(fileDescriptor1,data,strlen(data)+1);
		}
	}
	else
	{	//	child
		while(1)
		{
			read(fileDescriptor2,data,sizeof(data));
			printf("Data read is %s\n",data);
		}
	}

	return 0;
}
