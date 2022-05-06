//first occurane
int firsto(int a[],int n,int k){
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if(a[mid]<k){
            lo=mid+1;
        }
        else if(a[mid]>k){
            hi=mid-1;
        }
        else if(a[mid]==k){
             if(mid==0||a[mid]!=a[mid-1]){return mid;}
             else if(a[mid]==a[mid-1]){hi=mid-1;}
        }
    }
}

//Last occurance
int lastOcc(int arr[], int n, int x)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = (low + high) / 2;

		if(x > arr[mid])
			low = mid + 1;

		else if(x < arr[mid])
			high = mid - 1;

		else
		{
			if(mid == n - 1 || arr[mid + 1] != arr[mid])
				return mid;

			else
				low = mid + 1;
		}
	}
	return -1;
}

//Count occurances = first occurance - last occurance
