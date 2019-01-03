/*
    This file contains the code for map.
*/

#include <iostream>
#include <map>

using namespace std;
int main(void){
    std::map<char, int> charFreq;
    std::string myString("This is a simple and super string");

    // Start the foreach loop
    for(char ch: myString){
        charFreq[ch]++; // Increment key by one.
    }

    // Print the char freq.
    for(std::pair<char, int> p:charFreq){
        cout << p.first << " :: " << p.second << endl;
    }

    // notice that the map is sorted. Can you do something to make it
    // not sorted? What DS would you use?
    return 0;
}