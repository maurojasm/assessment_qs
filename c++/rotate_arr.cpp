#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;

void print(vector<int> nums) {
    cout << "[ ";
    for(int x: nums) {
            cout << x << ' ';
        }
    cout << "]\n";
}

void my_rotate_v1(vector<int>& nums, int k) {
    print(nums);
    int max_index = 0, index = 0;
    max_index = index = nums.size() - 1;
    int temp = 0;
    for(int i = 0; i < k; i++) {
        index = max_index;
        temp = nums[max_index];
        while(index > 0) {
            nums[index] = nums[index - 1];
            index--;
        }
        nums[0] = temp;
    }
    print(nums);
}

void my_rotate_v2(vector<int>& nums, int k) {
    print(nums);
    std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
    print(nums);
}

// off by one
void my_rotate_v3(vector<int>& nums, int k) {
    print(nums);
    
    int i = 0, size = nums.size();
    int index = size - (k % size), temp = 0;
    if(index != size) {
        while(index < size) {
            temp = nums[index];
            nums[index] = nums[i];
            nums[i] = temp;
            i++; index++;
        }
        index--;
        // this line makes the off by one error
        i += (k + 1) % 2;
        while(i != index) {
            temp = nums[index];
            nums[index] = nums[i];
            nums[i] = temp;
            index--;
        }
    }

    print(nums);
}

// not works when k and n are even, stuck infinite loop
void my_rotate_v4(vector<int>& nums, int k) {
    print(nums);
    
    int size = nums.size(), index = k % size;
    int temp1 = nums[0], temp2 = nums[index];
    for(int i = 0; i < size; i++) {
        nums[index] = temp1;
        index = (index + k) % size;
        temp1 = temp2;
        temp2 = nums[index];
    }

    print(nums);
}

int main() {
    vector<int> nums1{1,2,3,4,5,6,7};
    vector<int> nums2{-1,-100,3,99};
    vector<int> nums3{1, 2};
    int k1 = 3, k2 = 2, k3 = 1;

    // my_rotate_v1(nums1, k1);
    // my_rotate_v1(nums2, k2);

    // my_rotate_v2(nums1, k1);
    // my_rotate_v2(nums2, k2);

    // my_rotate_v3(nums1, k1);
    // my_rotate_v3(nums2, k2);
    // my_rotate_v3(nums3, k3);

    my_rotate_v4(nums1, k1);
    my_rotate_v4(nums2, k2);
    my_rotate_v4(nums3, k3);
}