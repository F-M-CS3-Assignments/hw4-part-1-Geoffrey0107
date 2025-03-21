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
    //vector <int> find_Idx;
    if (i >= (int)input.size()){
        cout << "overflow" << endl;
    }
    if (input[i] == 0) {
        cout << "cannot divide by 0" << endl;
    }
    for(size_t j = i; j < input.size(); j++){
        int num = input[i-1];
        if(input[j] % num == 0){
            //find_Idx.push_back(j);
            return j;
        }
        else{
            return -1;
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

vector<int> combine(vector<int> L, vector <int> R){
    for (int x : R) {
        L.push_back(x);
    }
    return L;
}

vector<int> longest_vector(vector<vector<int>> candidates){
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
    vector<int> L;
    L.push_back(input[0]);
    //LVal.push_back(input[0]);
    for (size_t i = 0; i < input.size() - 1; i++){
        int j = find_next_dividend_position(input, i+1);
        if(j==-1){continue;}
        vector <int> Rin = sub_vec(input, j);
        vector <int> R = bdc_helper(Rin);
        vector <int> cand_v = combine(L, R);
        cout << "result: " << vec_to_string(cand_v) <<endl;
        candidates.push_back(cand_v);
        //cout << "L: " << vec_to_string(L) <<endl;
        //cout << "j: " << j <<endl;
        //cout << "Rin: " << vec_to_string(Rin) <<endl;
        //cout << "R: " << vec_to_string(R) <<endl;
    }
    return longest_vector(candidates);
}

vector<int> biggest_divisible_conglomerate(vector<int> input){
    for(size_t i = 0; i < input.size(); i++){
        size_t min_Idx = i;
        for (size_t j = i + 1; j < input.size(); j++) {
            if(input[j] < input[min_Idx]){
                min_Idx = j;
            }
        }
        if(min_Idx != i){
            // int temp = input[i];
            // input[i] = input[min_Idx];
            // input[min_Idx] = temp;
            std::swap(input[i], input[min_Idx]);
        }
    }
    return bdc_helper(input);
}

int main(){
    vector <int> test = {28, 22, 7, 2, 8, 14, 24, 56};
    vector <int> test2 = {2,2,2,2};
    vector<vector<int>> vectors = {{1,2,3},{1,2,3,4},{1,2,3,4,5}};
    //cout << vec_to_string(test) << endl;
    cout << vec_to_string(biggest_divisible_conglomerate(test)) << endl;
    //cout << vec_to_string(bdc_helper(test));
    //cout << find_next_dividend_position(test,0) << endl;
    //cout << vec_to_string(sub_vec(test,3)) << endl;
    //cout << vec_to_string(combine(test,test2)) << endl;
    //cout << vec_to_string(longest_vector(vectors));
    return 0;
}

