#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/** INTERFACE FUNCTIONS **/

PathLL * buildPaths() {
	PathLL * retval = malloc(sizeof(PathLL));
	retval->head = NULL;
	return retval;
}

void freePaths(PathLL * p) {
	//fill in
    while(p -> head != NULL)
    {
        PathNode * n = p ->head ->next;
        freeNode(p -> head);
        p -> head = n;
    }
    free(p);
}

PathNode * buildNode(char * path) {
	//fill in
    PathNode * new = malloc(sizeof(PathNode));
    new -> path = malloc(sizeof(char) * (strlen(path) + 1));
	strcpy(new -> path, path);
    new -> next = NULL;
    return new;
    
	//WARNING: don't forget to use strcpy to copy path into the
	//new node. Don't just set them equal, otherwise if the input path changes
	//the node will have the wrong path.
}

void freeNode(PathNode * p) {
	//fill in
    free(p -> path);
    p -> next = NULL;
    free(p);
}

int countTurn(char * path)
{
    int t = 0;
    int i;
    for(i = 0; i < strlen(path); i ++)
    {
        if (path[i] != path[i + 1])
        {
            t ++;
        }
    }
    return t;
}

int comp(char * path1, char * path2)
{
    int ldiff = strlen(path1) - strlen(path2);
    int tdiff = countTurn(path1) - countTurn(path2);

    if (ldiff != 0)
    {
        return ldiff;
    }

    if (tdiff != 0)
    {
        return tdiff;
    }
    else
    {
        return strcmp(path1,path2);
    }

}


bool addNode(PathLL * paths, char * path) {
	
	//fill in
    PathNode * * ptr = &(paths->head);
    while ((* ptr != NULL) && ((comp((* ptr)->path, path) < 0))) {
        ptr = &((* ptr)->next);
    }

    if (((*ptr) != NULL) && !strcmp((*ptr)->path, path))
    {
        return false;
    }

    PathNode * newNode = buildNode(path);
    newNode->next = (*ptr);
    (*ptr) = newNode;

    return true;

}

bool removeNode(PathLL * paths, char * path)
{
  //fill in
  PathNode * n = paths -> head;
  while (n -> next != NULL)
  {
      if (n -> next -> path == path)
      {
          n -> next = n -> next -> next;
          freeNode(n -> next);
          return true;
      }
      n = n -> next;
  }
  return false;
}

bool containsNode(PathLL * paths, char * path) {
	//fill in
    PathNode * p = paths -> head;
    while (p != NULL)
    {
        if (strcmp(p -> path, path) == 0)
        {
            return true;
        }
        p = p -> next;
    }
    return false;
}

void printPaths(PathLL * paths, FILE * fptr) {
	PathNode * curr = paths->head;
	int i = 0;
	while (curr != NULL) {
		fprintf(fptr, "Path %2d: %s\n", i, curr->path);
		i++;
		curr = curr->next;
	}
}
