class SegmentTree{ // base class
    
    vector<int> treeArray;
    public:
    void set(int n){
        treeArray.resize(4*n, 0);
    }
    void buildTree(int tIndex, int low, int high, vector<int>&nums){
        if(low>high){return;}
        if(low==high){
            treeArray[tIndex] = nums[low];
            return;
        }
        
        int midIndex = low + (high-low)/2;
        
        buildTree(2*tIndex + 1, low, midIndex, nums);
        buildTree(2*tIndex + 2, midIndex+1, high, nums);
        
        treeArray[tIndex] = treeArray[2*tIndex+1] + treeArray[2*tIndex+2];
    }
    
    void updateTree(int tIndex, int low, int high, int valIndex, int val){
        if(low==high){
            treeArray[tIndex] = val;
            return;
        }
        
        int midIndex = low + (high-low)/2;
        
        if(valIndex <= midIndex){
            updateTree(2*tIndex+1, low, midIndex, valIndex, val);
        }else{
            updateTree(2*tIndex+2, midIndex+1, high, valIndex, val);
        }
        
        treeArray[tIndex] = treeArray[2*tIndex+1] + treeArray[2*tIndex+2];
    }
    
    int rangeQuery(int tIndex, int low, int high, int left, int right){
        if(left<=low && high<=right){
            return treeArray[tIndex];
        }
        
        if((right<low) || (high<left)){
            return 0;
        }
        
        int midIndex = low + (high-low)/2;
        
        return rangeQuery(2*tIndex+1, low, midIndex, left, right) + rangeQuery(2*tIndex+2, midIndex+1, high, left, right);
        
    }
};

class NumArray {
    SegmentTree obj;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        obj.set(n);
        obj.buildTree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        obj.updateTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return obj.rangeQuery(0, 0, n-1, left, right);
    }
};