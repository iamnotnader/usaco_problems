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
TASK: milk3
*/

#define GLASS_A 0
#define GLASS_B 1
#define GLASS_C 2
#define MAX_CAPACITY 21

int current_state[3], capacity[3];
bool has_occurred[MAX_CAPACITY][MAX_CAPACITY][MAX_CAPACITY];
bool possible_values[MAX_CAPACITY];
int amount;

void pour_milk(int from, int to)
{
	amount = current_state[from];
	if (current_state[to] + amount > capacity[to])
		amount = capacity[to] - current_state[to];

	current_state[from] -= amount;
	current_state[to] += amount;	
}

void try_all()
{
	if (has_occurred[current_state[GLASS_A]]
						 [current_state[GLASS_B]]
						 [current_state[GLASS_C]])
		return;
	
	has_occurred[current_state[GLASS_A]]
	   			[current_state[GLASS_B]]
					[current_state[GLASS_C]] = true;
	if (current_state[GLASS_A] == 0)
		possible_values[current_state[GLASS_C]] = true;
	
	int a_before = current_state[GLASS_A];
	int b_before = current_state[GLASS_B];
	int c_before = current_state[GLASS_C];
	for (int i = 0; i < 3; i++)
	{
		pour_milk(GLASS_C, GLASS_A);
		try_all();
		current_state[GLASS_A] = a_before;
		current_state[GLASS_B] = b_before;
		current_state[GLASS_C] = c_before;
		
		pour_milk(GLASS_C, GLASS_B);
		try_all();
		current_state[GLASS_A] = a_before;
		current_state[GLASS_B] = b_before;
		current_state[GLASS_C] = c_before;
		
		pour_milk(GLASS_B, GLASS_A);
		try_all();
		current_state[GLASS_A] = a_before;
		current_state[GLASS_B] = b_before;
		current_state[GLASS_C] = c_before;
		
		pour_milk(GLASS_B, GLASS_C);
		try_all();
		current_state[GLASS_A] = a_before;
		current_state[GLASS_B] = b_before;
		current_state[GLASS_C] = c_before;
		
		pour_milk(GLASS_A, GLASS_B);
		try_all();
		current_state[GLASS_A] = a_before;
		current_state[GLASS_B] = b_before;
		current_state[GLASS_C] = c_before;
		
		pour_milk(GLASS_A, GLASS_C);
		try_all();
		current_state[GLASS_A] = a_before;
		current_state[GLASS_B] = b_before;
		current_state[GLASS_C] = c_before;
	}
}

int main(void)
   {
      FILE *fin, *fout;
   
      fin = fopen("milk3.in", "r");
      fout = fopen("milk3.out", "w");
      assert(fin != NULL && fout != NULL);
     
      fscanf(fin, "%d %d %d", &(capacity[GLASS_A]), &(capacity[GLASS_B]), &(capacity[GLASS_C]));  
  		current_state[GLASS_A] = current_state[GLASS_B] = 0;
		current_state[GLASS_C] = capacity[GLASS_C];		
		 	
		try_all();
		
		vector<int> temp_vector;
		for (int i = 0; i < MAX_CAPACITY; i++)
			if (possible_values[i])
				temp_vector.push_back(i);
   	
		if (temp_vector.size() == 0)
			fprintf(fout, "NONE\n");
		
		for (unsigned int i = 0; i < temp_vector.size() - 1; i++)
		{
			cout << temp_vector[i] << " ";
			fprintf(fout, "%d ", temp_vector[i]);
		}
		cout << temp_vector[temp_vector.size()-1] << "\n";
		fprintf(fout, "%d\n", temp_vector[temp_vector.size()-1]);
      return 0;
   }
