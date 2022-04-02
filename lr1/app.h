#ifndef _APP_H_
#define _APP_H_

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

//========== functions ===========

matrix* matrix_sum(matrix* mat1, matrix* mat2, matrix* rez);
matrix* matrix_mult(matrix* mat1, matrix* mat2, matrix* rez);
matrix* matrix_mult_scalar_int(matrix* mat, matrix* rez, int scalari);
matrix* matrix_mult_scalar_float(matrix* mat, matrix* rez, float scalarf);

#endif
