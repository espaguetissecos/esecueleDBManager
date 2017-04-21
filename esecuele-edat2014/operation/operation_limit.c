#include "operation.h"

/* LIMIT OPERATION: operation whose result is the first N results of another source operation */

typedef struct {
    int limite;
    int contador;
    operation_t * operation;
} operation_limit_args_t;

void
operation_limit_reset(void* vargs) {
    operation_limit_args_t *args = vargs;
    operation_reset(args->operation);
}

int operation_limit_next(void* vargs) {
    operation_limit_args_t *args = vargs;
    
    if (args->contador >= args->limite) return 0;/*Mientras las veces que se ralice sea menor que el limite impuesto se imprimen las tuplas*/
    args->contador++;
    
    return operation_next(args->operation);
}

void* operation_limit_get(int col, void* vargs) {
    operation_limit_args_t *args = vargs;
    return operation_get (col, args->operation);
}

void operation_limit_close(void* vargs) {
    operation_limit_args_t *args = vargs;
    operation_close(args->operation);
    free(args);
}

operation_t*
operation_limit_create(operation_t* suboperation, int limit) {
    operation_t *operation;
    operation_limit_args_t *args;

    args = malloc(sizeof (operation_limit_args_t));
    args->operation = suboperation;
    args->limite = limit;
    args->contador = 0;

    operation = malloc(sizeof (operation_t));
	operation->types = (type_t *)calloc(sizeof(type_t), suboperation->ncols);
    operation->args = args;
    operation->reset = operation_limit_reset;
    operation->next = operation_limit_next;
    operation->get = operation_limit_get;
    operation->close = operation_limit_close;
    operation->ncols = suboperation->ncols;
	memcpy(operation->types, suboperation->types, sizeof(type_t) * suboperation->ncols);

    return operation;
}


