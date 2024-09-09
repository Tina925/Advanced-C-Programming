// ***
// *** You MUST modify this file.
// ***
#include <stdio.h>
#include <stdbool.h>
#include "hw3.h"

// must enclose the function by #ifdef TEST_INTEGRATE 
// and #endif to enable particial credits
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  // integrate the function stored in intrg's func
  // store the result in intrg's answer
  int i;
  double newVal;
  double sum = 0;
  double integral;
  double subwidth;

  subwidth = ((intrg->upperlimit - intrg->lowerlimit)/intrg->intervals);

  for (i = 1; i < intrg ->intervals ; i ++)
  {
      newVal = intrg ->lowerlimit + i*subwidth;
      sum = sum + intrg->func(newVal);
  }

  integral = subwidth / 2.0 * (intrg ->func(intrg ->lowerlimit) + 2 * sum + intrg -> func(intrg ->upperlimit));
  intrg ->answer = integral;

}
  #endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE
// and #endif to enable particial credits

#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{

  // open the input file name for reading
    FILE * fRead = fopen(infilename, "r");

  // if fopen fails, return false
    if ( fRead == NULL)
    {
        return false;
    }


  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  Integration intrg;
  if (fscanf(fRead, "%lf\n", &intrg.lowerlimit) != 1)
  {
    fclose(fRead);
    return false;
  }

  //printf("lower limit is: %lf\n", intrg.lowerlimit);

  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  if (fscanf(fRead, "%lf\n", &intrg.upperlimit) != 1)
  {
    fclose(fRead);
    return false;
  }

  //printf("upper limit is: %lf\n", intrg.upperlimit);



  // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  if (fscanf(fRead, "%d\n", &intrg.intervals) != 1)
  {
    fclose(fRead);
    return false;
  }


  //printf("intervals is: %d\n", intrg.intervals);

  // close the input file
  fclose(fRead);






  // open the output file for writing
  // if fopen fails, return false
  FILE * fWrite = fopen(outfilename, "w");
  if ( fWrite == NULL)
  {
    return false;
  }


  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5
  funcptr funcs[5] = {func1, func2, func3, func4, func5};

  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf

  // check the return value of fprintf.
  // If it is less one one, close the output
  // file and return false

  int i;
  for(i=0; i<5; i++)
  {
    intrg.func = funcs[i];
    integrate(&intrg);
    if (fprintf(fWrite, "%lf\n", intrg.answer) < 1)
    {
      fclose(fWrite);
      return false;
    }
  }









  // after going through all functions in funcs
  // close the output file
  fclose(fWrite);






  // if the function reaches here, return true




  return true;
}
#endif // RUN_INTEGRATE
