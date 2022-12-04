//PROBLEM LINK
https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution{
  public:
  
bool valid_subpart(string s, int i, int j){
    int len = j-i+1;
    if(len >3) return false;
    if(s[i] == '0'){
        if(len == 1) return true;
        return false;
    }
    int num = stoi(s.substr(i,j-i+1));
    if(num>=0 && num<=255) return true;
    return false;
}

bool valid_ip(string s, int len, int i, int j, int k){
    if(valid_subpart(s,0,i) && valid_subpart(s,i+1,j) && valid_subpart(s,j+1,k) && valid_subpart(s,k+1,len-1))
        return true;
    return false;    
}

void add_string(string s, int n, int i, int j, int k,vector<string> &res){
    string temp;
    temp.append(s.substr(0,i+1));
    temp.push_back('.');
    temp.append(s.substr(i+1,j-i));
    temp.push_back('.');
    temp.append(s.substr(j+1,k-j));
    temp.push_back('.');
    temp.append(s.substr(k+1,n-k-1));
    res.push_back(temp);
}

vector<string> genIp(string &s) {
    int i,j,k,n;
    vector<string> res;
    n = s.length();
    
    for(i=0;i<n-3;i++){
        for(j=i+1;j<n-2;j++){
            for(k=j+1;k<n-1;k++){
                if(valid_ip(s,n,i,j,k)){
                    add_string(s,n,i,j,k,res);
                }
            }
        }
    }
    return res;
}

};