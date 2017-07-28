//cf 1a
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, m, a;
    cin>>n>>m>>a;
    long long int x, y;
    x = n / a;
    y = m / a;
    if(x*a != n)
        x++;
    if(y*a != m)
        y++;
    cout<<x*y<<endl;
    return 0;
}
