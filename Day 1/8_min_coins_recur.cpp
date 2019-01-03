/*
minimum number of coins i.e. greedy shopkeeper problem
using recursive approach
Run both this example and dp one(example 9)a and compare the run times(for input 100)

https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

SPOILER ALERT: this approach checks all possible ways the coins could be divided and so is always correct, abeit a bit slow
*/

#include <bits/stdc++.h>
using namespace std;

//recursive approach to minimum number of coins to give Rs. 'change'
int minCoins(vector<int> &denom, int change)
{
    //initializing mini as some large value
    int mini = change+1;

    //base case for recursion
    //if change is zero, return 0 coins needed
    if(change==0)
        return 0;

    //iterate over all the coins and if the number of coins required for the step starting with that coin be smaller than mini, set it to mini
    for(int i = 0; i < denom.size(); i++)
    {
        //if coin i has value less than or equal to change
        if(denom[i] <= change)
            mini = min(mini, 1+minCoins(denom, change-denom[i]));
    }

    //return mini as minimum number of coins required
    return mini;
}

int main()
{
    //array/list of available coins i.e. denominations
    //for greedy, if this was not sorted in decreasing order, it would have to be sorted beforehand, since we are selecting the local maximum i.e. the highest value coin we can at every step
    vector<int> denom = {9, 6, 5, 1};

    //input: change to return to the customer
    int n;
    scanf(" %d", &n);

    //output: printing minimum number of coins
    printf("Min number of coins = %d\n", minCoins(denom, n));

    return 0;
}
