#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "mazehelper.h"
#include "path.h"
#include "list.h"

PathLL * solveMaze(Maze * m) {
	
	PathLL * successPaths = buildPaths();
	char * retval = malloc(((m->height * m->width) + 1) * sizeof(char));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	depthFirstSolve(m, mp, retval, 0, successPaths);
	
	free(retval);
	
	return successPaths;
}

void depthFirstSolve(Maze * m, MazePos curpos, char * path, int step, PathLL * successPaths)
{
	
  //Fill in. (Your best bet is to modify a working implementation from PA08)
    if (atEnd(curpos, m))
    {
        path[step] = '\0';
        if (!containsNode(successPaths, path))
        {
            addNode(successPaths, path);
        }
        return;
    }
    if (!squareOK(curpos, m))
    {
        return;
    }
    m->maze[curpos.ypos][curpos.xpos].visited = true;

    char direction[4] = {'n', 's', 'e', 'w'};
    MazePos steps[4] = {{.xpos= curpos.xpos, .ypos = curpos.ypos - 1},
                        {.xpos= curpos.xpos, .ypos = curpos.ypos + 1},
                        {.xpos= curpos.xpos + 1, .ypos = curpos.ypos},
                        {.xpos= curpos.xpos - 1, .ypos = curpos.ypos}};
//
    int i;

    for (i = 0; i < 4; i++)
    {
        path[step] = direction[i];
        depthFirstSolve(m, steps[i], path, step + 1, successPaths);
    }
    m->maze[curpos.ypos][curpos.xpos].visited = false;
    return;
}
