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
        int nuevaCapacidad = pq->capac * 2 + 1;
        
        pq->heapArray = realloc(pq->heapArray, nuevaCapacidad * sizeof(heapElem));
        if (pq->heapArray == NULL)exit(EXIT_FAILURE);
        pq->capac = nuevaCapacidad;
    }

    pq->heapArray[pq->size].data = data;
    pq->heapArray[pq->size].priority = priority;
    pq->size++;

    int aux = pq->size - 1;
    while(aux > 0){
        int parentAux = ((aux -1 )/ 2);
        if( pq->heapArray[aux].priority >  pq->heapArray[parentAux].priority){
            heapElem temp =  pq->heapArray[aux];
            pq->heapArray[aux] =  pq->heapArray[parentAux];
            pq->heapArray[parentAux] = temp;
            aux = parentAux;
        }else{
            break;
        }
    }


    
    

}


void heap_pop(Heap* pq){
    pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;

  int i=0;
  int izquierda=1;
  int derecha=2;
  int largo=i;
  
  while(1){

    if((izquierda < pq->size)&&(pq->heapArray[izquierda].priority > pq->heapArray[largo].priority)){
      largo= izquierda;
    }
    if((derecha < pq->size)&&(pq->heapArray[derecha].priority > pq->heapArray[largo].priority)){
      largo =derecha;
    }
    if(largo==i){
      break;
    }
    swap(&(pq->heapArray[i]),&(pq->heapArray[largo]));
    i=largo;
    break;
  }
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
