#include <iostream>
#include <vector>
using namespace std;

//stores the number of function calls that have been done for particular key
int num_calls = 0;

//only for use in sorted data sets
bool bin_search(vector<long> &primes, int l, int h, long key)
{
    num_calls++;
    //base case for recursion
    //when key not found
    if(l>=h)
        return false;

    int m = (l+h)/2;

    if(key == primes[m]) //if found
        return true;
    else if(key < primes[m]) // if key lies left of the mid value m
        return bin_search(primes, l, m, key); //recursively search in the left half
    else // if key lies right of the mid value m
        return bin_search(primes, m+1, h,  key); //recursively search in the right half
}

int main()
{
    //reads the file "prime1.txt" as input
    freopen("prime1.txt", "r", stdin);

    //number of primes upto 100,000,000, stored in prime1.txt (generated from sieve)
    int upto = 5761455;

    //vector to store the primes
    vector<long> primes(upto);
    //taking the primes as input
    for(int i = 0; i < upto; i++)
    {
        cin >> primes[i];
    }

    //vector of things to search
    vector<long> to_search = {1, 45, 467386, 2367832786, 7896, 3, 9923783};

    //loop over the things to search and check if each is a prime or not
    for(int i= 0; i < to_search.size(); i++)
    {
        num_calls=0;

        printf("\n%ld : ", to_search[i]);
        if(bin_search(primes, 0, upto, to_search[i])) //if found in the prime list
            printf("Found\n");
        else
            printf("Not Found\n");
        //print the number of function calls needed to find to_search[i]
        printf("\tNumber of calls: %d\n", num_calls);

    }
    return 0;
}
