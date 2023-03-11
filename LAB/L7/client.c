// Jacob Knox CST240 Lab7 3/15/2023

/* UDP client in the internet domain */

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// error function
void error(char *msg) {
  // perror prints the error message to stderr
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[]) {
  // declare variables
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[256];
 
  // check if port number and hostname/ip is provided
  if (argc < 3) {
    fprintf(stderr, "usage %s hostname port\n", argv[0]);
    exit(0);
  }

  // get port number
  portno = atoi(argv[2]);

  // create socket for all ip addresses (AF_INET) using TCP (SOCK_STREAM)
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // check if socket is created
  if (sockfd < 0) {
    error("ERROR opening socket");
  }
  
  // get server ip address
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }

  // clear address structure
  bzero((char *)&serv_addr, sizeof(serv_addr));
  // setup the host_addr structure for use in bind call
  serv_addr.sin_family = AF_INET;

  bcopy((char *)server->h_name, (char *)&serv_addr.sin_addr.s_addr, sizeof(server->h_length));

  // assign port number and ip address
  serv_addr.sin_port = htons(portno);
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

  printf("Connecting to server...\n");

  // connect to server, with a timeout
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    error("ERROR connecting");
  }

  // get message from user
  printf("Please enter the message: ");
  bzero(buffer, 256);
  fgets(buffer, 255, stdin);
  // send message to server
  n = write(sockfd, buffer, strlen(buffer));
  
  // check if message is sent
  if (n < 0) {
    error("ERROR writing to socket");
  }

  // clear buffer
  bzero(buffer, 256);
  // check for response from server
  n = read(sockfd, buffer, 255);
  // check if response is received
  if (n < 0) {
    error("ERROR reading from socket");
  }

  // print response from server
  printf("%s\n", buffer);
  return 0;
}
