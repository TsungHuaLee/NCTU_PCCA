//PolandBall and Forest
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>edge[10100];
bool visit[10100];
void init()
{
    for(int i = 0; i < 10010; i++)
    {
        edge[i].clear();
        visit[i] = false;
    }
}
void DFS(int point)
{
    visit[point] = true;
    for(int i = 0; i < edge[point].size(); i++)
        if(!visit[edge[point][i]])
            DFS(edge[point][i]);
    return;
}
void sol()
{
    int N,temp;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &temp);
        edge[i].push_back(temp);
        edge[temp].push_back(i);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
        if(!visit[i])
            {
                ans++;
                DFS(i);
            }
    }
    printf("%d\n", ans);
}

int main()
{
    init();
    sol();
}
