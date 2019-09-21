//	Prepared by Alkesh Shah

#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int _pipe1[2], _pipe2[2];
	if(pipe(_pipe1))
	{
		perror("PIPE1");
		return 0;
	}
	if(pipe(_pipe2))
	{
		perror("PIPE1");
		return 0;
	}

	if(fork() == 0)			//	child process
	{
		//	read the data received from PIPE1
		char pData[20];
		read(_pipe1[0],pData,sizeof(pData));

		//	modify the data
		for(int i = 0;pData[i];i++)
			pData[i] -= 32;

		//	write the modified data into PIPE2
		write(_pipe2[1],pData,strlen(pData)+1);
	}
	else				//	parent process
	{
		//	write the data into PIPE1
		char cData[20];
		printf("Please enter the data\t:");
		scanf("%s",cData);
		write(_pipe1[1],cData,strlen(cData)+1);

		//	read the data sent from PIPE2
		read(_pipe2[0],cData,sizeof(cData));
		printf("Modified data recieved from parent is %s\n",cData);
	}

	return 0;
}
