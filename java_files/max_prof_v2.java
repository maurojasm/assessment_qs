package java_files;

public class max_prof_v2 {
    public static void print(int[] nums) {
        System.out.print("[ ");
        for(int x: nums) {
            System.out.print(x + " ");
        }
        System.out.println(" ]");
    }

    public static int maxProfit(int[] prices) {
        int max_prof = 0;
        for(int i = 1; i < prices.length; i++) {
            if(prices[i] > prices[i - 1]) {
                max_prof += prices[i] - prices[i - 1];
            }
        }

        return max_prof;
    }

    public static void main(String[] args) {
        int nums1[] = {7,1,5,3,6,4};
        int nums2[] = {1,2,3,4,5};
        int nums3[] = {7,6,4,3,1};

        print(nums1);
        System.out.println(maxProfit(nums1));

        print(nums2);
        System.out.println(maxProfit(nums2));

        print(nums3);
        System.out.println(maxProfit(nums3));
    }
}