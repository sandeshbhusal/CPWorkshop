
/*
minimum number of coins i.e. greedy shopkeeper problem
using recursive approach with dynamic programming
Run both examples 8 and 9 and compare the run times(for input 100)

Resources:
https://www.geeksforgeeks.org/dynamic-programming/
https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

DIFFERENCES BETWEEN Naive Recursive AND Dynamic Programming optimized solutions
1) vector/array/dictionary to store calculated values(line 63)
2) when function called, check if value has already been calculated before(line 26)
3) set calculated value to the vector/array/dictionary(line 48)
4) pass the vector/array/dictionary by reference(line 24)

SPOILER ALERT: this approach checks all possible ways the coins could be divided and so is always correct, and optimized using dynamic programming
*/

#include <bits/stdc++.h>
using namespace std;

//dp approach to minimum number of coins to give Rs. 'change'
int minCoins(vector<int> &minCoinsArr, vector<int> &denom, int change)
{
    //if value has already been calculated before
    if(minCoinsArr[change]!=-1)
        return minCoinsArr[change];

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
            mini = min(mini, 1+minCoins(minCoinsArr, denom, change-denom[i]));
    }

    //return mini as minimum number of coins required
    //also set the calculated value in minCoinsArr
    return minCoinsArr[change] = mini;
}

int main()
{
    //array/list of available coins i.e. denominations
    //for greedy, if this was not sorted in decreasing order, it would have to be sorted beforehand, since we are selecting the local maximum i.e. the highest value coin we can at every step
    vector<int> denom = {9, 6, 5, 1};

    //input: change to return to the customer
    int n;
    scanf(" %d", &n);

    //vector to store the min number of coins required for change ranging from [0, change] i.e. memoization table
    //default value -1 denotes that minCoins for that value of change has not been collected until now
    vector<int> minCoinsArr(n+1, -1);

    //output: printing minimum number of coins
    printf("Min number of coins = %d\n", minCoins(minCoinsArr, denom, n));

    return 0;
}
