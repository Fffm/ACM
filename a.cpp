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

int a[30010];
vector<int> ans[30010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    int cnt=0;
    int p;
    for(int i=0;i<n;i++){
        p=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[p])
                p=j;
        }
        if(p!=i)
        {
            cnt++;
            swap(a[i],a[p]);
            ans[cnt-1].push_back(i);
            ans[cnt-1].push_back(p);
        }
    }

    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
        printf("%d %d\n",ans[i][0],ans[i][1]);



	return 0;
}

