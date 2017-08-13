//dijkstra
#include<iostream>
#include<queue> //priority queue
#include<vector> //vector
#include<climits>   //LLONG_MAX
using namespace std;
typedef pair<long long int, int> P; //for min priority_queue
int  numNode, numEdge;
vector< pair<long long int, int> >edge[100100];//(weight, end)
long long int dist[100100];//from source, need total weight
int pre[100100];
void init()
{
    for(int i = 0; i < 100100; i++)
        edge[i].clear();
    fill(dist, dist + 100100, LLONG_MAX);
    fill(pre, pre + 100100, 0);
    cin>>numNode>>numEdge;
    for(int i = 0; i < numEdge; i++)//題目1~N
    {
        int s,t;
        long long int w;
        cin>>s>>t>>w;
        edge[s].push_back(make_pair(w,t));
        edge[t].push_back(make_pair(w,s));
    }
    /*for(int i = 1; i <= numNode; i++){
        cout<<"i = "<<i<<endl;
        for(int j = 0; j < edge[i].size(); j++)
            cout<<"w = "<<edge[i][j].first<<" end = "<<edge[i][j].second<<endl;
    }*/
}

void dijkstra()
{
    priority_queue< P, vector<P>, greater<P> >que; //compare with first
    que.push(make_pair(0, 1)); // in src = 1, distance by far, (min total distance, point);
    dist[1] = 0;               //the meaning of pair here is defirent from vector
    P now;
    while(!que.empty())
    {
        now = que.top(); que.pop();
    //    cout<<"cost = "<<now.first<<" place = "<<now.second<<endl;
        for(int j = 0; j < edge[now.second].size(); j++)
        {
            int tail = edge[now.second][j].second;
            if(dist[tail] > now.first + edge[now.second][j].first)//dist[t] > dist[s] + w[s][t]
            {
                dist[tail] = now.first + edge[now.second][j].first;
                pre[tail] = now.second;
                que.push(make_pair(dist[tail], tail));
            }
        }
    }
    if(dist[numNode] == LLONG_MAX)
    {
        cout<<"-1\n";
        return;
    }
    vector<int>ans;
    int trace = numNode;
    while(trace != 0)
    {
        ans.push_back(trace);
        //cout<<trace<<" ";
        trace = pre[trace];
    }
    for(int i = ans.size() - 1; i >= 0; i--)
        cout<<ans[i]<<" ";
    //cout<<dist[numNode];
    return ;
}
int main()
{
    init();
    dijkstra();
}
