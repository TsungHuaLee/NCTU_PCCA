//flowers
#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

int dp[100100];
int table[100100];
int ncase, k;
long long int a,b;

void init()
{
    table[0] = dp[0] = 1;
    for(int i = 1; i < k; i++)
    {
        dp[i] = 1;
        table[i] = (table[i - 1] + dp[i])%MAX;
    }
    dp[k] = 2;
    table[k] = (table[k - 1] + dp[k])%MAX;

    for(int i = k + 1; i <= 100100; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - k]) % MAX;
        table[i] = (table[i - 1] + dp[i]) % MAX;
    }

    return;
}

int main()
{
    cin>>ncase>>k;
    init();

    while(ncase--)
    {
        cin>>a>>b;
        int count;
        count = (table[b] - table[a - 1]) % MAX;
        // (100 - 29)%15 = 11  !=  (100%15)- (29%15) = -4
        if(count < 0)
            count +=MAX;
        cout<<count<<endl;
    }
}
