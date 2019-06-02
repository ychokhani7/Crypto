#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

char mat[50000][26];
string key;
vector<pair<char,int>> v;
int l=0;

string fill_matrix(string plain)
{
    
    int r=1,c=1;
    for(int i=0;i<plain.length();i++)
    {
        mat[r][c++]=plain[i];
        if(c==l+1)
        {
            c=1;
            r++;
        }
    }
        
    if(c!=1)
    {
        for(int i=c;i<=l;i++)
            mat[r][i]='*';
    }
    else r--;

    string ne="";
    for(int i=0;i<v.size();i++)
        for(int j=1;j<=r;j++)
           ne+=mat[j][v[i].second];
    return ne;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string plain;
    getline(cin,plain);
    getline(cin,key);
    
    int n;
    cin>>n;
    
    transform(plain.begin(), plain.end(),plain.begin(), ::toupper);
    transform(key.begin(), key.end(),key.begin(), ::toupper);
    string::iterator end_pos = remove(plain.begin(), plain.end(), ' ');
    plain.erase(end_pos, plain.end());  
    
    l=key.length();
    
    for(int i=0;i<l;i++)
        v.push_back({key[i],i+1});
    sort(v.begin(),v.end());
    
    string news=plain;
    for(int i=1;i<=n;i++)
        news=fill_matrix(news);
    
    cout<<news<<endl;
  	return 0;
}