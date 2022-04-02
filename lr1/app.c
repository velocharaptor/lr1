#include "app.h"
#include <string.h>

// умножение/сложение квадратных матриц выполняется ток при одинаковых размерах(т.е. одном n)!!

matrix* matrix_sum(matrix* mat, matrix* mat1, matrix* rez_sum)
{	
	int temp0, t=0;
	float temp1;
	
	rez_sum->n = mat->n;
	rez_sum->size = mat->size;
	matrix_memory(rez_sum);
	
	printf("Enter second matrix (same size and size matrix as 1 matrix):\nYou want enter stdin or generate?\n1)stdin\n2)generate\n->");
	scanf("%d", &t);
	if(t == 1)
		input_stdin(mat1);
	else 
		generate_matrix(mat1);
	output_matrix(mat1);	
		
	for(int i = 0; i < rez_sum->n; i++)
	{
		for(int j = 0; j < rez_sum->n; j++)
		{
			if(rez_sum->size == 1)
			{
				//rez->arr[i][j] = mat->arr[i][j] + mat1->arr[i][j];
				temp0 = *(int*)mat->arr[i][j] + *(int*)mat1->arr[i][j];
				memcpy(rez_sum->arr[i][j], &temp0, sizeof(int));
			}
			else
			{ 
				//rez->arr[i][j] = mat->arr[i][j] + mat1->arr[i][j];
				temp1 = *(float*)mat->arr[i][j] + *(float*)mat1->arr[i][j];
				memcpy(rez_sum->arr[i][j], &temp1, sizeof(float));
			}
		}
	}

	return rez_sum;
}

matrix* matrix_mult(matrix* mat, matrix* mat1, matrix* rez_mult)
{	
	int temp0=0, t=0;
	float temp1=0;
	
	rez_mult->n = mat->n;
	rez_mult->size = mat->size;
	matrix_memory(rez_mult);
	
	printf("Enter second matrix (same size and size matrix as 1 matrix):\nYou want enter stdin or generate&\n1)stdin\n2)generate\n->");
	scanf("%d", &t);
	if(t == 1)
		input_stdin(mat1);
	else
		generate_matrix(mat1);
	output_matrix(mat1);
	
	for(int i = 0; i < rez_mult->n; i++)
	{
		for(int j = 0; j < rez_mult->n; j++)
		{	
			if(rez_mult->size == 1)
			{
				*(int*)rez_mult->arr[i][j] = 0;
				temp0 = 0;
				//printf("[%d][%d]\n", i, j);
			}
			else
			{
				*(float*)rez_mult->arr[i][j] = 0;
				temp1 = 0;
				//printf("[%d][%d]\n", i, j);
			}
			for(int k = 0; k < rez_mult->n; k++)
			{	
				if(rez_mult->size == 1)
				{	
					temp0 = temp0 + (*(int*)mat->arr[i][k]) * (*(int*)mat1->arr[k][j]);
					*(int*)rez_mult->arr[i][j] = temp0;
				//	printf("%d:", k);
				//	printf(" %d:\n", *(int*)rez_mult->arr[i][j]);
				}
				else
				{
					temp1 = temp1 + (*(float*)mat->arr[i][k]) * (*(float*)mat1->arr[k][j]);
					*(float*)rez_mult->arr[i][j] = temp1;
				//	printf("%d", k);
				//	printf(" %f:\n", *(float*)rez_mult->arr[i][j]);
				}
			}
		}
	}
	
	return rez_mult;
}

matrix* matrix_mult_scalar_int(matrix* mat, matrix* rez_mult_scalar, int scalari)
{
	rez_mult_scalar->n = mat->n;
	rez_mult_scalar->size = mat->size;
	matrix_memory(rez_mult_scalar);
	
	for(int i = 0; i < rez_mult_scalar->n; i++)
	{
		for(int j = 0; j < rez_mult_scalar->n; j++)
		{
			memcpy(rez_mult_scalar->arr[i][j], mat->arr[i][j], sizeof(int));
		}
	}

	for(int i = 0; i < rez_mult_scalar->n; i++)
	{
		for(int j = 0; j < rez_mult_scalar->n; j++)
		{
			*(int*)rez_mult_scalar->arr[i][j] *= scalari;
		}
	}
	return rez_mult_scalar;
}

matrix* matrix_mult_scalar_float(matrix* mat, matrix* rez_mult_scalar, float scalarf)
{	
	rez_mult_scalar->n = mat->n;
	rez_mult_scalar->size = mat->size;
	matrix_memory(rez_mult_scalar);

	for(int i = 0; i < rez_mult_scalar->n; i++)
	{
		for(int j = 0; j < rez_mult_scalar->n; j++)
		{
			memcpy(rez_mult_scalar->arr[i][j], mat->arr[i][j], sizeof(float));
		}
	}

	for(int i = 0; i < rez_mult_scalar->n; i++)
	{
		for(int j = 0; j < rez_mult_scalar->n; j++)
		{
			*(float*)rez_mult_scalar->arr[i][j] *= scalarf;
		}
	}
	return rez_mult_scalar;
}


































