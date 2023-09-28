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
    if (pq->size == 0)return NULL;
    return pq->heapArray[0].data;
}


void heap_push(Heap* pq, void* data, int priority){
    if (pq->size >= pq->capac) {
        // Aumentar la capacidad al doble + 1
        int nueva_capacidad = pq->capac * 2 + 1;
        pq->heapArray = realloc(pq->heapArray, nueva_capacidad * sizeof(heapElem));
        if (pq->heapArray == NULL)exit(EXIT_FAILURE);
        pq->capac = nueva_capacidad
    }

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (heap == NULL)exit(EXIT_FAILURE);
    
    // Inicializar variables del Heap
    heap->size = 0;
    heap->capac = 3;  
    heap->heapArray = (heapElem*)malloc(heap->capac * sizeof(heapElem));
    if (heap->heapArray == NULL) {
        free(heap);  // Liberar memoria asignada previamente
        exit(EXIT_FAILURE);
    }

    return heap;
}
