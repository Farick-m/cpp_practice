#include <iostream>
#include <vector>
#include <unordered_map>

/*
    Time and Space Complexity of Better Solution
    1. Time Complexity: O(n), as we need to parse 'n' number of elements to populate the unordered map
    2. Space Complexity: O(k), for this specific example where the size of the list is small.
        - Worst case scenario would be O(n) if we the size of the list grows. 
*/

std::pair<int, int> twoSum_mySolution(const std::vector<int>& arr, int target) {
    std::unordered_map<int, int> valueMap;
    std::pair<int, int> result;

    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i]; // 9 - 2 = 7
        std::cout << "complement" << complement << std::endl;
        
        if (valueMap.find(complement) != valueMap.end()) {
            return std::make_pair(valueMap[complement], i);
        }

        valueMap[arr[i]] = i;
    }

    return std::make_pair(-1, -1);
}




int main() {

    /*  INPUTS  */

    const std::vector<int> arr_1{2, 7, 11, 15};
    int target_1 = 9;
    auto result_1 = twoSum_mySolution(arr_1, target_1);
    const std::vector<int> arr_2{1, 2, 3, 4};
    int target_2 = 8;
    auto result_2 = twoSum_mySolution(arr_2, target_2);
    const std::vector<int> arr_3{1, 2, 3, 4, 5, 6};
    int target_3 = 11;
    auto result_3 = twoSum_mySolution(arr_3, target_3);

    /*  MY SOLUTION  */
    std::cout << "MY SOLUTION: Should return 0 and 1 - {" << result_1.first << ", " << result_1.second << "}" << std:: endl;
    std::cout << "MY SOLUTION: Should return -1 and -1 - {" << result_2.first << ", " << result_2.second << "}" << std:: endl;
    std::cout << "MY SOLUTION: Should return 4 and 5 - {" << result_3.first << ", " << result_3.second << "}" << std:: endl;


    return 0;
}