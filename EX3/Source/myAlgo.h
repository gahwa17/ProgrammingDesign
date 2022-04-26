#ifndef myAlgo_H
#define myAlgo_H

#define MAX_algorithm 2
#define MAX_person 1000

typedef int BOOL;

extern char algo_name[][10];
extern int relation_map[][MAX_person];

/**********************************************************
 *_map_init: Initialize friendship map.                   *
 **********************************************************/
void _map_init();

/**********************************************************
 *algo_init: Initialize visited[] for DFS/BFS.            *
 **********************************************************/
void algo_init();

BOOL _DFS(int now_person, int to_find);
BOOL _BFS(int ini_person, int to_find);

#endif