//LPS
  //Naive:
      /*
         #include <bits/stdc++.h> 
using namespace std; 

int longPropPreSuff(string str, int n){
    for(int len=n-1;len>0;len--){
        bool flag=true;
        for(int i=0;i<len;i++)
            if(str[i]!=str[n-len+i])
                flag=false;
                
        if(flag==true)
            return len;
    }
    return 0;
}

void fillLPS(string str, int *lps){
    for(int i=0;i<str.length();i++){
        lps[i]=longPropPreSuff(str,i+1);
    }
}
 
int main() 
{ 
    string txt = "abacabad";int lps[txt.length()];
    fillLPS(txt,lps);
    for(int i=0;i<txt.length();i++){
        cout<<lps[i]<<" ";
    }
    
    return 0; 
} 
      */ 

    
/*
//LPS using kmp: 
void fillLPS(string str, int *lps){
    int n=str.length(),len=0;
    lps[0]=0;
    int i=1;
    while(i<n){
        if(str[i]==str[len])
        {len++;lps[i]=len;i++;}
        else
        {if(len==0){lps[i]=0;i++;}
            else{len=lps[len-1];}
        }
    }
}
 
int main() 
{ 
    string txt = "abacabad";int lps[txt.length()];
    fillLPS(txt,lps);
    for(int i=0;i<txt.length();i++){
        cout<<lps[i]<<" ";
    }
    
    return 0; 
} 
*/

//Pattern search using KMP:
#include <bits/stdc++.h> 
using namespace std; 


void fillLPS(string str, int *lps){
    int n=str.length(),len=0;
    lps[0]=0;
    int i=1;
    while(i<n){
        if(str[i]==str[len])
        {len++;lps[i]=len;i++;}
        else
        {if(len==0){lps[i]=0;i++;}
            else{len=lps[len-1];}
        }
    }
}
void KMP(string pat,string txt){
    int N=txt.length();
    int M=pat.length();
    int lps[M];
    fillLPS(pat,lps);
    int i=0,j=0;
    while(i<N){
        if(pat[j]==txt[i]){i++;j++;}

        if (j == M) { 
            printf("Found pattern at index %d ", i - j); 
            j = lps[j - 1]; 
        } 
        else if (i < N && pat[j] != txt[i]) { 
            if (j == 0) 
                i++;
            else
                j = lps[j - 1];  
        }
    }
}
 
int main() 
{ 
    string txt = "ababcababaad",pat="ababa";
    KMP(pat,txt);
    return 0; 
} 