#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>

/*
ID: iamnotnad1
LANG: C++
TASK: transform
*/

   using namespace std;

   void rotate_clock_ninety(int** matrix, int N)
   {
      int temp[N][N];
   	
      for (int i = 0; i < N; i++)
         for (int j = 0; j < N; j++)
            temp[j][N-i-1] = matrix[i][j];
   	
      for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
         {
            matrix[i][j] = temp[i][j];
            //printf("%c", matrix[i][j]);
         }
         //cout << endl;
      }
   }
	
   void rotate_counter_ninety(int** matrix, int N)
   {
      int temp[N][N];
   	
      for (int i = 0; i < N; i++)
         for (int j = 0; j < N; j++)
            temp[i][j] = matrix[j][N-i-1];
   	
      for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
         {
            matrix[i][j] = temp[i][j];
            //printf("%c", matrix[i][j]);
         }
         //cout << endl;
      }
   }
	
   void reflect_horizontal(int** matrix, int N)
   {
      int temp[N][N];
   	
      for (int i = 0; i < N; i++)
         for (int j = 0; j < N; j++)
            temp[i][j] = matrix[i][N-j-1];
   	
      for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
         {
            matrix[i][j] = temp[i][j];
            //printf("%c", matrix[i][j]);
         }
         //cout << endl;
      }
   }

	
   bool same_matrix(int** matrix_a, int** matrix_b, int N)
   {
      for (int i = 0; i < N; i++)
         for (int j = 0; j < N; j++)
            if (matrix_a[i][j] != matrix_b[i][j])
               return false;
      return true;
   }

   int main(void)
   {
      FILE *fin, *fout;
   
      fin = fopen("transform.in", "r");
      fout = fopen("transform.out", "w");
      assert(fin != NULL && fout != NULL);
   
      int N;
      fscanf(fin, "%d", &N);
   	
      int** start_matrix;
      int** end_matrix;
      bool is_transformation = false; 	
   	
      start_matrix = (int**)malloc(N * sizeof(int*));
      for (int i = 0; i < N; i++)
         start_matrix[i] = (int*)malloc(N * sizeof(int));
   	
      end_matrix = (int**)malloc(N * sizeof(int*));
      for (int i = 0; i < N; i++)
         end_matrix[i] = (int*)malloc(N * sizeof(int));
   	
   
      fscanf(fin, "\n");
      for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
         {
            fscanf(fin, "%c", &(start_matrix[i][j]));
            //printf("%c", start_matrix[i][j]);
         }
         fscanf(fin, "\n");
         //printf("\n");
      }
   	
      for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
         {
            fscanf(fin, "%c", &(end_matrix[i][j]));
         	//printf("%c", end_matrix[i][j]);
         }
         fscanf(fin, "\n");
      	//printf("\n");
      }
   	
      //cout << same_matrix(start_matrix, start_matrix, N) << endl;
      //cout << same_matrix(start_matrix, end_matrix, N) << endl;
   	
   	//Check 90 deg rotation
      rotate_clock_ninety(start_matrix, N);
      if (same_matrix(start_matrix, end_matrix, N))
      {
         is_transformation = true;
         fprintf(fout, "%d\n", 1);
      }
   	//Check 180 deg rotation
      rotate_clock_ninety(start_matrix, N);
      if (same_matrix(start_matrix, end_matrix, N) && !is_transformation)
      {
         is_transformation = true;
         fprintf(fout, "%d\n", 2);
      }
   	//Check 270 deg rotation
      rotate_clock_ninety(start_matrix, N);
      if (same_matrix(start_matrix, end_matrix, N) && !is_transformation)
      {
         is_transformation = true;
         fprintf(fout, "%d\n", 3);
      }
   	//Return to start matrix.
      rotate_clock_ninety(start_matrix, N);
    
    	//Check horizontal reflection
      reflect_horizontal(start_matrix, N);
      if (same_matrix(start_matrix, end_matrix, N) && !is_transformation)
      {
         is_transformation = true;
         fprintf(fout, "%d\n", 4);
      } 
   	
   	//Check combination
   	//Check combo 90 deg rotation
      rotate_clock_ninety(start_matrix, N);
      if (!is_transformation)
      {
         if (same_matrix(start_matrix, end_matrix, N))
         {
            is_transformation = true;
            fprintf(fout, "%d\n", 5);
         }
      //Check combo 180 deg rotation
         rotate_clock_ninety(start_matrix, N);
         if (same_matrix(start_matrix, end_matrix, N))
         {
            is_transformation = true;
            fprintf(fout, "%d\n", 5);
         }
      //Check combo 270 deg rotation
         rotate_clock_ninety(start_matrix, N);
         if (same_matrix(start_matrix, end_matrix, N))
         {
            is_transformation = true;
            fprintf(fout, "%d\n", 5);
         }
      }		
   	
   	//Return to reflected matrix.
      rotate_clock_ninety(start_matrix, N);
   	//Return to start matrix
      reflect_horizontal(start_matrix, N);
   	
   	
   	//Check no change
      if (same_matrix(start_matrix, end_matrix, N) && !is_transformation)
      {
         is_transformation = true;
         fprintf(fout, "%d\n", 6);
      }
   	
      if (!is_transformation)
         fprintf(fout, "%d\n", 7);
   	
      return 0;
   }