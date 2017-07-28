//odd sum
#include<bits/stdc++.h>
#define MIN -1e9;
using namespace std;

int n, sum, ans, num1, num2;
vector<int>odd;
vector<int>even;

void init()
{
    odd.clear();
    even.clear();
    sum = 0;
    ans = MIN;
}

bool isOdd(long long int num)
{
    if(num&1)
        return true;
    else
        return false;
}

int main()
{
    cin>>n;
    init();
    int numodd = 0;
    int table[100100] = {};
    for(int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        if(a%2 == 0 && a>=0)
            sum += a;
        if(a&1){
            odd.push_back(a);
            numodd++;
        }
    }
    sort(odd.begin(), odd.begin() + numodd);
    reverse(odd.begin(), odd.end());
    //at least 1 odd
    table[0] = odd[0];
    ans = odd[0];
    for(int i = 1; i < numodd; i++)
    {
        table[i] = table[i - 1] + odd[i];
        if(isOdd(table[i]) && table[i] > ans){
            ans = table[i];
        }
    }
    ans+= sum;
    cout<<ans<<endl;
}
