//	Prepared by Alkesh Shah
//	This file demonstrates the receiver part of the simplex communication (i.e. one way) using named pipe(FIFO)
//	NOTE: Both tx and rx needs to be executed in parallel (using seperate terminal if you are working on linux terminal).

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	char data[20];
	int fileDescriptor;

	if(mkfifo("fifpFile",0644))
		perror("MKFIFO");

	fileDescriptor = open("fifoFile",O_RDONLY);
	if(fileDescriptor < 0)
	{
		perror("OPEN");
		return 0;
	}

	while(1)
	{	//	read() is a blocking call, so will be waiting untill it has something to read (or untill we write something from transmitter end)
		read(fileDescriptor,data,sizeof(data));
		printf("The data read is %s\n",data);
	}
	return 0;
}
