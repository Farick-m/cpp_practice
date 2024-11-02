#include <iostream>
#include <vector>
#include <unordered_set>

/*
    Using the an unordered set data structure we can easly solve this task

    1. Parse the entire list/vector and the values in an unordered set
        - The inherent feature of an unordered set will ensure that only unique elements exist in the set
    2. When the itteration is complete, we will compare the size of the original list to the size of the unordered set.
    If the sizes dont match, it means there are duplicate emelemts in the list

*/

bool containsDuplicate_mySolution(const std::vector<int>& arr) {
    std::unordered_set<int> uniqueElementSet;

    for (int num : arr) {
        uniqueElementSet.insert(num);
    }

    return uniqueElementSet.size() != arr.size();
}

/*
    Time and Space Complexity of My Solution
    1. Time Complexity: O(n), as we parse n number of elements once 
    2. Space Complexity: O(k), as we fill out an unordered_set, where k in the number of unique elements
*/

bool containsDuplicate_betterSolution(const std::vector<int>& arr) {
    std::unordered_set<int> uniqueElementSet;

    for (int num : arr) {
        if (uniqueElementSet.find(num) != uniqueElementSet.end()) {
            return true;
        }
        uniqueElementSet.insert(num);
    }

    return false;
}

/*
    Explanation of Improvements
    1. Early Exit: The loop will exit early if the element already exists in the unordered set.
*/

/*
    Time and Space Complexity of Better Solution
    1. Time Complexity: O(n), same as before
    2. Space Complexity: O(k), identical to my solution since we still use an unordered_set.
*/




int main() {

    /*  INPUTS  */

    std::vector<int> arr_1{1, 2, 3, 3}; // return = true = 1
    std::vector<int> arr_2{1, 2, 3, 4}; // return = false = 0
    std::vector<int> arr_3{1, 2, 3, 4, 5, 6, 7, 8, 2}; // return = true = 1

    /*  MY SOLUTION  */

    std::cout << "MY SOLUTION: Should return 1 - " << containsDuplicate_mySolution(arr_1) << std::endl;
    std::cout << "MY SOLUTION: Should return 0 - " << containsDuplicate_mySolution(arr_2) << std::endl;
    std::cout << "MY SOLUTION: Should return 1 - " << containsDuplicate_mySolution(arr_3) << std::endl;

    /*  BETTER SOLUTION  */
    
    std::cout << "BETTER SOLUTION: Should return 1 - " << containsDuplicate_betterSolution(arr_1) << std::endl;
    std::cout << "BETTER SOLUTION: Should return 0 - " << containsDuplicate_betterSolution(arr_2) << std::endl;
    std::cout << "BETTER SOLUTION: Should return 1 - " << containsDuplicate_betterSolution(arr_3) << std::endl;

    return 0;
}