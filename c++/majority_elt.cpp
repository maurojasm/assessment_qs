#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

// using sort func
int majorityElement_v1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n/2];
}
// using map
int majorityElement_v2(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> m;
    
    for(int i = 0; i < n; i++){
        m[nums[i]]++;
    }
    n = n/2;
    for(auto x: m){
        if(x.second > n){
            return x.first;
        }
    }
    return 0;
}
// Moore Voting Algo
int majorityElement_v3(vector<int>& nums) {
    int count = 0;
    int candidate = 0;
    
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    return candidate;
}

int main() {
    vector<int> nums1{3, 1, 3};
    vector<int> nums2{2, 2, 1, 1, 2, 2};

    std::cout << majorityElement_v1(nums1) << '\n';
    std::cout << majorityElement_v1(nums2) << '\n';

    std::cout << '\n';

    std::cout << majorityElement_v2(nums1) << '\n';
    std::cout << majorityElement_v2(nums2) << '\n';

    std::cout << '\n';

    std::cout << majorityElement_v3(nums1) << '\n';
    std::cout << majorityElement_v3(nums2) << '\n';
}