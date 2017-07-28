//cf 339a
#include<bits/stdc++.h>
using namespace std;
int first;
int main()
{
    string str;
    cin>>str;
    long long int sum = 0;
    int count[100] = {};
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '+')
            continue;
        int a = str[i] - '0';
        count[a]++;
        count[0]++;
    }
    int temp = 1;
    first = 0;
    while(count[1]){
        if(first == 0)
            first++;
        else
            cout<<'+';
        cout<<'1';
        count[1]--;
    }
    while(count[2]){
        if(first==0)
            first++;
        else
            cout<<'+';
        cout<<'2';

        count[2]--;
    }
    while(count[3]){
        if(first==0)
            first++;
        else
            cout<<'+';
        cout<<'3';

        count[3]--;
    }
}
