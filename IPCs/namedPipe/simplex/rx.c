#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	{
		read(fileDescriptor,data,sizeof(data));
		printf("The data read is %s\n",data);
	}
	return 0;
}
