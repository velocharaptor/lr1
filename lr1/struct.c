#include "struct.h"
#include <string.h>

void matrix_memory(matrix* mat)
{
	mat->arr = malloc(mat->n * sizeof(void**));
	for(int i = 0; i < mat->n; i++)
	{
		mat->arr[i] = malloc(mat->n * sizeof(void*));
		for(int j = 0; j< mat->n; j++)
		{
			mat->arr[i][j] = malloc(sizeof(void*));
		}
	}
}

void matrix_destroy(matrix* mat)
{
	for(int i = 0; i < mat->n; i++)
	{
		for(int j = 0; j < mat->n; j++)
		{
			free(mat->arr[i][j]);
		}
	}
	for(int i = 0; i < mat->n; i++)
	{
		free(mat->arr[i]);
	}
	free(mat->arr);
	free(mat);
}

void input_stdin(matrix* mat)
{
	int t;
	printf("Enter 1 or 2 for size:");
	scanf("%d", &t);
	if((t!=1)&&(t!=2))
	{
		while((t!=1)&&(t!=2))
		{
			printf("Input ERROR\n");
			printf("Enter 1 or 2 for size:");
			scanf("%d", &t);
		}
	}

	if(t==1)
	{
		mat->size = 1;
		printf("int-");
		printf("%d\n", mat->size);
	}
	else
	{
		mat->size = 2;
		printf("float-");
		printf("%d\n", mat->size);
	}

	printf("Enter size matrix:");
	scanf("%d", &mat->n);
	printf("%d\n", mat->n);
	matrix_memory(mat);
	
	int k = mat->n;
	int** a = malloc(k * sizeof(int*));
	for(int i = 0; i < k; i++)
		a[i] = malloc(k * sizeof(int));

	float** b = malloc(k * sizeof(float*));
	for(int i = 0; i < k; i++)
		b[i] = malloc(k * sizeof(float));

	if(mat->size == 1)
	{
		for(int i = 0; i < k; i++)
		{	
			for(int j = 0; j < k; j++)
			{
				printf("[%d][%d]:", i, j);
				scanf("%d", &a[i][j]);
			}
		}
	}
	else
	{
		for(int i = 0; i < k; i++)
		{
			for(int j = 0; j < k; j++)
			{
				printf("[%d][%d]:", i, j);
				scanf("%f", &b[i][j]);
			}
		}
	}

	for(int i = 0; i < mat->n; i++)
	{
		for(int j = 0; j < mat->n; j++)
		{
			if(mat->size == 1)
			{
				memcpy(mat->arr[i][j], &a[i][j], sizeof(int));
				//*(int*)mat->arr[i][j] = a[i][j];	 
			}
			else
			{
				memcpy(mat->arr[i][j], &b[i][j], sizeof(float));
				//*(float*)mat->arr[i][j] = b[i][j];
			}
		}
	}
	
	//printf("ok\n");
	
	for(int i = 0; i < k; i++)
	{
		free(a[i]);
		free(b[i]);
	}
	free(a);
	free(b);
}

void output_matrix(matrix* mat)
{
	printf("Output matrix:\n");
	for(int i = 0; i < mat->n; i++)
	{
		for(int j = 0; j < mat->n; j++)
		{
			if(mat->size == 1)
				printf("%d ", *(int*)mat->arr[i][j]);
			else
				printf("%f ", *(float*)mat->arr[i][j]);
		}
		printf("\n");
	}
}

void generate_matrix(matrix* mat)
{	
	srand(time(NULL));
	int count, t, n;
	printf("Enter 1 or 2 for size:");
	scanf("%d", &t);
	if(t==1)
	{
		mat->size = 1;
		printf("int-");
		printf("%d\n", mat->size);
	}
	else
	{
		mat->size = 2;
		printf("float-");
		printf("%d\n", mat->size);
	}
	
	printf("Enter max size element:");
	scanf("%d", &count);
	//count = rand();
	printf("Enter max size matrix:");
	scanf("%d", &n);	
	mat->n = n;
	//mat->n = rand() % n;
	printf("generate size: %d\n", mat->n);
	matrix_memory(mat);
	
	int k = mat->n;
	int** a = malloc(k * sizeof(int*));
	float** b = malloc(k * sizeof(float*));;
	for(int i = 0; i < k; i++)
	{
		a[i] = malloc(k * sizeof(int));	
		b[i] = malloc(k * sizeof(float));
	}

	if(mat->size==1)
	{
		for(int i = 0; i < k; i++)
		{
			for(int j = 0; j < k; j++)
			{
				a[i][j] = rand() % count;
			}
		}
	}	
	else
	{
		for(int i = 0; i < k; i++)
		{
			for(int j = 0; j < k; j++)
			{
				b[i][j] = rand() % count;
			}
		}
	}
	
	for(int i = 0; i < mat->n; i++)
	{
		for(int j = 0; j < mat->n; j++)
		{
			if(mat->size==1)
			{
				memcpy(mat->arr[i][j], &a[i][j], sizeof(int));
			}
			else
			{
				memcpy(mat->arr[i][j], &b[i][j], sizeof(float));
			}
		}
	}

	for(int i = 0; i < k; i++)
	{
			free(a[i]);
			free(b[i]);
	}
	free(a);
	free(b);
}
