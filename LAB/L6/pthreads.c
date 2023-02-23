// Jacob Knox CST 240 Lab 6 due 3/1/2023

#include <pthread.h>
#include <stdio.h>

#include "ll.h"

// if on linux use this
#include <unistd.h>

// if on windows use this
// #include <windows.h>

struct LinkedList *list;

int data = 0;
// 0 = check if data is in list
// 1 = delete
// 2 = purge and exit
int action = -2;

pthread_mutex_t list_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t data_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t action_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

void *thread1(void *arg);
void *thread2(void *arg);

void signal_action(int a, int d);
void wait_for_action();

int main() {
  // initialize the list
  list = malloc(sizeof(struct LinkedList));
  list->head = NULL;
  list->tail = NULL;

  // start the threads
  pthread_t t1, t2, t3;
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);
  // wait for the threads to finish
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  // make sure the list is empty to avoid memory leaks
  purge(list);
  return 0;
}

// represents an input data stream
void *thread1(void *arg) {
  int i;
  int check_3 = 0;
  int check_14 = 0;

  // load some data
  for (i = 0; i < 10; i++) {
    pthread_mutex_lock(&list_mutex);
    insertTail(list, i);
    printf("T1: inserted %d\n", i);
    pthread_mutex_unlock(&list_mutex);
  }
  // sleep to simulate waiting for a request
  //sleep(1);
  
  // wait for thread 2 to be ready
  wait_for_action();
  // signal to delete 3
  signal_action(1, 3);
  printf("T1: sent signal to delete 3\n");

  // sleep to simulate waiting for more data
  sleep(1);

  // add more data
  for (i = 10; i < 20000; i++) {
    pthread_mutex_lock(&list_mutex);
    insertTail(list, i);
    if (i % 10 == 0) {
      printf("T1: inserted up to %d\n", i);
    }
    pthread_mutex_unlock(&list_mutex);
    // send out requests to show that you can do multiple things at once
    if (i > 11 && check_3 == 0 && action == -1) {
      // signal to see if 3 is in the list
      signal_action(0, 3);
      printf("T1: sent signal to check if 3 is in the list\n");
      check_3 = 1;
    }
    if (i > 16 && check_14 == 0 && action == -1) {
      // signal to delete 14
      signal_action(1, 14);
      printf("T1: sent signal to delete 14\n");
      check_14 = 1;
    }

    // don't keep adding data if all the requests have been processed
    if (check_14 == 1  && check_3 == 1) {
      printf("T1: Final list length %d\n", i);
      break;
    }
  }
  
  // wait for thread 2 to be ready
  wait_for_action();
  // signal to purge the list and exit
  signal_action(2, 0);
  printf("T1: sent signal to purge the list and exit\n");

  // exit the thread
  return NULL;
}

void wait_for_action() {
  while (action != -1) {
   sleep(0.01);
  }
}

void signal_action(int a, int d) {
  pthread_mutex_lock(&action_mutex);
  pthread_mutex_lock(&data_mutex);
  action = a;
  data = d;
  pthread_mutex_unlock(&data_mutex);
  pthread_mutex_unlock(&action_mutex);
  pthread_cond_signal(&condition_cond);
}

// represents a user of the data
void *thread2(void *arg) {
  for (;;) {
   // signal that the request has been processed
   pthread_mutex_lock(&action_mutex);
   action = -1;
   pthread_mutex_unlock(&action_mutex);

   // wait for a data request
   pthread_mutex_lock(&condition_mutex);
   pthread_cond_wait(&condition_cond, &condition_mutex);
   pthread_mutex_unlock(&condition_mutex);
   printf("T2: got a request\n");
   // get the action and data
   pthread_mutex_lock(&action_mutex);
   pthread_mutex_lock(&data_mutex);
   int a = action;
   int d = data;
   pthread_mutex_unlock(&data_mutex);
   pthread_mutex_unlock(&action_mutex);

   // print the action and data
   printf("T2: action is %d\n", a);
   printf("T2: data is %d\n", d);

   // perform the action
   pthread_mutex_lock(&list_mutex);
   // sleep to simulate processing
   sleep(1);
   // exit if the action is to purge
   if (a == 2) {
      printf("T2: purging list\n");
      purge(list);
      pthread_mutex_unlock(&list_mutex);
      return NULL;
    }

    // check if the data is in the list
    int exists = find(list, d);
    // perform the action
    if (a == 0 && exists == 1) {
      printf("T2: %d is in the list\n", d);
    } else if (a == 1 && exists == 1) {
      printf("T2: deleting %d\n", d);
      deleteData(list, d);
    } else {
      printf("T2: %d is not in the list\n", d);
    }
    pthread_mutex_unlock(&list_mutex);
  }
}
