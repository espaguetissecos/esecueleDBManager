/*
 * File:   main.c
 * Author: Kiko
 *
 * Created on 11 de diciembre de 2014, 21:56
 */

#include <stdio.h>
#include <stdlib.h>
#include "index.h"
#include "table.h"
#include "record.h"
#include "type.h"

/*
 *
 */
int main(int argc, char** argv) {
    
    index_t* index;
    long* offsets = (long*)malloc(sizeof(long)*3);
    int noffsets = 0;
    int* keys = (int*)malloc(sizeof(int)*3);
    long**values = (long**) malloc(sizeof(long*)*3);
    values[0] = (long*) malloc(sizeof(long)*2);
    values[1] = (long*) malloc(sizeof(long)*3);
    values[2] = (long*) malloc(sizeof(long)*1);
    int* value = (int*) malloc(sizeof(int)*3);
    int i;
    
    keys[0] = 2;
    keys[1] = 3;
    keys[2] = 4;
    
    value[0] = 2;
    value[1] = 3;
    value[2] = 1;
    
    values[0][0] = 1;
    values[0][1] = 2;
    values[1][0] = 4;
    values[1][1] = 5;
    values[1][2] = 7;
    values[2][0] = 9;
    
    
    index_create("prueba");
    
    index = index_open("prueba");
    
    index_close(index);
    
    index = index_form(3, keys, value, values);
    
    index_save(index, "prueba");
    
    index_close(index);
    
    index = index_open("prueba");
    
    index_put(index, 1, 10);
    
    index_get(index, 3, &offsets, &noffsets);

    printf("Los offsets de la clave son \n");
    
    for(i=0; i<noffsets;i++){
        printf("%ld", offsets[i]);
        printf("\n");    

    }  
    printf("\nEl numero de offsets de la clave es ");
    printf("%d\n", noffsets);
        
/*
    index_close(index);
*/
    
    return 0;
}

