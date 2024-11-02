#include <iostream>
#include <vector>
#include <unordered_map>


int countLargestElement(const std::vector<int>& arr) {

    std::unordered_map<int, int> largestElementFreqMap;
    int n = 1;
    for (int i = 0; i < arr.size(); i++) {

        if (largestElementFreqMap.find(arr[i]) != largestElementFreqMap.end()) {
            largestElementFreqMap[arr[i]]++;
        } else {
          largestElementFreqMap[arr[i]] = n;
        }
    }

    for (const auto it : largestElementFreqMap) {
        std::cout << "{" << it.first << " : " << it.second << "}";
    }

    return 0;
}


int main() {
    std::vector<int> arr{1, 2, 3, 4, 4};

    countLargestElement(arr);
    // std::cout << countLargestElement(arr) << std::endl;

    return 0;
}