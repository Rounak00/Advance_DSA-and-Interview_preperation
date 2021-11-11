// recursive bubble sort

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	// Base case
	if (n == 1)
		return;

	// One pass of bubble sort. After
	// this pass, the largest element
	// is moved (or bubbled) to end.
	for (int i=0; i<n-1; i++)
		if (arr[i] > arr[i+1])
			swap(arr[i], arr[i+1]);

	// Largest element is fixed,
	// recur for remaining array
	bubbleSort(arr, n-1);
}


TC: O(n^2)
SC: O(n)

//Recursive insertion

void insertionSortRecursive(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;
 
    // Sort first n-1 elements
    insertionSortRecursive( arr, n-1 );
 
    // Insert last element at its correct position
    // in sorted array.
    int last = arr[n-1];
    int j = n-2;
 
    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}



//Sort Array in aditiya verma:


void pos(vector<int>a, int n, int tem){
    if(n==0){
        a.push_back(tem);
        return;
    }
    if(a[n-1]<tem){
        a.push_back(tem);
    }
    else{
        int temp=a[n-1];
        pos(a,n-1,tem);
        a.push_back(temp);
    }
}

void sorty(vector<int>a,int n){
    if(n==1){
        return;
    }
    int temp=a[a.size()-1];
    sorty(a,a.size()-1);
   
   pos(a, a.size()-1, temp);
    
}

int main() {
    
    vector<int>a={3,1,2};
    sorty(a,a.size());
    for(auto i:a){
        cout<<i<<" ";
    }
    return 0;
}