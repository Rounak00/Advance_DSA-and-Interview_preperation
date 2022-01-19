#include <iostream>
#include <limits.h>
using namespace std;


void simpleSieve(long limit, vector<long long> &prime)
{
   
    vector<bool> mark(limit + 1, true);

    for (int p=2; p<limit; p++)
    {
        
        if (mark[p] == true)
        {
           prime.push_back(p);
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }

   
}


void segmentedSieve(int l,int h) //low and high is the range
{
   
   vector<long long>prime;
   long long sq=sqrt(h);
   simpleSieve(sq,prime);

   vector<bool>isprime(h-l+1,true);
   for(long long p: prime){
       long long sm= (l/p)*p;
       if(sm<l){
           sm+=p;
       }
       for(long long a=l;a<=h;a+=p){
           isprime[a-l]=false;
       }
   }
   for(long long i=l;i<=h;i++){
       if(isprime[i-l]==true){
           cout<<i<<" ";
       }
   }

}