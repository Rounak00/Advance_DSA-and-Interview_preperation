#include <bits/stdc++.h>
using namespace std;

#define N 4 
  
int board[N][N];  

void printSolution(int board[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
} 
  
bool isSafe(int row, int col) 
{ 
  
    for (int i = 0; i < col; i++)  //for that Row
        if (board[row][i]) 
            return false; 
  
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)  //for upper diagonal
        if (board[i][j]) 
            return false; 
  
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) //for lower diagonal
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  
bool solveRec(int col) 
{ 
    if (col == N) 
        return true; 
  
    for (int i = 0; i < N; i++) { 
     
        if (isSafe(i, col)) { 
            board[i][col] = 1; 
  
            if (solveRec(col + 1)) 
                return true; 
  
            board[i][col] = 0;
        } 
    } 
  
    return false; 
} 
  
bool solve() 
{
    if (solveRec(0) == false) { 
        printf("Solution does not exist"); 
        return false; 
    } 
  
    printSolution(board); 
    return true; 
}

int main() {
	
	solve(); 
    return 0; 
	
}

TC= O(N!)


//Another:

bool isSafe(int row, int col, int n, vector<int> &queenArrangement){
    int i,j,temp;

    //Checks if it is row safe
    for(int r:queenArrangement){
        if(r == row) return false;
    }

    //Check if it upper diagonal safe
    temp = row-1;
    for(i=queenArrangement.size()-1;i>=0;i--){
        if(temp <= 0) break;
        if(temp == queenArrangement[i]) return false;
        temp--;
    }

    //Check if it is lower diagonal safe
    temp = row+1;
    for(i=queenArrangement.size()-1;i>=0;i--){
        if(temp > n) break;
        if(temp == queenArrangement[i]) return false;
        temp++;
    }

    return true;
}

void nqueen(int col, int n, vector<int> &queenArrangement, vector<vector<int> > &possibleQueenArrangements){
    //IT IS 1-BASED INDEXING, SO WE USED col > n, INSTEAD OF col == n
    if(col > n){
        possibleQueenArrangements.push_back(queenArrangement);
        return;
    }
    int row;
    for(row = 1;row <= n;row++){
        if(isSafe(row,col,n,queenArrangement)){
            queenArrangement.push_back(row);
            nqueen(col+1,n,queenArrangement,possibleQueenArrangements);
            queenArrangement.pop_back();
        }
    }
}

void print(vector<vector<int> > &possibleQueenArrangements){
    if(possibleQueenArrangements.size() == 0){
        cout<<"-1"<<endl;
        return;
    }
    for(auto arrangement: possibleQueenArrangements){
        cout<<"[";
        for(auto row : arrangement){
            cout<<row<<" ";
        }
        cout<<"] ";
    }
    cout<<endl;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> queenArrangement;
        vector<vector<int> > possibleQueenArrangements;
        nqueen(1,n,queenArrangement,possibleQueenArrangements);
        print(possibleQueenArrangements);
    }
    return 0; 
}


//Striver leetcode:
 bool isSafe1(int row, int col, vector<string> board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--; 
        }
        
        return true; 
    }
public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isSafe1(row, col, board, n)) {
                board[row][col] = 'Q'; 
                solve(col+1, board, ans, n); 
                board[row][col] = '.'; 
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
         
        solve(0,board, ans, n); 
        return ans; 
    }
    



//most optimize:

class Solution {

public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, 
               vector<int> &leftRow, 
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        
        for(int row = 0;row<n;row++) {
            if(leftRow[row]==0 && lowerDiagonal[row + col] == 0 
               && upperDiagonal[n-1 + col - row] == 0) {
                
                board[row][col] = 'Q'; 
                leftRow[row] = 1; 
                lowerDiagonal[row+col] = 1; 
                upperDiagonal[n-1 + col - row] = 1;
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
                board[row][col] = '.'; 
                leftRow[row] = 0; 
                lowerDiagonal[row+col] = 0; 
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 
        solve(0,board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
        return ans; 
    }
    
};