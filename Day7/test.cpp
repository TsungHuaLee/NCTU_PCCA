#include <bits/stdc++.h>
#include <map>
using namespace std;
map<string, int>::iterator it ;
int main ()
{
    string str = "zxcv.bn.ma.";
    for(int i = 0; i < str.length(); i++)
    {
        cout<<"len = "<<str.length()<<" i = "<<i;
        if(str[i] == '.')
            str.erase(i,1);
        cout<<" str = "<<str<<endl;
    }
}
