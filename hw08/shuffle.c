#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void printDeck(CardDeck deck)
{
    int ind;
    for (ind = 0; ind < deck.size; ind ++)
    {
        printf("%c ", deck.cards[ind]);
    }
    printf("\n");
}

void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
    int i;
    for (i=0; i<origDeck.size-1; i++)
    {
        leftDeck[i].size = i+1;
        memcpy(leftDeck[i].cards, origDeck.cards, (i+1) * sizeof(origDeck.cards[0]));

        rightDeck[i].size = origDeck.size-i-1;
        memcpy(rightDeck[i].cards, origDeck.cards+(i+1), (origDeck.size-i-1) * sizeof(origDeck.cards[0]));
    }
}

void recursiveInterleaveHelper(CardDeck leftDeck, int nLeft, CardDeck rightDeck, int nRight, CardDeck dest, int index, int round)
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
    shuffle(dest, round - 1);
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
    shuffle(dest, round -1);
    return;
  }

  dest.cards[index] = leftDeck.cards[nLeft];
  recursiveInterleaveHelper(leftDeck, nLeft - 1, rightDeck, nRight, dest, index - 1, round);

  dest.cards[index] = rightDeck.cards[nRight];
  recursiveInterleaveHelper(leftDeck, nLeft, rightDeck, nRight - 1, dest, index - 1, round);
}

void interleave(CardDeck leftDeck, CardDeck rightDeck, int round)
{
  CardDeck dest;
  dest.size = leftDeck.size + rightDeck.size;
  int nLeft = leftDeck.size - 1;
  int nRight = rightDeck.size -1;
  int index = rightDeck.size + leftDeck.size - 1;
  recursiveInterleaveHelper(leftDeck, nLeft, rightDeck, nRight, dest, index, round);
}

void shuffle(CardDeck origDeck, int round)
{

  if (round == 0)
  {
    printDeck (origDeck);
    return;
  }
  int numPoss = origDeck.size - 1;

  CardDeck *leftDeck = malloc(numPoss * sizeof(CardDeck));
  CardDeck *rightDeck = malloc(numPoss * sizeof(CardDeck));
  divide(origDeck, leftDeck, rightDeck);

  int i;
  for (i = 0; i < numPoss; i++)
  {
    interleave(leftDeck[i], rightDeck[i], round);
  }
  free(leftDeck);
  free(rightDeck);
}
