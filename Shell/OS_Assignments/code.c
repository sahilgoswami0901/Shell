#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
char cwd[1000];
char PWD[1000];

void* st(void* arr)
{
    system((char*)arr);
}
void execute_Chdir(char* directory){
	int x=chdir(directory);
	if(directory==-1){
		printf("Error in changing directory to %s\n",directory);
	}
	else{
		//for maintaining previous working directory for only "cd" command
		strcpy(PWD,cwd);
		strcpy(cwd,directory);
	}
}
void execute_Getcwd(){
	getcwd(cwd,sizeof(cwd));
	if(cwd==NULL){
		printf("getcwd() error\n");
	}
}
int checkforInt_C(char* token){
	if(strcmp(token,"cd")==0 || strcmp(token,"echo")==0 || strcmp(token,"pwd")==0 || strcmp(token,"exit")==0){
		return 1;
	}
	else{
		return 0;
	}
}
int checkforExt_C(char* token){
	if(strcmp(token,"ls")==0 || strcmp(token,"cat")==0 || strcmp(token,"date")==0 || strcmp(token,"rm")==0 || strcmp(token,"mkdir")==0){
		return 1;
	}
	else{
		return 0;
	}
}
void execute_cd(char* argument){
	if(argument==NULL || strcmp(argument,"-")==0){
		//for going back to previously working directory
		execute_Chdir(PWD);
	}
	else if(strcmp("..",argument)==0){
		//for going to the parent directory
		execute_Chdir("../");				
	}
	else{
		execute_Chdir(argument);
	}
}
void execute_pwd(char* get){
	if(get!=NULL){
		if(strcmp(get,"-L")==0){
			printf("%s\n",cwd);
		}
		else if(strcmp(get,"--help")==0){
			FILE* stream=fopen("/home/OS_Assignments/pwdhelp.txt","r");
			char read[1000];
			while(fgets(read,sizeof(read),stream)!=NULL){
				fputs(read,stdout);
			}
			fclose(stream);
		}
		else{
			printf("Command not supported \n");
		}
	}
	else{
		printf("%s\n",cwd);
	}
}
void execute_echo(char* token){
	if(token==NULL){
		printf("\n");
	}
	else if(strcmp(token,"--help")==0){
		printf("Type echo and then type anything then you get that entered thing in your terminal\n");
	}
	else{
		while(token!=NULL){
			printf("%s ",token);
			token=strtok(NULL," ");
		}
		printf("\n");
	}

}
void execute_exitt(char* token){
	if(token==NULL){
		exit(0);
	}
	else if(strcmp(token,"--help")==0){
		printf("Type 'exit' for exiting from shell\n");
	}
	
	else{
		printf("Command not supported \n");
	}
}
void execute_Int_C(char* token){
	if(strcmp(token,"echo")==0){
		token=strtok(NULL," ");
		execute_echo(token);
	}
	else if(strcmp(token,"pwd")==0){
		token=strtok(NULL," ");
		execute_pwd(token);
	}
	else if(strcmp(token,"exit")==0){
		token=strtok(NULL," ");
		execute_exitt(token);
	}
	else if(strcmp(token,"cd")==0){
		token=strtok(NULL," ");
		execute_cd(token);

	}

}
void execute_Ext_C(char arr[], char *token){

	if(strcmp(token,"cat")==0){
		token=strtok(NULL," ");
		execl("/home/OS_Assignments/cat",token,arr,NULL);
	}
	else if(strcmp(token,"ls")==0){
		token=strtok(NULL," ");
		execl("/home/OS_Assignments/ls",token,arr,NULL);
	}
	else if(strcmp(token,"mkdir")==0){
		token=strtok(NULL," ");
		execl("/home/OS_Assignments/mkdir",token,arr,NULL);
		
	}
	else if(strcmp(token,"date")==0){
		token=strtok(NULL," ");
		
		execl("/home/OS_Assignments/date",token,NULL);
	}
	else if(strcmp(token,"rm")==0){
		token=strtok(NULL," ");
		execl("/home/OS_Assignments/rm",token,arr,NULL);
		
	}

}


int main(int arg,char const *argc[]){

	execute_Getcwd();
	strcpy(PWD,cwd);
	
	while(1){
		execute_Getcwd();
		printf("%s ~$ ",cwd);
		char input[100];
		char dummy_str[105]="";

		scanf("%[^\n]%*c",input);

		strcat(dummy_str,input); 

		char* token;
		token=strtok(input," ");

		if(strcmp(token,"&t")==0)
		{
			token=strtok(NULL," ");
			if(strcmp(token,"ls")==0)
			{
				char path[1000]="";
				strcpy(path,"/home/OS_Assignments/");
				char* term=dummy_str+3;
				strcat(path,term);
				pthread_t p;
				int b=pthread_create(&p,NULL,st,(void*)path);
				pthread_join(p,NULL);
			}

		   else if(strcmp(token,"cat")==0)
			{
				char path[1000]="";
				strcpy(path,"/home/OS_Assignments/");
				char* term=dummy_str+3;
				strcat(path,term);
				pthread_t p;
				// int b=pthread_create(&p,NULL,(void*)(*system),(void*)path);
				int b=pthread_create(&p,NULL,st,(void*)path);
				pthread_join(p,NULL);
			}
			else if(strcmp(token,"mkdir")==0)
			{
				char path[1000]="";
				strcpy(path,"/home/OS_Assignments/");
				char* term=dummy_str+3;
				strcat(path,term);
				pthread_t p;
				// int b=pthread_create(&p,NULL,(void*)(*system),(void*)path);
				int b=pthread_create(&p,NULL,st,(void*)path);
				pthread_join(p,NULL);
			}
			else if(strcmp(token,"rm")==0)
			{
				char path[1000]="";
				strcat(path,"/home/OS_Assignments/rm");
				strcat(path," ");
				char* term=input+3;
				strcat(path,term);
				pthread_t p;
				int b=pthread_create(&p,NULL,(void*)(*system),(void*)path);
				pthread_join(p,NULL);
			}
			
		}

		if(checkforExt_C(token)==1){
			pid_t pid;
			pid=fork();

			if(pid==0){
				//child process
				execute_Ext_C(dummy_str,token);
				exit(0);
			}
			else if(pid>0){
				//parent process
				waitpid(0,NULL,0);
				//waiting for child process to end
			}
			else{
				printf("Error in forking\n");
			}

		}
		
		else if(checkforInt_C(token)==1){
			execute_Int_C(token);
		}


		else{
			if(strcmp(token,"help")==0){
				FILE* stream=fopen("/home/OS_Assignments/help.txt","r");
				char read[1000];
				while(fgets(read,sizeof(read),stream)!=NULL){
					fputs(read,stdout);
				}
				fclose(stream);
			}
			else{
				printf("Command not found\n");
				printf("Enter help for supported commands\n");
			}
		}

	}

	return(0);
}