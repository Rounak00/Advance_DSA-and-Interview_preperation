#include<iostream>
using namespace std;

int calc(int a[]){
   int r=a.size()-1,l=0,hr=0,hl=0;
   int res=0;
   while(l<=r){
       
       if(a[l]<=a[r]){
          if(a[l]>=hl){hl=a[l];}
          else{res+=hl-a[l];
                l++;}
       }
       else{
           if(a[r]>=hr){hr=a[r];}
           else{ res+=hr-a[r]; r--;}
       }
   }
   return res;
}
int main(){
    int a[]={0};
    cout<<calc(a);
}

/*
//another solution for leetcode:
class Solution {
public:
    int maxArea(vector<int>& a) {
     int res=0; 
     int l=0, r=a.size()-1;
        
       while(l<r){
           int mi=min(a[l],a[r]);
           res=max(res, mi*(r-l));
           if(a[l]<a[r]){l++;}
           else{r--;}
       } 
        return res;
    }
};

*/