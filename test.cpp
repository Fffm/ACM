/************************************************
* Author: Ac_sorry
* File: 
* Create Date: 
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

int ok;
int vis[20];
void dfs(int cur,int *res)
{
    printf("---%d `dfs\n",cur);
    if(ok) return;
    if(cur==9)
    {
        int sum=1+res[1]+res[4]+res[6];
        if(sum!=1+res[2]+res[5]+res[9])
            return;
        if(sum!=res[9]+res[6]+res[7]+res[8])
            return;
        if(sum!=8+res[1]+res[2]+res[3])
            return;
        if(sum!=8+res[4]+res[7]+3)
            return;
        if(sum!=3+res[5]+res[8]+res[3])
            return;
        ok=1;
        for(int i=1;i<=9;i++)
            printf("%d ",res[i]);
        printf("--\n");
        return;
    }
    for(int i=1;i<=12;i++)
    {
        if(!vis[i])
        {
            res[cur+1]=i;
            vis[i]=1;
            dfs(cur+1,res);
            vis[i]=0;
        }
    }
}
    


int main()
{
    int res[10];
    ok=0;
    memset(vis,0,sizeof vis);
    vis[1]=1;
    vis[3]=1;
    vis[8]=1;
    dfs(0,res);
    printf("-----------end\n");
	return 0;
}

