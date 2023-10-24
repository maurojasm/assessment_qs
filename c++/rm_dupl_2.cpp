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
    int j = 0, counter = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[j]){
            if(counter >= 2) {
                j += 2;
            } else {
                j++;
            }
            nums[j] = nums[i];
            i--;
            counter = 1;
        } else {
            counter++;
        }
    }
    return j + 1;
}

int main() {
    vector<int> nums1{1, 1, 1, 2}; 
    vector<int> nums2{0,0,1,1,1,2,2,3,3,4};
    vector<int> nums3{0,0,1,1,1,1,2,3,3};
    print(nums1);
    std::cout << "k = " << my_removeDuplicates(nums1) << '\n';
    // std::cout << "k = " << removeDuplicates(nums1) << '\n';
    print(nums1);

    std::cout << '\n';

    print(nums2);
    std::cout << "k = " << my_removeDuplicates(nums2) << '\n';
    // std::cout << "k = " << removeDuplicates(nums2) << '\n';
    print(nums2);

    std::cout << '\n';

    print(nums3);
    std::cout << "k = " << my_removeDuplicates(nums3) << '\n';
    // std::cout << "k = " << removeDuplicates(nums2) << '\n';
    print(nums3);

    return 0;
}