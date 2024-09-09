// ***
// *** You must modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//TODO Delete
#define TEST_DIVIDE
#define TEST_INTERLEAVE
#define TEST_SHUFFLE

// do not modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  //printDeck(origDeck);
  //printf("%d\n", origDeck.size);

  int i;
  for (i=0; i<origDeck.size-1; i++)
  {
    //leftDeck[i].size = MAX_SIZE;
    leftDeck[i].size = i+1;
    memcpy(leftDeck[i].cards, origDeck.cards, (i+1) * sizeof(origDeck.cards[0]));

    //rightDeck[i].size = MAX_SIZE;
    rightDeck[i].size = origDeck.size-i-1;
    memcpy(rightDeck[i].cards, origDeck.cards+(i+1), (origDeck.size-i-1) * sizeof(origDeck.cards[0]));
  }


/*
*/
}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.

// A 2 | 3 4

// 1 1 0 0
// 1 0 1 0
// 1 0 0 1
// 0 1 1 0
// 0 1 0 1
// 0 0 1 1

// A 2 3 | 4 5 6

// 1 1 1 0 0 0
// 1 1 0 1 0 0
// 1 1 0 0 1 0
// 1 1 0 0 0 1
// 1 0 1 1 0 0
// 1 0 1 0 1 0
// 1 0 1 0 0 1
// 0 1 1 1 0 0
// 0 1 1 0 1 0
// 0 1 1 0 0 1

//void recrusiveInterleaveHelper(CardDeck * leftDeck, CardDeck * rightDeck, CardDeck * dest);

void recursiveInterleaveHelper(CardDeck leftDeck, int nLeft, CardDeck rightDeck, int nRight, CardDeck dest, int index)
{
    //Repeat this process: merge the rest of the left deck with the right deck into the open spots on the output deck
    if (nLeft < 0)
    {
      int newindex;
      for(newindex = 0; newindex <= nRight; newindex++)
      {
        dest.cards[newindex] = rightDeck.cards[newindex];
//        index--;
      }
      printDeck(dest);
      return;

    }
    if (nRight < 0)
    {
      int newindex;
      for(newindex = 0; newindex <= nLeft; newindex++)
      {
        dest.cards[newindex] = leftDeck.cards[newindex];
//        index--;
      }
      printDeck(dest);
      return;
    }

    dest.cards[index] = leftDeck.cards[nLeft];
    recursiveInterleaveHelper(leftDeck, nLeft - 1, rightDeck, nRight, dest, index - 1);
    dest.cards[index] = rightDeck.cards[nRight];
    recursiveInterleaveHelper(leftDeck, nLeft, rightDeck, nRight - 1, dest, index - 1);
}

void interleave(CardDeck leftDeck, CardDeck rightDeck)
{
      CardDeck dest;
      dest.size = leftDeck.size + rightDeck.size;
      int nLeft = leftDeck.size - 1;
      int nRight = rightDeck.size -1;
      int index = rightDeck.size + leftDeck.size - 1;
      recursiveInterleaveHelper(leftDeck, nLeft, rightDeck, nRight, dest, index);
  //printDeck(* shuffled);
}
#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck)
{
  int numPoss = origDeck.size - 1;

  CardDeck *leftDeck = malloc(numPoss * sizeof(CardDeck));
  CardDeck *rightDeck = malloc(numPoss * sizeof(CardDeck));

  divide(origDeck, leftDeck, rightDeck);

  int i;
  for (i = 0; i < numPoss; i++)
  {
    interleave(leftDeck[i], rightDeck[i]);
  }
}
#endif
