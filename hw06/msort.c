#include "msort.h"
#include "student.h"
#include <stdio.h>

#ifndef OMIT_MSORT
void msort(Student * base, int nel, int (*compar)(const void *, const void *)) {
	
	//Base case: if the array has one or fewer elements, it's already sorted
	//so just return.

	//FILL IN
    if (nel <= 1)
        return;
    //Inductive case: split the array in two, sort the two pieces with msort,
	//merge the	sorted pieces

	//We're going to do this without explicitly creating the two separate arrays
	//We'll take advantage of the fact that to C, an array is just a pointer to
	//a region of memory. If we call msort on base, but pass in a smaller number
	//of elements, it will sort just that subarray. Similarly, if we call msort
	//but pass in the address of an element in the middle of the array, it will
	//sort the array *starting* from that element.
		
	//1. Find the midpoint of the array

	//FILL IN
  int m = nel / 2;
	//2a. Sort the first half of the array (remember to adjust the # elements)

    //0 1 2 3 4 5
	//FILL IN
   msort(base, m, compar);
	//2b. Sort the second half of the array. Pass in the address of the 
	//beginning of the second half of the array (remember to use the right # of 
	//elements)

	//FILL IN
	msort(base+m, (nel+1)/2, compar);
	//3a. Merge the two arrays (use merge)

	//FILL IN
	Student*newbase = merge(base,m, base + m, ((nel+1)/2), compar);
	//3b. Copy the merged array over top of the original array (use copy)
	//Don't forget to free the array you returned from merge -- you don't need it after the copy!

	//FILL IN
    copy(base, newbase, nel);
    free(newbase);
	return ;
}
#endif

#ifndef OMIT_MERGE
Student * merge(Student * base1, int nel1, Student * base2, int nel2, int (*compar)(const void *, const void *)) {

    //1. Allocate space for the returned merged array

    //FILL IN
    Student *newbase = malloc(sizeof(Student) * (nel1 + nel2));
    //2. Create indices to keep track of where you are in the three arrays

    //FILL IN
    int i = 0;
    int j = 0;
    int k = 0;
    //3. Go through base1 and base2, and merge them into the returned array
    while (k < (nel1+nel2))
    {
        if (i >= nel1)
        {
            newbase[k] = base2[j];
            j++;
        }
        else if (j >= nel2)
        {
            newbase[k] = base1[i];
            i++;
        }
        else if (compar(base1+i, base2+j) <= 0)
        {
            newbase[k] = base1[i];
            i++;
        }
            else
        {
                newbase[k] = base2[j];
                j++;
        }
            k++;
        }
        //4. Return the merged array

        //FILL IN
        return newbase;
    }


void copy(Student * to, Student * from, int nel) {
	/*
	An efficient implementation of this would use memcpy:
	memcpy(to, from, nel * width);

	We will do an element-by-element copy so you can see how it is done
	*/
	
	//loop over the from array and copy it byte by byte to the to array.
	for (int i = 0; i < nel; i++) {
		to[i] = from[i];
	}
	
	return;
}
#endif
