//max flow, hdu3549
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
int numNode, numEdge , ncase, now;
int edge[1010][1010];
int path[1010];// where come from
void init()
{
    memset(edge, 0, sizeof(edge));
    cin>>numNode>>numEdge;
    int v;
    for(int i = 0; i < numEdge; i++)
    {
        int s,t;
        cin>>s>>t>>v;
        edge[s][t] += v;//!!!!!
    }
    return;
}

int BFS(int source, int dest)
{
    bool visit[numNode + 10];
    int flow[numNode + 10] = {};
    memset(visit, false, sizeof(visit));
    memset(path, 0, sizeof(path));
    //!!!!
    for(int i = 0; i < numNode + 10; i++)
        flow[i] = 1e5;
    queue<int> Q;
    visit[source] = true;
    Q.push(source);
    while(!Q.empty())
    {
        int top = Q.front(); Q.pop();
        for(int j = 1; j <= numNode; j++)
        {
            if(!visit[j] && edge[top][j])
            {
                visit[j] = true;
                flow[j] = min(flow[top], edge[top][j]);
                //cout<<"j = "<<j<<" top = "<<top<<" flow[top] = "<<flow[top]<<" edge[top][j] = "<<edge[top][j]<<" flow[j] = "<<flow[j]<<endl;
                path[j] = top;
                Q.push(j);
                if(j == dest)
                    return flow[dest];
            }
        }
    }
    return 0;
}
void Edmond()
{
    int maxflow = 0;
    while(1)
    {
        int tempflow = BFS(1, numNode);
        if(tempflow == 0)
            break;
        maxflow+=tempflow;
        //cout<<tempflow<<" : ";
        for(int i = numNode; i != 1; i = path[i])
        {
        //    cout<<i<<" -> ";
            edge[path[i]][i] -= tempflow;
            edge[i][path[i]] += tempflow;
        }
        //cout<<endl;
        /*for(int i = 1; i <= 7; i++)
        {
            cout<<endl;
            for(int j = 1; j <= 7; j++)
                cout<<edge[i][j]<<" ";
        }*/
        //cout<<"\n\n----------\n";
    }

    printf("Case %d: %d\n",now, maxflow);
    return;
}
int main()
{
    cin>>ncase;
    for(now = 1; now <= ncase; now++)
    {
        init();
        Edmond();
    }
}
