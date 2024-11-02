#include <iostream>
#include <vector>
#include <unordered_map>

int countLargestElement_mySolution(const std::vector<int> &arr)
{
    /*
    Initialisng with 0 is bad becuase if the largest number is 0, then the code will fail.
     - So it best to initialise the largest element to be the first element

        int largest = arr[0];
    */
    int largest = 0;
    
    int n = 0;

    std::unordered_map<int, int> largestElementFreqMap;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            n = 1;
        }

        // std::cout << "largest = " << largest << std::endl;

        if (largestElementFreqMap.find(arr[i]) != largestElementFreqMap.end())
        {
            largestElementFreqMap[arr[i]]++;
        }
        else
        {
            largestElementFreqMap[arr[i]] = n;
        }
    }

    return largestElementFreqMap[largest];
}

int countLargestElement_betterSolution(const std::vector<int>& arr) {
    int largest = arr[0];
    int count = 0;

    for (int num : arr) {
        if (num > largest){
            largest = num;
            count = 1; // reset count for the new largest
        }
        else if (num == largest) {
            count++; // Increment the count if the number in the list is EQUAL to the largest number
        }
    }
    return count;
}

int main()
{
    const std::vector<int> arr{1, 5, 3, 4, 5, 4, 2, 0, 1, 5, 0, 0, 5};

    std::cout << "My Solution : " << countLargestElement_mySolution(arr) << std::endl;
    std::cout << "Better Solution : " << countLargestElement_betterSolution(arr) << std::endl;

    return 0;
}