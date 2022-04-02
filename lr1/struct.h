#ifndef _STRUCT_H_
#define _STRUCT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//==========  structs ===================

typedef struct matrix
{
	int n;
	void*** arr;
	int size;
}matrix;

//========== work with memory ===========

void matrix_memory(matrix* mat);
void matrix_destroy(matrix* mat);

//========== in / out matrix ============

void input_matrix_int(int** a, int k);
void input_matrix_float(float**b, int k);
void input_stdin(matrix* mat);
void output_matrix(matrix* mat);
void generate_matrix(matrix* mat);

#endif
