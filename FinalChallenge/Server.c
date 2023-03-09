#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

#define SIZE 1024

#define PORT 8888

int main(int argc, char const *argv[]) {
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[SIZE];

  // Create socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // set socket options
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Bind the socket to the address
  // close(server_fd);
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Accept incoming connection
  printf("Waiting for connection...\n");
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  printf("Connection accepted\n");

  // setup variables
  int first, second;
  char first_str[SIZE];
  char second_str[SIZE];
  char delim = ':';

  // read first message
  valread = read(new_socket, buffer, SIZE);
  printf("First message: %s\n", buffer);

  // parse first message
  char *token = strtok(buffer, &delim);
  first = atoi(token);
  token = strtok(NULL, &delim);
  strcpy(first_str, token);

  write(new_socket, "First message received", strlen("First message received"));

  // read second message
  valread = read(new_socket, buffer, SIZE);
  printf("Second message: %s\n", buffer);

  // parse second message
  token = strtok(buffer, &delim);
  second = atoi(token);
  token = strtok(NULL, &delim);
  strcpy(second_str, token);

  write(new_socket, "Second message received", strlen("Second message received"));

  printf("First: %d, Second: %d\n", first, second);
  printf("First string: %s, Second string: %s\n", first_str, second_str);

  // play fizz buzz until -1 is received
  int value;
  char response[SIZE] = {};
  while (1) {
    // read value
    valread = read(new_socket, buffer, SIZE);
    // terminate string, read will not terminate it
    buffer[valread] = '\0';
    value = atoi(buffer);
    printf("Received: %s\n", buffer);

    // check if value is -1
    if (value == -1) {
      break;
    }

    // reset response
    strcpy(response, "");

    // check if value is divisible by first and append first_str
    if (value % first == 0) {
      strcat(response, first_str);
    }

    // check if value is divisible by second and append second_str
    if (value % second == 0) {
      strcat(response, second_str);
    }

    // if the response is empty, send the value
    if (strcmp(response, "") == 0) {
      printf("Sending: %s\n", buffer);
      write(new_socket, buffer, strlen(buffer));
      continue;
    }

    // send response
    printf("Sending: %s\n", response);
    write(new_socket, response, strlen(response));
  }

  // close socket and cleanup
  printf("Closing socket\n");
  close(new_socket);

  return 0;
}
