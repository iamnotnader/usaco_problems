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
TASK: dualpal
*/

#define MAX_ARRAY_LEN 50

   int new_digits_array[MAX_ARRAY_LEN];

   int convert_to_diff_base(int number, int new_base)
   {
      for (int i = 0; i < MAX_ARRAY_LEN; i++)
         new_digits_array[i] = -1;
      int i, remainder;
      i = 0;
      while (number != 0)
      {
         remainder = number % new_base; 
         number = number / new_base; 
         new_digits_array[i] = remainder;
         i++;
      }
   }
   
   int number_length()
   {
      int i = 0;
      while (new_digits_array[i] != -1)
         i++;
   	
      return i;
   }
	
   bool check_palindrome()
   {
      int length = number_length();
      for (int i = 0; i < length; i++)
         if (new_digits_array[i] != new_digits_array[length - i - 1])
            return false;
      return true;
   }

   int main(void)
   {
      FILE *fin, *fout, *dict;
   
      fin = fopen("dualpal.in", "r");
      fout = fopen("dualpal.out", "w");
      assert(fin != NULL && fout != NULL);
      
      int N, S;
      fscanf(fin, "%d %d", &N, &S);
   
      int num_matches_found, current_num, num_bases_found;
      num_matches_found = 0;
      current_num = S+1;
   	
      while (num_matches_found < N)
      {
         num_bases_found = 0;
         for (int i = 2; i <= 10; i++)
         {
            convert_to_diff_base(current_num, i);
            if (check_palindrome())
               num_bases_found++;
            if (num_bases_found >= 2)
               break;
         }
         if (num_bases_found >= 2)
         {
            fprintf(fout, "%d\n", current_num);
            num_matches_found++;
         }
         current_num++;
      }
   
   
   	//fprintf(fout, "%s\n", valid_names[i]);
   	
      return 0;
   }