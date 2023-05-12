#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size == 0)
  {
    return NULL;
  }
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if (pq->size == pq->capac){
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = (heapElem*)realloc(pq->heapArray, pq->capac * sizeof(heapElem));
  }
  int currentIndex = pq->size;
  int parentIndex = (currentIndex -1)/2;

  while (currentIndex >0&& pq->heapArray[parentIndex].priority < priority){
    pq->heapArray[currentIndex] = pq->heapArray[parentIndex];
    currentIndex = parentIndex;
    parentIndex = (currentIndex - 1)/ 2;
  }

  pq->heapArray[currentIndex].data = data;
  pq->heapArray[currentIndex].priority =priority;
  pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* heap = (Heap*)malloc(sizeof(Heap));
  heap->heapArray = (heapElem*) malloc(3*sizeof(heapElem));
  heap->size = 0;
  heap->capac = 3;
   return heap;
}
