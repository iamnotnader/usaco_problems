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
TASK: barn1
*/

   struct empty_group
   {
      int start_pos;
      int num_empty;
   };

   bool compare_empty_groups(struct empty_group a, struct empty_group b)
   {
      return a.num_empty > b.num_empty;
   }

   int main(void)
   {
      FILE *fin, *fout;
   
      fin = fopen("barn1.in", "r");
      fout = fopen("barn1.out", "w");
      assert(fin != NULL && fout != NULL);
      
      int M, S, C;
      fscanf(fin, "%d %d %d\n", &M, &S, &C);
     
      bool cows[S];
     	
     	
      for (int i = 0; i < S; i++)
         cows[i] = false;
   	
      int cow_stall, first_cow, last_cow;
      for (int i = 0; i < C; i++)
      {
         fscanf(fin, "%d\n", &cow_stall);
         cows[cow_stall-1] = true;
      } 	
   	
      for (int i = 0; i < S; i++)
         if (cows[i] == true)
         {
            first_cow = i;
            break;
         }
      for (int i = S-1; i >= 0; i--)
         if (cows[i] == true)
         {
            last_cow = i;
            break;
         }
		
		cout << first_cow << " " << last_cow << endl;	
		
      vector<struct empty_group> empty_groups;
      bool in_empty_group = false;
      for (int i = 0; i < S; i++)
      {
         if (!in_empty_group)
         {
            if (cows[i] == false)
            {
               in_empty_group = true;
               struct empty_group temp;
               temp.start_pos = i;
               temp.num_empty = 1;
               empty_groups.push_back(temp);
            }
         }
         else
         {
            if (cows[i] == false)
               empty_groups[empty_groups.size() - 1].num_empty++;
            else
               in_empty_group = false;
         }
      }
    
      if (cows[0] == false)
      {
         cout << "accounting for first cow" << endl;
         empty_groups.erase(empty_groups.begin());
      }
      if (cows[S-1] == false)
      {
         cout << "accounting for last cow" << endl;
         empty_groups.erase(empty_groups.end() - 1);
      }
    
      sort(empty_groups.begin(), empty_groups.end(), compare_empty_groups);
    
      for (unsigned int i = 0; i < empty_groups.size(); i++)
         cout << empty_groups[i].num_empty << endl;
    
      int num_blocked = S - first_cow - (S - last_cow - 1);
		cout << "we start w/: " << num_blocked << endl;
      for (int i = 0; i < min(M-1, (int)(empty_groups.size())); i++)
      {
			cout << ".. " << num_blocked << endl; 
         num_blocked -= empty_groups[i].num_empty;
      }	
   	
      cout << num_blocked << endl;
      fprintf(fout, "%d\n", num_blocked);
   	
      return 0;
   }