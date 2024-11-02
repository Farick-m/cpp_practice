#include <iostream>
#include <vector>

bool isMonotonic_mySolution(const std::vector<int>& arr) {

/*
    Time and Space Complexity of My Solution
    1. Time Complexity: O(n), as we only make a single pass through the array of size n.
    2. Space Complexity: O(1), since we use only a few extra variables (increasing, decreasing, and prev).
*/
    bool increasing = false;
    bool decreasing = false;
    int prev = arr[0];

    for (int num : arr) {

        if (num > prev) {
            increasing = true;
            prev = num;
        }
        else if (num < prev){
            decreasing = true;
            prev = num;
        }

        // std::cout << "num =  = " << num << std::endl; 
        // std::cout << "increasing = " << increasing << std::endl; 
        // std::cout << "decreasing = " << decreasing << std::endl; 
        // std::cout << "prev =  = " << prev << std::endl; 
    }

    // std::cout << "END increasing = " << increasing << std::endl; 
    // std::cout << "END decreasing = " << decreasing << std::endl; 

    if (increasing == true && decreasing == true) {
            return false;
        }
    else {
        return true;
    }

}


bool isMonotonic_betterSolution(const std::vector<int>& arr) {
/*
    Explanation of Improvements
    1. Simplicity: This solution removes the usage of 'prev' as we directly access the elements from the list
    2. Early Exit: The loop can exit early if condition is met which slightly improve the perfomance by removing
        unnecessary comparisons.
*/

/*
    Time and Space Complexity of Better Solution
    1. Time Complexity: O(n), same as before
    2. Space Complexity: O(1), as we only use a constant amount of extra memory.
*/

    bool increasing = false;
    bool decreasing = false;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[i-1]) {
            increasing = true;
        }
        else if (arr[i] < arr[i-1]) {
            decreasing = true;
        }

        // std::cout << "arr[i-1] =  = " << arr[i-1] << std::endl; 
        // std::cout << "arr[i] =  = " << arr[i] << std::endl; 
        // std::cout << "increasing = " << increasing << std::endl; 
        // std::cout << "decreasing = " << decreasing << std::endl; 
        
        if (increasing && decreasing) {
            return false;
        }        
    }

    return true;
}

int main() {

    /*  INPUTS  */

    const std::vector<int> arr_1{1,1,2,2,3,4,4,5}; // Non-decreasing
    const std::vector<int> arr_2{1,1,2,1,2,4}; // both increasing and decreasing
    const std::vector<int> arr_3{5,5,4,4,4,3,2,1,1,1}; // Non-increasing

    /*  MY SOLUTION  */

    bool result_1 = isMonotonic_mySolution(arr_1);
    bool result_2 = isMonotonic_mySolution(arr_2);
    bool result_3 = isMonotonic_mySolution(arr_3);

    std::cout << "MY SOLUTION: Should be True because arr_1 is non-decreasing : " << result_1 << std::endl;
    std::cout << "MY SOLUTION: Should be False because arr_2 has both increasing and decreasing numbers : " << result_2 << std::endl;
    std::cout << "MY SOLUTION: Should be True because arr_3 is non-increasing : " << result_3 << std::endl;

    /*  BETTER SOLUTION  */

    bool result_4 = isMonotonic_betterSolution(arr_1);
    bool result_5 = isMonotonic_betterSolution(arr_2);
    bool result_6 = isMonotonic_betterSolution(arr_3);

    std::cout << "BETTER SOLUTION: Should be True because arr_1 is non-decreasing : " << result_4 << std::endl;
    std::cout << "BETTER SOLUTION: Should be False because arr_2 has both increasing and decreasing numbers : " << result_5 << std::endl;
    std::cout << "BETTER SOLUTION: Should be True because arr_3 is non-increasing : " << result_6 << std::endl;

    return 0;
}