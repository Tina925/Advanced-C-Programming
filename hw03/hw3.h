// ***
// *** You MUST modify this file.
// ***
#ifndef HW3_H
#define HW3_H

// declaring five functions to be integrated
double func1(double);
double func2(double);
double func3(double);
double func4(double);
double func5(double);

// Create a data type called funcptr for function pointers
// The type returns double and takes one double argument
// It must be called "funcptr" and must not use any other name.

typedef double (*funcptr)(double);// data type of funcptr for function pointers
// create a structure type that has the following attributes
// please make sure the names are exactly the same
//
// This type must be called Integration


typedef struct
{
    double upperlimit;
    double lowerlimit;
    int intervals;
    double answer;
    funcptr func;
} Integration;

// two functions to be implemented
void integrate(Integration * intrg);
bool  runIntegrate(char * infilename, char * outfilename);

#endif
