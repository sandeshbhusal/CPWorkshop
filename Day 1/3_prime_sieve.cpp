#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void prime_sieve(int upto)
{
    //allocate a vector(array) of size (upto+1) (to store the primality of numbers [0, upto]) and initialize all as true(all as prime)
    vector<bool> isPrime(upto+1, true);

    isPrime[0] = isPrime[1] = false;

    //the logic of why sqrt(upto) is used here is same as in example 2
    int sqr_upto = sqrt(upto);

    for(int i = 2; i <= sqr_upto; i++)
    {
        //if i has not been marked as "not prime"
        if(isPrime[i])
        {
            //set all multiples of i as "not prime" i.e. false
            for(int j = 2*i; j <= upto; j+=i)
                isPrime[j] = false;
        }
    }
    for(int i = 0; i <= upto; i++)
    {
        if(isPrime[i])
        {
            //print the prime number
            printf("%d\t", i);
        }
    }
}

int main()
{
    //upper limit
    int upto = 10000000;

    //generate and print all primes in the range [0, upto]
    //compare the times taken for execution of code of example 1, 2, 3
    prime_sieve(upto);

    return 0;
}
