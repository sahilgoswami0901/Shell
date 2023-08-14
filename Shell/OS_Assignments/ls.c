#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>
#include<errno.h>


void main(int argc, char *argv[]){
	char* token=argv[0];
	if(token==NULL){
		struct dirent **directory;
		int entities=scandir(".",&directory,0,alphasort);
		int i=0;
		while(i<entities){
			if(directory[i]->d_name[0]!='.'){
				printf("%s ",directory[i]->d_name);
				free(directory[i]);
			}
			i+=1;
		}
		free(directory);
		printf("\n");
	}
	else if(strcmp(token,"-R")){		//recursively print all files present in directory
		struct dirent *directory;
		DIR *entity=opendir(".");
		if(entity==NULL){
			printf("Error as type of directory is null\n");
		}
		else{
			while(directory!=NULL){
				printf("%s ",directory->d_name);
				directory=readdir(entity);
			}
		}
		printf("\n");
		free(directory);
		free(entity);
	}
	else if(strcmp(token,"-l")){		//print all files separated by new line
	   DIR* dir=opendir(".");
		if(dir== NULL)
		{
		    perror("directory is empty");
		}	
		struct dirent* entity;
		entity=readdir(dir);
		while(entity!=NULL)
		{
			printf("%s\n",entity->d_name);
			entity=readdir(dir);
		}
		closedir(dir);
	
		
	}
	else{
		printf("Command not supported\n");
	}
}