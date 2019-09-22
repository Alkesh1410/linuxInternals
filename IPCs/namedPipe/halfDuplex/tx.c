//	Prepared by Alkesh Shah
//	This file demonstrates transmitter part of halfduplex communication using named pipe(FIFO)
//	NOTE: Both tx and rx needs to be executed in parallel (using seperate terminal if you are working on linux terminal).

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	char data[20];
	int fileDescriptor1, fileDescriptor2;

	if(mkfifo("fifoFile1",0644))
		perror("MKFIFO_fifoFile1");
	if(mkfifo("fifoFile2",0644))
		perror("MKFIFO_fifoFile2");

	fileDescriptor1 = open("fifoFile1",O_WRONLY);
	if(fileDescriptor1 < 0)
	{
		perror("OPEN_fileDescriptor1");
		return 0;
	}
	fileDescriptor2 = open("fifoFile2",O_RDONLY);
	if(fileDescriptor2 < 0)
	{
		perror("OPEN_fileDescriptor2");
		return 0;
	}

	while(1)
	{
		//	write the data into file1 (i.e. fifoFile1)
		printf("Enter the data in file1\t:");
		scanf("%s",data);
		write(fileDescriptor1,data,strlen(data)+1);	

		//	read the data from file2 (i.e. fifoFile2)
		read(fileDescriptor2,data,sizeof(data));
		printf("Data read from file2 is %s\n",data);
	}

	return 0;
}
