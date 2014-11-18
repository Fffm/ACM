/************************************************
* Author: Ac_sorry
* File: HDU 1007 排序 
* Create Date:2014-11-18 
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

struct node{
    double x,y;
}p[N];

int cmp(node a,node b)
{
    //if(a.x-b.x<1e-8)
        return a.y<b.y;
    //return a.x<b.x;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1,n)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        double dis;
        double minn=sqrt((p[0].x-p[1].x)*(p[0].x-p[1].x)+(p[0].y-p[1].y)*(p[0].y-p[1].y));
        //cout<<"--"<<minn<<endl;
        for(int i=2;i<n;i++)
        {
        
            dis=sqrt((p[i].x-p[i-1].x)*(p[i].x-p[i-1].x)+(p[i].y-p[i-1].y)*(p[i].y-p[i-1].y));
            //cout<<dis<<endl;
            if(dis<minn)
                minn=dis;
            if(minn==0)
                break;
        }

        printf("%.2f\n",minn/2);
    }

	return 0;
}
/* 数据有问题，正解应该是按x排，求minn，然后再按y排，求minn*/
