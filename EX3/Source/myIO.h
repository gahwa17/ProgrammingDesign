#ifndef myIO_H
#define myIO_H

#include "basic.h"
#include "myAlgo.h"

#define _print(n) {printf(#n": ");_print_relation();}

void _build_map();
void _print_relation();
void _check_argument(int argc, char **argv);
void _err_message(int condition);


#endif