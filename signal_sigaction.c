/**
 * File: signal_sigaction.c
 * Brief: learning how to use sigaction
 * Author: Julian Bolan
 * Date: 11/15/2026
 * Compile: gcc signal_sigaction.c -o sigaction
 */


#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

volatile sig_atomic_t recieved_sigint = 0; // volatile makes sure recieved_sigint is read from memory on every loop interation and not optimized 
// so that the variable is not read from memory at each loop iteration and therfore reads the signal in from the other terminal

// sig_atomic_tensures that when there is a signal interupt, the shared memory between the handler and main which is recieved_sigint is not corrupted.
// signinfo->si_value.sival_int can only be info sent to a handlder, that's why a volatile sig_atomic_t variable is used
void handler(int sig, siginfo_t* info, void *ctx) { // void* ctx (context) holds the saved CPU state of the the code that was interupted
    recieved_sigint = 1;
    char str[128];
    int slen = snprintf(str, sizeof(str), "Sender PID: %d\n", (int) info->si_pid); // storing sender pid in char array to write
    write(STDOUT_FILENO, str, slen); // si_pid provides the sender's process ID
                                               // writing instead of printing since it's more robust for
}                                               // for programs with signals interupts

int main(void) {
    // union sigval recieved_sigint = 0;
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));  // passing pointer of sigaction struct, set mem to 0, size in bytes to set memory values
    sa.sa_sigaction = handler; // setting handler i.e. passing tha handler function to the sa struct
    sigemptyset(&sa.sa_mask); //  clear the signal set so no extra signals are ignored while the handler runs
    // sa.sa_flags = 0; // not setting flags / no special behavior
    sa.sa_flags = SA_SIGINFO; // setting the flag to have the handler be called with the three arg version which includes siginfo_t* info
    sigaction(SIGUSR1, &sa, NULL); // signal number, new disposition (NULL otherwise), where to save old dispoition if you want (NULL otherwise)

    printf("Recieving PID is %d\n", getpid());  // printing the PID of recieving process
    
    // kill(getpid(), SIGUSR1); // alternative method to send SIGUSR1 signal to processs
    while(!recieved_sigint) { // the while loop runs until the signal is recieved
        pause(); // suspends the process until a signal is delivered
    }
}