#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

char mat[8][8];
bool vis[36];
string a="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string plain;
string key;
int r=1,c=1;
void fill_matrix()
{
    for(int i=0;i<key.length();i++)
    {
        if(isalpha(key[i])!=0)
        {
            if(vis[key[i]-'A'+10]==0)
            {
                vis[key[i]-'A'+10]=1;
                mat[r][c]=key[i];
                c++;
            }
        }
        else
        {
            if(vis[key[i]-'0']==0)
            {
                vis[key[i]-'0']=1;
                mat[r][c]=key[i];
                c++;
            }
        }
        if(c==7)
        {
            c=1;
            r++;
        }
    }
    
    if(c==7)
        c=1;
    for(int i=r;i<=6;i++)
    {
        for(int j=c;j<=6;j++)
        {
            c=1;
            for(int k=0;k<a.length();k++)
            {
                if(vis[k]==0)
                {
                    vis[k]=1;
                    mat[i][j]=a[k];
                    break;
                }
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin,plain);
    getline(cin,key);
    
    transform(plain.begin(), plain.end(),plain.begin(), ::toupper);
    transform(key.begin(), key.end(),key.begin(), ::toupper);
    string::iterator end_pos = remove(plain.begin(), plain.end(), ' ');
    plain.erase(end_pos, plain.end());  
    fill_matrix();
    vector <string> v={};
    string t="";
    for(int i=0;i<plain.length();i++)
    {
        t="";
        if(i==plain.length()-1)
        {
            t+=plain[i];
            t+='X';
            v.push_back(t);
        }
        else if(plain[i]==plain[i+1])
        {
            t+=plain[i];
            t+='X';
            v.push_back(t);
        }
        else
        {
            t+=plain[i];
            t+=plain[i+1];
            v.push_back(t);
            i++;
        }
    }
    int x1,x2,y1,y2;
    for(int i=0;i<v.size();i++)
    {
        for(int j=1;j<=6;j++)
        {
            for(int k=1;k<=6;k++)
            {
                if(v[i][0]==mat[j][k])
                    x1=j,y1=k;
                if(v[i][1]==mat[j][k])
                    x2=j,y2=k;
            }
        }
        if(x1==x2)
        {
            if(y1+1>6)
                y1=0;
            if(y2+1>6)
                y2=0;
            cout<<mat[x1][y1+1]<<mat[x2][y2+1];
        }
        else if(y1==y2)
        {
            if(x1+1>6)
                x1=0;
            if(x2+1>6)
                x2=0;
            cout<<mat[x1+1][y1]<<mat[x2+1][y2];
        }
        else
        {
            cout<<mat[x1][y2]<<mat[x2][y1];
        }
    }
  	return 0;
}