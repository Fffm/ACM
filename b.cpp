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


int boy[111];
int girl[111];
int num[111];
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",boy+i);
    sort(boy,boy+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",girl+i);
        num[girl[i]]++;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(num[boy[i]-1]>0)
        {
            num[boy[i]-1]--;
            cnt++;
        }
        else if(num[boy[i]]>0)
        {
            num[boy[i]]--;
            cnt++;
        }
        else if(num[boy[i]+1]>0)
        {
            num[boy[i]+1]--;
            cnt++;
        }
    }
    printf("%d\n",cnt);





	return 0;
}

