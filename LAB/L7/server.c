// Jacob Knox CST240 Lab7 3/15/2023

/* Creates a datagram server. The port number is passed as an argument. This server runs forever */

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// error function
void error(char *msg) {
  // perror prints the error message to stderr
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  // declare variables
  int sockfd, newsockfd, portno, clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  // check if port number is provided
  if (argc < 2) {
    fprintf(stderr, "ERROR, no port provided\n");
    exit(1);
  }

  // create socket for all ip addresses (AF_INET) using TCP (SOCK_STREAM)
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // check if socket is created
  if (sockfd < 0) {
    error("ERROR opening socket");
  }

  // clear address structure
  bzero((char *)&serv_addr, sizeof(serv_addr));

  // get port number
  portno = atoi(argv[1]);

  // setup the host_addr structure for use in bind call
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  // bind socket to port
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    error("ERROR on binding");
  }

  // listen for connections
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);

  // wait for connection and accept
  newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);

  // check if connection is accepted
  if (newsockfd < 0) {
    error("ERROR on accept");
  }

  // clear buffer
  bzero(buffer, 256);

  // read message from client
  n = read(newsockfd, buffer, 255);

  // check if message is read
  if (n < 0) {
    error("ERROR reading from socket");
  }
  
  // print message
  printf("Here is the message: %s\n", buffer);

  // write back to client
  n = write(newsockfd, "I got your message", 18);
  
  // check if message is written
  if (n < 0) {
    error("ERROR writing to socket");
  }
  return 0;
}
