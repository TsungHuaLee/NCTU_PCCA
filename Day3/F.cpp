//cf 318a
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int input, k, middle = 0, ans;

    cin>>input>>k;

    if(input&1)
        middle = input/2 + 1;
    else
        middle = input/2;
    //k>middle even
    if(k > middle)
    {
        k -= middle;
        ans = k*2;
        cout<<ans<<endl;
    }
    else
    {
        ans = k*2 - 1;
        cout<<ans<<endl;
    }
    return 0;
}
