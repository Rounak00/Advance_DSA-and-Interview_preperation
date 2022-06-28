class Solution {
public:
   string minWindow(string s, string p) {
         map<char,int>m;
    int n=s.size();
       if(s.size()<p.size()){return "";}
    for(int i=0;i<p.size();i++){
        m[p[i]]++;
    }
    int c=m.size();
    int i=0,j=0;
    int resStart=0,reslen=INT_MAX;
    while(j<n){
        m[s[j]]--;
        if(m[s[j]]==0){
            c--;
        }
        if(c==0){
            while(c==0){
                if(reslen>(j-i+1)){
                    reslen=j-i+1;
                    resStart=i;
                }
                if(m.find(s[i])!=m.end())
                {m[s[i]]++;
                if(m[s[i]]>0){
                    c++;
                }}
                i++;
            }
        }
        j++;
            
    }
    if(reslen==INT_MAX){
        return "";
    }
    return s.substr(resStart,reslen);
    }
};