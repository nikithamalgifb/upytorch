/*
This file is an example embedding for the Interpreter Manager class
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "interpreterManager.h"


extern "C" {
    #include "py/compile.h"
    #include "py/runtime.h"
    #include "py/gc.h"
    #include "py/stackctrl.h"

    #include "py/builtin.h"
    #include "py/repl.h"
    #include "py/stackctrl.h"
    #include "py/mphal.h"
    #include "py/mpthread.h"
    #include "extmod/misc.h"
    #include "extmod/vfs.h"
    #include "extmod/vfs_posix.h"
    #include "input.h"
    #include "py/objlist.h"


    //#include "../../lib/__main.c"
    int __main();

}

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

    __main();

    // Initialized stack limit
    mp_stack_set_limit(40000 * (BYTES_PER_WORD / 4));
    // Initialize heap
    gc_init(heap, heap + sizeof(heap));
    // Initialize interpreter
    mp_init();

    const char str[] = "import sys\nprint(sys.modules)";
    if (execute_from_str(str)) {
        printf("Error\n");
        return -1;
    }

    return 0;
}
