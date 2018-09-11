#include <stdio.h>
#include <vector>

#define MAX 2000
using namespace std;

vector<int> graph[MAX];
bool visit[MAX];
bool flag;

void dfs(int start) {
    visit[start] = true;

    int next;
    for(int i = 0; i < graph[start].size(); i++) {
        next = graph[start][i];
        if(!visit[next]) dfs(next);
    }
}

int main() {
    int v, testCase, node;
    int cnt = 0;
    scanf("%d", &testCase);

    for(int k = 0; k < testCase; k++) {
        scanf("%d", &node);
        flag = false; cnt = 0;
        for(int i = 1; i <= node; i++) {
            scanf("%d", &v);
            graph[i].push_back(v);
        }

        for(int i = 1; i <= node; i++) {
            /* 그래프 개수 구할 때 */
            if(!visit[i]) cnt++;
            dfs(i); // <- if안에 넣기
        }
        for(int i = 1; i <= node; i++) {
            graph[i].clear();
            visit[i] = false;
        }
        printf("%d\n", cnt);
    }
}