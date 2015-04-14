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
TASK: packrec
*/

struct rectangle
{
	int x;
	int y;
};

struct rectangle init_rect_arr[4];

int main(void)
   {
      FILE *fin, *fout;
   
      fin = fopen("packrec.in", "r");
      fout = fopen("packrec.out", "w");
      assert(fin != NULL && fout != NULL);
     
      fscanf(fin, "%d %d\n", &init_rect_arr[0].x, &init_rect_arr[0].y);
    	fscanf(fin, "%d %d\n", &init_rect_arr[1].x, &init_rect_arr[1].y);
   	fscanf(fin, "%d %d\n", &init_rect_arr[2].x, &init_rect_arr[2].y);
   	fscanf(fin, "%d %d\n", &init_rect_arr[3].x, &init_rect_arr[3].y);  
   	
      //fprintf(fout, "%d\n", unique_sol);
   	
      return 0;
   }
