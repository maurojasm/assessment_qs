#include <iostream>
#include <vector>

using std::vector;
using std::cout;

void print(vector<int> nums) {
    cout << "[ ";
    for(int x: nums) {
            cout << x << ' ';
        }
    cout << "]\n";
}

// not working completely
int maxProfit_v1(vector<int>& prices) {
    int min = 0, max = 0;
    int min_i = 0, max_i = 0;
    int max_prof = 0;

    if (prices.size() == 0) {
        return max_prof;
    } else {
        min = prices[0]; 
    }

    for(size_t i = 1; i < prices.size(); i++) {
        if(min > prices[i]) {
            min = prices[i];
            min_i = i;
        }
    }
    max = min;
    for (size_t i = min_i + 1; i < prices.size(); i++) {
        if(max < prices[i]) {
            max = prices[i];
            max_i = i;
        }
    }

    if(max_i < min_i) {
        return 0;
    } else {
        max_prof = max - min;
    }

    return max_prof;
}

// gets max profit, very slow
int maxProfit_v2(vector<int>& prices) {
    int max_prof = 0, prof = 0;
    for(unsigned int i = 0; i < prices.size(); i++) {
        for(unsigned int j = i; j < prices.size(); j++) {
            prof = prices[j] - prices[i];
            if(max_prof < prof) {
                max_prof = prof;
            }
        }
    }

    return max_prof;
}

int maxProfit(vector<int>& prices) {
    int lsf = INT_MAX;
    int op = 0;
    int pist = 0;
    
    for(int i = 0; i < prices.size(); i++){
        if(prices[i] < lsf){
            lsf = prices[i];
        }
        pist = prices[i] - lsf;
        if(op < pist){
            op = pist;
        }
    }
    return op;
}

int main() {
    vector<int> nums1{7,1,5,3,6,4};
    vector<int> nums2{7,6,4,3,1};
    vector<int> nums3{2,4,1};

    // print(nums1);
    // cout << maxProfit_v1(nums1) << '\n';

    // print(nums2);
    // cout << maxProfit_v1(nums2) << '\n';

    // print(nums3);
    // cout << maxProfit_v1(nums3) << '\n';

    // print(nums1);
    // cout << maxProfit_v2(nums1) << '\n';

    // print(nums2);
    // cout << maxProfit_v2(nums2) << '\n';

    // print(nums3);
    // cout << maxProfit_v2(nums3) << '\n';

    print(nums1);
    cout << maxProfit(nums1) << '\n';

    print(nums2);
    cout << maxProfit(nums2) << '\n';

    print(nums3);
    cout << maxProfit(nums3) << '\n';
}