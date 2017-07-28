//cleaner robot
#include<iostream>
#include<cstdlib>
#include<memory.h>
using namespace std;
int map[15][15];
int flag[15][15][5], clear[15][15];
int dir;

bool up(int i, int j)
{
    if(map[i - 1][j])
        return false;
    else
        return true;
}
bool right(int i, int j)
{
    if(map[i][j + 1])
        return false;
    else
        return true;
}
bool down(int i, int j)
{
    if(map[i + 1][j])
        return false;
    else
        return true;
}
bool left(int i, int j)
{
    if(map[i][j - 1])
        return false;
    else
        return true;
}


int main()
{
    memset(map, 1, sizeof(int)*15*15);
    memset(flag, 0, sizeof(int)*15*15*5);
    memset(clear, 0, sizeof(int)*15*15);
    int row, col;
    cin>>row>>col;
    string input;
    int startRow, startCol;
    for(int i = 1; i <= row; i++)
    {
        cin>>input;
        for(int j = 0; j < input.length(); j++)
        {
            if(input[j] == '.')
            {
                map[i][j + 1] = 0;
                continue;
            }
            if(input[j] == '*')
            {
                map[i][j + 1] = 1;
                continue;
            }
            else
            {
                if(input[j] == 'U')
                    dir = 1;
                if(input[j] == 'R')
                    dir = 2;
                if(input[j] == 'D')
                    dir = 3;
                if(input[j] == 'L')
                    dir = 4;
                clear[i][j + 1] = 1;
                startRow = i;
                startCol = j + 1;
                //bug in this, add map[i][j+1] = 0
                map[i][j+1] = 0;
                continue;
            }
        }
    }
    while(1)
    {
        //cout<<"row = "<<startRow<<" col = "<<startCol<<" dir = "<<dir<<endl;;
        if(dir == 1)
        {
            //already done
            if(flag[startRow][startCol][dir])
                break;
            flag[startRow][startCol][dir] = 1;
            //can do
            if(up(startRow, startCol))
            {
                startRow--;
                clear[startRow][startCol] = 1;
                continue;
            }
            else
            {
                dir++;
                continue;
            }
        }
        if(dir == 2)
        {
            if(flag[startRow][startCol][dir])
                break;
            flag[startRow][startCol][dir] = 1;
            if(right(startRow, startCol))
            {
                startCol++;
                clear[startRow][startCol] = 1;
                continue;
            }
            else
            {
                dir++;
                continue;
            }
        }
        if(dir == 3)
        {
            if(flag[startRow][startCol][dir])
                break;
            flag[startRow][startCol][dir] = 1;
            if(down(startRow, startCol))
            {
                startRow++;
                clear[startRow][startCol] = 1;
                continue;
            }
            else
            {
                dir++;
                continue;
            }
        }
        if(dir == 4)
        {
            if(flag[startRow][startCol][dir])
                break;
            flag[startRow][startCol][dir] = 1;
            if(left(startRow, startCol))
            {
                startCol--;
                clear[startRow][startCol] = 1;
                continue;
            }
            else
            {
                dir = 1;
                continue;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= row; i++)
        for(int j = 1; j <= col; j++)
            ans += clear[i][j];
    cout<<ans;
}
