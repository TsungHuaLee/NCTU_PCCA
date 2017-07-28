//cf 469a
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,q;
    cin>>n;
    int X[1000] = {}, Y[1000] = {}, ans[1000] = {}, temp;

    cin>>p;
    for(int i = 0; i < p ; i++)
    {
        cin>>temp;
        ans[temp]++;
    }
    cin>>q;
    for(int i = 0; i < q; i++)
    {
        cin>>temp;
        ans[temp]++;
    }
    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        if(!ans[i])
        {
            flag = false;
            cout<<"Oh, my keyboard!\n";
            return 0;
        }
    }
    cout<<"I become the guy.\n";
}
