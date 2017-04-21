/*
 * File:   main.c
 * Author: Kiko
 *
 * Created on 11 de diciembre de 2014, 21:56
 */

#include <stdio.h>
#include <stdlib.h>
#include "table.h"
#include "record.h"
#include "type.h"

/*
 *
 */
int main(int argc, char** argv) {
    
    
    int i;
    type_t t[4];
    table_t* tu;
    void** values;
    record_t* r = NULL;
    char word[5]= "paco";
    
    values = malloc(4*sizeof(void*));
    
    values[0] = malloc(sizeof(int));
    *((int*)values[0]) = 15;
    printf("%d\n", *(int*)values[0]);
    
    values[1] = malloc(sizeof(char)*strlen(word)+1);
    strcpy(((char*)values[1]), word);
    printf("%s\n", (char*)values[1]);
    
    values[2] = malloc(sizeof(double));
    *((double*)values[2]) = 10.19;
    printf("%f\n", *(double*)values[2]);

    values[3] = malloc(sizeof(long));
    *((long*)values[3]) = 20;
    printf("%ld\n", *(long*)values[3]);
    
    
    for(i=0; i < 4 ; i++)
        t[i]= i;
    
    table_create("prueba", 4, t);
    
    tu = table_open("prueba");
    
    printf("Columnas: %d\n", table_ncols(tu));
    
    printf("Primera pos: %ld\n", table_first_pos(tu));
    
    printf("Ultima pos: %ld\n", table_last_pos(tu));
    
    table_insert_record(tu, values);
    
    r = table_read_record(tu, table_first_pos(tu));
    
    printf(" %ld\n", record_next(r));
    
    printf(" %s\n", (char*)record_get(r, 1));
    
    record_free(r);
    
    for (i=0; i<4; i++) {
        free(values[i]);
    }
    
    free(values);
    
    table_close(tu);
    
    return 0;
}

