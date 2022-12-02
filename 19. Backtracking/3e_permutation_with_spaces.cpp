//PROBLEM LINK
//https://practice.geeksforgeeks.org/problems/permutation-with-spaces/0

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution{
public:
   void helper(string &s, set<string>&ans, int i ){
       if(i+1==s.length()){
           ans.insert(s);
           return;
       }
       helper(s,ans,i+1);
       s.insert(i+1," ");
       helper(s,ans,i+2);
       s.erase(i+1,1);
   }
    vector<string> permutation(string s){
        set<string>ans;
        helper(s,ans,0);
        vector<string>a;
        for(auto i=ans.begin();i!=ans.end();i++){
            a.push_back(*i);
        }
        return a;
    }
};