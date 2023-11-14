#include "serv_cli_fifo.h"
#include "Handlers_cli.h"

int main()
{
    /* Déclarations */
    int fdq, fdr; // descripteurs
    struct question question;
    struct reponse reponse;

    /* Installation des Handlers */
    signal(SIGUSR1, hand);
    srand(getpid());
    /* Ouverture des tubes nommés*/
    fdq = open(QUESTION, O_WRONLY);
    /* Construction et envoi d’une question */
    question.pid_cli = getpid();
    question.question = 1 + rand() % NMAX;
    write(fdq, &question, sizeof(question));
    close(fdq);
    fdr = open(REPONSE, O_RDONLY);
    read(fdr, &reponse, sizeof(reponse));
    /* Envoi du signal SIGUSR1 au serveur */
    kill(reponse.pid_serv, SIGUSR1);
    /* Traitement local de la réponse */
    printf(" message d'entrée au serveur :%d\n", question.question);
    for (int i = 0; i < question.question; i++)
        printf("...recus du seveur :%d \n", reponse.reponse[i]);
    printf("\n");
    return 0;
}
