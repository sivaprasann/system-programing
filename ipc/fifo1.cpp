//Program to implement fifo
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#define MAX 256
using namespace std;
int main(){
	char fifoname[] = "fifotest";
	int fifofd,ret,err,bye = 1;
	char readbuff[MAX];
	char writebuff[MAX];
	err = mkfifo(fifoname,0666);
/*	if(err == -1){
		perror("Error creating FIFO");
		exit(EXIT_FAILURE);
	}*/
	while(bye){
	      fifofd = open(fifoname,O_WRONLY);
	      memset(writebuff,0,MAX);
	      write(1,"Message from Friend:",20);
              ret = read(0,writebuff,MAX);
	      //writebuff[ret+1] = '\0';
	      write(1,writebuff,ret);
	      close(fifofd);

             bye =  strcmp("Bye\n",writebuff);
	     cout<<bye<<":"<<writebuff<<endl;
             if(bye){
               
	      fifofd = open(fifoname,O_RDONLY);
              ret = read(fifofd,readbuff,MAX);
	      write(1,"Message From Froend:",20);
	      write(1,readbuff,ret);
	      write(1,"\n",1);
	      
	      close(fifofd);
	     }
	}
}
