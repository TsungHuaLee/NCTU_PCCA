//password
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
    bool flag = false;
    int len;
    string prestr, sustr, midstr, ans;
    ans.clear();
    for(int i = equal.size() - 1; i > 0; i--)
    {
        len = input.length() - equal[i];
        prestr = input.substr(0, len);
        sustr = input.substr(equal[i], len);
        if(prestr != sustr)
            continue;
        for(int j = 1; j < i; j++)
        {
            midstr = input.substr(equal[j], len);
            if(midstr == prestr)
            {
                if(prestr.length() > ans.length())
                    ans = prestr;
                flag = true;
            }
        }
    }
    if(flag)
        cout<<ans<<endl;
    else
    cout<<"Just a legend\n";
}
