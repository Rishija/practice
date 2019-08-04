/*
 Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
 */
#include <iostream>
#include <map>
using namespace std;

/*
 Time : O(n)
 Space : O(1)
 */
bool palindrome_permutation(string s) {

	int n = s.size();
	if(n < 2)
		return true;

	map<char, int> check;
	int cnt = 0;

	for(char x : s) {
		check[x] ^= 1;
		check[x] ? ++cnt : --cnt;
	}
	return (cnt < 2) ? true : false;
}

int main() {

	string s = "baba";
	cout << palindrome_permutation(s) << endl;

	s = "tbytb";
	cout << palindrome_permutation(s) << endl;

	s = "a";
	cout << palindrome_permutation(s) << endl;

	s = "aa";
	cout << palindrome_permutation(s) << endl;

	s = "oorrrr";
	cout << palindrome_permutation(s) << endl;

	s = "tttkk";
	cout << palindrome_permutation(s) << endl;

	// false
	s = "tuuuti";
	cout << palindrome_permutation(s) << endl;

	s = "errrggge";
	cout << palindrome_permutation(s) << endl;

	s = "ab";
	cout << palindrome_permutation(s) << endl;

	s = "gghjk";
	cout << palindrome_permutation(s) << endl;

	s = "oooppp";
	cout << palindrome_permutation(s) << endl;

	return 0;
}
