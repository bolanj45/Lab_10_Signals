/**
 * File: send_signal.c
 * Brief: sending signal and random value SIGUSR1 to rec_signal.c
 * Author: Julian Bolan
 * Date: 11/15/2026
 * Compile: gcc send_signal.c -o send_signal
 */

// void handle_sigusr2(int sig, siginfo_t* siginfo, void* context) {
//     int y = 1; // changed y value to succesfully end send signal
// }
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {

    srand(time(NULL)); // seed

    int randNum = rand();
    printf("randNum %d\n", randNum);

    union sigval value;
    value.sival_int = randNum;

    // struct sigaction sa;
    // sa.sa_flags = SA_SIGINFO;
    // sa.sa_sigaction = handle_sigusr2;
    // sigemptyset(&sa.sa_mask);
    // sigaction(SIGUSR1, &sa, NULL);
    // printf("argv[1] i.e. recv signal process id: %d\n", atoi(argv[1]));
    sigqueue(atoi(argv[1]), SIGUSR1, value); // argv[1] is the pid I typed in CMD line found with pgrep -a recv_signal.c

    // while (y == 0) {
    //     sleep(1);
    // }

    return 0;

}