//cf 546b
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int num[10000] = {};
    int temp, ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        if(!num[temp])
            num[temp]++;
        else
        {
            temp++;
            ans++;
            while(num[temp] != 0)
            {
                ans++;
                temp++;
            }
            num[temp]++;
        }
    }

    cout<<ans<<endl;
}
