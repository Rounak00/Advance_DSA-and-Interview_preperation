#include <bits/stdc++.h> 
using namespace std; 
#define ROW 4 
#define COL 3 


class Node 
{ 
	public: 
	bool isEndOfCol; 
	Node *child[2];
} ; 


Node* newNode() 
{ 
	Node* temp = new Node(); 
	temp->isEndOfCol = 0; 
	temp->child[0] = temp->child[1] = NULL; 
	return temp; 
} 


bool insert(Node** root, int (*M)[COL], 
				int row, int col ) 
{ 
	
	if (*root == NULL) 
		*root = newNode(); 

	
	if (col < COL) 
		return insert (&((*root)->child[M[row][col]]), 
										M, row, col + 1); 

	else  
	{ 
		 
		if (!((*root)->isEndOfCol)) 
			return (*root)->isEndOfCol = 1; 

		
		return 0; 
	} 
} 




int  countDis(int (*M)[COL]) 
{ 
	Node* root = NULL;  
	int i; 
    int cnt = 0;
	
	for (i = 0; i < ROW; ++i) 
	    if (insert(&root, M, i, 0)) 
		    cnt++;
		    
	return cnt;
} 

 
int main() 
{ 
	int M[ROW][COL] = {{1, 0, 0},  
                       {1, 1, 1},  
                       {1, 0, 0},  
                       {0, 1, 0}}; 

	cout << countDis(M); 

	return 0; 
} 