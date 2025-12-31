#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int time = 0, articulation[MAX], visited[MAX], low[MAX], dfn[MAX], parent[MAX];

void dfnlow(int u, int adj[MAX][MAX], int V) {
    int children = 0, v;
    visited[u] = 1;
    low[u] = dfn[u] = ++time;

    for (v = 0; v < V; v++) {
        if (!adj[u][v]) continue;
        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfnlow(v, adj, V);

            if (low[v] < low[u]) {
                low[u] = low[v];
            }

            if (parent[u] == -1 && children > 1) {
                articulation[u] = 1;
            }

            else if (parent[u] != -1 && low[v] >= dfn[u]) {
                articulation[u] = 1;
            }
        }

        else if (v != parent[u]) {
            if (dfn[v] < low[u]) {
                low[u] = dfn[v];
            }
        }
    }
}

void findArticulationPoints(int adj[MAX][MAX], int V) {
    int i;

    
}