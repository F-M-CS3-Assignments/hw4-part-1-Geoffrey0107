
#include "bdc.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>


int main() {
	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	cout << "answerset: " << vec_to_string(ans) << endl;
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);


	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	// Test 3: non divisible
	values = {3, 5, 7, 11};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {3}; 
	set<int> answerSet3(ans.begin(), ans.end());
	assert(answerSet3.size() == 0);

	// Test 4: all divisible
	values = {1, 2, 4, 8, 16};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {1, 2, 4, 8, 16};
	set<int> answerSet4(ans.begin(), ans.end());
	assert(answerSet4 == soln);

	// Test 5: Empty vector
	values = {};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {};  
	set<int> answerSet5(ans.begin(), ans.end());
	assert(answerSet5 == soln);

	values = {7};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {7};  
	set <int> answerSet6(ans.begin(), ans.end());
	assert(answerSet6 == soln);

	values = {2, 4, 0, 8};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {2,4,8};
	set <int> answerSet7(ans.begin(), ans.end());
	assert(answerSet7 == soln);

	return 0;
}
