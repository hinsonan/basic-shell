#include <stdio.h>
#include <unistd.h>


#define MAX_LINE 80 /* The maximum length command */




int main(void){
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    int shouldRun = 1; /* flag to determine when to exit program */

    
    char *argArray[3];
    //static input
    char *cmd = "ls";
    argArray[0] = "ls";
    argArray[1] = "-la";
    argArray[2] = NULL;

    while (shouldRun) {
        printf("osh>");
        fflush(stdout);





        /**
         * After reading user input, the steps are:
         * (1) fork a child process using fork()
         * (2) the child process will invoke execvp()
         * (3) if command included &, parent will invoke wait()
         */
         execvp( argArray[0],  argArray);
        break;
        }

    return 0;
}
