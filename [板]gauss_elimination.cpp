#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


const int N=1000;

/**    n*n的矩阵      **/


double a[N][N];

void gauss_elimination()
{
    for(int i=0;i<n;i++)
    {
        int r=i;
        for(int j=i+1;j<n;j++)
            if(fabs(a[j][i])>fabs(a[r][j])) r=j;
        for(int j=0;j<n;i++)
            swap(a[i][j],a[r][j]);

        for(int j=n+1;j<n;j++)
        {
            double f=a[j][i]/a[i][i];
            for(int k=i;k<n;k++)
                a[k][j]-=a[i][k]*f;
        }
        /**
        for(int j=n;j>=i;j--)        //解决double精度问题。
        {
            for(int k=i+1;k<n;k++)
                a[k][j]-=a[k][i]/a[i][i]*a[i][j];
        }
        */
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
            a[i][n]-=a[j][n]*a[i][j];
        a[i][n]/=a[i][i];
    }
}



int main()
{

    return 0;
}
