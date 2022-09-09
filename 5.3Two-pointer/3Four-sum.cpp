class Solution {
public:
   vector<vector<int>> fourSum(vector<int>& a, int t) {
	vector<vector<int>> res;
	if(a.size() < 4) return res;
	int n = a.size();

	//1. Sort
	sort(a.begin(), a.end());

	//2. Fix i and j, and search for a twoSum pair in the remaining array.
	for(int i=0; i<n; i++){
        long long int t3=t-a[i];
		for(int j=i+1; j<n; j++){
			long long int t2 = t3-a[j];
			int low = j+1, high = n-1;
			while(low<high){
				int sum = a[low] + a[high];
				if(sum == t2){
					
					res.push_back({a[i],a[j],a[low],a[high]});
					while(low<high && a[low]== a[low+1]) low++;
					while(low<high && a[high] == a[high-1]) high--;
					low++;
					high--;
				}
				else if(sum < t2){
                  do{low++;
                    }while(low<high && a[low]==a[low-1]);
                } 
				else{ 
                 do{
                     high--;
                 }while(low<high && a[high]==a[high+1]);
                }
                
			}
			while(j+1 < n && a[j] == a[j+1]) j++;
			//Like low++ and high--, we didn't write j++ again because j loop above increments it to next position.
		}
		while(i+1 < n && a[i] == a[i+1]) i++;
		//Like low++ and high--, we didn't write i++ again because i loop above increments it to next position.
	}
	return res;

        
    }
};