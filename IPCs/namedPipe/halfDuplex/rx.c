//	Prepared by Alkesh Shah
//	This file demonstrates the receiver part of halfduplex communication using named pipe(FIFO)
//	NOTE: Both tx and rx needs to be executed in parallel (using seperate terminal if you are working on linux terminal).

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	char data[20];
	int fileDescriptor1, fileDescriptor2;

	fileDescriptor1 = open("fifoFile1",O_RDONLY);
	if(fileDescriptor1 < 0)
	{
		perror("OPEN_fileDescriptor1");
		return 0;
	}
	fileDescriptor2 = open("fifoFile2",O_WRONLY);
	if(fileDescriptor2 < 0)
	{
		perror("OPEN_fileDescriptor2");
		return 0;
	}

	while(1)
	{
		//	read the data from file1 (i.e. fifoFile1)
		read(fileDescriptor1,data,sizeof(data));
		printf("Data read from file1 is %s\n",data);

		//	write the data in file2 (i.e. fifoFile2)
		printf("Enter the data in file2\t:");
		scanf("%s",data);
		write(fileDescriptor2,data,strlen(data)+1);
	}

	return 0;
}
