//cf 330a
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin>>row>>col;
    int pos[row + 10][col + 10] = {};
    long long int ans;
    for(int i = 0; i < row; i++)
    {
        string str;
        cin>>str;
        for(int j = 0; j < col; j++)
        {
            if(str[j] == 'S')
            {
                pos[i][j] = 2;
            }
        }
    }
    int r = 0,c = 0;
    for(int i = 0 ; i < row; i++)
    {
        bool flag = true;
        for(int j = 0; j < col; j++)
        if(pos[i][j])
        {
            flag = false;
            break;
        }
        if(flag)
            r++;
    }
    for(int i = 0 ; i < col; i++)
    {
        bool flag = true;
        for(int j = 0; j < row; j++)
        if(pos[j][i])
        {
            flag = false;
            break;
        }
        if(flag)
            c++;
    }
    ans = r * col + c * row - r*c;
    cout<<ans<<endl;
}
