/************************************************
* Author: Ac_sorry
* File: A
* Create Date: 2014-11-16
*************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

vector<int> break_int(int n)
{
    vector<int> t;
    while(n)
    {
        t.push_back(n%10);
        n/=10;
    }
    return t;
}

bool check(vector<int> &t)
{
    int n=t.size();
    for(int i=0;i<n/2;i++)
    {
        if(t[i]!=t[n-1-i])
            return false;
    }
    return true;
}

int add(int n,vector<int> &t)
{
    int size=t.size();
    for(int i=size-1;i>=0;i--)
    {
        n+=t[i]*pow(10,size-1-i);
    }
    return n;
}



int main()
{
    int n;
    int cnt;
    vector<int> ans;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        ans.clear();
        ans.push_back(n);
        vector<int> tmp;
        while(!check(break_int(n)))
        {
            cnt++;
            n=add(n,break_int(n));
            ans.push_back(n);
        }
        printf("%d\n",cnt);
        int len=ans.size();
        printf("%d",ans[0]);
        for(int i=1;i<n;i++)
            printf("--->%d",ans[i]);
        printf("\n");


    }

	return 0;
}

