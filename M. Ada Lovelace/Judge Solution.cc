#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	string s = "Ada" ; 
 
	int res = 0 ; 
 
	for( int i = 0 ; i < s.size() ; i ++ ) {
		res += s[ i ] ; 
	}
 
	cout << res << endl ; 
}
