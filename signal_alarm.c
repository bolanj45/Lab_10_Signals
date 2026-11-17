/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 * date: 11/15/0226
 * compile: gcc signal_segfault.c -o signal_segfault
 */

/**
 * Modified by: Julian Bolan
 * 
 * Brief summary of modifications: add int sig so program would compile
 */


#include <stdio.h>
#include <unistd.h> 
#include <signal.h>
#include <stdlib.h>

void signal_handler (int sig) {
    printf("signal was received\n");
}


int main (int argc, char* argv[]) {
    signal(SIGALRM, signal_handler); // 
    alarm(5); // sends ALRM signal after five seconds
    pause(); // waits until SIGALRM signal from alarm() after 5 seconds

    // Return to exit the program
    return 0;
}