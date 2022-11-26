class Solution {
private:
    void solve(string d,int ind, string output,string mapping[],vector<string>&ans){
      //basecase
        if(ind>=d.length()){ans.push_back(output); return;}
        
        int num=d[ind]-'0';
        string value=mapping[num];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(d,ind+1,output,mapping,ans);
            output.pop_back(); //backtrack
        }
    }
public:
    vector<string> letterCombinations(string d) {
        if(d.length()==0){return {};}
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs",
                            "tuv","wxyz"};
        string output;
        vector<string>ans;
        int ind=0;
        
        solve(d,ind,output,mapping,ans);
        return ans;
    }
};