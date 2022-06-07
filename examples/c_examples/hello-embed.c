/*
This file is an example embedding for the Interpreter Manager class
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "py/compile.h"
#include "py/runtime.h"
#include "py/gc.h"
#include "py/stackctrl.h"

static char heap[16384];


mp_obj_t execute_from_str(const char *str) {
    nlr_buf_t nlr;
    if (nlr_push(&nlr) == 0) {
        qstr src_name = 1/*MP_QSTR_*/;
        mp_lexer_t *lex = mp_lexer_new_from_str_len(src_name, str, strlen(str), false);
        mp_parse_tree_t pt = mp_parse(lex, MP_PARSE_FILE_INPUT);
        mp_obj_t module_fun = mp_compile(&pt, src_name, false);
        mp_call_function_0(module_fun);
        nlr_pop();
        return 0;
    } else {
        // uncaught exception
        return (mp_obj_t)nlr.ret_val;
    }
}

int main() {
    // Initialized stack limit
    mp_stack_set_limit(40000 * (BYTES_PER_WORD / 4));
    // Initialize heap
    gc_init(heap, heap + sizeof(heap));
    // Initialize interpreter
    mp_init();

    const char str[] = "print('Hello world of easy embedding!')";
    if (execute_from_str(str)) {
        printf("Error\n");
        return -1;
    }
}

uint mp_import_stat(const char *path) {
    return MP_IMPORT_STAT_NO_EXIST;
}

void nlr_jump_fail(void *val) {
    printf("FATAL: uncaught NLR %p\n", val);
    exit(1);
}
