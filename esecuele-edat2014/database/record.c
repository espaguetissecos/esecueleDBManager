#include "record.h"

struct record_ {
    int ncols;/* Nmero de columnas de elementos*/
    long next;/*Siguiente posicion para leer el siguiente record*/
    void** values;/* Valores del record*/
};

record_t* record_create(void** values, int ncols, long next) {
    record_t *record = (record_t*) malloc (sizeof(record_t));
    record->ncols = ncols;
    record->next= next;
    record->values = values;
    return record;
}

void* record_get(record_t* record, int n) {
    if (record == NULL)
        return NULL;
    return record->values[n];
}

long record_next(record_t* record) {
    return record->next;
}

void record_free(record_t* record) {
    int i;
    if (record == NULL) {
        return;
    }
    for(i=0;i<record->ncols;i++){
        free(record->values[i]);
    }
    
    free(record->values);
    free(record);
}
