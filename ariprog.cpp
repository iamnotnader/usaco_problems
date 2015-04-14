#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <set>


   using namespace std;

/*
ID: iamnotnad1
LANG: C++
TASK: ariprog
*/

#define MAX_THING 250*250*2

   //set<int> i_hate_stl_sets;
   //vector<struct sequence> sequence_vector;
   bool vec[MAX_THING+1000];
   vector<int> bisquare_vector;//(250*250*2);
   int N, M;
   FILE *fin, *fout;
	int num_found = 0;

   void generate_all_bisquares(int index, int num_at)
   {
      if (index == 2)
      {
         vec[num_at] = true;
         return;
      }
   
      for (int i = 0; i <= M; i++)
         generate_all_bisquares(index+1, num_at + i*i);
   }

   void find_all_progressions()
   {
      int current;
      bool found;
   	//struct sequence temp;
   	//cout << M << " " << N << endl;
      for (int sum = 1; sum <= M*M*2/(N-1); sum++)
      {
      	//if (sequence_vector.size() >= 10000)
      	//	break;
      	//cout << "SUM: " << sum << " ";
         for (unsigned int i = 0; i < bisquare_vector.size(); i++)
         {
         	found = true;
         	//cout << current << endl;
            current = bisquare_vector[i];
         	
            for (int j = 0; j < N; j++)
            {
            	//cout << current + sum*j << " ";
            	if ((current + sum*j) >= (MAX_THING))
            	{
            		found = false;
            		break;
            	}
               if (!vec[current + sum*j])
               {
               	//cout <<"BAD: "<< current << " " << sum << endl;
               	found = false;
                  break;
               }
               //cout << endl;
            }
            if (found == true)
         	{
         		//cout << "GOT HIM!" << endl;
         		//cout <<"GOOD: "<< current << " " << sum << endl;
         		num_found++;
         		fprintf(fout, "%d %d\n", current, sum);
         	}
         	//cout << endl;
         }
         //cout << endl;
      }
   }

   int main(void)
   {
   
      fin = fopen("ariprog.in", "r");
      fout = fopen("ariprog.out", "w");
      assert(fin != NULL && fout != NULL);
     
     	//int N, M;
     
      fscanf(fin, "%d\n%d", &N, &M);
      
   	for (int i = 0; i < 250*250*2+1; i++)
   		vec[i] = false;
   			
      generate_all_bisquares(0, 0);
   	
   	for (int i = 0; i < 250*250*2+1; i++)
   		if (vec[i])
   			bisquare_vector.push_back(i);
   
   	//struct sequence temp;
   	//sequence_vector.push_back(temp);
   	
   	find_all_progressions();
   	
   	if (num_found == 0)
   		fprintf(fout, "NONE\n");
   	
   	cout << bisquare_vector.size() << " " << MAX_THING;
   	
   	//	bisquare_vector.push_back((*it));
   	
   	//for (int i = 0; i < bisquare_vector.size(); i++)
   	//	cout << bisquare_vector[i] << endl;
   	
   	
      //fprintf(fout, "%d\n", unique_sol);
   	
      return 0;
   }
