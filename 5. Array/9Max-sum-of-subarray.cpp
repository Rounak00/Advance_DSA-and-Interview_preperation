//If all number is negetive then use
int maxSum(int arr[], int n)
{
	int res = arr[0];

	int maxEnding = arr[0];

	for(int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);

		res = max(maxEnding, res);
	}
	
	return res;
}
// naive: 2loop
//Efficient: kadane's algo

// Its also accepyted
int sum(int a[],int n){
	int sum=0;
	int ans=INT_MIN;
	for(itn i=0;i<n;i++){
		sum+=a[i];
		ans=max(ans,sum);
		if(sum<0){sum=0;}
	}
	return ans;
}