// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//TODO Delete define
#define TEST_COUNTINT
#define TEST_READINT
#define TEST_COMPAREINT
#define TEST_WRITEINT

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1
  int currInt;
  int intCount = 0;

  FILE * fRead = fopen(filename, "r");
  if ( fRead == NULL)
  {
    return -1;
  }

  while (fscanf(fRead, "%d\n", &currInt) == 1)
  {
    intCount++;
  }

  // remember to fclose if fopen succeeds
  fclose(fRead);
  return intCount;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  int currInt;
  int intCount = 0;

  FILE * fRead = fopen(filename, "r");
  if ( fRead == NULL)
  {
    return false;
  }


  while (fscanf(fRead, "%d\n", &currInt) == 1)
  {
    if (intCount >= size)
      return false;

    intArr[intCount] = currInt;
    intCount++;
  }

  if (intCount < size)
    return false;

  // remember to fclose if fopen succeeds
  fclose(fRead);

  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
  return (* (int *)p1 - * (int *)p2);
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  // 
  // fclose and return true
  FILE * fWrite = fopen(filename, "w");
  if ( fWrite == NULL)
  {
    return false;
  }

  int i;
  for(i=0; i<size; i++)
  {
    fprintf(fWrite, "%d\n", intArr[i]);
  }

  fclose(fWrite);
  return true;

}
#endif

