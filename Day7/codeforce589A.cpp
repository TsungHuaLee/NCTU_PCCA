//email aliases
#include<bits/stdc++.h>
using namespace std;
int N;
map<string, vector<string> >email;
map<string, vector<string> >::iterator ite;
void init()
{
    email.clear();
}
void lower(string& str)
{
    for(int i = 0 ; i < str.length(); i++)
    {
        if( 'A' <= str[i] && str[i] <= 'Z')
            str[i] = str[i] - ('Z' - 'z');
    }
    return;
}

void input()
{
    cin>>N;
    string in, login, domain, newEmail;
    for(int i = 0; i < N; i++)
    {
        cin>>in;
        int at = in.find('@');
        login = in.substr(0, at);
        lower(login);
        domain = in.substr(at, in.length() - at);
        lower(domain);
        if(domain == "@bmail.com")
        {
            size_t add = login.find('+');
            if(add != string::npos)
            {
                login = login.substr(0, add);
            }
            for(int i = 0; i < login.length(); i++)
            {
                if(login[i] == '.')
                    login.erase(i,1);
            }
        }
        newEmail = login + domain;
        //cout<<newEmail<<endl;
        email[newEmail].push_back(in);
    }
    return;
}

void sol()
{
    cout<<email.size()<<endl;
    for(ite = email.begin(); ite != email.end(); ite++)
    {
        cout<<ite->second.size();
        for(int i = 0; i < ite->second.size(); i++)
            cout<<" "<<ite->second[i];
        cout<<endl;
    }
}
int main()
{
    init();
    input();
    sol();
}
