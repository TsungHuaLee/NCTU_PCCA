//PolandBall and Hypothesis 
#include<iostream>
#include<cstdlib>
using namespace std;
bool isodd(int num)
{
    if(num&1)
        return true;
    else
    return false;
}

int main()
{
    int n, ans;
    cin>>n;
    long long int temp;
    for(int m = 1; m <= 1000; m++)
    {
        temp = (n * m) + 1;
        for(int j = 2; j < temp; j ++)
            if((temp % j) == 0)
                {
                    cout<<m<<endl;
                    return 0;
                }
    }
}
