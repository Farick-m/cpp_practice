#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low)/2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else {
            high = mid -1;
        }
    }

    return -1;

}




int main ()
{

    std::vector<int> arr = {1,2,3,4,5,6,7};
    int target = 7;

    int val = binarySearch(arr, target);

    std::cout << "val = " << val << std::endl;

    return 0;
}