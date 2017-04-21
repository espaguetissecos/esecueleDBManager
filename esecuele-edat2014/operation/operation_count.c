#include "operation.h"

/* COUNT OPERATION: operation whose result is the number of results of the source operation */

typedef struct {
    int flag;/* Si ya se ha contao algo se desactiva*/
    int count;/*Cuenta de los registros que lee*/
    operation_t* operation;/* Operaciones a realizar*/
} operation_count_args_t;

void
operation_count_reset(void* vargs) {
    operation_count_args_t *args = vargs;
    operation_reset(args->operation);
    
    args->count = 0;
    args->flag = 1;
    
    return;
}

int operation_count_next(void* vargs) {
    int ret;
    operation_count_args_t *args = vargs;

    if (args->flag == 1) {/* Si ya tenemos algo contado no podemos contar nada hasta que no se resetea*/
        while(operation_next(args->operation)) {/* Mientras tengas registros que leer*/
            args->count++;/*aumentamos el contador de registros leidos*/
        }
        args->flag = 0;
        return 1;
    }
    else 
        return 0;
}

void* operation_count_get(int col, void* vargs) {
    operation_count_args_t* args = vargs;
    operation_t* op = args->operation;

    if (col == 0) {
        return &(args->count);
    }
    return NULL;
}

void operation_count_close(void* vargs) {
    operation_count_args_t* args = vargs;
    operation_close(args->operation);
    free(args);
}

operation_t*
operation_count_create(operation_t* suboperation) {
    operation_t* operation;
    operation_count_args_t* args;

    args = malloc(sizeof(operation_count_args_t));
    args->operation = suboperation;
    args->count = 0;
    args->flag = 1;

    operation = malloc(sizeof(operation_t));
    operation->args = args;
    operation->reset = operation_count_reset;
    operation->next = operation_count_next;
    operation->get = operation_count_get;
    operation->close = operation_count_close;
    operation->ncols = 1;
    operation->types = malloc(1 * sizeof(type_t));
    operation->types[0] = INT;

    return operation;
}

