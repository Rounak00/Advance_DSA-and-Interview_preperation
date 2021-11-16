#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combinationSumUtil(int i, int sum, int target,vector<int> &arr,set<vector<int> >                &combinations,vector<int>&possibleCombination){
        if(sum == target){
            combinations.insert(possibleCombination);
            return;
        }

        if(sum > target || i == arr.size()){
            return;
        }
    
        sum += arr[i];
        possibleCombination.push_back(arr[i]);
        combinationSumUtil(i+1,sum,target,arr,combinations,possibleCombination);
        sum -= arr[i];
        possibleCombination.pop_back();
    
        combinationSumUtil(i+1,sum,target,arr,combinations,possibleCombination);
    }
    
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort( candidates.begin(), candidates.end() );
        set<vector<int> > combinations;
        vector<int> possibleCombination;
        combinationSumUtil(0,0,target,candidates,combinations,possibleCombination);
        vector<vector<int> > Combinations;
        for(auto x:combinations){
            Combinations.push_back(x);
        }
        return Combinations;
    }
};

// best solution using DP
//you need to use set in recursion