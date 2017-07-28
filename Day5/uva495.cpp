//Fibonacci Freeze
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> fib[5010];


vector<int> add(int a, int b)
{
    //cout<<a<<" + "<<b<<" ";
    int digit = fib[a].size();

    vector<int>temp = fib[a];

    for(int i = 0; i < fib[b].size(); i++)
        temp[i] += fib[b][i];

    for(int i = 0; i < digit; i++)
    {
        if(i == digit -1)
        {

            int x = temp[i] / 10;
    //        cout<<" temp[i] = "<<temp[i]<<" x = "<<x<<" ";
            if(x > 0)
            {
                temp.push_back(x);
                temp[i]%=10;
            }
            break;
        }
        temp[i + 1] += temp[i]/10;
        temp[i] %= 10;
    }
    //cout<<" "<<temp.size();
    //for(int i = temp.size() - 1; i>=0; i--)
    //    cout<<temp[i];
    //cout<<"\n";
    return temp;
}
void init()
{
    for(int i = 0; i < 5010; i++)
        fib[i].clear();

    fib[0].push_back(0);
    fib[1].push_back(1);

    for(int i = 2; i < 5001; i++)
        fib[i] = add(i-1,i-2);

}

int main()
{
    init();
    int target;
    while(cin>>target)
    {
        printf("The Fibonacci number for %d is ", target);
        for(int i = fib[target].size() - 1; i >= 0; i--)
        {
            printf("%d", fib[target][i]);
        }
        printf("\n");
    }
}
