/*
minimum nuber of coins i.e. greedy shopkeeper problem
using greedy

Question from : https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

SPOILER ALERT: this approach is not correct for all cases. case in point, change of Rs 11 given denominations below
*/

#include <bits/stdc++.h>
using namespace std;

//greedy approach to minimum number of coins to give Rs. 'change'
int minCoins(vector<int> &denom, int change)
{
    int coin_count = 0;

    for(int i = 0; i < denom.size(); i++)
    {
        //if change left to give is greater than or equal to the value of the
        //i'th coin, select that coin(increment coin_count), decrement change by the coins value
        while(change >= denom[i])
        {
            coin_count++;
            change -= denom[i];
        }

        //if change is already accounted for, break out of the loop
        if(change==0) break;
    }
    return coin_count;
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
