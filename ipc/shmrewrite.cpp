//Program to write share Memory
#include <iostream>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#define MAX 256
using namespace std;
int main(){
	key_t key;
	int shmid;
	char *msg;

	key = ftok("keyfile",65);
	shmid = shmget(key,1024,0666|IPC_CREAT);
	if(shmid == -1){
		perror("Error Creating Shared Memory");
		exit(EXIT_FAILURE);
	}
	msg = (char *) shmat(shmid,(void *)0,0);
	cout <<"Data Read from share memory:" <<msg <<endl;
	memset(msg,0,MAX);
        write(1,"Enter your data to Store: ",25);
	read(0,msg,MAX);

	cout <<"Data Written to Share Memory: " <<msg <<endl;
	shmdt(msg);
	return 0;
}
