#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "graph.h"

int main(void){
    graph g;
    int size = 0;
    int e1,e2;
    if (1 == scanf("%d", &size)){
        g = graph_new(size);
        while (2 == scanf("%d %d",&e1, &e2)){
            graph_add_edge(g,e1,e2);
        }
        graph_dfs(g);
        graph_print(g);
        graph_free(g);
    }
    return EXIT_SUCCESS;
}
