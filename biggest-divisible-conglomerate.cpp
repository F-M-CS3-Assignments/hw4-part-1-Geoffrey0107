#include "bdc.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>

string vec_to_string(vector<int> v){
    string result = "[";
    for (int i = 0; i < v.size(); i++){
        result += std::to_string(v[i]);
        if (i != v.size() - 1) {  
            result += ", ";
        }
    }
    result += "]";
    return result;
}
vector<int> biggest_divisible_conglomerate(vector<int> input){
    for(int i = 0; i < input.size() - 1; i++){
        int min_Idx = i;
        for (int j = i + 1; j < input.size(); j++) {
            if(input.at(i) < input.at(min_Idx)){
                min_Idx = j;
            }
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
        }
    }
    return input;
}

vector<int> bdc_helper(vector<int> input){
    if(input.size() == 0 || input.size() == 1){
        return input;
    }


}

main(){
    vector <int> test = {4,5,3,1};
    for (int i = 0; i < test.size(); i++){
        cout << biggest_divisible_conglomerate(test).at(i);
    }
    return 0;
}

