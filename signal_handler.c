/**********************************************
*  Filename: signal_handler.c
*  Description: how to use signal()
*  Author: Julian Bolan
*  Date: 11/14/2026
*  Compile: gcc signal_handler.c -o signal_handler
***********************************************/  
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal(int sig) {
    printf("\nReceived a signal\n");
    // exit(1); // remove the exit here and can add kill(pid, SIGKILL);
    //kill(getpid(), SIGKILL);
    
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }
    
    return 0;
}