#ifndef GRAPH_H_
#define GRAPH_H_
typedef struct vertexrec *vertex;
typedef struct graphrec *graph;
extern graph graph_new(int v);
extern void graph_free(graph g);
extern void graph_print(graph g);
extern void graph_add_edge(graph g, int v, int connect_to);
extern void graph_bfs(graph g, int source);

#endif
