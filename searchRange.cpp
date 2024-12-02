#include <iostream>
#include <vector>

/*
    You are given an integer array arr sorted in non-decreasing order. Your task is to find the starting and ending
    position of a given target value. If target is not present in arr, return {-1, -1}.

    Write a function to achieve this in O(log n) time complexity.

    Sample Input:
        arr = [5, 7, 7, 8, 8, 10]
        target = 8

    Sample Output:
        3, 4

*/

class cppPractice
{
public:
    std::pair<int, int> searchRange(const std::vector<int> &arr, int target);
};

std::pair<int, int> cppPractice::searchRange(const std::vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    int first = -1, second = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            if (arr[mid] == target) {
                first = mid;
            }
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }

    // reset low and high values
    low = 0;
    high = arr.size() - 1;

    while (low <= high){
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target) {
            if (arr[mid] == target) {
                second = mid;
            }
            low = mid + 1; 
        }
        else {
            high = mid - 1;
        }
    }

    if (first == -1 || second == -1) return {-1,-1}; 

    return {first, second};
}

int main()
{
    cppPractice practice;

    std::vector<int> testVals = {5, 7, 7, 8, 8, 8, 8, 10};
    int target = 8;

    std::pair<int, int> res = practice.searchRange(testVals, target);

    std::cout << "firsts = " << res.first << std::endl;
    std::cout << "second = " << res.second << std::endl;

    return 0;
}
