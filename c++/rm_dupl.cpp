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
    int k = 0, index = 1;
    for(unsigned int j = index; j < nums.size(); j++) {
        if(nums[k] != nums[j]) {
            index = j + 1;
            if((k + 1) != j && (k + 1) < nums.size()) {
                int temp = nums[k + 1];
                nums[k + 1] = nums[j];
                nums[j] = temp;
            }
            k++;
        }
    }

    return k + 1;
}   

int main() {
    vector<int> nums1{1, 2, 3, 4, 5}; 
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