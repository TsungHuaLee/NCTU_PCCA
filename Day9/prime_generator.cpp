//prime generator ,spoj prime1
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<memory.h>
using namespace std;

long long int ncase;
vector<long long int> prime;
long long int ans[100100];
void build()
{
    prime.clear();
    prime.push_back(2);
    prime.push_back(3);
    prime.push_back(5);
    prime.push_back(7);
    prime.push_back(11);
    //precompute all primes smaller than sqrt(1e9)
    long long int sq = sqrt(1500000000);
    for(long long int i = 13; i < sq; i++)
    {
        bool isprime = true;
        for(long long int j = 0; prime[j]*prime[j] <= i; j++)
        {
            if(i % prime[j] == 0)
            {
                isprime = false;
                break;
            }
        }
        if(isprime)
            prime.push_back(i);
    }
    return ;
}

void compute(long long int left, long long int right)
{
    long long int dif = right - left, temp;
    for(int i = 0; i <= dif; i++)
    {
        ans[i] = 1; //set true
        temp = left + i;
        for(int j = 0; prime[j]*prime[j] <= temp; j++)
        {
            if(temp % prime[j] == 0)
            {
                ans[i] = 0;
                break;
            }
        }
    }
    if(left == 1)
        ans[0] = 0;
    for(int i = 0; i <= dif; i++)
        if(ans[i])
            cout<<i + left<<endl;
}
int main()
{
    build();
    cin>>ncase;
    while(ncase--)
    {
        long long int a,b;
        cin>>a>>b;
        compute(a,b);

    }
    return 0;
}
