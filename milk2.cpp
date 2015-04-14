#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>

/*
ID: iamnotnad1
LANG: C++
TASK: milk2
*/

   using namespace std;

   struct milk_man
   {
      int start;
      int end;
   };

   bool milk_man_cmp(struct milk_man a, struct milk_man b)
   {
      if (a.start > b.start)
         return false;
      else if (a.start < b.start)
         return true;
      else
      {
         if (a.end > b.end)
            return true;
         else if (a.end < b.end)
            return false;
         else
            return false;
      }
   }

   bool milkers_overlap(struct milk_man &a, struct milk_man &b)
   {
      if (a.start <= b.start && a.end >= b.start
      ||  a.start <= b.end && a.end >= b.end)
      {
         return true;
      }
      else
         return false;
   }


   int main(void)
   {
      FILE *fin, *fout;
      int i, n, m;
   
      fin = fopen("milk2.in", "r");
      fout = fopen("milk2.out", "w");
      assert(fin != NULL && fout != NULL);
   
      int N;
      fscanf(fin, "%d", &N);
   
      vector <struct milk_man> men(N);
   
      for (int i = 0; i < N; i++)
      {
         fscanf(fin, "%d", &(men[i].start));
         fscanf(fin, "%d", &(men[i].end));
      //fprintf(fout, "%d, %d\n", men[i].start, men[i].end);
      }
      sort(men.begin(), men.end(), milk_man_cmp);
   
      int low, high, max_milking, max_idle;
      low = men[0].start;
      high = men[0].end;
      max_milking = max_idle = 0;
      struct milk_man current_milker = men[0];
   
      for (int i = 0; i < N-1; i++)
      {
         //cout <<"l: " << low << " h: " << high << endl;
         if (milkers_overlap(current_milker, men[i+1]))
         {
            //cout << "true" << endl;
            high = max(current_milker.end, men[i+1].end);
            if (high == men[i+1].end)
               current_milker = men[i+1];
            if (high - low > max_milking)
               max_milking = high-low;
         }
         else
         {
            if (high - low > max_milking)
               max_milking = high-low;
         	
            if (men[i+1].start - high > max_idle)
               max_idle = (men[i+1].start - high);
         		
            current_milker = men[i+1];
            low = current_milker.start;
            high = current_milker.end;
         }
      }
      if (current_milker.end - current_milker.start > max_milking)
         max_milking = current_milker.end - current_milker.start;
   
      //printf("%d %d\n", max_milking, max_idle);
      fprintf(fout, "%d %d\n", max_milking, max_idle);
      return 0;
   }