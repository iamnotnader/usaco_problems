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
TASK: calfflac
*/

#define MAX_ARRAY_LENGTH 20001

   char input[MAX_ARRAY_LENGTH];
   char full_text[MAX_ARRAY_LENGTH];
   
   struct palindrome
   {
      int index;
      int length;
   };
	
   bool is_palindrome(int pos, int len)
   {
      for (int i = 0; i < len/2; i++)
         if (input[pos + i] != input[pos + len - i - 1])
            return false;
      return true;
   }
	
   int main(void)
   {
      FILE *fin, *fout;
   
      fin = fopen("calfflac.in", "r");
      fout = fopen("calfflac.out", "w");
      assert(fin != NULL && fout != NULL);
      
      //int M, S, C;
      //fscanf(fin, "%d %d %d\n", &M, &S, &C);
   	
      int full_length = 0;
      while ((full_text[full_length] = fgetc(fin)) != EOF)
         full_length++;
      
      full_text[full_length] = -1;
      full_text[full_length+1] = 0;
      
      int length = 0;
      int temp_len = 0;
      while (full_text[temp_len] != -1)
      {
         if (isalpha(full_text[temp_len]))
         {
            input[length] = tolower(full_text[temp_len]);
            length++;
         }
         temp_len++;
      }
   	
      input[length] = -1;
      input[length+1] = 0;
   	
      for (int i = 0; i < full_length; i++)
         cout << full_text[i];
      cout << endl;
   	
   	
      int max = 0;
      int index = 0;
      int jump = 0;
      for (int i = 0; i < length; i++)
      {
         for (int j = max; j < length-i+1; j++)
         {
            if (is_palindrome(i, j))
            {
               jump = j-1;
               if (j > max)
               {	
                  max = j;
                  index = i;
               }
            }
         }
         i+=jump;
         jump = 0;
      }
   		 
   	
      for (int i = 0; i < length; i++)
         cout << input[i];
      cout << endl;
   			
      cout << index << " " << max << endl;
     
      int index_of_longest = 0;
      for (int i = 0; i <= index; i++)
      {
         while (!isalpha(full_text[index_of_longest]))
         {
         	//printf("%c", full_text[index_of_longest]);
            index_of_longest++;
         }
      	//printf("%c", full_text[index_of_longest]);
         index_of_longest++;
      }
      index_of_longest--; 	
   
      int num_to_add = 0;
      for (int i = 0; i <= max-1; i++)
      {
         while (!isalpha(full_text[index_of_longest+i+num_to_add]))
         {
            printf("%c", full_text[index_of_longest+i+num_to_add]);
            num_to_add++;
         }
      }
   	
      cout << endl;
      cout << num_to_add << endl;
      full_text[index_of_longest+max+num_to_add] = 0;
   
      fprintf(fout, "%d\n%s\n", max, full_text+index_of_longest);
   	
      return 0;
   }