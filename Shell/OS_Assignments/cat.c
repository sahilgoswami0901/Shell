#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
char cwd[1000];
void Getcwd(){
	getcwd(cwd,sizeof(cwd));
	if(cwd==NULL){
		printf("getcwd() error\n");
	}
}
int main(int argc, char* argv[]){
	// for(int i=0;argv[i]!=NULL;i++)
	// {
	// 	if(argv[i][0]!='\0')
	// 	printf("%s\n",argv[i]);
	// }
	const char* token=argv[0];
	// printf("%s\n",token);
	char string[105];
	strcpy(string,argv[1]);
	// printf("%d\n",strlen(argv[1]));
	if(token==NULL){
		printf("Argument missing, Try 'cat --help' for more information. \n");
	}

	else if(strcmp(token,"-n")==0){

		char* iterator=strtok(string," ");
		if(strcmp(iterator,"cat")==0){
			iterator=strtok(NULL," ");
			if(strcmp(iterator,"-n")==0){
				iterator=strtok(NULL," ");
			}
		}

		struct stat st={0};		//for storing information about file
		int line=1;
		Getcwd();
		strcat(cwd,"/");
		strcat(cwd,iterator);
		if(stat(cwd,&st)==-1){
			printf("File does not exist\n");
		}
		FILE *stream=fopen(cwd,"r");
		// printf("%s/n",cwd);
		if(stream!=NULL){
			char read[1000];
			while((fgets(read,sizeof(read),stream))!=NULL){
				printf("%d ",line);
				line+=1;
				fputs(read,stdout);
				
			}
		}

		if(stream==NULL){
			printf("Error in opening file\n");
		}
	}
	else if(strcmp(token,"-E")==0){		
		struct stat st={0};		//for storing information about file

		char* iterator=strtok(string," ");
		if(strcmp(iterator,"cat")==0){
			iterator=strtok(NULL," ");
			if(strcmp(iterator,"-E")==0){
				iterator=strtok(NULL," ");
			}
		}

		Getcwd();
		strcat(cwd,"/");
		strcat(cwd,iterator);

		if(stat(cwd,&st)==-1){
			printf("File does not exist\n");
		}
		FILE *stream=fopen(cwd,"r");
		if(stream!=NULL){
			char read[1000];
			while(fgets(read,sizeof(read),stream)!=NULL){
				strcat(read,"$");
				fputs(read,stdout);
			}
		}

		if(stream==NULL){
			printf("Error in opening file\n");
		}
	}
	else if(strcmp(token,"--help")==0){	
		printf("Help in cat Command\n");
		
	}
	else
	{
		struct stat st={0};		//for storing information about file

		char* iterator=strtok(string," ");
		if(strcmp(iterator,"cat")==0){
			iterator=strtok(NULL," ");
			if(strcmp(iterator,"-E")==0){
				iterator=strtok(NULL," ");
			}
		}

		Getcwd();
		strcat(cwd,"/");
		strcat(cwd,iterator);

		if(stat(cwd,&st)==-1){
			printf("File does not exist\n");
		}
		FILE *stream=fopen(cwd,"r");
		if(stream!=NULL){
			char read[1000];
			while(fgets(read,sizeof(read),stream)!=NULL){
				fputs(read,stdout);
			}
		}

		if(stream==NULL){
			printf("Error in opening file\n");
		}
	}
}