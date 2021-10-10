#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int a[]={1,1,1,2,2,4,4,4,4,4,5,7};
    int n=12;
   
    int freq = 1, i = 1;

	while(i < n)
	{
		while(i < n && a[i] == a[i - 1])
		{
			freq++;
			i++;
		}

		cout<<a[i - 1] << " " << freq << endl;

		i++;
		freq = 1;
	}
}