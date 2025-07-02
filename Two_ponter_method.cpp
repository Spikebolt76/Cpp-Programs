// 1. Two-sum Problem [sorted array -> use Two-pointer method => O(n) || unsorted array -> use hashmap => O(n)]

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 4, 7, 10, 13, 17, 20, 23, 27, 30, 34, 38, 41, 45, 50};
    int target = 57;

    int left = 0;
    int right = arr.size() - 1;

    while (left < right){
        int current_sum = arr[left] + arr[right];
        if(current_sum == target){
            cout << "Pair found: " << arr[left] << " + " << arr[right] << " = " << target << endl;
            return 0;
        } 
        else if (current_sum > target) right--;
        else left++;
    }
    cout << "No pair found." << endl;
    return 0;
}

// 2. container with most water : [O(n^2), bruteforce]
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_cap{};
        int i, j;

        for (i = 0; i < height.size() - 1; i++){
            for (j = i + 1; j < height.size(); j ++){
                int current_cap = min(height[i], height[j]) * (j - i);
                if (current_cap > max_cap){
                    max_cap = current_cap;
                }
            }
        }
        return max_cap;
    }
};

=================================
---> with Two pointer method  O(n) :-
// We move the pointer with the lower height because we’ve already calculated the maximum possible area for that specific height —
Any further move toward the center will only reduce the width, and since the height is either the same or smaller,
→ the area will definitely be smaller.

int maxArea(vector<int>& height) {
    int max_cap{};
    int left = 0;
    int right = height.size() - 1;

    while (left < right){
        int h = min(height[left], height[right]);
        int w = right - left;
        max_cap = max(max_cap, h * w);

        if(height[left] < height[right]) left++;
        else right--;
    }
    return max_cap;
}

====================================

3. Remove Duplicate O(n): hashing / two pointer :- 

unordered_set<int> seen;
int j = 0;

for (int i = 0; i < arr.size(); i++) {
    if (seen.count(arr[i]) == 0) {
        seen.insert(arr[i]);
        arr[j++] = arr[i];
    }
}
return j;
-----------------------------------------------
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

*/