#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Final Exam
Std ID : ***********
Name : MingyuKim
*/

//Please do not input spaces in file

//This program works on just 3 unknown variables. Sorry.
//This program cannot recognize 1 automatically. So you have to put 1. ( 1x+1y+1z=3 (O)  x+y+z=3(X) ) 
	//Ex)
	//50x+37y+1z=-44.39
	//-43x+39y+1z=45.31
	//52x+41y+1z =-44.96



//Global variables
float determinant = 0;
float mat[3][3];
float b[3];

float recursive(int a)  //Make determinant by using classical adjoint matrix.
{
	
	determinant = determinant + (mat[0][a] * (mat[1][(a + 1) % 3] * mat[2][(a + 2) % 3] - mat[1][(a + 2) % 3] * mat[2][(a + 1) % 3]));

	if (a == 2)
	{
		return determinant;
	}

	return recursive(a+1);
}

void main(void)
{
	//Open file by using pointer. File name = a.txt
	FILE* fp; 
	fp = fopen("a.txt", "r");
	
	//Input matrix
	fscanf(fp, "%f %*c %f %*c %f %*c %*c %f %f %*c %f %*c %f %*c %*c %f %f %*c %f %*c %f %*c %*c %f",
		&mat[0][0], &mat[0][1], &mat[0][2], &b[0],
		&mat[1][0], &mat[1][1], &mat[1][2], &b[1],
		&mat[2][0], &mat[2][1], &mat[2][2], &b[2]
	);

	//output matrix A.
	int i, j;
	puts("");
	printf("Matirx A))\n");
	for (i = 0; i < 3; i++)					
	{
		printf("\n");
		for (j = 0; j < 3; j++)
			printf("%f\t", mat[i][j]);
	}

	puts("");
	puts("");

	//output matrix b.
	printf("Matrix b))\n");
	for (i = 0; i < 3; i++)
	{
		puts("");
		printf("%.4f\t", b[i]);
	}

	//Determinant by using recursive function
	float result = 0;
	result = recursive(0);

	//If determinant value is 0, we can't find roots in matrix.	  
	if (result == 0)
	{
		printf("\n\nError. Determinant = 0\n");
	}
	else
	{
		printf("\n\nDeterminant : %f\n", result);
	}



	//Inverse of matrix.
	if (determinant != 0)
	{
		printf("\nInverse of matrix is : \n\n");
		
		for (i = 0; i < 3; i++)				//make inverse of matrix by using classical adjoint matrix.
		{
			for (j = 0; j < 3; j++)
				printf("%f\t", ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / determinant);
			printf("\n");
		}
	}
	puts("");


	//Find root
	float inverse[3][3];

	for (i = 0; i < 3; i++)				//make inverse of matrix by using classical adjoint matrix.
	{
		for (j = 0; j < 3; j++)
		{
			inverse[i][j] = (((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / determinant);
		}
	}

	float root[3];

	for (i = 0; i < 3; i++)
	{
		root[i] = inverse[i][0] * b[0] + inverse[i][1] * b[1] + inverse[i][2] * b[2];
	}

	if (determinant != 0)
	{
		printf("Roots))\n\n");
		printf("x = %f y = %f z = %f", root[0], root[1], root[2]);
	}
	
	
	puts("");

	fclose(fp);

	//Write the result in the same file.
	FILE* fpw;
	fpw = fopen("a.txt", "w");
	fprintf(fpw, "x = % f, y = % f, z = % f", root[0], root[1], root[2]);
		
	fclose(fpw);

	system("pause");
	
}


