
varun goel
1 year ago
Simple and understandable code
#include<iostream>
using namespace std;

int main(){
	int arr[]={1,3,8,10,15};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	int key=20;
	int s,e,m;
	
	s=0;
	e=n-1;
	
	while(s<=e){
		m=s+(e-s)/2;
		
		if(arr[m]==key){
			cout<<"Minimum difference is 0";
			return 0;
		}else if((arr[m]>key) && (m==0 || arr[m-1]<key)){
			int d1=abs(arr[m]-key);
			int d2=abs(key-arr[m-1]);
			
			if(d1<d2){
				cout<<"Min difference is "<<d1<<" with element "<<arr[m];
				return 0;
			}else{
				cout<<"Min difference is "<<d2<<" with element "<<arr[m-1];
				return 0;
			}
		}else if((arr[m]<key) && m==e){
			cout<<"Min difference is "<<key-arr[m]<<" with element "<<arr[m];
			return 0;
		}else if(arr[m]<key){
			s=m+1;
		}else{
			e=m-1;
		}
	}
	
	return -1;
}