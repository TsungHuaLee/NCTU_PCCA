//Lottery 
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int numBall, numColor, target;
    cin>>numBall>>numColor;
    target = numBall / numColor;
    int each[1000] = {};

    for(int i = 0; i < numBall; i++)
    {
        int temp;
        cin>>temp;
        each[temp]++;
    }
    long long int ans = 0;
    for(int i = 1; i <= numBall; i++)
    {
        if(each[i] > target)
        {
        //    cout<<i<<endl;
            ans = ans + each[i] - target;
        }
    }
    cout<<ans<<endl;
}
