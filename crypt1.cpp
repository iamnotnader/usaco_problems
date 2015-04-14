#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <math.h>

   using namespace std;

/*
ID: iamnotnad1
LANG: C++
TASK: crypt1
*/
   bool nums[10];
   int num_set[10];
   int N;
   int crypt_nums[5];
   int product[5];
   int prod_len;
   int unique_sol = 0;
	//bool ALL_SOLUTIONS[98902];

   void convert_to_arr(int num3)
   {
      product[4] = num3/10000;
      num3 -= (num3/10000) * 10000;
      product[3] = num3/1000;
      num3 -= (num3/1000) * 1000;
      product[2] = num3/100;
      num3 -= (num3/100) * 100;
      product[1] = num3/10;
      num3 -= (num3/10) * 10;
      product[0] = num3;
      num3 -= num3;
   }

   void check_crypt()
   {
      int num1 = crypt_nums[0]*100 + crypt_nums[1]*10 + crypt_nums[2];
      int num2 = crypt_nums[3]*10 + crypt_nums[4];
   	if (num1*num2 > 9999)
   		return;
   	
      convert_to_arr(num1*crypt_nums[4]);
      if (	 nums[product[0]]
         &&  nums[product[1]]
         &&  nums[product[2]]
         &&  !product[3])
      {
         convert_to_arr(num1*crypt_nums[3]);
         if (nums[product[0]]
         &&  nums[product[1]]
         &&  nums[product[2]]
         &&  !product[3])
         {
            convert_to_arr(num1*num2);
            if (nums[product[0]]
            &&  nums[product[1]]
            &&  nums[product[2]]
            &&  nums[product[3]]
            &&  !product[4])
            //&&  (ALL_SOLUTIONS[num1*num2] == false))
            {
            	//ALL_SOLUTIONS[num1*num2] = true;
            	//cout << num1 << "\n " << num2 <<"\n " <<num1*crypt_nums[4]<<"\n"<<num1*crypt_nums[3]<<"\n"<< num1*num2 <<endl<< endl;
            	unique_sol++;
            }
         }
      }
         
         
   }

   void try_all_crypts(int index)
   {
      if (index == 5)
         check_crypt();
      else
      {
         for (int i = 0; i < N; i++)
         {
            crypt_nums[index] = num_set[i]; 
            try_all_crypts(index + 1);
         }
      }
   }

   int main(void)
   {
      FILE *fin, *fout;
   
      fin = fopen("crypt1.in", "r");
      fout = fopen("crypt1.out", "w");
      assert(fin != NULL && fout != NULL);
     
      fscanf(fin, "%d\n", &N);
   	
      for (int i = 0; i < 9; i++)
         nums[i] = false;
   	
      int read_number;
      for (int i = 0; i < N; i++)
      {
         fscanf(fin, "%d ", &read_number);
         nums[read_number] = true;
         num_set[i] = read_number;
      }
   	
   	//for (int i = 0; i < 98902; i++)
   	//	ALL_SOLUTIONS[i] = false;
   	
      try_all_crypts(0);
   	
   	//convert_to_arr(123);
   	//for (int i = 0; i < 5; i++)
   	//	cout << product[i] << endl;
   	
   	//cout << unique_sol << endl;
   	//for (int i = 0; i < 10; i++)
   		//cout << nums[i] << " " << endl;
   	//cout << endl;
   	
      fprintf(fout, "%d\n", unique_sol);
   	
      return 0;
   }
