#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "table.h"
#include "../type/type.h"

struct table_ {
    int n_cols;/*Numero de columnas de la tabla*/
    type_t* t;/* Tipos de elementos de la tabla*/
    FILE* path;/* Fichero a guardar la tabla y los elementos*/
    long first_pos;/* Pimera posicion despues de los datos de tabla en el primer registro*/
    long last_pos;/* Ultima posicion del fichero*/
};

void table_create(char* path, int ncols, type_t* types) {
    FILE *f1 = fopen(path, "w+");
    if (f1 == NULL) {
        return;
    }
    fwrite(&ncols, sizeof(int), 1, f1);/* Insertamos numero de elementos de la tabla*/
    fwrite(types, sizeof(type_t), ncols, f1);/* Insertamos los tipos*/
    fclose(f1);
}

table_t* table_open(char* path) {
    table_t *t = (table_t*) malloc (sizeof(table_t));
    t->path = fopen(path, "r+");
    if(t->path == NULL){
        return NULL;
    }
    fread(&t->n_cols, sizeof(int), 1, t->path);/* Leemos el numero de elementos*/
    t->t = (type_t*) malloc (t->n_cols * sizeof(type_t));
    fread(t->t, sizeof(type_t), t->n_cols, t->path);/* Leemos los tipos*/ 
    
    t->first_pos = ftell(t->path);/*Primera posicion del registro a leer*/
    fseek(t->path, 0, SEEK_END);
    t->last_pos = ftell(t->path);/* Ultima posicion del fichero*/
    
    return t;
}

void table_close(table_t* table) {
    if(table == NULL){
        return;
    }
    fclose(table->path);
    free(table->t);
    free(table);
    table = NULL;
}

int table_ncols(table_t* table) {
    if (table != NULL)
        return table->n_cols;
    return 0;
}

type_t* table_types(table_t* table) {
    if (table != NULL)
        return table->t;
    return 0;
}

long table_first_pos(table_t* table) {
    return table->first_pos;
}

long table_last_pos(table_t* table) {
    return table->last_pos;
}

record_t* table_read_record(table_t* table, long pos) {
    int i,  tam;
    record_t* r;
    void** gen;
    long next = pos;
    
    if(table == NULL){
        return NULL;
    }
    
    if(table_last_pos(table) == pos){
        return NULL;
    }
    
    gen = malloc(table->n_cols * sizeof(void*));
    
    fseek(table->path, pos, SEEK_SET);
    
    for (i=0; i < table->n_cols;i++){
        fread(&tam, sizeof(int), 1, table->path);
        
        gen[i] = malloc(tam);
        fread(gen[i], tam, 1, table->path);
        
        next = next + tam + sizeof(int);
    }   
    
    r = record_create(gen, table->n_cols, next);
    
    return r;
}

void table_insert_record(table_t* table, void** values) {
    int i, tam;
    
    if(table == NULL || values == NULL){
        return;
    }
    
    fseek(table->path, 0, SEEK_END);
    
    for(i=0;i<table->n_cols;i++){
        tam = value_length(table->t[i], (char*)values[i]);
        fwrite(&tam, sizeof(int), 1, table->path);
        fwrite(values[i], value_length(table->t[i], (char*)values[i]), 1, table->path);
    }
    
    table->last_pos = ftell(table->path);/* Actualizamos la ultima posicion*/
    
}
