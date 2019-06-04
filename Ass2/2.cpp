#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int val(string s)
{
    int ans=0;
    for(int i=0;i<s.length();i++)
    {
        ans*=2;
        ans+=s[i]-'0';
    }
    return ans;
}
 
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string f,g,w;
    cin>>f>>g>>w;
    int valw=val(w);
    int n=w.length();
    valw^=(1<<(n-1));
    //cout<<valw<<endl;
    int a[21]={};
    a[0]=1;
    for(int i=1;i<21;i++)
    {
        a[i]=a[i-1]*2;
        if(i<n-1)
            continue;
        if(a[i]&(1<<(n-1)))
        {
            //cout<<i<<' '<<a[i]<<endl;
            a[i]^=valw;
            a[i]^=(1<<(n-1));
            //cout<<i<<endl;
        }
       // cout<<i<<' '<<a[i]<<endl;
    }
    int ans=0;
    int valf=0;
    int tempvalf=val(f);
    //cout<<valf<<endl;
    reverse(f.begin(),f.end());
    for(int i=0;i<f.length();i++)
    {
        if(i<n-1)
        {
            if(f[i]=='1')
                valf^=(1<<(i));
            continue;
        }
        if(f[i]=='1')
            valf^=a[i];
    }
    //cout<<valf<<endl;
    for(int i=0;i<g.length();i++)
    {
        if(g[i]=='1')
        {
            int cur=(valf<<(g.length()-i-1));
            for(int i=n-1;i<21;i++)
            {
                if(cur&(1<<i))
                {
                    cur^=a[i];
                    cur^=(1<<i);
                }
            }
            //cout<<cur<<' '<<i<<endl;
            ans^=cur;
        }
    }
    int flag=0;
    for(int i=n-1;i>=0;i--)
    {
        if(ans&(1<<i))
        {
            flag=1;
            cout<<1;
        }
        else if(flag)
            cout<<0;
    }
    if(!flag)
        cout<<0;
  //  cout<<ans;
    return 0;
}