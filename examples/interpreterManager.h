/*

This file defines the class for the interpreter manager class.

*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//Micropython Modules are in C
extern "C" {
    #pragma once
    #include "py/compile.h"
    #include "py/runtime.h"
    #include "py/gc.h"
    #include "py/stackctrl.h"
}

class Interpreter {
    public:
        Interpreter(int nInterps);
        ~Interpreter() {};
};
