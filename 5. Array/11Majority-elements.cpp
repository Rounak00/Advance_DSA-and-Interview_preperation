#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//naive: 2loop
//eficient: hashmap / unordermap
//efficiemt: first sort then count
//effcient: booyer's moor's algo
int findMajority(int arr[], int n)
{
	int res = 0, count = 1;
    	for(int i = 1; i < n; i++)
    	{
    		if(arr[res] == arr[i])
    			count++;
    		else 
    			count --;
    		if(count == 0)
    		{
    			res = i; count = 1;
    		}
    	}
    	count = 0;
    	for(int i = 0; i < n; i++)
    		if(arr[res] == arr[i])
    			count++;
    	if(count <= n /2)
    		res = -1;
    	return res; 
}

// Psyuedo :
/*
1. We assume we have our first element which is at first one time so we start a loop from second element 
2. if that element and second element is same then count ++ and if not then count -- 
3. if count is ==0 then count again start from one for this particular element
*/