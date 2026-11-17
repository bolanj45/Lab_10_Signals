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
 * added another handler but for SIGSEGV and had the handler exit the program with an error 
 * status of one so that the program would not keep calling the handler and printing the error message
 * as the program resumes where it left off at error and keeps trying to dereference the NULL pointer
 * 
 */


#include <stdio.h>
#include <unistd.h> 
#include <signal.h>
#include <stdlib.h>

void signal_handler (int sig) {
    printf("signal was received\n");
}

void signal_handler_SIGSEGV(int sig) {
    printf("Segmentation fault (SIGSEGV) signal was received from Linux kernel\n");
    exit(1);
}

int main (int argc, char* argv[]) {
    // signal(SIGALRM, signal_handler); // 
    // alarm(5); // sends ALRM signal after five seconds
    // pause(); // waits until SIGALRM signal from alarm() after 5 seconds


    // runs after the handler is done
    signal(SIGSEGV, signal_handler_SIGSEGV);

    // Declare a null pointer
    int* i = NULL;
    
    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    
    // Return to exit the program
    return 0;
}