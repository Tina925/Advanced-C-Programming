// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
	
  // Note that from here on, you can access elements of the arr with
  // expressions like a[i]
	
  // initialize all elements
    int i;
    int kcount;
    int ncount;

  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
    for (i = 0; i < n; i++)
    {
        arr[i] = 1;
    }

    i = 0;
    kcount = 0;
    ncount = 0;
    while (ncount < n)
    {
        if (i >= n)
        {
            i = 0;
        }

        if (arr[i] == 0)
        {
            i++;
            continue;
        }

        //fprintf(stdout, "%d\n", i);
        kcount++;
        if(kcount >= k)
        {
            fprintf(stdout, "%d\n", i);
            arr[i] = 0;
            kcount = 0;
            ncount++;
        }
        i++;
    }
  // print the last one




  // release the memory of the array
  free (arr);
}
#endif
