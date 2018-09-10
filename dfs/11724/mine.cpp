#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX 1000

using namespace std;

vector<int> graph[MAX + 1];
vector<int> index;
bool visit[MAX];
bool flag;

void dfs(int start) {
    if(!visit[start]) flag = true;

    int next;
    visit[start] = true;
    for(int i = 0; i < graph[start].size(); i++) {
        next = graph[start][i];
        if(!visit[next]) dfs(next);
    }
}

int main() {
    int n, m, u, v;
    int cnt = 0;
    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < m ; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
        index.push_back(u);
        index.push_back(v);
    }

    sort(index.begin(), index.end());
    index.erase(unique(index.begin(), index.end()), index.end());

    for(int i = 0 ; i < index.size() ; i++) {
        dfs(index[i]);
        if(flag) {
            flag = false;
            cnt++;
        }
    }
    if(index.size() < n) cnt += n - index.size();

    printf("%d\n", cnt);
}