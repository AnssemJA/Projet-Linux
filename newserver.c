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
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  int n;
  // creation de socket
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0)
  {
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");
  // initialisation de port et addresse
  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);
  // connexion sur le ports
  n = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (n < 0)
  {
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Bind to the port number: %d\n", port);

  // boucle while

  while (1)

  { // ecouter le client
    listen(server_sock, 5);
    printf("Listening...\n");
    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
    printf("[+]Client connected.\n");
    // recevoir la question
    recv(client_sock, &qes, sizeof(qes), 0);
    for (int i = 0; i < qes.question; i++)
    {
      n = rand() % 50;
      rep.reponse[i] = n;
    }
    // gerer des nombres aléatoires
    srand(getpid());
    // envoyer les nombres qu'il a gérrer
    send(client_sock, &rep, sizeof(rep), 0);
    // Fermeture de socket
    close(client_sock);
    printf("[+]Client disconnected.\n\n");
  }

  return 0;
}
