#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the doubly linked list
struct Node {
  int data;           // Data stored in the node
  struct Node* prev;  // Pointer to the previous node in the list
  struct Node* next;  // Pointer to the next node in the list
};

struct LinkedList {
  struct Node* head;
  struct Node* tail;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
  // Allocate memory for the new node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  // Set the data of the new node to the given value
  newNode->data = data;
  // Set the previous and next pointers of the new node to NULL
  newNode->prev = NULL;
  newNode->next = NULL;
  // Return the new node
  return newNode;
}

// Function to insert a new node at the beginning of the list
void insertHead(struct LinkedList* list, int data) {
  // Create a new node with the given data
  struct Node* newNode = createNode(data);
  // Set the next pointer of the new node to the current head of the list
  newNode->next = list->head;
  // Set the previous pointer of the current head to the new node
  if (list->head != NULL) {
    list->head->prev = newNode;
  } else {
    // If the head is NULL, set the tail to the new node
    list->tail = newNode;
  }
  // Set the head of the list to the new node
  list->head = newNode;
}

// Function to insert a new node at the end of the list
void insertTail(struct LinkedList* list, int data) {
  // Create a new node with the given data
  struct Node* newNode = createNode(data);
  // Set the previous pointer of the new node to the current tail of the list
  newNode->prev = list->tail;
  // Set the next pointer of the current tail to the new node
  if (list->tail != NULL) {
    list->tail->next = newNode;
  } else {
    // If the tail is NULL, set the head to the new node
    list->head = newNode;
  }
  // Set the tail of the list to the new node
  list->tail = newNode;
}

// Function to delete a node with the given data from the list
void deleteData(struct LinkedList* list, int data) {
  // If the list is empty, return
  if (list->head == NULL) {
    return;
  }
  // If the head of the list contains the data, delete the head
  if (list->head->data == data) {
    // save for deletion later
    struct Node * temp = list->head;
    // Set the head of the list to the next node
    list->head = list->head->next;
    // If the head is not NULL, set the previous pointer to NULL
    if (list->head != NULL) {
      list->head->prev = NULL;
    } else {
      // If the head is NULL, set the tail to NULL
      list->tail = NULL;
    }
    // Free the memory of the old head
    free(temp);
    return;
  }

  // If the tail of the list contains the data, delete the tail
  if (list->tail->data == data) {
    struct Node * temp = list->tail;
    // Set the tail of the list to the previous node
    list->tail = list->tail->prev;
    // If the tail is not NULL, set the next pointer to NULL
    if (list->tail != NULL) {
      list->tail->next = NULL;
    } else {
      // If the tail is NULL, set the head to NULL
      list->head = NULL;
    }
    // Free the memory of the old tail
    free(temp);
    return;
  }

  // Otherwise, traverse the list to find the node with the given data
  struct Node* current = list->head;
  while (current != NULL) {
    // If the current node contains the data, delete it
    if (current->data == data) {
      // Set the previous node's next pointer to the current node's next pointer
      current->prev->next = current->next;
      // Set the next node's previous pointer to the current node's previous pointer
      current->next->prev = current->prev;
      // Free the memory of the current node
      free(current);
      return;
    }
    // Otherwise, move to the next node
    current = current->next;
  }
}

void purge (struct LinkedList* list) {
  struct Node* current = list->head;
  while (current != NULL) {
    struct Node* temp = current;
    current = current->next;
    free(temp);
  }
  list->head = NULL;
  list->tail = NULL;
}

// Function to search for a node with the given data in the list
int find (struct LinkedList* list, int data) {
  struct Node* current = list->head;
  // Traverse the list to find the node with the given data
  while (current != NULL) {
    // If the current node contains the data, return 1
    if (current->data == data) {
      return 1;
    }
    // Otherwise, move to the next node
    current = current->next;
  }
  return 0;
}

// Function to print the contents of the list
int is_empty(struct LinkedList* list) {
  // If the head of the list is NULL, return 1
  return list->head == NULL;
}
