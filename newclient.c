#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "serv_cli.h"

int main()
{
  // Declaration
  char *ip = "127.0.0.0";
  int port = 5566;
  struct question qes;
  struct reponse rep;
  int sock;
  struct sockaddr_in addr;
  socklen_t addr_size;
  int n;

  // creation de socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
  {
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");
  // initialisation de port et addresse
  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = port;
  addr.sin_addr.s_addr = inet_addr(ip);
  // connexion sur le serveur
  connect(sock, (struct sockaddr *)&addr, sizeof(addr));
  printf("Connected to the server.\n");
  // choisir un nombre aléatoire
  n = rand() % NMAX;
  qes.question = n;
  printf("Client send the random number: % d \n ", qes.question);
  // envoi la question
  send(sock, &qes, sizeof(qes), 0);
  // recevoir la réponse
  recv(sock, &rep, sizeof(rep), 0);
  printf("  reponse of server is: \n ");

  for (int i = 0; i < qes.question; i++)
  {
    printf(" + % d \n ", rep.reponse[i]);
  }
  // fermeture de socket
  close(sock);
  printf("Disconnected from the server.\n");

  return 0;
}
