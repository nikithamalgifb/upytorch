/*
This file defines the class for the interpreter manager class.
*/
#pragma once
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


class Interpreter {
    public:
        Interpreter();
        ~Interpreter() {};
};
