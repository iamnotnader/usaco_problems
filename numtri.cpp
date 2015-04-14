#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

   using namespace std;

/*
ID: iamnotnad1
LANG: C++
TASK: numtri
*/
#define MAX_ROW 1000

   int prev_row[MAX_ROW];
   int this_row[MAX_ROW];
   int R, temp;

   void copy_over_array()
   {
      temp = 0;
      while (this_row[temp] != 0)
		{
         prev_row[temp] = this_row[temp];
			temp++;
		}
   }

   int main()
   {
      FILE *fin, *fout;
   
      fin = fopen("numtri.in", "r");
      fout = fopen("numtri.out", "w");
   
      assert(fin != NULL && fout != NULL);
   
      fscanf(fin, "%d\n", &R);
   	
      for (int i = 0; i < MAX_ROW; i++)
         this_row[i] = prev_row[i] = 0;
   
      for (int i = 0; i < R+1; i++)
		{
			copy_over_array();
         for (int j = 0; j < i; j++)
         {
				////cout << "before.." << endl;
            if (j == 0)
            {
               fscanf(fin, "%d", &(this_row[j]));
					//cout << "CASE1 "<< this_row[j]<<" "<<prev_row[j]<<endl;
               this_row[j] += prev_row[j];
            }
            else if (j == (i-1))
            {
               fscanf(fin, "%d", &(this_row[j]));
     				//cout<<"CASE2 "<<this_row[j]<<" "<<prev_row[j-1]<<endl;     
					this_row[j] += prev_row[j-1];
            }
            else
            {
               fscanf(fin, "%d", &(this_row[j]));
					//cout<<"CASE3 "<<this_row[j]<<" "<<max(prev_row[j-1], prev_row[j])<<endl;
               this_row[j] += max(prev_row[j-1], prev_row[j]);
            }
         }
		}
  		
		////cout << "here!" << endl;
		int max = 0; 	
   	for (int i = 0; i < R; i++)
		{
			//cout << this_row[i] << endl;
			if (max < this_row[i])
				max = this_row[i];
		}
		//cout << max << endl;
		fprintf(fout, "%d\n", max);
   }