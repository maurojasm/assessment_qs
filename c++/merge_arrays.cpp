#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int min = 0, test = 0, total_elts = n + m;
        int fir_index = 0, sec_index = 0;
        vector<int> result;

        if(m == 0 && n == 0) {
            min = INT_MAX; test = INT_MAX;
        } else if(n == 0) {
            min = nums1[0]; test = INT_MAX;
        } else if (m == 0) {
            min = INT_MAX; test = nums2[0];
        } else {
            min = nums1[0]; test = nums2[0];
        }
        
        for(int i = 0; i < total_elts; i++) {
            if(min < test) {
                result.push_back(min);
                fir_index++;
                if(fir_index < m) {
                    min = nums1[fir_index];
                } else {
                    min = INT_MAX;
                }
            } else {
                result.push_back(test);
                sec_index++;
                if(sec_index < n) {
                    test = nums2[sec_index];
                } else {
                    test = INT_MAX;
                }
            }
        }
        nums1 = result;
    }
};