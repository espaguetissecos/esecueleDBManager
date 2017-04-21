#include "operation.h"

/* OFFSET OPERATION: operation whose result all but the first N results of another source operation */

typedef struct {
    int comienzo;/* Numero de op a surpimir*/
    int sumprim;/*Contador de op surpimidas*/
    operation_t * operation;
} operation_offset_args_t;

void
operation_offset_reset(void* vargs) {
    operation_offset_args_t* args = vargs;
    args->sumprim = 1;
    args->comienzo = 0;
}

int operation_offset_next(void* vargs) {
    operation_offset_args_t* args = vargs;

	while(args->sumprim != args->comienzo){/* Suprime las primeras tuplas hasta el numero de offset y despues las restantes las imprime*/
		args->sumprim ++;
		operation_next(args->operation);
		
	}
	
	return operation_next(args->operation);
}

void* operation_offset_get(int col, void* vargs) {
    operation_offset_args_t *args = vargs;
    return operation_get(col, args->operation);
}

void operation_offset_close(void* vargs) {
    operation_offset_args_t* args = vargs;
    operation_close(args->operation);
    free(args);
}

operation_t*
operation_offset_create(operation_t* suboperation, int offset) {
    operation_t* operation;
    operation_offset_args_t* args;

    args = malloc(sizeof (operation_offset_args_t));
    args->operation = suboperation;
    args->comienzo = offset;
    args->sumprim = 0;

    operation = malloc(sizeof (operation_t));
    operation->types = (type_t *) calloc(sizeof(type_t), suboperation->ncols);
    operation->args = args;
    operation->reset = operation_offset_reset;
    operation->next = operation_offset_next;
    operation->get = operation_offset_get;
    operation->close = operation_offset_close; 
    operation->ncols = suboperation->ncols;
    memcpy(operation->types, suboperation->types, sizeof(type_t) * suboperation->ncols);

    return operation;
}

