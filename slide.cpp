/*
    Demonstration of sliding window algorithms
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    // Find the maximum sum of 3 numbers.
    vector<int> array{1, 2, 3,4, 5, 6, 7, 8, 0, 1};
    int size = 3;
    int maxSum = array[0];
    for(int i = 0; i< array.size()-3; i++){
        int sum = 0;
        for(int j=1; j<=size; j++){
            sum += array[i+j];
        }
        if(sum > maxSum) maxSum = sum;
    }
    cout << "Using naive approach: " << maxSum << endl;
    cout << "Using Sliding window: ";

    maxSum = array[0] + array[1] + array[2];
    for(int i=0; i<array.size()-3; i++){
        int tempSum = maxSum - array[i] + array[i+3];
        if(tempSum > maxSum) maxSum = tempSum;
    }
    cout << maxSum << endl;
    return 0;
}