/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Greggory Hickman
 * Email: hickmang@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pq.h"
#include "dynarray.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 * in addition, you want to define an element struct with both data and priority, 
 * corresponding to the elements of the priority queue. 
 */
struct pq {
  struct dynarray* brain;
};

struct element {
  void* data;
  int priority;
};


/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {

  //Initialize the new priority queue
  struct pq* new_pq = malloc(sizeof(struct pq));
  assert(new_pq);

  //Initialize the "brain"
  new_pq->brain = dynarray_create();

  return new_pq;

}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
  
  assert(pq);

  dynarray_free(pq->brain); //Free the brain
  free(pq); //Free the queue

}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {

  //If empty, 1. If not empty, 0. Yee haw.
  if (dynarray_length(pq->brain) == 0) return 1;
  else return 0;

}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, higher priority
 * values are given precedent, and higher place in the queue.  In other words, the
 * element in the priority queue with the highest priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   data - the data value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, higher priority values
 *     should correspond to the first elements.  In other words,
 *     the element in the priority queue with the highest priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* data, int priority) {

  printf("Tree Print:\n");
  for (int i = 0; i < dynarray_length(pq->brain); i++) {
    printf("%d, ", ((struct element*)dynarray_get(pq->brain, i))->priority);
    
    if (i == 0 || i == 2 || i == 6 || i == 14 || i == 30 || i == 62 || i == 126) {
      printf("\n");
    }

  }
  printf("\n\n");

  //Put together the element with the passed in data
  struct element* element = malloc(sizeof(struct element));
  element->data = data;
  element->priority = priority;

  int currentAddress = dynarray_length(pq->brain); //Get the current address of the element that we just added (array length - 1)

  dynarray_insert(pq->brain, -1, element); //Insert the element into the next available spot in the tree
  
  //printf("Insert - %d: %d\n", currentAddress, ((struct element*)dynarray_get(pq->brain, currentAddress))->priority);

  //Stop if the element is at the top of the heap
  while (currentAddress != 0) {

    //Compare the element to it's parent
    int parentAddress = (int)((currentAddress + 1) / 2) - 1;

    //If parent priority < current node priority...
    if (((struct element*)dynarray_get(pq->brain, parentAddress))->priority < ((struct element*)dynarray_get(pq->brain, currentAddress))->priority) {
      
      //...then swap them
      void* temp = dynarray_get(pq->brain, currentAddress);
      dynarray_set(pq->brain, currentAddress, dynarray_get(pq->brain, parentAddress));
      dynarray_set(pq->brain, parentAddress, temp);

    }
    else {
      return;
    }

  }
 
}

/*
 * This function should return the data of the first element in a priority
 * queue, i.e. the data associated with the element with highest priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the data of the first item in pq, i.e. the item with
 *   max priority value.
 */
void* pq_max(struct pq* pq) {
  struct element* element = (struct element*)(dynarray_get(pq->brain, 0));
  return element->data;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with highest priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with highest priority value.
 */
int pq_max_priority(struct pq* pq) {
  struct element* element = (struct element*)(dynarray_get(pq->brain, 0));
  return element->priority;
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with highest priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   highest priority value.
 */
void* pq_max_dequeue(struct pq* pq) {
  struct element* element = (struct element*)(dynarray_get(pq->brain, 0)); //This is highest priority boy
  return NULL; 
}
