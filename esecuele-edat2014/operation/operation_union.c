
#include "operation.h"

/* UNION OPERATION: concatenation of the results of two operations with the same columns */

typedef struct {
    int exe_op;/* Consulta a leer*/
    operation_t* operation1;/* Primera consulta*/
    operation_t* operation2;/*Segunda consulta*/
} operation_union_args_t;

void
operation_union_reset(void* vargs) {
    operation_union_args_t* args = vargs;
    operation_reset(args->operation1);
    operation_reset(args->operation2);
}

int operation_union_next(void* vargs) {
    int ret;
    operation_union_args_t* args = vargs;
    operation_t* operation1 = args->operation1;
    operation_t* operation2 = args->operation2;

    if (args->exe_op == 1) {/* Lee la cosulta 1*/
        ret = operation_next(operation1);
        if (ret == 0) {/* Si todo ha ido bien lee la 2*/
            args->exe_op = 2;
            ret = operation_next (operation2);
        }
    } else{/* Si ha leido la 1 lee la 2*/
        ret = operation_next (operation2);
    }
    return ret;
}

void* operation_union_get(int col, void* vargs) {
    void* value;
    operation_union_args_t* args = vargs;
    operation_t* operation1 = args->operation1;
    operation_t* operation2 = args->operation2;

    if (args->exe_op == 1) {
        /* indica leer la primera operacion*/
        value = operation_get(col, operation1);
    } else {
        /* indica leer la seguda*/
        value = operation_get(col, operation2);
    }

    return value;
}

void operation_union_close(void* vargs) {
    operation_union_args_t* args = vargs;
    operation_close(args->operation1);
    operation_close(args->operation2);
    free(args);
}

operation_t*
operation_union_create(operation_t* operation1, operation_t* operation2) {
    operation_t* operation;
    operation_union_args_t* args;
 
    args = malloc(sizeof(operation_union_args_t));
    args->exe_op = 1;
    args->operation1 = operation1;
    args->operation2 = operation2;
 
    operation = malloc(sizeof(operation_t));
    operation->args = args;
    operation->reset = operation_union_reset;
    operation->next = operation_union_next;
    operation->get = operation_union_get;
    operation->close = operation_union_close;
    operation->ncols = operation_ncols(operation1); /* las mismas operaciones deben tener las mismas columnas*/
    operation->types = malloc(operation->ncols * sizeof(type_t)); /* ambas operaciones deben tener los mismos tipos para las mismas columnas*/
    
    memcpy(operation->types, operation1->types, operation1->ncols * sizeof(type_t));
 
    return operation;
}

