#include "hw2.h"
#include "stdio.h"

double integrate1(Range rng)
{
  int i;
  double newVal;
  double sum = 0;
  double integral;
  double subwidth;

  /*
  printf("lowerlimit is: %f\n", rng.lowerlimit);
  printf("upperlimit is: %f\n", rng.upperlimit);
  printf("intervals is: %d\n", rng.intervals);
  */


  subwidth = ((rng.upperlimit - rng.lowerlimit)/rng.intervals);

  for (i = 1; i < rng.intervals ; i ++)
  { 
     newVal = rng.lowerlimit + i*subwidth;
     sum = sum+func(newVal);
  }
  
  integral = subwidth / 2.0 * (func(rng.lowerlimit) + 2 * sum + func(rng.upperlimit));
   
  return integral;

   /* Fill in for Part 1 */

}

void integrate2(RangeAnswer * rngans)
{
  rngans -> answer = integrate1(rngans -> rng);

    /* Fill in for Part 2 */

}
