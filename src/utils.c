#include "utils.h"
#include <stdlib.h>
#include <string.h>


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{

	*argv =(char**)malloc(sizeof(char*)*10);
		
	char cpy[100] ={0};
	strcpy(cpy,command);	

	char* tok;
	tok = strtok(cpy," \n\t");
	
	int count =0;
	
	while( tok!=NULL){
        (*argv)[count] = (char*)malloc(sizeof(char)*10);

        strcpy((*argv)[count], tok);
	tok = strtok(NULL," \n\t");       
	count++;
	 }
	
	*argc  = count;

	if((*argc)==0)
	{
	(*argv)[0] = (char*)malloc(sizeof(char)*10);
	strcpy((*argv)[0],"");
	(*argc)=1;
	}
}
