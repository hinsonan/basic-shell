#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


#define MAX_LINE 80 /* The maximum length command */




int main(void){
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    int shouldRun = 1; /* flag to determine when to exit program */


    char *argArray[3];
    //static input

    argArray[0] = "ls";
    argArray[1] = "-la";
    argArray[2] = NULL;

    while (shouldRun) {
        printf("osh>");
        fflush(stdout);

        pid_t pid;

        pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if(pid == 0) {
            execvp(argArray[0],  argArray);
        }

        else {
          int i;
            for (i = 0; i<2; i++)
            {
                if(strcmp(argArray[i],"&"))
                {wait(NULL);
                    }
            }
            printf("Child Complete\n");
        }


        /**
         * After reading user input, the steps are:
         * (1) fork a child process using fork()
         * (2) the child process will invoke execvp()
         * (3) if command included &, parent will invoke wait()
         */
        break;
    }

    return 0;
}
