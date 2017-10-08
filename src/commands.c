#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"
#define MAX_PATH 260

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
 
 if( chdir(argv[1])==0){
  return 0;
  }else
   return -1;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;
 
  char buffer[MAX_PATH] ={0};
  char* cwd = NULL;
  cwd = getcwd(buffer,MAX_PATH);
  printf("%s\n",cwd);
  return 0;
   
}

int validate_cd_argv(int argc, char** argv) {
 if(argc ==2 && strcmp(argv[0],"cd")==0){
 
 return 1;
 }else
  return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc ==1 && strcmp(argv[0],"pwd")==0){
  return 1;
 }else
 return 0;

}
