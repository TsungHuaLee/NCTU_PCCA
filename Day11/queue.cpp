//queue CodeForces 545D
#include<bits/stdc++.h>
using namespace std;
int N;

void sol()
{
    priority_queue<long long int, vector<long long int>, greater<long long int> > que;
    for(int i = 0; i < N; i++)
    {
        long long int a;
        cin>>a;
        que.push(a);
    }
    long long int accu = 0, count = 0;
    for(int i = 0; i < N; i++)
    {
        long long int temp;
        temp = que.top(); que.pop();
        if(temp >= accu)
        {
            accu +=temp;
            count++;
        }
    }
    cout<<count<<endl;
}
int main()
{
    cin>>N;
    sol();
}
