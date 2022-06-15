/*
This file defines the class for the interpreter manager class.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//Micropython Modules are in C
extern "C" {
    #include "py/compile.h"
    #include "py/runtime.h"
    #include "py/gc.h"
    #include "py/stackctrl.h"
}

#define HEAP_SIZE 16384

class Interpreter {
    public:
        Interpreter();
        ~Interpreter() {};
};
