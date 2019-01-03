#include <iostream>
#include <vector>
using namespace std;

int main(void){
    // We need to find the first pair whose sum will be equal to 7.
    // Note that there can be multiple answers.
    vector<int> array{10, 20, 35, 50, 75, 80};
    // Final sum should be 70.
    int required = 70;
    // Naive Algorithm:
    int iterations = 0;
    int i, j;
    for(i=0; i<array.size(); i++){
        bool flag = false;
        for(j=i+1; j<array.size(); j++){
            iterations++;
            if(array[i] + array[j] == required){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    cout << "@ Using naive algorihtm: " << endl;
    cout << "Positions " << i << " " << " and " << j << " gave the ans." << endl;
    cout << "Iterations Required: " << iterations << endl;
    cout << "@ Using Two Pointer method: " << endl;
    // Initialize the left and right pointers.
    i = 0;
    j = array.size() -1;
    iterations = 0;
    int sum = 0;
    while((sum = array[i] + array[j]) != required){
        if(sum < required) i++;
        else j--;
        iterations++;
    }   
    cout << "Positions " << i << " " << " and " << j << " gave the ans." << endl;
    cout << "Iterations Required: " << iterations << endl;
    

    return 0;
}