#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int execl(const char* path,const char* arg,...);

int main(int argc, char *argv[]){
        int i=0;
        pid_t ppid = getppid();
        pid_t p1=getpid();
        printf("i son/pa ppid pid fpid\n");
        //ppid指当前父进程的pid
        //pid指当前进程的pid
        //fpid指fork返回的当前进程的值
        for (i=0;i<2;i++){
                pid_t fpid = fork();
                if(fpid>0){
                        printf("%d parent %4d %4d %4d\n",i,getppid(),getpid(),fpid);
                        if(i==1 && ppid!=getppid()){
                                fpid =fork();
                                if(fpid>0)
                                        printf("%d parent %4d %4d %4d\n",i,getppid(),getpid(),fpid);
                                else if(!fpid){
                                        //printf("%d son %4d %4d %4d\n",i,getppid(),getpid(),fpid);
                                }
                                else if(fpid==-1)
                                         printf("fork");
                        }
                }
                 else if(!fpid){
                        //printf("%d son %4d %4d %4d\n",i,getppid(),getpid(),fpid);
                 }
                else if(fpid==-1)
                        perror("fork");
        }
        i=0;
        while(1){
                sleep(1);
                printf("mypid is %4d myppid is %4d\n",getpid(),getppid());
                i++;
                if(i>5 && (p1 == (getpid()-1))){
		//制造一个段错误,访问地址为０的内存区域
		unsigned char* pstr = 0x00;
		*pstr = 0x00;
		}
        }
        return 0;
}
