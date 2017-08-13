//PolandBall and Game
#include<bits/stdc++.h>
using namespace std;
map<string, int>::iterator ite;
int main()
{
    int N,M;
    cin>>N>>M;
    if(N > M)
    {
        cout<<"YES\n";
        return 0;
    }
    if(N < M)
    {
        cout<<"NO\n";
        return 0;
    }

    map<string, int> word;
    word.clear();
    for(int i = 0; i < N; i++)
    {
        string str;
        cin>>str;
        word[str] = 1;
    }
    int onlyenemy = 0;
    for(int j = 0; j < M; j++)
    {
        string str;
        cin>>str;
        ite = word.find(str);
        if(ite != word.end()) //both know
        {
            //cout<<ite->first<<endl;
            onlyenemy++;
        }
    }
    if(onlyenemy&1)
    cout<<"YES\n";
    else
    cout<<"NO\n";
    return 0;
}
