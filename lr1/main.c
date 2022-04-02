#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "app.h"

int main()
{
	matrix* mat = malloc(sizeof(matrix));
	matrix* mat1 = malloc(sizeof(matrix));
	matrix* rez_sum = malloc(sizeof(matrix));
	matrix* rez_mult = malloc(sizeof(matrix));
	matrix* rez_mult_scalar = malloc(sizeof(matrix));
	
	int n, k = 0, h =0, l = 0, b = 0;
	int j = 0, s = 0, m = 0, p = 0;
	int scalari;
	float scalarf;
	while(k != 1)
	{
		printf("1)Input matrix\n2)Generate matrix\n3)Output matrix\n4)Sum matrix\n5)Mult matrix\n6)Mult scalar matrix\n7)Exit\n->:");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				if(j!=0)
				{
					matrix_destroy(mat);
					mat = malloc(sizeof(matrix));
					printf("Last matrix destroed\n");
				}
				input_stdin(mat);
				output_matrix(mat);
				j++;
				break;
			case 2:
				if(j!=0)
				{
					matrix_destroy(mat);
					mat = malloc(sizeof(matrix));
					printf("Last matrix destroed\n");
				}
				generate_matrix(mat);
				output_matrix(mat);
				j++;
				break;
			case 3:
				h = 0;
				while(h != 1)
				{
					printf("1)Output input matrix\n2)Output rez_sum matrix\n3)Output rez_mult matrix\n4)Output rez_mult_scalar matrix\n5)Exit\n->");
					scanf("%d", &b);
					if((b==1)&&(j!=0))
						output_matrix(mat);
					else
					{	
						if((j==0)&&(b==1))
						{
							printf("You cant output this matrix, need first input her!\n");
						}
						if((b==2)&&(s!=0))
							output_matrix(rez_sum);
						else
						{
							if((s==0)&&(b==2))
							{
								printf("You cant output this matrix, need first count rez_sum!\n");
							}
							if((b==3)&&(m!=0))
								output_matrix(rez_mult);
							else			
							{
								if((m==0)&&(b==3))
								{
									printf("You cant output this matrix, need first count rez_mult!\n");
								}
								if((b==4)&&(p!=0))	
									output_matrix(rez_mult_scalar);
								else
									if((p==0)&&(b==4))
									{
										printf("You cant output this matrix, need fisrt count rez_mult_scalar!\n");
									}
							}
						}
					}		
					if(b==5)
						h = 1;
				}
				break;
			case 4:
				if(s!=0)
				{
					mat1 = malloc(sizeof(matrix));
					matrix_destroy(rez_sum);
					printf("REZ_SUM MATRIX DESTROED\n");
					rez_sum = malloc(sizeof(matrix));
				}
				if((m!=0)&&(s==0))
					mat1 = malloc(sizeof(matrix));
					
				rez_sum = matrix_sum(mat, mat1, rez_sum);
				matrix_destroy(mat1);
				printf("Rez_sum: ");
				output_matrix(rez_sum);
				s++;
				break;
			case 5:
				if(m!=0)
				{
					mat1 = malloc(sizeof(matrix));
					matrix_destroy(rez_mult);
					printf("REZ_MULT MATRIX DESTROED\n");
					rez_mult = malloc(sizeof(matrix));
				}
				if((s!=0)&&(m==0))
					mat1 = malloc(sizeof(matrix));
					
				rez_mult = matrix_mult(mat, mat1, rez_mult);
				matrix_destroy(mat1);
				printf("Rez_mult: ");
				output_matrix(rez_mult);
				m++;
				break;
			case 6:
				printf("Enter scalar(int or float):\n1)int\n2)float\n->");
				scanf("%d", &l);
				if(l==1)
				{
					printf("Enter scalar:");
					scanf("%d", &scalari);
					rez_mult_scalar = matrix_mult_scalar_int(mat, rez_mult_scalar, scalari);
				}
				else
				{
					printf("Enter scalar:");
					scanf("%f", &scalarf);
					rez_mult_scalar = matrix_mult_scalar_float(mat, rez_mult_scalar, scalarf);
				}
				output_matrix(rez_mult_scalar);
				p++;
				break;
			case 7:
				printf("Exit succesfull\n");
				k = 1;
				if(j!=0)
					matrix_destroy(mat);
				else
					free(mat);
				if(s!=0)
					matrix_destroy(rez_sum);
				else
				{
					free(rez_sum);
				}
				if(m!=0)
					matrix_destroy(rez_mult);
				else
				{
					free(rez_mult);
				}	
				if(p!=0)
					matrix_destroy(rez_mult_scalar);
				else
				{
					free(rez_mult_scalar);
				}
				if((s==0)&&(m==0)&&(p==0))
					free(mat1);
				break;
			default:
				printf("ERROR INPUT!\n");
				break;
		}
	}
	return 0;
}
