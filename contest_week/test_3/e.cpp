/************************************************
* Author: Ac_sorry
* File: E
* Create Date: 2014-11-17 
*************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=100010;

int edge[500][500];
bool vis[500];
int m;
int l,e1,n,e2;


int lowc[500];
int prim(int s)
{
    int minn,res=0;
    int p;
    bool v_has[500];
    memset(v_has,false,sizeof v_has);
    v_has[s]=true;
    for(int i=0;i<l+n;i++)
        if(vis[i]) lowc[i]=edge[s][i];
    for(int i=1;i<n+l-m;i++)
    {
        minn=INF;
        for(int j=0;j<n+l;j++)
        {
            if(!v_has[j]&&vis[j]&&lowc[j]<minn)
            {
                minn=lowc[j];
                p=j;
            }
        }
        if(minn==INF) return -1;
        res+=minn;
        v_has[p]=true;
        for(int j=0;j<n+l;j++)
        {
            if(!v_has[j]&&vis[j]&&edge[p][j]<lowc[j])
                lowc[j]=edge[p][j];
        }
    }

    return res;
}



int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int u,v,c;
        int ans;
        memset(edge,INF,sizeof edge);
        memset(vis,false,sizeof vis);
        scanf("%d%d",&l,&e1);
        for(int i=0;i<e1;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            if(c<edge[u][v])
                edge[u][v]=edge[v][u]=c;
            vis[u]=vis[v]=true;
        }
        scanf("%d%d",&n,&e2);
        for(int i=0;i<e2;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            if(c<edge[u][v])
                edge[u][v]=edge[v][u]=c;
            vis[u]=vis[v]=true;
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&u);
            vis[u]=false;
        }
        for(int i=0;i<n+l;i++)
        {
            if(vis[i])
            {
                ans=prim(i);
                break;
            }
        }
        if(ans!=-1)
            printf("%d\n",ans);
        else
            printf("what a pity!\n");
    }
        

	return 0;
}

