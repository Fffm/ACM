/************************************************
* Author: Ac_sorry
* File: C 
* Create Date:2014-11-17 
*************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;
typedef long long LL;
LL a[50100];

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        LL ans=0;
        for(int i=0;i<n;i++)
            scanf("%lld",a+i);
        sort(a,a+n);
        for(int i=1;i<n;i++)
        {
            a[i]+=a[i-1];
            ans+=a[i];
            sort(a+i,a+n);
        }
        printf("%lld\n",ans);
    }
	return 0;
}

