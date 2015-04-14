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
TASK: bisquare
*/

   set<int> i_hate_stl_sets;
   vector<struct sequence> sequence_vector;
   int N, M;
   
	struct sequence
	{
		int start;
		int dist;
	};

   void generate_all_bisquares(int index, int num_at)
   {
      if (index == 2)
      {
      //cout << num_at << endl;
         i_hate_stl_sets.insert(num_at);
         return;
      }
   
      for (int i = 0; i <= M; i++)
         generate_all_bisquares(index+1, num_at + i*i);
   }

   void find_all_progressions()
   {
      int current;
      bool found;
   	struct sequence temp;
   	//cout << M << " " << N << endl;
      for (int sum = 1; sum <= M*M*2/(N-1); sum++)
      {
      	if (sequence_vector.size() >= 10000)
      		break;
      	//cout << "SUM: " << sum << " ";
         for (int i = 0; i <= M*M*2-(N-1)*sum; i++)
         {
         	//cout << "STARTING NUMBER: " << i << " ";
         	//cout << endl;
         	found = true;
            current = i;
            for (int j = 0; j < N; j++)
            {
            	//cout << "LONGEST FOUND: " << j << " ";
            	//cout << current + sum*j << " ";
               if ((i_hate_stl_sets.find(current + sum*j)) == i_hate_stl_sets.end())
               {
               	found = false;
                  break;
               }
               //cout << endl;
            }
            if (found == true)
         	{
         		//cout << "GOT HIM!" << endl;
         		temp.start = i;
         		temp.dist = sum;
         		sequence_vector.push_back(temp);
         	}
         	//cout << endl;
         }
         //cout << endl;
      }
   }

   int main(void)
   {
      FILE *fin, *fout;
   
      fin = fopen("bisquare.in", "r");
      fout = fopen("bisquare.out", "w");
      assert(fin != NULL && fout != NULL);
     
     	//int N, M;
     
      fscanf(fin, "%d\n%d", &N, &M);
   			
      generate_all_bisquares(0, 0);
   	find_all_progressions();
   	
      //i_hate_stl_sets.insert(1);
      //set<int>::iterator it;
   	//for (it = i_hate_stl_sets.begin(); it != i_hate_stl_sets.end(); it++)
   		//cout << (*it) << endl;
   	
   	cout << sequence_vector.size() << endl;
   	for (unsigned int i = 0; i < sequence_vector.size(); i++)
   		fprintf(fout, "%d %d\n", sequence_vector[i].start, sequence_vector[i].dist);
   		//cout << sequence_vector[i].start << " " << sequence_vector[i].dist << endl;
   	
   	//	bisquare_vector.push_back((*it));
   	
   	//for (int i = 0; i < bisquare_vector.size(); i++)
   	//	cout << bisquare_vector[i] << endl;
   	
   	
      //fprintf(fout, "%d\n", unique_sol);
   	
      return 0;
   }
