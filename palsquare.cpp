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
TASK: palsquare
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
   
      fin = fopen("palsquare.in", "r");
      fout = fopen("palsquare.out", "w");
      assert(fin != NULL && fout != NULL);
      
      int base;
      fscanf(fin, "%d", &base);
      
   	for (int i = 1; i < 300; i++)
   	{
   		convert_to_diff_base(i*i, base);
   		if (check_palindrome())
   		{
   			convert_to_diff_base(i, base);
   			int length = number_length();
   			for (int j = 0; j < length; j++)
   			{
   				//cout << "GOTIT!" << endl;
   				if (new_digits_array[length-j-1] <= 9)
   					fprintf(fout, "%c", (new_digits_array[length-j-1] + 48));
   				else
   					fprintf(fout, "%c", (new_digits_array[length-j-1] + 55));
   			}
   			fprintf(fout, " ");
   			
   			convert_to_diff_base(i*i, base);
   			length = number_length();
   			for (int j = 0; j < length; j++)
   			{
   				//cout << "GOTIT!" << endl;
   				if (new_digits_array[length-j-1] <= 9)
   					fprintf(fout, "%c", (new_digits_array[length-j-1] + 48));
   				else
   					fprintf(fout, "%c", (new_digits_array[length-j-1] + 55));
   			}
   			fprintf(fout, "\n");
   		}
   	}
   	
   	
   	//fprintf(fout, "%s\n", valid_names[i]);
   	
      return 0;
   }
