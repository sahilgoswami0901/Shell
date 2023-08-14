#include<stdio.h>
#include<string.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include<dirent.h>

char cwd[1000];
int main(int argc,char* argv[]){
    // for(int i=0;argv[i]!=NULL;i++)
	// {
	// 	printf("%s\n",argv[i]);
	// }
	char* token=argv[0];
	getcwd(cwd,sizeof(cwd));
	// printf("%s\n",token );
	char string[100];
	strcpy(string,argv[1]);

	if(cwd==NULL){
		printf("getcwd() error\n");
	}

	if(token==NULL){
		printf("Argument missing, Try 'mkdir --help' for more information. \n");
	}
	else
    {
		if(strcmp(token,"--help")==0){
			printf("Help prompt for mkdir \n");
		}
        else if(strcmp(token,"-p")==0)
        {
            // printf("YES\n");
            char* iterator=strtok(string," ");
			if(strcmp(iterator,"mkdir")==0){
				iterator=strtok(NULL," ");
                // printf("%s\n",iterator );
				if(strcmp(iterator,"-p")==0){
					iterator=strtok(NULL," ");
                    // printf("%s\n",iterator );
				}
			}
            // iterator=strtok(NULL,"/");
            // printf("%s\n",iterator );
            // printf("%s\n",iterator);
            getcwd(cwd,sizeof(cwd));
			
			while(iterator!=NULL)
			{
				char dummy[1000];
                iterator=strtok(iterator,"/");
                // printf("%s\n",iterator);
                // iterator=strtok(NULL," ");
                // printf("%s\n",iterator);
				getcwd(dummy,sizeof(dummy));
				strcat(dummy,"/");
				strcat(dummy,iterator);

				// printf("%s\n",dummy );
				int s=mkdir(dummy,0777);
				if(s==-1)
                {
					printf("cannot create '%s' directory, it already exist\n",iterator);
					iterator=strtok(NULL,"/");
                    // printf("%s\n",iterator);
                    while(iterator!=NULL)
                    {
                        strcat(dummy,"/");
                        strcat(dummy,iterator);

                        // printf("%s\n",dummy );
                        int s=mkdir(dummy,0777);
                        if(s==-1){
                            printf("cannot create '%s' directory, it already exist\n",iterator);
                            iterator=strtok(NULL," ");
                        }
                        else
                        {
                            printf("directory %s created\n",iterator);
                            iterator=strtok(NULL," ");
                        }
                    }
                }
				else
                {
					printf("directory %s created\n",iterator);
					iterator=strtok(NULL," ");
                    // printf("%s\n",iterator);

                    getcwd(cwd,sizeof(cwd));
                    while(iterator!=NULL)
					{
                        // char dummy[1000];
                        // getcwd(dummy,sizeof(dummy));
                        strcat(dummy,"/");
                        strcat(dummy,iterator);

                        // printf("%s\n",dummy );
                        int s=mkdir(dummy,0777);
                        if(s==-1){
                            printf("cannot create '%s' directory, it already exist\n",iterator);
                            iterator=strtok(NULL," ");
                        }
                        else{
                            printf("directory %s created\n",iterator);
                            iterator=strtok(NULL," ");
                        }
                    }

				}
			}
        }
		else if(strcmp(token,"-v")==0)
        {

			char* iterator=strtok(string," ");
			if(strcmp(iterator,"mkdir")==0){
				iterator=strtok(NULL," ");
                // printf("%s\n",iterator );
				if(strcmp(iterator,"-v")==0){
					iterator=strtok(NULL," ");
                    // printf("%s\n",iterator);
				}
			}
			getcwd(cwd,sizeof(cwd));
			
			while(iterator!=NULL)
			{
				char dummy[1000];
				getcwd(dummy,sizeof(dummy));
				strcat(dummy,"/");
				strcat(dummy,iterator);

				// printf("%s\n",dummy );
				int s=mkdir(dummy,0777);
				if(s==-1){
					printf("cannot create '%s' directory, it already exist\n",iterator);
					iterator=strtok(NULL," ");
				}
				else{
					printf("directory %s created\n",iterator);
					iterator=strtok(NULL," ");
				}
			}
		}
		else{

			char* iterator=strtok(string," ");
			if(strcmp(iterator,"mkdir")==0){
				iterator=strtok(NULL," ");
			}
			getcwd(cwd,sizeof(cwd));
			
			while(iterator!=NULL)
			{
				char dummy[1000];

				getcwd(dummy,sizeof(dummy));
				strcat(dummy,"/");
				strcat(dummy,iterator);

				int s=mkdir(dummy,0777);
				if(s==-1){
					printf("cannot create directory, it already exist\n");
				}
				else{
					iterator=strtok(NULL," ");
				}
			}
			
		}

	}
	return 0;
}