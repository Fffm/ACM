/************************************************
* Author: Ac_sorry
* File: 
* Create Date: 
* Motto: One heart One life
* CSDN: http://blog.csdn.net/code_or_code
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
#include<stack>
#define INF 0x3f3f3f3f
//#define MAX INT_MAX
//#define MIN INT_MIN
//#define PI acos(-1.0)
using namespace std;
typedef long long LL;

const int V=1000;

int edge[V][V],pre[V], post[V], tag_pre,tag_post;
void dfstag(int cur,int n) 
{
    pre[cur] = ++tag_pre;
    for (int i = 0; i < n; ++i)
        if (edge[cur][i]) {
            if (0 == pre[i]) {
                dfstag(i, n);
            }
        }
    post[cur] = ++tag_post;
}

int main()
{
    memset(edge,0,sizeof edge);
    edge[0][1]=edge[1][0]=1;
    edge[0][6]=edge[6][0]=1;
    edge[1][2]=edge[2][1]=1;
    edge[2][3]=edge[3][2]=1;
    edge[2][4]=edge[4][2]=1;
    edge[3][4]=edge[4][3]=1;
    edge[1][5]=edge[5][1]=1;
    edge[5][6]=edge[6][5]=1;
    edge[6][7]=edge[7][6]=1;
    edge[7][8]=edge[8][7]=1;
    edge[7][9]=edge[9][7]=1;
    edge[8][9]=edge[9][8]=1;
    dfstag(0,10);
    for(int i=0;i<10;i++)
        printf("%d-> %d  %d\n",i,pre[i],post[i]);

	return 0;
}

