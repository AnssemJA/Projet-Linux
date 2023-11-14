#include "serv_cli_fifo.h"
#include "Handlers_Serv.h"

int main()
{
    /*Déclarations */
    int fdq, fdr; // descripteurs
    struct question question;
    struct reponse reponse;

    /* Création des tubes nommés */
    mkfifo(REPONSE, 0666);
    mkfifo(QUESTION, 0666);
    /*initialisation du générateur de nombres aléatoires*/
    srand(getpid());

    /* Installation des Handlers */
    for (int sig = 1; sig <= NSIG; sig++)
    {
        signal(sig, fin_serveur);
    }
    signal(SIGUSR1, hand);

    while (1)
    { /* Ouverture des tubes nommés */
        fdq = open(QUESTION, O_RDONLY);

        /* lecture d’une question */

        read(fdq, &question, sizeof(question));
        /* construction de la réponse */
        for (int i = 0; i < question.question; i++)
            reponse.reponse[i] = rand() % 50;
        close(fdq);

        /* envoi de la réponse */
        fdr = open(REPONSE, O_WRONLY);
        write(fdr, &reponse, sizeof(reponse));
        /* envoi du signal SIGUSR1 au client concerné */

        kill(question.pid_cli, SIGUSR1);
        printf(" Client appellé \n");
        close(fdr);
    }

    return 0;
}