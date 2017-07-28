//Longest Run on a Snowboard
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<memory.h>
#define MAX 10000
using namespace std;

int map[200][200];
int row, col,ans;

void traversal(int r, int c, int sum)
{
    if((map[r][c] < map[r][c+1]) &&( map[r][c] < map[r][c-1] )&& (map[r][c] < map[r+1][c]) && (map[r][c] < map[r-1][c]) )
    {
        if(ans < sum)
            ans = sum;
        return;
    }
    if(map[r][c] > map[r][c + 1])
    {
        traversal(r, c + 1, sum + 1);
    }
    if(map[r][c] > map[r][c - 1])
    {
        traversal(r, c - 1, sum + 1);
    }
    if(map[r][c] > map[r + 1][c])
    {
        traversal(r + 1, c, sum + 1);
    }
    if(map[r][c] > map[r - 1][c])
    {
        traversal(r - 1, c, sum + 1);
    }
    return;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--)
    {
        memset(map, MAX, sizeof(int)*200*200);
        char name[200] = {};
        scanf("%s %d %d", name, &row, &col);
        //outside infinite
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
                scanf("%d", &map[i][j]);
        ans = 0;
        //choose start
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
                traversal(i, j, 1);
        printf("%s: %d\n", name, ans);
    }
}
