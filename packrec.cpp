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
TASK: packrec
*/

   struct rectangle
   {
      int x;
      int y;
   };
	
   bool fncomp(struct rectangle a,struct rectangle b)
   {
      if (a.x == b.x)
         return a.y < b.y;
      else
         return a.x < b.x;
   }

   struct rectangle init_rect_arr[4];
   struct rectangle scratch_array[4];
   int w1, w2, w3, w4, h1, h2, h3, h4;
   bool rects_tried[4];
   int min_area = 0xfffffff;
	//set<struct rectangle> winners;
   bool(*fn_pt)(struct rectangle,struct rectangle) = fncomp;
   set<struct rectangle,bool(*)(struct rectangle,struct rectangle)> winners (fn_pt);
	//int num_tried = 0;

   void check_rectangle()
   {
   	//num_tried++;
      //cout << min_area << " " << num_tried<< endl;
      int area, x, y;
      struct rectangle temp;
   	
      w1 = scratch_array[0].x;
      w2 = scratch_array[1].x;
      w3 = scratch_array[2].x;
      w4 = scratch_array[3].x;
   	
      h1 = scratch_array[0].y;
      h2 = scratch_array[1].y;
      h3 = scratch_array[2].y;
      h4 = scratch_array[3].y;
   	
   	//rect 1
      x = (w1+w2+w3+w4);
      y = max(max(max(h1, h2), h3), h4);
      area = x * y;
      if (area < min_area)
      {
         //cout << "1" << endl;
         min_area = area;
         if (x < y)
         {
            temp.x = x;
            temp.y = y; 
         }
         else
         {
            temp.x = y;
            temp.y = x; 
         }
         winners.clear();
         winners.insert(temp);
      }
      else if (area == min_area)
      {
         if (x < y)
         {
            temp.x = x;
            temp.y = y; 
         }
         else
         {
            temp.x = y;
            temp.y = x; 
         }
         winners.insert(temp);
      }
   	
   	//rect 2
		x = max(w1+w2+w3, h4);
		y = (max(max(h1, h2), h3) + w4);
      area = x * y;
      if (area < min_area)
      {
         //cout << "2" << endl;
         min_area = area;
         if (x < y)
         {
            temp.x = x;
            temp.y = y; 
         }
         else
         {
            temp.x = y;
            temp.y = x; 
         }
         winners.clear();
         winners.insert(temp);
      }
      else if (area == min_area)
      {
         if (x < y)
         {
            temp.x = x;
            temp.y = y; 
         }
         else
         {
            temp.x = y;
            temp.y = x; 
         }
         winners.insert(temp);
      }
   		
   	//rect 3
		x = (max(w1+w2, h4) + w3);
		y = max(max(h1, h2) + w4, h3);
      area =  x * y;
      if (area < min_area)
      {
         //cout << "3" << endl;
         min_area = area;
         if (x < y)
         {
            temp.x = x;
            temp.y = y; 
         }
         else
         {
            temp.x = y;
            temp.y = x; 
         }
         winners.clear();
         winners.insert(temp);
      }
      else if (area == min_area)
      {
         if (x < y)
         {
            temp.x = x;
            temp.y = y; 
         }
         else
         {
            temp.x = y;
            temp.y = x; 
         }
         winners.insert(temp);
      }
   	
   	//rect 4
		x = (max(w1,w2) + w3 + w4);
		y = max(max(h1+h2, h3), h4);
      area = x * y;
      if (area < min_area)
      {
         //cout << "4" << endl;
         //cout << area << endl;
         //cout << w1 << " " << w2 << " " << w3 << " " << w4 << endl;
         //cout << h1 << " " << h2 << " " << h3 << " " << h4 << endl;
         min_area = area;
         if (x < y)
         {
            temp.x = x;
            temp.y = y; 
         }
         else
         {
            temp.x = y;
            temp.y = x; 
         }
         winners.clear();
         winners.insert(temp);
      }
      else if (area == min_area)
      {
         if (x < y)
         {
            temp.x = x;
            temp.y = y; 
         }
         else
         {
            temp.x = y;
            temp.y = x; 
         } 
         winners.insert(temp);
      }
   	
   	//rect 5
      if (h3 >= h2
      &&  w1 <= w2)
      {
			x = max(w1+h4, w2+w3);
			y = max(h1+h2, h3+w4);
         area = x * y;
         if (area < min_area)
         {
            //cout << "5" << endl;
            //cout << area << endl;
            //cout << w1 << " " << w2 << " " << w3 << " " << w4 << endl;
            //cout << h1 << " " << h2 << " " << h3 << " " << h4 << endl;
            min_area = area;
            if (x < y)
         {
            temp.x = x;
            temp.y = y; 
         }
         else
         {
            temp.x = y;
            temp.y = x; 
         }
            winners.clear();
            winners.insert(temp);
         }
         else if (area == min_area)
         {
            if (x < y)
         {
            temp.x = x;
            temp.y = y; 
         }
         else
         {
            temp.x = y;
            temp.y = x; 
         }
            winners.insert(temp);
         }
      }
   }

   void try_all_permutations(int depth)
   {
      if (depth == 4)
         check_rectangle();
   
      for (int i = 0; i < 4; i++)
      {      
         if (rects_tried[i] == false)
         {
            rects_tried[i] = true;
         
            scratch_array[depth] = init_rect_arr[i];
            try_all_permutations(depth+1);
         
            scratch_array[depth].x = init_rect_arr[i].y;
            scratch_array[depth].y = init_rect_arr[i].x;
            try_all_permutations(depth+1);
         	
            rects_tried[i] = false;
         }
      }
   }

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
   	
      try_all_permutations(0);
   
   	//cout << "The winners: " << endl;	
      fprintf(fout, "%d\n", min_area);
      set<struct rectangle>::iterator it;
      for (it=winners.begin(); it != winners.end();)
      {
         int x = (*it).x;
         int y = (*it).y;
         if (x < y)
            fprintf(fout, "%d %d\n", x, y);
         else
            fprintf(fout, "%d %d\n", y, x);
         while ((x == (*it).x) && (y == (*it).y))
            it++;
      }
      //cout << min_area << endl;
      //fprintf(fout, "%d\n", unique_sol);
   	
      return 0;
   }
