//almost prime
#include<bits/stdc++.h>
using namespace std;
vector<int>prime;

void buildtable()
{
    prime.clear();
    prime.push_back(2);
    prime.push_back(3);
    prime.push_back(5);
    prime.push_back(7);
    prime.push_back(11);
    int numPrime = 5;
    for(int i = 13; i < 4000; i++)
    {// from 13 to 4000, find prime number
        bool isprime = true;
        for(int j = 0; prime[j] * prime[j] <= i; j++) // 搜尋範圍到開根號
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
}

void sol()
{
    int N;
    cin>>N;
    int ans = 0;
    for(int i = 2; i <= N; i++) //2 ~ N, 每個做質因數分解
    {
        int two = 0;    //題目要剛好質因數個數為2的
        for(int j = 0; prime[j] <= i && j < prime.size(); j++)
        {
            if(i % prime[j] == 0)
                two++;
        }
        if(two == 2){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    buildtable();
    sol();
    return 0;
}
