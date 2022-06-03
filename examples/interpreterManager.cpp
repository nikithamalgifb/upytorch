#include "interpreterManager.h"

Interpreter::Interpreter(size_t heap_size){
    char heap[heap_size];
    // Initialized stack limit
    mp_stack_set_limit(40000 * (BYTES_PER_WORD / 4));
    // Initialize heap
    gc_init(heap, heap + sizeof(heap));
    // Initialize interpreter
    mp_init();

}
