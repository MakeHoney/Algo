#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAX 10000
using namespace std;

vector<int> graph[MAX];
bool visit[MAX];
int num[1000], idx = -1;

void dfs(int start) {
    visit[start] = true;
    int next; 
    for(int i = 0; i < graph[start].size(); i++) {
        next = graph[start][i];
        if(!visit[next]) {
            num[idx]++;
            dfs(next);
        }
    }
}

int main() {
    char str[MAX];
    char tmp[30];
    int n, cnt = 0;

    scanf("%d", &n);
    int whole = n * n;
    for(int i = 0; i < n; i++) {
        scanf("%s", tmp);
        !i ? strcpy(str, tmp) : strcat(str, tmp); 
    }

    for(int i = 0; i < whole; i++) {
        if(str[i] == '0') continue;
        if(i % n != 0 && i >= 1 && str[i - 1] == '1') graph[i].push_back(i - 1);
        if(i >= n && str[i - n] == '1') graph[i].push_back(i - n);
        if((i + 1) % n != 0 && i < whole - 1 && str[i + 1] == '1') graph[i].push_back(i + 1);
        if(i < whole - n && str[i + n] == '1') graph[i].push_back(i + n);
    }
    for(int i = 0; i < whole; i++) {
        if(!visit[i] && str[i] == '1') {
            cnt++; idx++;
            dfs(i);
        }
    }

    printf("%d\n", cnt);
    sort(num, num + cnt);
    for(int i = 0; i < idx + 1; i++) {
        printf("%d\n", num[i] + 1);
    }
}