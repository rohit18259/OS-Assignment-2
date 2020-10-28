/* Name: Rohit Roy
   Roll_Number: 2018259 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int a = 10;

int main(){
	pid_t pid;
	pid = fork();
	if (pid<0){
		fprintf(stderr,"fork failed");
		return 1;
	}
	else if (pid==0){
		while (a>-90){
			printf("child process: %d\n",a);
			a--;
		}
		printf("child process: %d\n",a);
		printf("child process over\n");
	}
	else{
		while (a<100){
			printf("parent process: %d\n",a);
			a++;
		}
		printf("parent process: %d\n",a);
		printf("parent process over\n");
		waitpid(-1,NULL,0);
	}
	return 0;
}
