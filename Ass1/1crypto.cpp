#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	string str;
	int len;
	//cout<<"Enter the encrypted text : ";
	cin>>str;
	len = str.length();
	//cout<<"\n The length of encrypted text is: "<<len<<"\n";
	int x = (len+1)/2;
	//cout<<"The length of plain text will be: "<<x<<"\n";
	string arr="";
	char d= str[0];
	arr=arr+d;
	//cout<<arr[0];
	int z=1;
    for (int i = 0; i < x-1; i++)
    {
    	int a = str[i];
	    int b = str[i+1];
	    if(a>47 && a<58)
            a = a - 48;
        else if (a>96 && a<103)
            a=a-87;
        else if (a>64 && a<71)
            a= a-55;

        if(b>47 && b<58)
            b = b - 48;
        else if (b>96 && b<103)
            b=b-87;
        else if (b>64 && b<71)
            b= b-55;

	int c = a ^ b;

	if (c>=0 && c<=9)
	{
	    arr+=c;//cout<<char(c)<<endl;
	}
	else if (c>9 && c<=25)
	{
		c = c + 55;
		c=c+32;
		//cout<<char(c)<<endl;
		arr+=c;
	}

    }
    //cout<<arr[x-1];
    cout<<arr;


	return 0;
}