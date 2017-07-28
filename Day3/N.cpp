//cf 34b
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, m;
    long long int ans = 0;
    cin>>n>>m;
    int temp, numneg = 0 ;
    long long int neg[1000] = {};
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        if(temp < 0)
        {
            neg[numneg] = temp;
            numneg++;
        }
    }
    sort(neg, neg+numneg+1);
    for(int i = 0; i < m; i++)
    {
        ans += neg[i];
    }
    cout<<-ans<<endl;

}
