#include <iostream>
#include <cmath>
using namespace std;

//function that returns true if n is prime
bool isPrime(int n)
{
    //for cases 0 and 1
    if(n<=1)
        return true;

    //check if n is multiple of any number from [2, square root of n]
    //if yes, return false i.e. not a prime
    //faster than eg 1 because of only checking upto sqrt(n) rather than n-1
    int sqr_n = sqrt(n);
    for(int i = 2; i <= sqr_n; i++)
    {
        if(n%i==0)
            return false;
    }

    //if n is multiple of no number from [2, square root of n], return true
    return true;
}

int main()
{
    //upper limit
    int upto = 10000000;

    //print all primes in the range [0, upto]
    //compare the times taken for execution of code of example 1, 2, 3
    for(int i = 0; i <= upto; i++)
    {
        if(isPrime(i))
            printf("%d\t", i);
    }
    return 0;
}
