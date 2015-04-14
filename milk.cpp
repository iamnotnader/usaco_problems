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
TASK: milk
*/

struct milk_man
{
	int price;
	int amount;
};

bool compare_milk_man(struct milk_man a, struct milk_man b)
{
	return a.price < b.price;
}

int main(void)
   {
      FILE *fin, *fout, *dict;
   
      fin = fopen("milk.in", "r");
      fout = fopen("milk.out", "w");
      assert(fin != NULL && fout != NULL);
      
      int N, M;
      fscanf(fin, "%d %d\n", &N, &M);
     	vector<struct milk_man> farmers(M);
     
     	int price, amount;  
   	for (int i = 0; i < M; i++)
   	{
   		fscanf(fin, "%d %d\n", &price, &amount);
   		farmers[i].price = price;
   		farmers[i].amount = amount;
   	}	
   	
   	sort(farmers.begin(), farmers.end(), compare_milk_man);
   	int total_price = 0;
   	
   	for (int i = 0; i < M; i++)
   	{
   		if (N < farmers[i].amount)
   		{
   			total_price += farmers[i].price * N;
   			N = 0;
   			break;
   		}
   		else
   		{
   			total_price += farmers[i].price * farmers[i].amount;
   			N -= farmers[i].amount;
   		}
   	}
   		
   	cout << total_price << endl;
   	fprintf(fout, "%d\n", total_price);
   	
      return 0;
   }