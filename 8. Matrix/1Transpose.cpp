#include <iostream>
#include <cmath>


using namespace std;

const int n = 4;
/*
Naive:-

void transpose(int mat[n][n])
{
	int temp[n][n];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			temp[i][j] = mat[j][i];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = temp[i][j];

}
*/
void transpose(int arr[][n]){
     for(int i = 0; i < n; i++){ 
		for(int j = i + 1; j < n; j++){ 
			swap(arr[i][j], arr[j][i]);
        }
     }
}
int main()
{	
	int arr[n][n] = {{1, 2, 3, 4},
				   {5, 6, 7, 8},
				   {9, 10, 11, 12},
				   {13, 14, 15, 16}};
   transpose(arr);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}	
	return 0;
}


/*
1 2 3

  calc
1
2
3   
*/
