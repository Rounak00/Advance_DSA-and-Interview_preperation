#include <iostream>
#include <cmath>

using namespace std;

const int R = 4, C = 4;
void bTraversal(int mat[R][C])
{
	if(R==1){
        for(int i=0;i<C;i++)cout<<mat[0][i]<<" ";
    }
    if(C==1){
        for(int i=0;i<R;i++)cout<<mat[i][0]<<" ";
    }
    else{
       for(int i=0;i<C;i++){cout<<mat[0][i]<<" ";}
       for(int i=1;i<R;i++){cout<<mat[i][C-1]<<" ";}
       for(int i=C-2;i>=0;i--){cout<<mat[R-1][i]<<" ";}
       for(int i=R-2;i>=1;i++){cout<<mat[i][0]<<" ";}
    }
}

int main()
{	
	int arr[R][C] = {{1, 2, 3, 4},
				   {5, 6, 7, 8},
				   {9, 10, 11, 12},
				   {13, 14, 15, 16}};

    bTraversal(arr);

	return 0;
}