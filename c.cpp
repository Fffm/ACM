/************************************************
* Author: Ac_sorry
* File: 
* Create Date:2014-11-18 
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

int main()
{

    int n,mm;
    char num_l[111];
    char num_s[111];
    while(scanf("%d%d",&n,&mm)==2)
    {
        memset(num_l,'0',sizeof num_l);
        memset(num_s,'0',sizeof num_s);
        if(n>1&&mm==0)
            printf("-1 -1\n");
        else if (n==1&&mm==0)
            printf("0 0\n");
        else
        {
            if(mm>n*9)
                printf("-1 -1\n");
            else
            {
                int m=mm;
                if(mm<(n-1)*9+1)
                {
                    m=mm-1;
                    num_s[0]='1';
                }
                for(int i=n-1;i>=0;i--)
                {
                    if(m>9)
                    {
                         m-=9;
                         num_s[i]='9';
                    }
                     else
                    {
                        num_s[i]=m+'0';
                        break;
                    }
                }
                m=mm;
                for(int i=0;i<n;i++)
                {
                    if(m>9)
                    {
                        m-=9;
                        num_l[i]='9';
                    }
                    else
                    {
                        num_l[i]=m+'0';
                        break;
                    }
                }

                num_s[n]=num_l[n]='\0';
                printf("%s %s\n",num_s,num_l);
            }
        }
    }

	return 0;
}

