//graph coloring
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;

int numP, numE, ans;
vector<int> map[110];
int cant[110], black[110], temp[110] ;

void init()
{
    for(int i = 0; i < 110; i++)
        map[i].clear();
    memset(cant, 0, sizeof(int)*110);
    memset(black, 0, sizeof(int)*110);
    memset(temp, 0, sizeof(int)*110);
    return;
}

void traversal(int point, int choose, int nochoose)
{
    if( (choose + nochoose) ==  numP || point > numP )
    {
    //    cout<<"choose = "<<choose<<" nochoose = "<<nochoose<<" ans = "<<ans<<endl;
        if(ans < choose)
        {
            ans = choose;
            for(int i = 0; i < ans; i++)
                black[i] = temp[i];
        }
        return;
    }
    //if can choose + choose it
    if(cant[point] == 0)
    {
        int newNo = nochoose;
        vector<int> reduce;
        //if choose, adjacent point can't
        for(int i = 0; i < map[point].size(); i++)
        {
            //prevent repeat compute
            if(cant[map[point][i]] == 0)
            {
                cant[map[point][i]] = 1;
                reduce.push_back(map[point][i]);
                newNo++;
            }
        }
        //temp: at "choose" time is "point"
        temp[choose] = point;
        //go to next point;
        traversal(point + 1, choose + 1, newNo);
        //go back to original state, for no choose
        for(int i = 0; i < reduce.size(); i++)
            cant[reduce[i]] = 0;
    }
    //no matter "can choose" or not, don't choose
    //if this point can choose but we don't choose --> nochoose++, depend on cant[?]
    traversal(point + 1, choose, nochoose + !cant[point]);
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d", &numP, &numE);
        init();

        for(int i = 0; i < numE; i++)
        {
            int s,t;
            scanf("%d%d", &s, &t);
            map[s].push_back(t);
            map[t].push_back(s);
        }
        ans = 0 ;
        traversal(1, 0, 0);
        printf("%d\n", ans);
        for(int i = 0; i < ans; i++){
            if(i != 0)
                printf(" ");
            printf("%d", black[i]);
        }
        printf("\n");
    }
}
