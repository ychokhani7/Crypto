#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int key[4];

int gcdExtended(int a, int b, int *x, int *y);  
int modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    int res = (x%m + m) % m; 
    return res; 
} 
int gcdExtended(int a, int b, int *x, int *y) 
{  
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string cryp;
    getline(cin,cryp);
    
    string s1,s2;
    cin>>s1>>s2;
   
    
    key[0]=(4*(s1[0]-'A')+19*(s2[0]-'A'))%26;
    key[1]=(4*(s1[1]-'A')+19*(s2[1]-'A'))%26;
    key[2]=(19*(s1[0]-'A')+19*(s2[0]-'A'))%26;
    key[3]=(19*(s1[1]-'A')+19*(s2[1]-'A'))%26;
    
   
    int det=key[0]*key[3]-key[1]*key[2];
    swap(key[0],key[3]);
    key[1]=-1*key[1];
    key[2]=-1*key[2];
    det=((det%26)+26)%26;
    int modinv=modInverse(det,26);
    
    key[0]=((key[0]*modinv)%26+26)%26;
    key[1]=((key[1]*modinv)%26+26)%26;
    key[2]=((key[2]*modinv)%26+26)%26;
    key[3]=((key[3]*modinv)%26+26)%26;
    
    for(int i=0;i<cryp.length();i+=2)
    {
        int v1=((cryp[i]-'A')*key[0]+(cryp[i+1]-'A')*key[2])%26+65;
        int v2=((cryp[i]-'A')*key[1]+(cryp[i+1]-'A')*key[3])%26+65;
        cout<<(char)v1<<(char)v2;
    }
  	return 0;
}