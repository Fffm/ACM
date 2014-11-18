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

const int N=100010;

int a[N];
int main()
{
    int n,T;
    cin>>T;
    for(int cas=1;cas<=T;cas++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int st=1,en=n;
        int s=1;
        int maxx=-1001;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
            if(sum>maxx)
            {
                maxx=sum;
                st=s;
                en=i;
            }
            if(sum<0)
            {
                sum=0;
                s=i+1;
            }

        }
        if(cas!=1)
            cout<<endl;
        printf("Case %d:\n",cas);
        printf("%d %d %d\n",maxx,st,en);
    }


	return 0;
}

