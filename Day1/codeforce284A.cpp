//Cows and Primitive Roots 
#include<bits/stdc++.h>
using namespace std;
int priRoot(int prime, int count)
{
    //  1<= x < p
    for(int i = 1; i < prime; i++)
    {
        //do x-1 ~ x^p-2 can't be divisible by prime
        int temp = i;
        bool isAns = true;
        for(int p = 1; p <= prime - 2; p++)
        {
            if((temp - 1)%prime == 0)
                {
                    isAns = false;
                    break;
                }
            temp = (temp * i) % prime;
        }

        //x^p-1 can be divisible by prime
        if(isAns && (temp - 1)%prime != 0)
            isAns = false;

        if(isAns)
            count++;
    }
    return count;
}
int main()
{
    int prime;
    int count;
    cin>>prime;
    count = 0;
    cout<<priRoot(prime, count)<<endl;
}
