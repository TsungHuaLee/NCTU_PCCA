//敵兵部陣
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
long long int ncase, N;
struct NODE
{
    int l;
    int r;
    int sum;
}node[500000];
int arr[500000];

void init()
{
    for(int i = 0; i < 500000; i++)
    {
        node[i].l = 0;
        node[i].r = 0;
        node[i].sum = 0;
        arr[i] = 0;
    }
    return;
}
void build(int L, int R, int i)
{
    //leaf
    if(L == R)
    {
        node[i].l = L;
        node[i].r = R;
        node[i].sum = arr[L];
        return;
    }
    int M = (L + R) / 2;
    build(L, M, i<<1);
    build(M + 1, R, i<<1|1);

    node[i].sum = node[i<<1].sum + node[i<<1|1].sum;
    node[i].l = L;
    node[i].r = R;
    return;
}

int add;
void update(int pos, int i)
{
    //out range
    if(pos < node[i].l || pos > node[i].r)
        return;
    if((node[i].l <= pos )&& (pos <= node[i].r))
        {
            node[i].sum += add;
        }
    update(pos, i<<1);
    update(pos, i<<1|1);

    return;
}

long long int ans;
void Query(int L, int R, int i)
{
    //out range
    if((node[i].r < L) ||(node[i].l > R))
        return;
    if( (L <= node[i].l) && (node[i].r <= R))
        {
            ans+=node[i].sum;
            return;
        }
    Query(L, R, i<<1);
    Query(L, R, i<<1|1);

    return;
}
int main()
{
    scanf("%lld", &ncase);
    for(int a = 1; a <= ncase; a++)
    {
        printf("Case %d:\n",a);
        init();
        scanf("%lld", &N);
        for(int k = 1; k <= N; k++)
            scanf("%d", &arr[k]);
        int count = 1;
        while(N > (1<<count))
            count++;
        build(1, 1<<count, 1);

        while(1)
        {
            char str[100]={};
            scanf("%s", str);
            if(!strcmp(str,"End"))
                break;

            if(!strcmp(str,"Query"))
            {
                int left, right;
                scanf("%d %d",&left,&right);
                ans = 0;
                Query(left, right, 1);
                printf("%d\n", ans);
                continue;
            }
            if(!strcmp(str,"Add"))
            {
                int where;
                scanf("%d%d",&where, &add);
                update(where, 1);
                //for(int i = 1; i <= 26; i++)
                //{
                //    cout<<"i = "<<i<<" l = "<<node[i].l<<" r = "<<node[i].r<<" sum = "<<node[i].sum<<endl;
                //}
                continue;
            }
            if(!strcmp(str,"Sub"))
            {
                int temp;
                scanf("%d%d",&temp, &add);
                add *= -1;
                update(temp, 1);
                continue;
            }
        }
    }

}
