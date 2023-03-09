#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/select.h>
#include <pthread.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
#define SIZE 1024

int main() {
  int sockfd, ret, flags, valread;
  struct sockaddr_in server_addr;
  char buffer[SIZE];

  // create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // set server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  server_addr.sin_port = htons(SERVER_PORT);

  // connect to server
  ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (ret < 0 && errno != EINPROGRESS) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // send the first message
  strcpy(buffer, "3:fizz");
  write(sockfd, buffer, strlen(buffer));

  ret = read(sockfd, buffer, SIZE);

  // send the second message
  strcpy(buffer, "5:buzz");
  write(sockfd, buffer, strlen(buffer));

  ret = read(sockfd, buffer, SIZE);

  int values[] = {3, 5, 12, 7, 15, 13, 1, 10};
  char responses[8][SIZE] = {"fizz", "buzz", "fizz", "7", "fizzbuzz", "13", "1", "buzz"};

  for (int i = 0; i < 8; i++) {
    // send each message
    sprintf(buffer, "%d", values[i]);
    printf("Sending: %s\n", buffer);
    write(sockfd, buffer, strlen(buffer));

    //check if the response is correct
    valread = read(sockfd, buffer, SIZE);
    // terminate the string, read/write doesn't do this
    buffer[valread] = '\0';
    printf("Received: %s\n", buffer);
    if (strcmp(buffer, responses[i]) == 0) {
      printf("Correct response: %s\n", buffer);
    } else {
      printf("Incorrect response: %s\n", buffer);
      printf("Expected: %s\n", responses[i]);
    }
  }

  // send the last message
  strcpy(buffer, "-1");
  write(sockfd, buffer, strlen(buffer));

  // close the socket
  close(sockfd);

  return 0;
}
