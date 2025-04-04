#include "bdc.h"
#include <vector>
#include <cassert>
#include <iostream>
#include <set>

string vec_to_string(vector<int> v){
    string result = "[";
    for (size_t i = 0; i < v.size(); i++){
        result += std::to_string(v[i]);
        if (i != v.size() - 1) {  
            result += ", ";
        }
    }
    result += "]";
    return result;
}

int find_next_dividend_position(vector <int> input, int i){
    if (i >= (int)input.size()){
        cout << "overflow" << endl;
    }
    if (input[i] == 0) {
        cout << "cannot divide by 0" << endl;
    }
    int num = input[i-1];
    if(num != 0){
        for(size_t j = i; j < input.size(); j++){
            if(input[j] % num == 0){
                return j;
            }
        }
    }
    return -1;
}

vector <int> sub_vec(vector <int> input, size_t j){
    vector <int> result;
    for(size_t i = j; i < input.size(); i++ ){
        result.push_back(input[i]);
    }
    return result;
}

vector<int> combine(const vector<int> &L, const vector<int> &R){

    if(R.size() > 0 && R.at(0) % L.at(0) != 0){
        return L;
    }

    vector<int> output;
    for(size_t i = 0; i < L.size(); i++){
        output.push_back(L.at(i));
    }

    for(size_t i = 0; i <R.size(); i++){
        output.push_back(R.at(i));
    }
    return output;
}

vector<int> longest_vector(vector<vector<int>> candidates){
    if (candidates.empty()) return {};
    size_t max = 0;
    size_t idx = 0;
    for(size_t i = 0; i < candidates.size(); i++){
        if(candidates[i].size() > max){
            max = candidates[i].size();
            idx = i;
        }
    }
    return candidates[idx];
}

vector<int> bdc_helper(vector<int> input){
    vector<vector<int>> candidates;
    if(input.size() == 0 || input.size() == 1){
        return input;
    }
    for (size_t i = 0; i < input.size() - 1; i++){
        vector<int> L;
        int j = find_next_dividend_position(input, i+1);
        if(j==-1){continue;}
        L.push_back(input[i]);
        vector <int> Rin = sub_vec(input, j);
        vector <int> R = bdc_helper(Rin);
        vector <int> cand_v = combine(L, R);
        candidates.push_back(cand_v);
    }
    return longest_vector(candidates);
}

// vector<int> biggest_divisible_conglomerate(vector<int> input){
//     for(size_t i = 0; i < input.size(); i++){
//         size_t min_Idx = i;
//         for (size_t j = i + 1; j < input.size(); j++) {
//             if(input[j] < input[min_Idx]){
//                 min_Idx = j;
//             }
//         }
//         if(min_Idx != i){
//             std::swap(input[i], input[min_Idx]);
//         }
//     }
//     return bdc_helper(input);
// }
/*
The time complexity of the previous recursive approach is O(2^n) because in the worst case,
it tries every possible subset. 

The time complexity of the Dynamic Programming approach is O(n^3) because there is a triple 
nested for loop as the highest complexity. 

This Dynamic Programming approach first sorts the input in ascending order, then uses 
dynamic programming to build up valid divisible chains. For each element, it checks if 
it can extend a previous successful chain by being divisible by a smaller number. The 
algorithm keeps updating the chains to always store the longest one ending at each index. 
Finally, it returns the longest chain found.
*/
vector<int> biggest_divisible_conglomerate(vector<int> input){
    if(input.size() == 0 || input.size() == 1){
        return input;
    }
    for(size_t i = 0; i < input.size(); i++){
        size_t min_Idx = i;
        for (size_t j = i + 1; j < input.size(); j++) {
            if(input[j] < input[min_Idx]){
                min_Idx = j;
            }
        }
        if(min_Idx != i){
            std::swap(input[i], input[min_Idx]);
        }
    }

    vector<vector<int>> answers(input.size());
    for(size_t i = 0; i < answers.size(); i++){
        answers.at(i) = {input.at(i)};
    }

    for(size_t i = 0; i < input.size(); i++){
        int curr_element = input[i];
        for(size_t j = i + 1; j < input.size(); j++){
            if(input[j] % curr_element == 0 && answers[i].size() >= answers[j].size()){
                answers[j] = {input.at(j)};
                for(size_t k = 0; k < answers[i].size(); k++){
                    answers[j].push_back(answers[i][k]);
                }
            }
        }
    }
    size_t max_len = 0;
    size_t max_idx = 0;
    for (size_t i = 0; i < answers.size(); ++i) {
        if (answers[i].size() > max_len) {
            max_len = answers[i].size();
            max_idx = i;
        }
    }
    return answers[max_idx];
}
