#include<iostream>
#include<algorithm>
using namespace std;
int R=4 , C=4;

int printsum(int arr[][4]){
   int sum1,sum2;
   int size=4;
   for(int i=0;i<size;i++){
    sum1+=arr[i][i];
    sum2=arr[i][size-1-i];
   }
   if(size%2==0){
       return(sum1+sum2-(arr[size/2][size/2]));
   }
return (sum1+sum2);
}



int main()
{	
	int arr[4][4] = {{1, 2, 3, 4},
				    {5, 6, 7, 8},
				    {9, 10, 11, 12},
				    {13, 14, 15, 16}};

  printsum(arr);

	return 0;
}