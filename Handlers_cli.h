#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void hand_reveil(int sig)
{
    printf("Terminé!");
    return;
}