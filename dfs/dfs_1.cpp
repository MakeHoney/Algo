// #include <iostream>
#include <stdio.h>
#include <vector>

#define MAX 100

using namespace std;

vector<int> graph[MAX + 1];
bool visit[MAX];

void dfs(int start) {
    visit[start] = true;
    int next;
    for(int i = 0; i < graph[start].size(); i++) {
        next = graph[start][i];
        if(!visit[next]) dfs(next);
    }
}

int main(int argc, char** argv) {
    printf("%d", visit[50]);
    int m, u, v;

    scanf("%d", &m); // 간선의 개수
    
    for(int i = 0 ; i < m ; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
        // printf("%d %d\n", u, v);
    }

    dfs(1);
}
