//cf 550A
#include<bits/stdc++.h>
using namespace std;

string str;
string AB = "AB", BA = "BA";

bool findAB(int start, int& next)
{
    for(int i = start ; i < str.length() - 1; i++)
    {
        string sub = str.substr(i,2);
        if(sub == AB)
        {
            a = true;
            next = i;
            return true;
        }
    }
    return false;
}

bool findBA(int start, int& next)
{
    for(int i = start ; i < str.length() - 1; i++)
    {
        string sub = str.substr(i,2);
        if(sub == BA)
        {
            b = true;
            next = i;
            return true;
        }
    }
    return false;
}
//AB BA 前後順序會影響
int main()
{
    cin>>str;

    int next = 0;
    if(findAB(0, next))
    {
        next += 2;
        int temp;
        if(findBA(next, temp))
        {
            cout<<"YES\n";
            return 0;
        }
    }

    if(findBA(0, next))
    {
        next += 2;
        int temp;
        if(findAB(next, temp))
        {
            cout<<"YES\n";
            return 0;
        }
        else
        {
            cout<<"NO\n";
            return 0;
        }
    }

    cout<<"NO\n";
    return 0;
}
