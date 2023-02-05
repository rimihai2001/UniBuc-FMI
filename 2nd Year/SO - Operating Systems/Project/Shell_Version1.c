#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


char h[100000]="";

int main()
{
    printf("\033[0;34m");
    printf("Welcome to the shell\n");
    printf("We are waiting for your commands...\n\n");
    printf("\033[0m"); 
    while(1)
    {
        printf("\033[0;32m");
        printf("user> ");
        printf("\033[0m"); 
        int childpid=-1;
        
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
                    childpid=fork();
                    if(childpid==0)
                    {
                        char* argv[] = {"pwd", NULL};
                        execv("/bin/pwd", argv);
                    }
                    wait(NULL);
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
                
                childpid=fork();
                if(childpid==0)
                {
                    char* argv[] = {"mkdir", command_mkdir, NULL};
                    execv("/bin/mkdir", argv);
                }
                wait(NULL);
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
                
                childpid=fork();
                if(childpid==0)
                {
                    char* argv[] = {"rmdir", command_rmdir, NULL};
                    execv("/bin/rmdir", argv);
                }
                wait(NULL);
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
                
                chdir(command_cd);
                
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
                    
                    printf("%s ", command_echo);
                    printf("\n");
                }
        else if(strcmp(command, "history") == 0)
                {
                    printf("\nHistory:\n%s\n\n", h);
                }
        else if(strcmp(command, "clear_history") == 0)
                {
                    memset(h,0,sizeof(h));
                    printf("\nHistory cleared\n\n");
                }
        else
        {
             printf("Invalid command. Try again!\n\n");
        }
    }
    return 0;
}
