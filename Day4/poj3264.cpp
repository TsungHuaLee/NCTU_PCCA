//Balanced Lineup 
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
long long int N, Q;
struct NODE
{
    int l;
    int r;
    int max;
    int min;
}node[500000];
int arr[500000];

void init()
{
    for(int i = 0; i <500000; i++)
    {
        node[i].l = 0;
        node[i].r = 0;
        node[i].max = -1000100;
        node[i].min = 1000100;
        arr[i] = 0;
    }
    return;
}
int i;
void build(int L, int R, int i)
{
    //leaf
    if(L == R)
    {
        node[i].l = L;
        node[i].r = R;
        node[i].max = arr[L];
        node[i].min = arr[L];
        return;
    }
    int M = (L + R) / 2;
    build(L, M, i<<1);
    build(M + 1, R, i<<1|1);

    node[i].min = min(node[i<<1].min, node[i<<1|1].min);
    node[i].max = max(node[i<<1].max, node[i<<1|1].max);
    node[i].l = L;
    node[i].r = R;
    return;
}

int MAX, MIN;
void Query(int L, int R, int i)
{
    //out range
    if(node[i].r < L || node[i].l > R)
        return;
    if( L <= node[i].l && node[i].r <= R)
        {
            MIN = min(MIN, node[i].min);
            MAX = max(MAX, node[i].max);
            return;
        }
    Query(L, R, i<<1);
    Query(L, R, i<<1|1);

    return;
}
int main()
{
    init();
    scanf("%lld%lld", &N, &Q);
    for(int i = 1; i <= N; i++)
        scanf("%d",&arr[i]);
    int count = 1;
    while(N > (1<<count))
        count++;
    build(1, 1<<count, 1);

    for(int i = 0; i < Q; i++)
    {
        int left, right;
        scanf("%d%d",&left,&right);
        MIN = 1000100, MAX = -1000100;
        Query(left, right, 1);
        printf("%d\n", MAX-MIN);
    }

}
