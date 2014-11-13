#include<iostream>
#include<cstdio>

using namespace std;

int uset[2020];
int rel[2020];

void make_set(int n)
{
    for(int i=1;i<=n;i++)
    {
        uset[i]=i;
        rel[i]=0;
    }
}

int find_set(int x)
{
    if(uset[x]!=x)
    {
        int t=uset[x];
        uset[x]=find_set(uset[x]);
        rel[x]=(rel[t]+rel[x])%2;
    }
    return uset[x];
}

int union_set(int x,int y)
{
    int fx=find_set(x),fy=find_set(y);
    if(fx==fy)
    {
        if(rel[x]==rel[y]) return 1;
        else return 0;
    }
    uset[fx]=fy;
    rel[fx]=(2-rel[x]+1+rel[y])%2;
    return 0;
}

int main()
{
    int n,m;
    int cas=0;
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int u,v;
        int ok=0;
        make_set(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            if(ok==0)
            {
               ok= union_set(u,v);
            }
        }
        printf("Scenario #%d:\n",cas++);
        if(ok)
            printf("Suspicious bugs found!\n\n");
        else
            printf("No suspicious bugs found!\n\n");
    }
    return 0;
}
