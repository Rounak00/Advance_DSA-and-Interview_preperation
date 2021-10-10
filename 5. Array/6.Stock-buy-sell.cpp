#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//naive: 
/*
int maxProfit(int price[], int start, int end)
{
	if(end <= start)
		return 0;

	int profit = 0;

	for(int i = start; i < end; i++)
	{
		for(int j = i + 1; j <= end; j++)
		{
			if(price[j] > price[i])
			{
				int curr_profit = price[j] - price[i] 
								  + maxProfit(price, start, i - 1)
								  + maxProfit(price, j + 1, end);

				profit = max(profit, curr_profit);
			}
		}
	}

	return profit;
}
*/
//efficient:-
int maxProfit(int price[], int n)
{
	int profit = 0;

	for(int i = 1; i < n; i++)
	{
		if(price[i] > price[i - 1])
			profit += price[i] - price[i -1];
	}

	return profit;

}

// if the question said only one time buy and sell then first use 2 loop, then aux space where we store from right to left max, then optimize is we can run a loop for left and always see it's max profit we use additional three variables
