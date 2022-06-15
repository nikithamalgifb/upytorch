#include "interpreterManager.h"


Interpreter::Interpreter(){
    char heap[HEAP_SIZE];
    // Initialized stack limit
    mp_stack_set_limit(40000 * (BYTES_PER_WORD / 4));
    // Initialize heap
    gc_init(heap, heap + sizeof(heap));
    // Initialize interpreter
    mp_init();
}
