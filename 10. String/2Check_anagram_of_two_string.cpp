/*
//Naive
#include <bits/stdc++.h> 
using namespace std; 
  
bool areAnagram(string &s1, string &s2) 
{ 
    int n1 = s1.length(); 
    int n2 = s2.length(); 
    if (n1 != n2) 
        return false; 
  
    sort(s1.begin(), s1.end()); 
    sort(s2.begin(), s2.end()); 
  
    return (s1==s2); 
} 
 
int main() 
{ 
    string str1 = "abaac"; 
    string str2 = "aacba"; 
    if (areAnagram(str1, str2)) 
        cout << "The two strings are anagram of each other"; 
    else
        cout << "The two strings are not anagram of each other"; 
  
    return 0; 
} 
*/


//Efficient:
#include <bits/stdc++.h> 
using namespace std; 

const int CHAR=256;
bool areAnagram(string &s1, string &s2) 
{ 
    int n1 = s1.length(); 
    int n2 = s2.length(); 
    if (n1 != n2) 
        return false; 
    
    int count[CHAR]={0};
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    
    for(int i=0;i<CHAR;i++){
        if(count[i]!=0)return false;
    }
    return true;
} 
 
int main() 
{ 
    string str1 = "abaac"; 
    string str2 = "aacba"; 
    if (areAnagram(str1, str2)) 
        cout << "The two strings are anagram of each other"; 
    else
        cout << "The two strings are not anagram of each other"; 
  
    return 0; 
} 