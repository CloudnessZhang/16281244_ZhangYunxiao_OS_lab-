#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>

int execl(const char* path,const char* arg,...);

int main(int argc, char *argv[]){
        pid_t fpid;
        fpid = fork();
	if(fpid>0){
		//printf("I am the parent of fpid=%d!\n",fpid);
		while(1){
			sleep(1);
		}
	}
	else if(!fpid){
		//printf("I am the baby!\n");
		int ret;
		ret = execl("/usr/bin/vi","vi","test.txt",NULL);
		if(ret == -1)
			perror("execl");
		}
	else if(fpid==-1)
		perror("fork");
        return 0;
}

