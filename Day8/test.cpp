#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin>>input;
    vector<int>equal;
    for(int i = 0; i < input.length(); i++)
        if(input[i] == input[0])
            equal.push_back(i);
    if(equal.size() < 3)
    {
        cout<<"Just a legend\n";
        return 0;
    }
    map<string, int> mymap;

}
