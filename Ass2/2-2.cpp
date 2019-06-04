#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int val(string s);
int valf=0;
int flag=0;
int main()
{
    string f,g,w;
    cin>>f>>g>>w;
    int n=w.length();
    int valw=val(w);
    int tempvalf=val(f);
    reverse(f.begin(),f.end());
    valw^=(1<<(n-1));
    int a[21]={};
    int ans=0;
    a[0]=1;
    for(int i=1;i<21;i++)
    {
        a[i]=a[i-1]*2;
        if(i<n-1)
            continue;
        if(a[i]&(1<<(n-1)))
        {
            a[i]^=valw;
            a[i]^=(1<<(n-1));
        }
    }
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
            ans^=cur;
        }
    }
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
    return 0;
}
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
