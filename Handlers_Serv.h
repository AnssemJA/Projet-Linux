#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void hand_reveil(int sig)
{
    return;
}
void fin_serveur(int sig)
{

    unlink(QUESTION);
    unlink(REPONSE);
    exit(2);
}
