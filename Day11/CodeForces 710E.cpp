#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int target, onetime, copytime;
    cin>>target>>onetime>>copytime;
    long long int *dp;
    dp = (long long int*)malloc(sizeof(long long int)*10000100);
    dp[1] = onetime;
    for(long long int i = 2; i <= target; i++)
    {
        long long int first = dp[i - 1] + onetime;
        long long int second = dp[i/2] + copytime;
        if(i&1)
            second = min(dp[(i - 1) / 2] + copytime + onetime, dp[(i + 1) / 2] + copytime + onetime);
        dp[i] = min(first, second);
    }
    cout<<dp[target]<<endl;
}
