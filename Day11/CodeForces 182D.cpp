//Common Divisors
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    if(s1.length() > s2.length())
        swap(s1,s2);
    vector<int>factor;
    for(int i = 1; i <= s1.length(); i++)
        if((s1.length() % i == 0) && (s2.length() % i == 0))
            factor.push_back(i);
    string sub1,sub2, compare;
    int ans = 0, mul1, mul2;
    bool flag;
    for(int i = 0; i < factor.size(); i++)
    {
        //cout<<"factor = "<<factor[i]<<endl;
        sub1 = s1.substr(0, factor[i]);
        sub2 = sub1;
        mul1 = s1.length() / factor[i];
        mul2 = s2.length() / factor[i];
        //cout<<"mul1 = "<<mul1<<", mul2 = "<<mul2<<endl;
        compare.clear();
        for(int i = 0; i < mul1; i++)
            compare += sub1;
        if(compare != s1)
            continue;
        compare.clear();
        for(int i = 0; i < mul2; i++)
            compare += sub2;
        if(compare == s2)
            ans++;
    }
    cout<<ans<<endl;
}
