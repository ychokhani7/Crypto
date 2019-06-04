#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 999999999
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,c1,c2,n1,n2;
    cin>>n>>c1>>n1>>c2>>n2;
    int x1=n/n1,x2=n/n2;
    int cost=INF,l1=0,l2=0,mi=0;
    for(int i=0;i<=x1;i++)
    {
        if((n-(i*n1))%n2==0)
        {
            x2=(n-(i*n1))/n2;
            mi=i*c1+x2*c2;
            if(mi<cost)
            {
                mi=cost;
                l1=i;l2=x2;
            }
        }
    }
    cout<<l1<<" "<<l2;
    return 0;
}

    //MIN COST IMPLEMENTATION DP SOLUTION
    // int mincost[3][n+1];
    // for (int i=0; i<=n; i++) 
    //     mincost[0][i] = INF; 
    // for (int i=1; i<=2; i++) 
    //     mincost[i][0] = 0;
    // int val[]={c1,c2},wt[]={n1,n2};
    // for (int i=1; i<=2; i++) 
    // { 
    //     for (int j=1; j<=n; j++) 
    //     { 
    //         if (wt[i-1] > j) 
    //             mincost[i][j] = mincost[i-1][j]; 
    //         else
    //             mincost[i][j] = min(mincost[i-1][j], mincost[i][j-wt[i-1]] + val[i-1]); 
    //     } 
    // } 
    // cout<<mincost[2][n];