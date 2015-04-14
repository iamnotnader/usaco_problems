#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <set>

/*
ID: iamnotnad1
LANG: C++
TASK: namenum
*/

   using namespace std;

   vector<char*> valid_names;

   bool fncomp (char* a, char* b) 
   {
      if (strcmp(a, b) < 0) 
         return true; 
      else 
         return false;
   }
   bool(*fn_pt)(char*,char*) = fncomp;
   set<char*,bool(*)(char*,char*)> dictionary (fn_pt);

//vector<char*> dictionary;
   char num_string[200]; 
   char test_string[200]; 
   char key_pad[8][3] = {{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};

   void enumerate_all_names(int char_at)
   {
      if (char_at == strlen(num_string))
      {
      	//cout << test_string << endl;
      //cout << test_string << endl;
         set<char*>::iterator it;
         it = dictionary.find(test_string);
         if (it != dictionary.end())
         {
            valid_names.push_back(*it);
         }
         return;
      }
      for (int i = 0; i < 3; i++)
      {
         test_string[char_at] = key_pad[num_string[char_at]-50][i];
         enumerate_all_names(char_at + 1);
      }
   }	

   int main(void)
   {
      FILE *fin, *fout, *dict;
   
   	bzero(num_string, 200);	
      bzero(test_string, 200);
   
      fin = fopen("namenum.in", "r");
      dict = fopen("dict.txt", "r");
      fout = fopen("namenum.out", "w");
      assert(fin != NULL && fout != NULL);
      unsigned long long num;
      fscanf(fin, "%s", num_string);
      
      char temp_word[200];
      char* word_to_push;
      while (!feof(dict) )
      {
         fscanf(dict, "%s\n", temp_word);
         word_to_push = (char*)malloc(strlen(temp_word)+1);
         strcpy(word_to_push, temp_word);
         dictionary.insert(word_to_push);
         //cout << dictionary.size() << endl;
      }
   	
      
      cout << num_string << endl;
      enumerate_all_names(0);
      if (valid_names.size() == 0)
         fprintf(fout, "%s\n", "NONE");
      //cout << valid_names.size() << endl; 
      for (unsigned int i = 0; i < valid_names.size(); i++)
         fprintf(fout, "%s\n", valid_names[i]);
   	
      return 0;
   }