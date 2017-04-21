#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "index.h"

struct index_ {
    int n_key;/* Clave*/
    int* key;/* NUmero de claves*/
    int *n_tuplas;/*Numero de elementos de las claves*/
    long** tuplas;/* Elementos de las claves*/
};

int BBin(int* table, int tam, int clave){
    int f, l, m;
    f=0;
    l = tam-1;
    while(f<=l){/* Se repite mientas que el final no sea igual que el principio*/
        m= f+(l-f)/2;/*Divide en 2 la tabla*/
        if(table[m] == clave)/* Compara que el elemento medio sea la clave*/
            return m;
        else if (table[m] < clave)/* Si no la dividimos a la mitad y vamos a un lado o a otro*/
            f=m+1;
        else
            l=m-1;
    }
    return -1;
    
}

/* Funcion para crear un indice para probarlo no se utiliza en la ejecucion del poryecto entero*/
index_t* index_form (int key, int* keys, int* value, long** values){
    index_t* index = (index_t*)malloc(sizeof(index_t));
    index->n_key = key;
    index->key = keys;
    index->n_tuplas = value;
    index->tuplas = values;
    return index;
}

/* Crea a un indice en un fichero con los campos a 0*/
int index_create(char* path) {
    FILE* f1 = fopen(path, "w+");
    int aux = 0;
    fseek(f1, 0, SEEK_SET);
    fwrite(&aux, sizeof(int), 1, f1);
    fclose(f1);
    return 1;
}


int index_save(index_t *index, char* path) {
    FILE* f1 = fopen(path, "w+");
    int i;
    
    fseek(f1, 0, SEEK_SET);
    
    fwrite(&index->n_key, sizeof(int), 1, f1);/* Guardamos el numero de claves*/
    
    fwrite(index->key, sizeof(int), index->n_key, f1);/* Guardamos las claves*/
    
    for(i=0;i<index->n_key;i++){/* Guardamos el numero de elementos de cada clave y sus elementos*/
        fwrite(&index->n_tuplas[i], sizeof(int), 1, f1);
        fwrite(index->tuplas[i], sizeof(long), index->n_tuplas[i], f1);
    }
    
    fclose(f1);
    return 1;
}

index_t* index_open(char* path) {
    FILE* f1= fopen(path, "r+");
    int i;
    
    index_t* index = (index_t*)malloc(sizeof(index_t));
    fread(&index->n_key,  sizeof(int), 1, f1);
    if (index->n_key == 0) {/* Si el indice esta vacio lo inicializamos todo a null*/
        index->key = NULL;
        index->n_tuplas = NULL;
        index->tuplas = NULL;
        
        fclose(f1);
        
        return index;
    }/* Si no lo lo leemos*/
    index->key = (int*)malloc(sizeof(int)*index->n_key);
    index->n_tuplas = (int*)malloc(sizeof(int)* index->n_key);
    index->tuplas = (long**)malloc(sizeof(long*)*index->n_key);
    
    fread(index->key, sizeof(int), index->n_key, f1);
    
    for(i=0; i < index->n_key; i++){
        fread(&index->n_tuplas[i], sizeof(int), 1, f1);
        index->tuplas[i] = (long*)malloc(sizeof(long)*index->n_tuplas[i]);
        fread(index->tuplas[i], sizeof(long), index->n_tuplas[i], f1);
    }
    
    fclose(f1);
    return index;
}

int index_put(index_t *index, int key, long pos) {
    int i, new = 0, m;
    
    m = BBin(index->key, index->n_key, key);
    
    if(m == -1)
        new = 1;
    
    if(new == 0){/* Si existe la clave donde la queremos insertar, la buscamos y la insertamos al final, ya que el indice nuevo no va a ser menor que los anteriores*/
        index->n_tuplas[m] = index->n_tuplas[m] + 1;/* Aumento el nuemero de valores*/
        index->tuplas[m] = (long*) realloc (index->tuplas[m], index->n_tuplas[m] * sizeof(long));/* Aumento el array*/
        index->tuplas[m][index->n_tuplas[m] - 1] = pos;/* Incluyo el elemento*/
    }
    
    else{/* Si es nuevo hay que desplazar todos una posicion mas e insertarlo en el medio*/
        index->n_key++;
        index->key = (int*) realloc (index->key,sizeof(int) * index->n_key);
        index->n_tuplas = (int*) realloc (index->n_tuplas, sizeof(int) * index->n_key);
        index->tuplas = (long**) realloc (index->tuplas, sizeof(long) * index->n_key);
        
        for(i = index->n_key - 1;index->key[i - 1] > key && i + 1 > 1;i--){
            index->key[i] = index->key[i - 1];
            index->n_tuplas[i] = index->n_tuplas[i - 1];
            index->tuplas[i] = index->tuplas[i - 1];
        }
        
        index->tuplas[i] = (long*) malloc (sizeof(long));
        index->n_tuplas[i] = 1;
        index->tuplas[i][0] = pos;
        index->key[i] = key;
    }
    
    return 1;
}

void index_get(index_t *index, int key, long** poss, int* nposs) {
    int i, j;
    
    i = (BBin(index->key, index->n_key, key));/* Buscamos la posicion del indice en el array*/
    
    if (i == -1) {
        printf("No se encuentra la clave");
        return;
    }
    
    for(j=0; j!=i; j++)
        index->n_tuplas++;
    
    *nposs = *index->n_tuplas; /*Guardamos la posicion en noffsets de
                                la cantidad de sitios donde aparece la
                                key*/
    
    for(j=0; j!=i; j++)
        index->n_tuplas++;
    
    for(j=0; j < *nposs; j++)
        poss[0][j] = index->tuplas[i][j]; /*Guardamos la posicion en offsets de el
                                              array de sitios donde aparece la key*/
    for(;j > 0; j--);
    
}

void index_close(index_t *index) {
    int i;
    
    for (i = 0; i < index->n_key; i++) {
        free(index->tuplas[i]);
    }
    free(index->tuplas);
    free(index->key);
    free(index->n_tuplas);
    free(index);
    index = NULL;
    return;
}
