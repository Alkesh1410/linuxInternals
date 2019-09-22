//	Prepared by Alkesh Shah

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	char data[20];
	int fileDescriptor;

	if(mkfifo("fifoFile",0644))
		perror("MKFIFO");

	fileDescriptor = open("fifoFile",O_WRONLY);
	if(fileDescriptor < 0)
	{
		perror("OPEN");
		return 0;
	}
	while(1)
	{
		printf("Please enter the Data\t:");
		scanf("%s",data);
		write(fileDescriptor,data,strlen(data)+1);
	}

	return 0;
}
