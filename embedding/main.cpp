#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;


#include "interpreterManager.h"

string readFileIntoString(const string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

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

    Interpreter m;

    //string str = readFileIntoString("./test.txt");
    const char str2[] = "import sysprint(sys.__loader__)";
    if (execute_from_str(str2)) {
        std::cout << "Error\n";
        return -1;
    }

    return 0;
}
