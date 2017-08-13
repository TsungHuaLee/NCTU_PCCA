//	Pouring Rain
#include<bits/stdc++.h>
#define pi 3.14159265359
using namespace std;

int main()
{

    double diameter, initial, drink, growth;
    cin>>diameter>>initial>>drink>>growth;
    double radius;
    radius = diameter / 2;
    //cout<<"radius = "<<radius<<endl;
    double bottlearea = radius*radius*pi;
    //cout<<bottlearea<<endl;
    double decrease = drink / bottlearea;
    //cout<<growth<<" "<<decrease<<endl;
    if(growth > decrease)
    {
        cout<<"NO";
        return 0;
    }
    double T = initial / (decrease - growth);
    cout<<"YES\n"<<T;
}
