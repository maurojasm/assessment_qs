package java_files;

public class prod_arr {
    public static void print(int[] nums) {
        System.out.print("[ ");
        for(int x: nums) {
            System.out.print(x + " ");
        }
        System.out.println("]");
    }

    // O(n^2) time complex: nested for loops. Brute force approach
    // O(1) space complex: constant space
    // not optimized 
    public static int[] productExceptSelf_v1(int[] nums) {
        int n = nums.length, prod = 0;
        int result[] = new int[n];
        for(int i = 0; i < n; i++) {
            prod = 1;
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                prod *= nums[j];
            }
            result[i] = prod;
        }
        return result;
    }

    // O(n) time complex: three for loops, not nested
    // O(n) space complex: space for left and right product
    // better than brute force, can be more optimized
    public static int[] productExceptSelf_v2(int[] nums) {
        int n = nums.length;
        int ans[] = new int[n];
        int left_Product[] = new int[n];
        int right_Product[] = new int[n];
        left_Product[0] = 1;
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i-1];
        }
        right_Product[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;
    }

    // O(n) time complex: 2 for loops, not nested
    // O(1) space complex: constant space
    // most optimized solution
    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int output[] = new int[n];
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }

    public static void main(String[] args) {
        int nums1[] = {1,2,3,4};
        int nums2[] = {-1,1,0,-3,3};

        print(nums1);
        // print(productExceptSelf_v1(nums1));
        print(productExceptSelf(nums1));

        print(nums2);
        // print(productExceptSelf_v1(nums2));
        print(productExceptSelf(nums2));
    }
}
