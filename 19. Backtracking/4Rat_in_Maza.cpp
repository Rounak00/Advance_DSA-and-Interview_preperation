#include <bits/stdc++.h>
using namespace std;

#define N 4 
  
bool solveMazeRec( 
    int maze[N][N], int x, 
    int y, int sol[N][N]); 
  

  
bool isSafe(int maze[N][N], int i, int j) 
{  
    return ( i < N && j < N && maze[i][j] == 1);
} 
 
bool solveMaze(int maze[N][N]) 
{ 
    int sol[N][N] = { { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } }; 
  
    if (solveMazeRec(maze, 0, 0, sol) == false) { 
        printf("Solution doesn't exist"); 
        return false; 
    } 
  
    printSolution(sol); 
    return true; 
} 

bool solveMazeRec( int maze[N][N], int i, int j, int sol[N][N]) 
{ 
    if ( i == N - 1 && j == N - 1 && maze[i][j] == 1) { 
        sol[i][j] = 1; 
        return true; 
    } 
  
    if (isSafe(maze, i, j) == true) { 
        sol[i][j] = 1; 
  
        if (solveMazeRec(maze, i + 1, j, sol) == true) 
            return true; 
  
        if (solveMazeRec(maze, i, j + 1, sol) == true) 
            return true; 
  
        sol[i][j] = 0; 
    } 
  
    return false; 
}

int main() {
	
	int maze[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 
  
    solveMaze(maze);    
    return 0;  
	
}

// Tc= O(2^(n^2))
// SC= O(n^2)

//Another Solution








bool issafe( int row, int col,int m[6][6],int n){
    if(row<0 || row>=n || col<0 || col>=n || !m[row][col])
        return false;
    return true;    
}

void solve(int r,int c,vector<string>&ans,string &cur,int mat[6][6],int n){
    if(r==n-1&&c==n-1)
    {
        ans.push_back(cur);
        return;
    }

    int rowchange[]={-1,1,0,0};
    int columnchange[]={0,0,-1,1};
    char d[]={'U','D','L','R'};

    for(int i=0;i<4;i++){
       if( issafe(r+rowchange[i],c+columnchange[i],mat,6) ){

        mat[r][c]=0;
        cur.push_back(d[i]);

        solve(r+rowchange[i],c+columnchange[i],ans,cur,mat,n);

        mat[r][c]=1;
        cur.pop_back();
       } 
    }
} 


int main (){
    int n=6;
    int mat[6][6]={{1,1,0,0,0,0},
                   {0,1,0,1,1,1},
                   {0,1,1,1,0,1},
                   {0,0,0,0,0,1},
                   {0,0,0,0,0,1},
                   {0,0,0,0,0,1}};
    vector<string>ans;
    string c;
    solve(0,0,ans,c,mat,n);
    for(auto i:ans){
        cout<<i<<" ";
    }
}