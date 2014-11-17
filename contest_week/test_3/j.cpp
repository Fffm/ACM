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

char h_dir[30];
char v_dir[30];
int vis[50][50];
int n,m;
int num;

void dfs(int h,int v)
{
    //cout<<"fsf"<<endl;
    if(h>=0&&h<n&&v>=0&&v<m&&!vis[h][v])
    {
        num++;
        //out<<"-"<<h<<"-"<<v<<endl;
        vis[h][v]=1;
        if(h_dir[h]=='>')
            dfs(h,v+1);
        else if(h_dir[h]=='<')
            dfs(h,v-1);

        if(v_dir[v]=='v')
            dfs(h+1,v);
        else if(v_dir[v]=='^')
            dfs(h-1,v);
    }
}


int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        scanf("%s%s",h_dir,v_dir);
        int fail=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                num=0;
                memset(vis,0,sizeof vis);
                dfs(i,j);
                if(num!=n*m)
                    break;
            }
            if(num!=n*m)
                break;
        }
        if(num==n*m)
            printf("YES\n");
        else
            printf("NO\n");
    }

	return 0;
}

