/**
 * @file signal_segfault.c
 * @brief program that assigns a the SIGALRM signal to a signal handler and sends an alarm signal after 5 seconds
 *  prompting the handler which prints a message "signal was recieved"
 * Date: 11/16/2026
 * Author: Julian Bolan
 * Compile: gcc signal_alarm.c -o signal_alarm
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