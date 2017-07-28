//cf 236a
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int count[30]={};
    for(int i = 0; i < str.length(); i++)
    {
        int a;
        a = str[i]-'a';
        count[a]++;
    }
    int flag = 0 ;
    for(int i = 0; i < 30 ; i++)
        if(count[i])
            flag++;
    if(flag&1)
        cout<<"IGNORE HIM!\n";
    else
        cout<<"CHAT WITH HER!\n";
}
