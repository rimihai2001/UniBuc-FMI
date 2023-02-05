#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int mkdir(const char *pathname, mode_t mode);


char h[100000]="";

int main()
{
    printf("\033[0;34m");
    printf("Welcome to the shell\n");
    printf("We are waiting for your commands...\n\n");
    printf("\033[0m"); 
    int bool_last = 1;
    int bool_or = 0;
    int bool_and = 0;
    while(1)
    {  
        int childpid=-1;
        char curr_path[100]="";
        getcwd(curr_path, sizeof(curr_path));


        printf("\033[0;32m");
        printf("%s>", curr_path);
        printf("\033[0m"); 
        

        
        
        char command[50];
        scanf("%s",command);
        size_t length = strlen(h);
        size_t length2 = strlen(command);
        h[length] = '\n';
        h[length+1] = '\0';
        strcat(h,command);
        h[length+length2+2] = '\0';
        
        
        if(strcmp(command,"quit")==0 || strcmp(command,"q")==0)
        {
            printf("Goodbye! Have a nice day!\n");
            exit(0);
        }
        else if(strcmp(command,"ls")==0)
        {
            childpid=fork();
            if(childpid==0)
            {
                char* argv[] = {"ls", NULL};
                execv("/bin/ls", argv); 
            }
            wait(NULL);
        }
        else if(strcmp(command, "pwd") == 0)
                {
                  printf("%s\n", curr_path);
                }
        else if(strcmp(command, "mkdir") == 0)
            {
                char command_mkdir[100]="";
                scanf("%s",command_mkdir);
                size_t length3 = strlen(command_mkdir);
                
                length = strlen(h);
                h[length] = ' ';
                h[length+1] = '\0';
                
                strcat(h,command_mkdir);
                h[length+length3+2] = '\0';
                
                strcat(curr_path, "/");
                strcat(curr_path, command_mkdir);
                if(bool_or == 0 && bool_last == 1)
                {
                  if(mkdir(curr_path, 0777)==-1)
                {
                  printf("Directory could not be created! Try again!\n");
                }
                else{
                  printf("Directory successfully created!\n");
                };
                wait(NULL);
                }
                else {
                  bool_or=0;
                }
            }
        else if(strcmp(command, "rmdir") == 0)
            {
                char command_rmdir[100]="";
                scanf("%s",command_rmdir);
                
                size_t length4 = strlen(command_rmdir);
                length = strlen(h);
                h[length] = ' ';
                h[length+1] = '\0';
                
                strcat(h,command_rmdir);
                h[length+length4+2] = '\0';
                
                strcat(curr_path, "/");
                strcat(curr_path, command_rmdir);
                if(bool_or == 0 && bool_last == 1)
                    {
                      if(rmdir(curr_path)==-1)
                    {
                    printf("Directory not found! Try again!\n");
                    }
                else{
                    printf("Directory successfully removed\n");
                };
                    wait(NULL);
                    }
                    else 
                    {
                      bool_or = 0;
                    } 
                
            }
        else if(strcmp(command, "cd") == 0)
                {
                    char command_cd[100]="";
                scanf("%s",command_cd);
                
                size_t length5 = strlen(command_cd);
                length = strlen(h);
                h[length] = ' ';
                h[length+1] = '\0';
                
                strcat(h,command_cd);
                h[length+length5+2] = '\0';

                if(bool_or == 0 && bool_last == 1)
                 {
                  if(chdir(command_cd)==-1)
                  {
                    printf("Directory not found! Try again!\n");
                  };
                  wait(NULL);
                 }
                else 
                {
                  bool_or = 0;
                }
                
                
                wait(NULL);
                }
        else if(strcmp(command, "echo") == 0)
                {
                    char command_echo[100]="";
                    scanf("%s",command_echo);
                    size_t length5 = strlen(command_echo);
                
                    length = strlen(h);
                    h[length] = ' ';
                    h[length+1] = '\0';
                    strcat(h,command_echo);
                    h[length+length5+2] = '\0';

                    if(bool_or == 0 && bool_last == 1)
                    {
                      printf("%s ", command_echo);
                      printf("\n");
                    }
                    else 
                    {
                      bool_or = 0;
                    } 
                }
        else if(strcmp(command, "history") == 0)
                {
                  if(bool_or == 0 && bool_last == 1)
                    {
                      printf("\nHistory:\n%s\n\n", h);
                    }
                    else 
                    {
                      bool_or = 0;
                    } 
                    
                }
        else if(strcmp(command, "clear_history") == 0)
                {
                  if(bool_or == 0 && bool_last == 1)
                    {
                      memset(h,0,sizeof(h));
                      printf("\nHistory cleared\n\n");
                    }
                    else 
                    {
                      bool_or = 0;
                    } 
                    
                }
        else if(strcmp(command, "cls") == 0)
                {
                  if(bool_or == 0 && bool_last == 1)
                    {
                      system("clear");
                      printf("\033[0;34m");
                      printf("Welcome to the shell\n");
                      printf("We are waiting for your commands...\n\n");
                      printf("\033[0m"); 
                    }
                    else 
                    {
                      bool_or = 0;
                    } 
                    
                }
        else if(strcmp(command, "touch") == 0)
                {
                  char command_tch[100]="";
                  scanf("%s",command_tch);
                  size_t length5 = strlen(command_tch);
                
                  length = strlen(h);
                  h[length] = ' ';
                  h[length+1] = '\0';
                  strcat(h,command_tch);
                  h[length+length5+2] = '\0';

                  if(bool_or == 0 && bool_last == 1)
                  {
                    FILE *fl;
                    fl = fopen(command_tch, "w");
                    if (fl)
                    {
                    printf("%s\n", "File created succesfully!");
                    }
                    else
                    {
                      printf("File could not be created. Try again!\n\n");
                    }
                  }
                  else 
                  {
                    bool_or = 0;
                  } 
                }
        else if(strcmp(command, "rm") == 0)
            {
                char command_rm[100]="";
                scanf("%s",command_rm);
                
                size_t length4 = strlen(command_rm);
                length = strlen(h);
                h[length] = ' ';
                h[length+1] = '\0';
                
                strcat(h,command_rm);
                h[length+length4+2] = '\0';
                
                strcat(curr_path, "/");
                strcat(curr_path, command_rm);
                if(remove(curr_path)==-1)
                {
                  printf("File not found! Try again!\n");
                }
                else{
                  printf("File removed successfully!\n");
                };
                wait(NULL);
            }
        else if(strcmp(command, "||") == 0)
                {
                    bool_or = 1;
                }
        else if(strcmp(command, "&&") == 0)
                {
                    bool_and = 1;
                }
        else
        {
             printf("Invalid command. Try again!\n\n");
        }
    }
    return 0;
}
