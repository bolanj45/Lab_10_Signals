/**
 * File: recv_signal.c
 * Brief: program recieving signal SIGUSR1 sent by send_signal.c
 * and pritning the random value sent
 * Author: Julian Bolan
 * Date: 11/15/2026
 * Compile: gcc recv_signal.c -o recv_signal
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int x = 0;

void handle_sigusr1(int sig, siginfo_t* siginfo, void *context) {
    x = siginfo->si_value.sival_int;
    printf("printing sival_int, %d\n", x);
}


int main(void) {


    // signal(SIGUSR2, handle_sigusr2);

    // union sigval value;
    // value.sival_int = 1;

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_sigusr1;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    // sigqueue(getpid(), SIGUSR1, value);

    while (x == 0) {
        sleep(1);
    }
    return 0;
}