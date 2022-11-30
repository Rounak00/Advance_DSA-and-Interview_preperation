void helper(string s, int n, int k, int ix,string &ans){
    if(k==0){return;}

    char maxc=s[ix];
    for(int i=ix+1;i<n;i++){
        if(maxc<s[ix])maxc=s[ix];
    }
    if(maxc!=s[ix]){k--;}
    for(int i=n-1;i>=ix;i--){
        if(maxc==s[i]){
            swap(s[ix],s[i]);
            if(ans<s)ans=s;
            helper(s,n,k,ix+1,ans);
            swap(s[ix],s[i]);
        }
    }
}


string solution(string s, int k){
    if(k==0){return s;}
    string ans=s;
    int ix=0;
    int n=s.length();
    solve(s,n,k,ix,ans)
    return ans;
}