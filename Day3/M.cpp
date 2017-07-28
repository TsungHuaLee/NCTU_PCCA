//cf 486a
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int ans = 0;
    long long int n;
    cin>>n;
    ans += n/2;
    if(n&1)
        ans -= n;
    cout<<ans<<endl;
}
