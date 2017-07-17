//Dreamoon and WiFi 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double posibility = 0;
    string send, receive;
    cin>>send>>receive;
    int countpos = 0, countneg = 0, count = 0;
    for(int i = 0; i < send.length(); i++)
    {
        if(send[i] == '+')
            countpos++;
        else
            countneg++;
        if(receive[i] == '+')
            countpos--;
        else if(receive[i] == '-')
            countneg--;
        else
            count++;
    }
    if(countpos < 0 || countneg < 0)
    {
        printf("%.12lf\n",posibility);
        return 0;
    }
    if(count == 0)
    {
        posibility = 1;
        printf("%.12lf\n",posibility);
        return 0;
    }
    double Denominator = pow(2,count);
    double Numerator = 1,a = 1,b = 1;
    for(int i = 1; i <= count; i++)
        Numerator *= i;
    for(int i = 1; i <= countpos; i++)
        a *= i;
    for(int i = 1; i <= countneg; i++)
        b *= i;
    Numerator = Numerator/(a*b);
//    cout<<"Numerator = "<<Numerator<<" Denominator = "<<Denominator<<endl<<Numerator / Denominator;

    printf("%.12lf\n", Numerator/Denominator);
}
