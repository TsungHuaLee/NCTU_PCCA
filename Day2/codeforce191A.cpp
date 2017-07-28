//Dynasty Puzzles
#include<bits/stdc++.h>
#define MAX -1e9;
using namespace std;

struct Name
{
    int first;
    int last;
    int len;
};
struct Name name[5*100001];
long long int dp[30][30];
int n,ans;

void init()
{
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            {
                if(i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = MAX;
            }
    ans = MAX;
    return;
}

void findMax()
{
    //every name
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            //dp[?][a] = dp[?][c] + ca
            dp[j][name[i].last] = max(dp[j][name[i].last], dp[j][name[i].first] + name[i].len);
        }
        /*for(int k = 0; k < 26; k++){
            cout<<endl;
            for(int l = 0; l < 26; l++)
                printf("%ld ",dp[k][l]);
        }
        cout<<endl;*/
    }

    for(int i = 0; i < 26; i++)
        if(dp[i][i] > ans)
            ans = dp[i][i];
    cout<<ans<<endl;
    return;
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        char temp[10]={};
        scanf("%s", temp);
        //'a' - 'a' = 0,
        name[i].first = temp[0] - 'a';
        name[i].last = temp[strlen(temp) - 1] - 'a';
        name[i].len = strlen(temp);
    }
    init();
    findMax();

}
