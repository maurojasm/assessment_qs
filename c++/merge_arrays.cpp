#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::vector;
using std::rotate;
using std::swap;

void print(vector<int> nums) {
    for(int x: nums) {
            std::cout << x << ' ';
        }
    std::cout << std::endl;
}

void solution(vector<int> nums1, int m, vector<int> nums2, int n){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--; k--;
        }
        else{
            nums1[k] = nums2[j];
            j--; k--;
        }
    }
    while(j>=0){
        nums1[k] = nums2[j];
        j--; k--;
    }
    print(nums1);
}

void my_solution(vector<int> nums1, int m, vector<int> nums2, int n) {
    int min = 0, test = 0, total_elts = n + m;
    int fir_index = 0, sec_index = 0;
    int max = 0;

    if(n == 0 && m == 0) {
        min = 0; test = 0;
    } else if(n == 0) {
        max = nums1[m - 1];
        max *= (max + 1);
        min = nums1[0]; test = max;
    } else if (m == 0) {
        max = nums2[n - 1];
        max *= (max + 1);
        min = max; test = nums2[0];
    } else {
        max = std::max(nums1[m - 1], nums2[n - 1]);
        max *= (max + 1);
        min = nums1[0]; test = nums2[0];
    }

    print(nums1);
    print(nums2);
    std::cout << std::endl;

    while(fir_index < total_elts) {
        if(min < test) {
            fir_index++;
            if(fir_index < m) {
                min = nums1[fir_index];
            } else {
                min = INT_MAX;
                nums1[fir_index] = min;
            }
        } else {
            swap(nums1[fir_index], nums2[sec_index]);
            sec_index++;
            if(sec_index < n) {
                test = nums2[sec_index];
            } else {
                sec_index = 0;
                test = nums2[sec_index];
            }
        }
    }
    // nums1 = result;
    print(nums1);
    std::cout << std::endl;
}

int main() {
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    int m = 3, n = 3;
    // vector<int> nums1{1};
    // vector<int> nums2;
    // int m = 1, n = 0;
    // vector<int> nums1{0};
    // vector<int> nums2{1};
    // int m = 0, n = 1;
    // vector<int> nums1;
    // vector<int> nums2;
    // int m = 0, n = 0;
    

    // int x = 1, m = 3;
    // std::swap(nums1[x], nums2[x]);
    // rotate(nums1.rbegin() + x, nums1.rbegin() + m, nums1.rend());

    my_solution(nums1, m, nums2, n);
    
    return 0;
}
