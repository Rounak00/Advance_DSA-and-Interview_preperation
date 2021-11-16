#include<bits/stdc++.h>
using namespace std;

void combinationSumUtil(int i, int sum, int target,vector<int> &arr,vector<vector<int> > &combinations,vector<int> &possibleCombination){
    if(sum == target){
        combinations.push_back(possibleCombination);
        return;
    }

    if(sum > target || i == arr.size()){
        return;
    }
    combinationSumUtil(i+1,sum,target,arr,combinations,possibleCombination);
    
    sum += arr[i];
    possibleCombination.push_back(arr[i]);
    combinationSumUtil(i,sum,target,arr,combinations,possibleCombination);
    sum -= arr[i];
    possibleCombination.pop_back();
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    sort( A.begin(), A.end() );
    A.erase( unique( A.begin(), A.end() ), A.end() );
    vector<vector<int> > combinations;
    vector<int> possibleCombination;
    combinationSumUtil(0,0,B,A,combinations,possibleCombination);
    return combinations;
}

//TC= O(2^n);
