/*
For examples 1 and 5, dont forget to check out the number of iterations to find a key when the key is present in the set to be searched and also when it is not present(worst case)
Some materials:
https://en.wikipedia.org/wiki/Linear_search
https://www.geeksforgeeks.org/linear-search/
https://www.geeksforgeeks.org/linear-search-vs-binary-search/
https://www.geeksforgeeks.org/binary-search/

*/
#include <iostream>
#include <vector>
using namespace std;

//stores the number of tries trying to match key
int num_tries = 0;

bool lin_search(vector<long> &primes, long key)
{
    for(int i = 0; i < primes.size(); i++)
    {
        num_tries++;
        if(key==primes[i])
            return true;
    }
    return false;
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
        scanf(" %ld", &primes[i]);
    }

    //vector of things to search
    vector<long> to_search = {1, 45, 467386, 2367832786, 7896, 3, 9923783};

    for(int i= 0; i < to_search.size(); i++)
    {
        num_tries=0;

        printf("\n%ld : ", to_search[i]);
        if(lin_search(primes, to_search[i])) //if found in the prime list
            printf("Found\n");
        else
            printf("Not Found\n");
        //print the number of iterations needed to find to_search[i]
        printf("\tNumber of tries: %d\n", num_tries);

    }

    return 0;
}
