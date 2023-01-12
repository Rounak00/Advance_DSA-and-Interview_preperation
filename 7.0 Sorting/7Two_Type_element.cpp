//Naive: use temp array
//Efficient: lomuto partition
    //questeion may varry like posetive-negetive, odd-even, o-1;


#include <iostream>
using namespace std;

void sort(int arr[],int n){
    int i=-1,j=n;
    while(true)
    {
        do{i++;}while(arr[i]<0);
        do{j--;}while(arr[j]>=0);
        if(i>=j)return;
        swap(arr[i],arr[j]);
    }
}

int main() {
	
    int arr[]={13,-12,18,-10};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	sort(arr,n);
	
	for(int x:arr)
	    cout<<x<<" ";
}

//Also can this
void segregate0and1(int arr[], int n)
{

    int type0 = 0;

    int type1 = n - 1;
 

    while (type0 < type1) {

        if (arr[type0] == 1) {

            swap(arr[type0], arr[type1]);

            type1--;

        }

        else {

            type0++;

        }

    }
}
