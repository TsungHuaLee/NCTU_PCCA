#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct CAKE
{
    long long int len;
    long long int wid;
    long long int num;
}Cake;

bool compare(const Cake& a, const Cake& b)
{
    return a.wid < b.wid;
}
int main()
{
    int num;
    scanf("%d", &num);
    vector<Cake>cake;
    Cake temp;
    for(int i = 0; i < num; i++)
    {
        scanf("%lld %lld", &temp.len, &temp.wid);
        if(temp.len < temp.wid)
            swap(temp.len, temp.wid);
        temp.num = 0;
        cake.push_back(temp);
    }
    sort(&cake[0], &cake[0] + cake.size(), compare);

    vector<Cake>newcake(cake);
    for(int i = num - 1; i >= 0; i--)
    {
        for(int j = i -1; j >= 0; j--)
        if(newcake[i].len <= newcake[j].len)
        {
            temp.wid = newcake[j].wid;
            temp.len = newcake[i].len;
            temp.num = 0;
            newcake.push_back(temp);
        }
    }
    //for(int i = 0; i < newcake.size(); i++)
    //    cout<<"wid = "<<newcake[i].wid<<" len = "<<newcake[i].len<<" num = "<<newcake[i].num<<endl;

    long long int ans = -1, mul;
    int width, leng;

    for(int i = cake.size() - 1; i >= 0; i--)
    {
        for(int j = 0; j < newcake.size(); j++)
        {
            if( (cake[i].wid >= newcake[j].wid)&&(cake[i].len >= newcake[j].len) )
            {
                newcake[j].num++;
                mul = newcake[j].len*newcake[j].wid*newcake[j].num;
                if(ans < mul)
                {
                    ans = mul;
                    width = newcake[j].wid;
                    leng = newcake[j].len;
                }
            }
        }
    }

    //cout<<endl;
    //for(int i = 0; i < newcake.size(); i++)
    //    cout<<"wid = "<<newcake[i].wid<<" len = "<<newcake[i].len<<" num = "<<newcake[i].num<<endl;
    printf("%lld\n%d %d", ans, leng, width);

}
