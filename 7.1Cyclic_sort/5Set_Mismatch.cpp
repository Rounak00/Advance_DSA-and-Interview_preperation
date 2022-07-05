/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int i=0;
    while(i<arr.size()){
        int c=arr[i]-1;
        if(arr[i]==arr[c]){
            i++;
        }
        else{
            swap(arr[i],arr[c]);
        }
    }
        for(int j=0;j<arr.size();j++){
            if(arr[j]-1!=j){
                return {arr[j],j+1};
            }
        }
        return {-1,-1};
    } 
};