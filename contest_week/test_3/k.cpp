/************************************************
* Author: Ac_sorry
* File:K 
* Create Date: 2014-11-17
*************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

char s[30];
int mima[100010];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int v;
        int ok;
        for(int i=0;i<n;i++)
            scanf("%d",mima+i);
        for(int i=0;i<26;i++)
        {
            ok=1;
            for(int j=0;j<n;j++)
            {
                s[j]=mima[j]^('A'+i);
                if(s[j]<'A'||s[j]>'Z')
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                s[n]='\0';
                printf("%s\n",s);
                break;
            }
        }
    }

	return 0;
}

