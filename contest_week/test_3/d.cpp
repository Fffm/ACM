/************************************************
* Author: Ac_sorry
* File: D
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
const int N=100010;


int t[35],dam[35];
int dp[500];

int main()
{
    int n,L;
    while(scanf("%d%d",&n,&L)==2)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",t+i,dam+i);
        }
        memset(dp,0,sizeof dp);
        for (int j=1;j<=330;++j) {
            for (int i=0;i<n;++i) {
                dp[j+t[i]]=max(dp[j+t[i]],dp[j]+j*dam[i]);
            }
        }
        for(int i=0;i<=350;i++)
        {
            if(dp[i]>=L)
            {
                printf("%d\n",i);
                break;
            }
        }
    }

	return 0;
}

