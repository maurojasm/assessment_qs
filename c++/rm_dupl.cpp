#include <iostream>
#include <vector>

using std::vector;

void print(vector<int> nums) {
    std::cout << "[ ";
    for(int x: nums) {
            std::cout << x << ' ';
        }
    std::cout << ']' << std::endl;
}

int my_removeDuplicates(vector<int>& nums) {
    int k = 0, index = 0;
    for(unsigned int i = 0; i < nums.size(); i++) {
        while(i + index < nums.size()) {
            if(nums[i] != nums[index]) {
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                k++;
            } else {
                index++;
            }
        }
    }

    return k;
}   

int main() {
    vector<int> nums1{1, 1, 2}; 
    vector<int> nums2{0,0,1,1,1,2,2,3,3,4};
    print(nums1);
    std::cout << "k = " << my_removeDuplicates(nums1) << '\n';
    print(nums1);

    std::cout << '\n';

    print(nums2);
    std::cout << "k = " << my_removeDuplicates(nums2) << '\n';
    print(nums2);

    return 0;
}