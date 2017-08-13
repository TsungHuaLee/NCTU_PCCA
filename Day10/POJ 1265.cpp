//area
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int move;
struct NODE
{
    double x,y;
};
vector<NODE>node;
int edgepoint, inpoint;
double area;
void init()
{
    edgepoint = 0, inpoint = 0, area = 0;
    node.clear();
    cin>>move;
    struct NODE temp;
    cin>>temp.x>>temp.y;
    node.push_back(temp);
    for(int i = 1; i < move; i++)
    {
        cin>>temp.x>>temp.y;
        temp.x += node[i - 1].x;
        temp.y += node[i - 1].y;
        node.push_back(temp);
    }// node 最後一個才是 (0,0)
    //for(int i = 0; i < node.size(); i++)
    //    cout<<node[i].x<<" "<<node[i].y<<endl;
    //cout<<"\n---------\n\n";
}

int edgecount(int dx,int dy)
{
    int re = __gcd(abs(dx), abs(dy)) + 1 - 1;//包含端點 - 起點
    //cout<<"re = "<<re<<endl;
    return re;
}

void onedge()
{
    struct vt;
    double dx = node[0].x - node[node.size() - 1].x, dy = node[0].y - node[node.size() -1].y;
    //cout<<dx<<" "<<dy<<endl;
    edgepoint += edgecount(dx, dy);
    for(int i = 1; i < move; i++)
    {
        dx = node[i].x - node[i - 1].x, dy = node[i].y - node[i - 1].y ;
        //    cout<<dx<<" "<<dy<<endl;
        edgepoint += edgecount(dx,dy);
    }
    return;
}

double cross_pruduct(const NODE& a, const NODE& b)
{
    return a.x*b.y-a.y*b.x;
}
double triarea(const NODE& a, const NODE& b)
{
    return cross_pruduct(a,b);
}
void totalarea()
{
    for(int  i = 0; i < node.size() - 1; i++)
    {
        //01 12 23 34 45 56
        double toadd = triarea(node[i], node[i + 1]);
        //cout<<toadd<<endl;
        area += toadd;
    }
    // area 在外面除, 減少誤差
    area += triarea(node[node.size() -1], node[0]);
    area /= 2.0L;
    return ;
}
void inedge()
{   //area = inpoint + edgepoint/2  - 1
    inpoint = (int)area - edgepoint/2 + 1;
    return;
}
int main()
{
    int ncase;
    cin>>ncase;
    for(int t = 1; t <= ncase; t++)
    {
        init();
        onedge();
        totalarea();
        inedge();
        printf("Scenario #%d:\n%d %d %.1lf\n\n",t, inpoint, edgepoint, area);
    }
}
