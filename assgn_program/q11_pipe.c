#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(){
	int fd[2];
	char buff[50];
	char data[50] = {};
	
	//open a pipe
	if(pipe(fd) == -1){
		perror("pipe");
		exit(1);
	}
	
	sprintf(buff,"This is demo program for pipe");
	write(fd[1],buff,strlen(buff));
	
	printf("\n");
	
	read(fd[0],data,5);
	printf("%s\n",data);
	
	read(fd[0],data,5);
	printf("%s\n",data);
	
	read(fd[0],data,10);
	printf("%s\n",data);
}
