#include <iostream>
#include <vector>

using std::vector;

void print(vector<int> nums) {
    for(int x: nums) {
            std::cout << x << ' ';
        }
    std::cout << std::endl;
}

// my solution
int my_removeElement(vector<int>& nums, int val) {
    int counter = 0, temp = 0, k = 0;
    for(unsigned int i = 0; i < nums.size(); i++){
        if(nums[i] == val) {
            counter++;
            nums[i] = -1;
            k = i;
            i--;
            while(k + 1 < nums.size()) {
                temp = nums[k + 1];
                nums[k + 1] = nums[k];
                nums[k] = temp;
                k++;
            }
        }
    }
    return nums.size() - counter;
}

// better solution
int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }

int main() {
    // vector<int> nums{3, 2, 2, 3};
    // int val = 3;
    vector<int> nums{0,1,2,2,3,0,4,2};
    int val = 2;

    print(nums);
    // std::cout << "k = " << my_removeElement(nums, val) << '\n';
    std::cout << "k = " << removeElement(nums, val) << '\n';
    print(nums);
}