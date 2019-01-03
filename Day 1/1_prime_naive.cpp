/*
Examples 1, 2, 3 deal with prime number generation

Some resources:
https://www.geeksforgeeks.org/prime-numbers/
https://www.geeksforgeeks.org/primality-test-set-1-introduction-and-school-method/
https://www.geeksforgeeks.org/sieve-of-eratosthenes/

*/


#include <iostream>
using namespace std;

//function that returns true if n is prime
bool isPrime(int n)
{
    //for cases 0 and 1
    if(n<=1)
        return true;

    //check if n is multiple of any number from [2, n-1]
    //if yes, return false i.e. not a prime
    //if n is multiple of no number from [2, n-1], return true
    for(int i = 2; i < n; i++)
    {
        if(n%i==0)
            return false;
    }
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
