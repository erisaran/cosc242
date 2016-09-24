#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "graph.h"

typedef enum { UNVISITED, VISITED_SELF, VISITED_DESCENDANTS } state_t;
typedef enum {UNDIRECTED, DIRECTED } direct_t;

static int step;

struct graphrec {
    int size;
    vertex *vertices;
    int **edges;
    direct_t type;
};

struct vertexrec {
    state_t state;
    int predecessor;
    int distance;
    int finish;
    int s;
    int number;
    vertex *adjacent;
};

vertex vertex_new(int num,int max){
    int i;
    vertex v = emalloc(sizeof *v);
    v->state = UNVISITED;
    v->predecessor = -1;
    v->distance = -1;
    v->finish = 0;
    v->s = max;
    v->number = num;
    v->adjacent = emalloc(max * sizeof v->adjacent[0]);
    for (i = 0; i < max; i ++){
        v->adjacent[i] = NULL;
    }
    return v;
}

graph graph_new(int v){
    int i,r;
    graph g = emalloc(sizeof *g);
    g->size = v;
    g->type = DIRECTED;
    g->edges = emalloc(v * sizeof g->edges[0]);
    for (i = 0; i < v; i ++){
        g->edges[i] = emalloc(v * sizeof g->edges[0][0]);
        for (r = 0; r < v; r++){
            g->edges[i][r] = 0;
        }
    }
    g->vertices = emalloc(v * sizeof g->vertices[0]);
    for (i = 0; i < v; i ++){
        g->vertices[i] = vertex_new(i,g->size);
    }
    return g;
}

void graph_free(graph g){
    int i = 0;
    for (i = 0; i < g->size; i ++){
        free(g->edges[i]);
    }
    for (i = 0; i < g->size; i ++){
        free(g->vertices[i]->adjacent);
        free(g->vertices[i]);
    }
    free(g->edges);
    free(g->vertices);
    free(g);
}

void add_undirected(graph g, int v, int connect_to){
    g->edges[v][connect_to] = 1;
    g->edges[connect_to][v] = 1;
}

void add_directed(graph g, int v, int connect_to){
    g->edges[v][connect_to] = 1;
    g->vertices[v]->adjacent[connect_to] = g->vertices[connect_to];
}

void graph_add_edge(graph g, int v, int connect_to){
    if (g->type == UNDIRECTED){
        add_undirected(g, v, connect_to);
    }else {
        add_directed(g, v, connect_to);
    }
}

void visit(vertex v){
    int i;
    vertex u;
    v->state = VISITED_SELF;
    step ++;
    v->distance = step;
    for (i = 0; i < v->s; i++){
        if (v->adjacent[i] != NULL){
            u = v->adjacent[i]; 
            if (u->state == UNVISITED){
                u->predecessor = v->number;
                visit(u);
            }
        }
    }
    step++;
    v->state = VISITED_DESCENDANTS;
    v->finish = step;
}

void graph_dfs(graph g){
    int i;
    step = 0;
    for (i = 0; i < g->size; i ++){
        if (g->vertices[i]->state == UNVISITED){
            visit(g->vertices[i]);
        }
    }
}

void graph_print(graph g){
    int r,c;
    int b4 = 0;
    for (r = 0; r < g->size; r ++){
        printf("%d | ",r);
        for (c = 0; c < g->size; c ++){
            if (g->edges[r][c] > 0){
                if (b4 == 1){
                    printf(", ");
                }
                b4 = 1;
                printf("%d", g->vertices[c]->number);
            }
        }
        b4 = 0;
        printf("\n");
    }
    printf("\n");
    printf("vertex distance pred finish\n");
    for (r = 0; r < g->size; r ++){
        printf("%3d %8d %5d %5d\n", r, g->vertices[r]->distance,
               g->vertices[r]->predecessor, g->vertices[r]->finish);
    }
}
            
