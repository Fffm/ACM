#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int n,m,q;
int uset[10010];
int r1[50010],r2[50010];

struct qq{
    int L,p;
    int res;
}LL[10010];

int cmp1(qq a,qq b)
{
    return a.L<b.L;
}

int cmp2(qq a,qq b)
{
    return a.p<b.p;
}


struct node{
    int u,v;
    int c;
}p[50010];


int cmp(node a,node b)
{
    return a.c<b.c;
}
void make_set(int nn)
{
    for(int i=1;i<=nn;i++)
        uset[i]=-1;
}

int find_set(int x)
{
    if(uset[x]<0) return x;
    uset[x]=find_set(uset[x]);
    return uset[x];
}


int union_set(int x,int y)
{
    int cnt;
    if((x=find_set(x))==(y=find_set(y)))
        return 0;
    if(uset[x]<uset[y])
    {
        cnt=uset[x]*uset[y];
        uset[x]+=uset[y];
        uset[y]=x;
    }
    else
    {
        cnt=uset[x]*uset[y];
        uset[y]+=uset[x];
        uset[x]=y;
    }

    return cnt;
}


int main()
{
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        int pos=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].c);
        }
        for(int i=0;i<q;i++)
        {
            scanf("%d",&LL[i].L);
            LL[i].p=i;
        
        }

        sort(p,p+m,cmp);
        p[m].c=-1;
        sort(LL,LL+q,cmp1);
        make_set(n);
        int cnt=0;
        for(int i=0;i<q;i++)
        {
            while(LL[i].L>=p[pos].c&&pos<m)
            {
                cnt+=union_set(p[pos].u,p[pos].v);
                pos++;
            }
            LL[i].res=cnt;
        }
        sort(LL,LL+q,cmp2);
        for(int i=0;i<q;i++)
           printf("%d\n",LL[i].res);
    }
    return 0;
}
