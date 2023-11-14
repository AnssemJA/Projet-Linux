#define __S_C__FIFO
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <signal.h>
#define NMAX 30
#define QUESTION "fifo1"
#define REPONSE "fifo2"
struct reponse
{
    int pid_serv;
    int reponse[NMAX];
};
struct question
{
    int pid_cli, question;
};
void hand(int sig)
{
    if (sig == SIGUSR1)
    {
        printf(" vous avez recus un signal SIGUSR1 \n");
    }
}