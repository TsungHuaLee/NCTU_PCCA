//cf 579a
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int x;
    cin>>x;
    long long int ans = 0;
    while(x)
    {
        int a = x&1;
        if(a)
            ans++;
        x= x>>1;
    }
    cout<<ans<<endl;
}
