#include <iostream>
#include <vector>

using namespace std;
int main(void){

    vector<int> myArray;

    myArray.push_back(10);
    myArray.push_back(45);
    myArray.push_back(13);
    myArray.push_back(11);
    myArray.push_back(78);

    cout << "Printing All elements: " << endl;
    for(auto x: myArray){
        cout << x << " ";
    }

    cout << endl;

    cout << "First Element: " << myArray[0] << endl;
    cout << "Size: " << myArray.size() << endl;
    cout << "Resize Operation :: Decrease size of the array to 3." << endl;
    myArray.resize(3);
    myArray.pop_back();
    cout << "Deleted a single element from the back " << endl;
    cout  << "Remaining elements : " << endl;
    
    for(auto x:myArray){
        cout << x << " ";
    }

    cout << endl;
    return 0;
}