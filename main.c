#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CircularBuffer.h"


/*
    main
*/
int main (void) {
	circularBuffer_t *cbptr;
	int *getVal;
   
    getVal = malloc (sizeof (int));
    
    cbptr = malloc (sizeof (circularBuffer_t));     
    createCircularBuffer(cbptr, 5);

    put (cbptr, 1);
    put (cbptr, 2);
    put (cbptr, 3);
    put (cbptr, 4);
    put (cbptr, 5);
    put (cbptr, 6);
    put (cbptr, 7);
    put (cbptr, 8);
    put (cbptr,9);
    put (cbptr,10);
    while(1){
      get (cbptr, getVal);
      printf("Value: %i  \n",*getVal);
      for(int i=0;i<100000000;i++){

      }
    }
    
    freeCircularBuffer (cbptr);
    free (cbptr);
    free (getVal);
    
    return 0;
}