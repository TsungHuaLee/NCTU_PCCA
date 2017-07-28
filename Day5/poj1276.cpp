//cash machine
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    long long int target, N;
    while(scanf("%lld%lld", &target, &N)!=EOF)
    {

        int num, value;
        vector<long long int>bi;

        long long int temp;
        for(int i = 0; i < N; i++)
        {
            scanf("%d%d", &num, &value);
        //    cout<<"i = "<<i<<endl;
            for(int j = 1; num > 0 ; j <<= 1)
            {
                if(j > num)
                    j = num;
                num -= j;
                temp = j*value;
                if(temp <= target)
                    bi.push_back(temp);
        //        cout<<j<<" * "<<value<<" = "<<j*value<<endl;
            }
        }
        long long int dp[100100] = {};
        for(int i = 0; i < bi.size(); i++)
        {
            //從小的開始跑,會重複算-->從大的看
            for(int j = target; j >= bi[i]; j--)
                dp[j] = max(dp[j], dp[j - bi[i]] + bi[i]);
        }
        printf("%d\n", dp[target]);
    }
}
