/*
    anthor:Ac_sorry
    date:2014/11/5
    hint:背包问题
*/



#include<cstring>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


/**        01背包
    dp[i][v]=max(dp[i-1][v],dp[i-1][v-c[i]]+w[i]);

    朴实的二维：
    F[0; 0::V ]   0
    for i<-1 to N
        for v <-Ci to V
            F[i , v] = max{F[i-1, v] , F[i-1,v-ci] + wi;
*/

const int N=1000;

int dp[N][N];
int w[N],c[N];

void ZeroOnePack(int c,int w)
{
    for(int i=v;i>=c;i--)
        dp[i]=max(dp[i],dp[i-c]+w);
}


void CompletePack(int c,int w)
{
    for(int i=c;i<=v;i++)
        dp[i]=max(dp[i],dp[i-c]+w);
}


void MultiplePack(int c,int w,int m,int i)
{
    if(c*m>i)
    {
        CompletePack(c,w);
        return;
    }
    int k=1;
    while(k<m)
    {
        ZeroOnePack(k*c,k*w);
        m-=k;
        k=k*2;
    }
    ZeroOnePack(c*m,)
}



int main()
{
    for(int i=1;i<=n;i++)
        ZeroOnePack(c[i],w[i]);

    //or:

    for(int i=0;i<=n;i++)
        CompletePack(c[i],w[i]);

}


