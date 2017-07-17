//sherlock and his girlfriend
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num, prime[100100] = {2, 3, 5, 7, 11}, numPrime = 5;
    cin>>num;

    int count = 0, color[100100] = {};

    for(int i = 0; i <= num; i++)
        color[i] = 2;
    //find prime
    for(int i = 13; i < 100100; i++)
    {
        bool is_prime = true;
        for(int j = 0; prime[j]*prime[j] <= i; j++)
        {
            if(i%prime[j] == 0)
                {
                    is_prime = false;
                    break;
                }
        }
        if(is_prime)
        {
            prime[numPrime] = i;
            numPrime++;
        }
    }


    int j = 0;
    for(int i = 1; i <= num; i++)
    {
        int temp;
        temp = i + 1;
        if(temp == prime[j])
            {
                color[i] = 1;
                j++;
            }
    }

    if(num < 3)
        cout<<1<<endl;
    else
        cout<<2<<endl;
    for(int i = 1; i <= num; i++)
        cout<<color[i]<<" ";

}
