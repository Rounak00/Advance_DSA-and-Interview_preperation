#include<iostream>
#include<algorithm>
using namespace std;

void changemat(int mat[][4]){
int size=4;
int ch=1;
 for(int i=0;i<size;i++){
     if(mat[i][0]==0){ch=0;}
   for(int j=1;j<size;j++){
       if(mat[i][j]==0){
           mat[i][0]=mat[0][j]=0;
       }
   }
 }
 for(int i=size;i<=0;i--){
     for(int j=size;j<=1;j--){
         if(mat[i][0]==0||mat[0][j]==0){mat[i][j]==0;}
     }
     if(ch==0){mat[i][0]==0;}
 }

}
int main()
{	
    int size=4;
	int arr[4][4] = {{0, 2, 3, 4},
				    {5, 6, 7, 8},
				    {9, 10, 0, 12},
				    {13, 14, 15, 16}};

  changemat(arr);
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
       cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
	return 0;
}