#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, const char* argv[]){
	const char* token=argv[0];
	// for(int i=0;argv[i]!=NULL;i++)
	// {
	// 	printf("%s\n",argv[i]);
	// }
	char string[105];
	strcpy(string,argv[1]);
	//printf("%s\n",stringng);
	if(token==NULL){
		printf("missing operand \n");
	}
	else if(strcmp(token,"-i")==0){		//asks the user for confirmation before removing each file

		char* iterator=strtok(string," ");
		if(strcmp(iterator,"rm")==0){
			iterator=strtok(NULL," ");
			if(strcmp(iterator,"-i")==0){
				iterator=strtok(NULL," ");
			}
		}

		while(iterator!=NULL){
			printf("remove file %s ? Enter 'y' for yes: ",iterator);
			char ch;
			scanf("%c",&ch);
			if(ch=='y'){
				remove(iterator);
			}
			else{
				return 0;
			}
			iterator=strtok(NULL," ");
		}

	}
	else if(strcmp(token,"-f")==0){		//removes the file forcefully, this option never give error if file is not present
		char* iterator=strtok(string," ");
		if(strcmp(iterator,"rm")==0){
			iterator=strtok(NULL," ");
			if(strcmp(iterator,"-f")==0){
				iterator=strtok(NULL," ");
			}
		}

		while(iterator!=NULL){
			remove(iterator);
			
			iterator=strtok(NULL," ");
		}

	}
	else{
		// for removing multiple files simultaneously
		
		char* iterator=strtok(string," ");
		if(strcmp(iterator,"rm")==0){
			iterator=strtok(NULL," ");
		}

		while(iterator!=NULL){
			int s=remove(iterator);
			if(s!=0){
				printf("File %s does not exist. \n",iterator);
			}
			iterator=strtok(NULL," ");
		}

	}
}