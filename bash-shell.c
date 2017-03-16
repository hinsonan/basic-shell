#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

//declares a function that will parse the user input
void parseArray (char cmdArray[], char *argArray[]);

#define MAX_LINE 80 /* The maximum length command */

int main(void){
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    int shouldRun = 1; /* flag to determine when to exit program */


    while (shouldRun) {
        fflush(stdout);
        printf("osh>");
        fflush(stdout);

        //makes an array that holds the command
        char cmdArray[50];
        //makes an array that will hold the parsed values of the usr input
        char *argArray[3];

        //calls the parse array function
        parseArray(cmdArray, argArray);

        //initializes the pid
        pid_t pid;

        pid = fork();

        //these blocks will execute based on the pid values

        if (pid < 0) {
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if(pid == 0) {
          //this line will execute the command the user inputed
            execvp(argArray[0],  argArray);
        }

        else {
            for (int i = 0; i<2; i++)
            {
              //if there is a parent to wait on call the wait method
                if( (strcmp(argArray[i],"&")) == '0')
                {wait(NULL);
                    }
            }
            printf("Child Complete\n");
        }

        shouldRun = 0;
    }

    return 0;
}

void parseArray (char cmdArray[], char *argArray[]){

    //get the user input
    fgets(cmdArray, 50, stdin);
    //this char pointer will be used to help parse the command
    char *command;
    //these are the delimeters that will tell the strtok method when to parse the string
    char spaces[]=" \t\r\n\v\f";
    //parses the string when it gets to a delimiter
    command = strtok(cmdArray, spaces);
    int i = 0;

    //this loop continues to parse the string until it reaches the end or gets to null
    while( command != NULL )
    {
        argArray[i] = command;
        i++;
        command = strtok(NULL, spaces);
    }

}
