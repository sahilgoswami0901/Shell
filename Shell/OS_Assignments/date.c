#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]){
	char* token=argv[0];
	if(token==NULL){
		time_t Time;
		Time = time(NULL);
		struct tm tm;
		tm = *localtime(&Time);
		printf("Current Time: %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
		printf("Current Date: %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	}
	else if(strcmp(token,"-u")==0){	
		//UTC Time	
		time_t Time=time(&Time);
		struct tm *UTC=gmtime(&Time);
		if(UTC==NULL){
			printf("Error: gmtime() failed \n");
		}
		printf("UTC TIME : %s\n",asctime(UTC));
	}
	else if(strcmp(token,"--help")==0){	
		//Help for date command
		printf("Help in date:\n");
		FILE* stream=fopen("/home/OS_Assignments/date.txt","r");
			char read[1000];
			while(fgets(read,sizeof(read),stream)!=NULL){
				fputs(read,stdout);
			}
			fclose(stream);
	}
	else{
		printf("Command not supported\n");
	}
}