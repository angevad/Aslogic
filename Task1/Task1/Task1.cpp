// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cmath>
#include "atlstr.h"
#include <iostream>

int CountZeroBits(CString *psString)
  {
  int nZerobits(0);

  int nStrSize = psString->GetLength ();
  BSTR pcStr = psString->AllocSysString ();

  for (int n (0); n < nStrSize; n++)
    {
    unsigned int uChar = pcStr[n];

    for (int shift = 0; shift < 32; shift ++)
      {
      if ((uChar & 1 << shift) == 0)
        nZerobits ++;
      }
    }

  return nZerobits;
  }

int CountZeroBitsQuick(CString *psString)
  {
  int nZerobits(0);

  int nStrSize = psString->GetLength ();
  BSTR pcStr = psString->AllocSysString ();
  UINT uBitMask[32];
  for (UINT i (0); i < 32; i++)
    uBitMask[i] = (UINT) pow (2.0, (double)i);

  for (int n (0); n < nStrSize; n++)
    {
    unsigned int uChar = pcStr[n];
 
    for (int shift = 0; shift < 32; shift ++)
      {
      if ((uChar & uBitMask[shift]) == 0)
        nZerobits ++;
      }
    }

  return nZerobits;
  }

int _tmain(int argc, _TCHAR* argv[])
  {
  using namespace std;
  
  //CString sStr("test");
  char chStr[255];

  std::cout << "Input string for calc zero bits in word.\n";
  std::cin >> chStr;
  CString sStr (chStr);
  std::cout << "Number of zero bits in word: " << CountZeroBits (&sStr) << "\n";

  std::cout << "Input string for calc zero bits in word(quick).\n";
  std::cin >> chStr;
  sStr = chStr;
  std::cout << "Number of zero bits in word: " << CountZeroBitsQuick (&sStr);
	return 0;
  }

