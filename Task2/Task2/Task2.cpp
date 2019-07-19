// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <set>
#include <vector>
#include <iostream>

int FindFirstRepetedValue (std::vector <int> *pvArray)
  {
  using namespace std;
  set<int> ArraySet;
  
  for (vector<int>::iterator iter = pvArray->begin (); iter != pvArray->end (); iter++)
    {
    if ((ArraySet.insert (*iter)).second == false)
      return (*iter);
    }
  return (-1);
  }

int _tmain(int argc, _TCHAR* argv[])
  {
  using namespace std;
  const int N = 100;
  const int M = 1000;
  vector <int> vnArray;

  for (int n (0); n < N; n++)
    vnArray.push_back (rand () % M);

  cout<<"The first repeted value in array: " << FindFirstRepetedValue (&vnArray) << endl;

  cin.get ();
	return 0;
  }

