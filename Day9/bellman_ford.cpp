//bellman ford, hdu2544
#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstdio>
#define MAX 1e9
using namespace std;
int N, M, ans,dp[110];
typedef struct MAP
{
    int sour;
    int dest;
    int value;
}Map;

vector<Map>map;
void init()
{
    map.clear();
    for(int i = 0; i < 110; i++)
        dp[i] = MAX;
    int s,t,v;
    Map temp;
    for(int i = 0; i < M; i++)
    {
        cin>>temp.sour>>temp.dest>>temp.value;
        if(temp.sour == 1)
            dp[temp.dest] = temp.value;
        if(temp.dest == 1)
            dp[temp.sour] = temp.value;

        map.push_back(temp);
        swap(temp.sour,temp.dest);
        map.push_back(temp);
    }

    return;
}
void bellmanford()
{   //1 ~ N-1
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < map.size(); j++)
        {
        //    printf("dp[%d] = %d v.s. dp[%d] = %d + %d \n", map[j].dest, dp[map[j].dest], map[j].sour,dp[map[j].sour], map[j].value);
            if(dp[map[j].dest] > (dp[map[j].sour] + map[j].value))
                dp[map[j].dest] = dp[map[j].sour] + map[j].value;
        }
    }
    cout<<dp[N]<<endl;
}
int main()
{
    while(cin>>N>>M)
    {
        if(N == 0 && M == 0)
            return 0;
        init();
        bellmanford();
    }

}
