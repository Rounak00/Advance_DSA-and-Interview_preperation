Recursive Solution and memoize solutions:

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You can do at most one transaction

class Solution {
public:
    int find(vector<int> &prices, int i,int k,bool buy,vector<vector<int>> &v)
    {
        //if we have no stock or we have no chance of transaction(k=0)
        if(i>=prices.size()||k<=0) return 0;
        if(v[i][buy]!=-1) return v[i][buy];
        
        if(buy)  //if we are buying then next time we will sell else next time we will buy
        {        //-prices[i], because bought stock of prices[i], expend money
            
           return v[i][buy]=max(-prices[i]+find(prices,i+1,k,!buy,v),find(prices,i+1,k,buy,v)); 
        }
        else    //it's time to sell , now decrease k, we have done 1 transaction
        {       //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
           return v[i][buy]=max( prices[i]+find(prices,i+1,k-1,!buy,v),find(prices,i+1,k,buy,v)); 
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(); 
        vector<vector<int>> v(n,vector<int> (2,-1));
        //passing here buy=1 because we will first buy then sell
        //we can do atmost k=1 transaction
        return find(prices,0,1,1,v);
    }
};
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

You can do as many transactions as you like

class Solution {
public:
int find(int ind,vector<int> &v,bool buy,vector<vector<int>> &memo)
{    
    if(ind>=v.size()) return 0;
    if(memo[ind][buy]!=-1) return memo[ind][buy];
    
    if(buy) //if we are buying then next time we will sell else next time we will buy
    {      //-prices[i], because bought stock of prices[i], expend money, !buy because next time sell
        
       return memo[ind][buy]=max(-v[ind]+find(ind+1,v,!buy,memo),find(ind+1,v,buy,memo));  
    }
    else   //it's time to sell 
    {      //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
        
       return memo[ind][buy]=max(v[ind]+find(ind+1,v,!buy,memo),find(ind+1,v,buy,memo));  
    }
     
}
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n<2) return 0;
        vector<vector<int>> v(n+1,vector<int>(2,-1));
        //passing here buy=1 because we will first buy then sell 
        return find(0,prices,1,v); 
    }
};
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

You may complete at most two transactions.

class Solution {
public:
    int find(vector<int> &prices,int ind,bool buy,int c,vector<vector<vector<int>>> &memo)
    {   
        //if buy =1 means we have to buy now
        //else we have to sell now
        if(ind>=prices.size()||c>=2) return 0; //counter
        if(memo[ind][buy][c]!=-1) return memo[ind][buy][c];
        if(buy) //now we can either buy prices[i] or we can skip it and try next to buy
        {
            return memo[ind][buy][c]=max(-prices[ind]+find(prices,ind+1,!buy,c,memo),find(prices,ind+1,buy,c,memo));
        }
        else  //now we can either sell prices[i] or we can skip it and try next to sell
        {
            return memo[ind][buy][c]=max(prices[ind]+find(prices,ind+1,!buy,c+1,memo),find(prices,ind+1,buy,c,memo));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        //here we can do maximum two transaction
        //Use 3-D vector because here three states i,k,buy/sell
        vector<vector<vector<int>>> memo(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
          
       return find(prices,0,1,0,memo); 
    }
};
 
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

You may complete at most k transactions.

class Solution {
public:
    int find(vector<int> &prices,int ind,bool buy,int c,int k,vector<vector<vector<int>>> &memo)
    {   //if buy =1 means we have to buy now
        //else we have to sell now
        if(ind>=prices.size()||c>=k) return 0; //counter
        
        else if(memo[ind][buy][c]!=-1) return memo[ind][buy][c];
         
        if(buy) //now we can either buy prices[i] or we can skip it and try next to buy
        {
        return memo[ind][buy][c]=max(-prices[ind]+find(prices,ind+1,!buy,c,k,memo),find(prices,ind+1,buy,c,k,memo));
        }
        else  //now we can either sell prices[i] or we can skip it and try next to sell
        {
        return memo[ind][buy][c]=max(prices[ind]+find(prices,ind+1,!buy,c+1,k,memo),find(prices,ind+1,buy,c,k,memo));
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
        
        //edge case we are not able to pick 2k points from n points, which means 
        //we will not reach the limit no matter how we try. 
        //if the price of day i arise, buy the stock in i-1th day and sell it at ith day.
        if (2 * k > prices.size()) {
            int res = 0;
            for (int i = 1; i < prices.size(); i++) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }
        
         //here we can do maximum k transaction
        vector<vector<vector<int>>> memo(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return find(prices,0,1,0,k,memo); 
    }
};