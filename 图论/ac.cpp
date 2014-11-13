#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


const int N=100010;
int uset[N];

void make_set(int n)
{
    for(int i=0;i<n;i++)
        uset[i]=-1;
}

int find_set(int x)
{
    if(uset[x]<0) return x;
    uset[x]=find_set(uset[x]);
    return uset[x];
}


void union_set(int x,int y)
{
    if((x=find_set(x))==(y=find_set(y)))
        return;
    
    if(uset[x]<uset[y])
    {
        uset[x]+=uset[y];
        uset[y]=x;
    }
    else
    {
        uset[y]+=uset[x];
        uset[x]=y;
    }
}


int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        make_set(N);
        int x,y;
        int peo=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            peo=max(max(x,y),peo);
            union_set(x,y);
        }

        int maxx=-1;
        for(int i=1;i<=peo;i++)
        {
            if(uset[i]<maxx)
                maxx=uset[i];
        }
        printf("%d\n",-maxx);
    }
}
