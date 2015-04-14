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
TASK: clocks
*/
#define MAX_DEPTH 1000

   int clocks[9];
   int path[MAX_DEPTH];

   int moves[9][6] = {{0,1,3,4,-1,-1},
   						 {0,1,2,-1,-1,-1},
   						 {1,2,4,5,-1,-1},
   						 {0,3,6,-1,-1,-1},
   						 {1,3,4,5,7,-1},
   						 {2,5,8,-1,-1,-1},
   						 {3,4,6,7,-1,-1},
   						 {6,7,8,-1,-1,-1},
   						 {4,5,7,8,-1,-1}};
   int num_tried[9] = {0,0,0,0,0,0,0,0,0};
   int min_array[9] = {0,0,0,0,0,0,0,0,0};
   int min_found = 0xfffffff;
   int combos = 0;
	
   void rotate_clock(int clock_number)
   {
      if (clocks[clock_number] == 12)
         clocks[clock_number] = 3;
      else
         clocks[clock_number] += 3;
   }
	
   void un_rotate_clock(int clock_number)
   {
      if (clocks[clock_number] == 3)
         clocks[clock_number] = 12;
      else
         clocks[clock_number] -= 3;
   }
	
   void apply_move(int move_index)
   {
      int i = 0;
      while (moves[move_index][i] != -1)
      {
         rotate_clock(moves[move_index][i]);
         i++;
      }
   }
	
   void un_apply_move(int move_index)
   {
      int i = 0;
      while (moves[move_index][i] != -1)
      {
         un_rotate_clock(moves[move_index][i]);
         i++;
      }
   }
	
   bool is_solution()
   {
      for (int i = 0; i < 9; i++)
         for (int j = 0; j < num_tried[i]; j++)
            apply_move(i);
   
      for (int i = 0; i < 9; i++)
         if (clocks[i] != 12)
         {
            for (int i = 0; i < 9; i++)
               for (int j = 0; j < num_tried[i]; j++)
                  un_apply_move(i);
            return false;
         }
   	
      for (int i = 0; i < 9; i++)
         for (int j = 0; j < num_tried[i]; j++)
            un_apply_move(i);
         
   	
      for (int i = 0; i < 9; i++)
         //cout << clocks[i] << endl;	
      return true;
   }
	
   void copy_over_array()
   {
      for (int i = 0; i < 9; i++)
         min_array[i] = num_tried[i];
   }
	
   void dfs(int index, int num_on)
   {
      for (int i = 0; i < 9; i++)
         //cout << num_tried[i] << " ";
      //cout << endl;
   	
		if (num_on > min_found)
          return;
		
      if (index == 9)
      {
         if (is_solution())
         {
            min_found = num_on;
            copy_over_array();
         }
			return;
      }
      for (int i = 0; i < 4; i++)
      {
         num_tried[index] = i;
         dfs(index+1, num_on + i);
      }
   }

   int main(void)
   {
      FILE *fin, *fout;
   
      fin = fopen("clocks.in", "r");
      fout = fopen("clocks.out", "w");
      assert(fin != NULL && fout != NULL);
     	
      for (int i = 0; i < 3; i++)
         fscanf(fin, "%d %d %d\n", &clocks[0+3*i], &clocks[1+3*i], &clocks[2+3*i]);
   	
      for (int i = 0; i < MAX_DEPTH; i++)
         path[i] = -1;
   	
      dfs(0, 0);
   	
      vector<int> temp;
      for (int i = 0; i < 9; i++)
         for (int j = 0; j < min_array[i]; j++)
         {
            temp.push_back(i);
         }
      
      if (temp.size() == 0)
         fprintf(fout, "\n");	
   	
      for (unsigned int i = 0; i < temp.size() - 1; i++)
         fprintf(fout, "%d ", temp[i]+1);
      fprintf(fout, "%d\n", temp[temp.size()-1]+1);
   	
      //fprintf(fout, "%d\n", unique_sol);
   	
      return 0;
   }
