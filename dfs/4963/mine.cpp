#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX 3000
using namespace std;

vector<int> graph[MAX];
bool visit[MAX];

void dfs(int start) {
    visit[start] = true;

    int next = 0;
    for(int i = 0; i < graph[start].size(); i++) {
        next = graph[start][i];
        if(!visit[next]) dfs(next);
    }
}

int main() {
    int w, h, whole = 0, cnt = 0;
    char str[MAX];
    char tmp[51];


    while(true) {
        scanf("%d %d", &w, &h);
        whole = w * h;
        cnt = 0;
        if(!w) break;
        for(int i = 0; i < whole; i++) {
            scanf("%s", tmp);
            !i ? strcpy(str, tmp) : strcat(str, tmp);
        }

        for(int i = 0; i < whole; i++) {
            if(str[i] == '0') continue;
            if(i % w != 0 && i >= 1 && str[i - 1] == '1')
                graph[i].push_back(i - 1);
            if((i + 1) % w != 0 && i < whole - 1 && str[i + 1] == '1')
                graph[i].push_back(i + 1);
            if(i >= w && (str[i - w] == '1' || str[i - w + 1] == '1'))
                if(str[i - w] == '1')
                    graph[i].push_back(i - w);
                else if((i + 1) % w != 0)
                    graph[i].push_back(i - w + 1);
            if(i < whole - w && (str[i + w] == '1' || str[i + w - 1] == '1'))
                if(str[i + w] == '1')
                    graph[i].push_back(i + w);
                else if(i % w != 0)
                    graph[i].push_back(i + w - 1);
            if(i % w != 0 && i > w &&  str[i - w - 1] == '1')
                graph[i].push_back(i - w - 1);
            if((i + 1) % w != 0 && i < whole - w - 1 && str[i + w + 1] == '1')
                graph[i].push_back(i + w + 1);
        }

        for(int i = 0; i < whole; i++) {
            if(!visit[i] && str[i] == '1') {
                cnt++;
                dfs(i);
            }
        }

        printf("%d\n", cnt);
        memset(str, 0x00, MAX);
        memset(visit, 0x00, MAX);
        for(int i = 0; i < MAX; i++) graph[i].clear();
    }
}