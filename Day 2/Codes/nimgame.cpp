/*Description 
There are n piles of coins. Player 1 and 2 alternately take off any
number of coins from a pile. The player to take the last coin wins.

In this Game there are two states namely winning state and losing state. 
Winning state is the state in which nimsum is non-zero.(nimsum is the xor
of number of coins in each pile. e.g there are x1 coins in pile 1, x2 coins
in pile 2...xn coins in pile n then nimsum = x1 xor x2 xor...xor xn). If the
numsum is 0, it is losing state. If a player starts from winning state, he always
wins the game if he plays optimally.

Lemmas: 
1. If nimsum is zero after n moves, nimsum will always be non-zero after 
n+1 moves 
2. If nimsum is non zero after n moves, nimsum can be made 0 by choosing 
certain moves.

At the end there aren't any piles left and it is a losing state.Before 
that there is only one pile remaining which is a winning state. Using these facts 
and above Lemmas, it can be proved that if a player starts at the state with
nimsum non-zero he will definitely win the game if he plays optimally.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string nimGame(vector<int> pile){
	int nimsum = 0;
	for(int i=0; i<pile.size(); i++){
		nimsum = nimsum ^ pile[i];
	}
	if(nimsum == 0) return "Second";
	return "First";
}

int main(){
	int n;
	int a;
	vector<int> pile;
	printf("Enter number of piles: ");
	scanf("%d", &n);
	printf("Enter number of coins in ith pile:\n");
	for(int i=0; i<n; i++){
		printf("%dth pile: ", i+1);
		scanf("%d", &a);
		pile.push_back(a);
	}
	printf("\nThe Winner is %s Player\n", nimGame(pile).c_str());
	return 0;
}