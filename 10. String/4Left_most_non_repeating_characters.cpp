/*
//Naive: 2loop

#include <bits/stdc++.h> 
using namespace std; 


int nonRep(string &str) 
{
    for(int i=0;i<str.length();i++){
        bool flag=false;
        for(int j=0;j<str.length();j++){
            if(i!=j&&str[i]==str[j]){
                flag=true;
                break;
            }
        }
        if(flag==false)return i;
    }
    return -1;
}
 
int main() 
{ 
    string str = "geeksforgeeks";
    cout<<"Index of leftmost non-repeating element:"<<endl;
    cout<<nonRep(str)<<endl;  
    
    return 0; 
} 

*/

/*
//Better:

#include <bits/stdc++.h> 
using namespace std; 

const int CHAR=256;
int nonRep(string &str) 
{
    int count[CHAR]={0};
    for(int i=0;i<str.length();i++){
        count[str[i]]++;
    }
    for(int i=0;i<str.length();i++){
        if(count[str[i]]==1)return i;
    }
    return -1;
}
 
int main() 
{ 
    string str = "geeksforgeeks";
    cout<<"Index of leftmost non-repeating element:"<<endl;
    cout<<nonRep(str)<<endl;  
    
    return 0; 
} 

*/


//Efficient:

#include <bits/stdc++.h> 
using namespace std; 

const int CHAR=256;
int nonRep(string &str) 
{
    int fI[CHAR];
    fill(fI,fI+CHAR,-1);
    
    for(int i=0;i<str.length();i++){
        if(fI[str[i]]==-1)
        fI[str[i]]=i;
        else
        fI[str[i]]=-2;
    }
    int res=INT_MAX;
    for(int i=0;i<CHAR;i++){
        if(fI[i]>=0)res=min(res,fI[i]);
    }
    return (res==INT_MAX)?-1:res;
}
 
int main() 
{ 
    string str = "geeksforgeeks";
    cout<<"Index of leftmost non-repeating element:"<<endl;
    cout<<nonRep(str)<<endl;  
    
    return 0; 
} 

