package java_files;

public class can_jump {
    public static void print(int[] nums) {
        System.out.print("[ ");
        for(int x: nums) {
            System.out.print(x + " ");
        }
        System.out.println(" ]");
    }

    // doesn't really work -- infinite loop 
    public static boolean canJump(int[] nums) {
        boolean result = false;
        int start = nums[0], index = 0, jump = 0;
        while(start > 0) {
            jump += nums[index];
            index += nums[index];
            if(jump == nums.length - 1) {
                return true;
            } else if(jump > nums.length - 1) {
                jump = 0; index = 0;
                start--;
            }
        }

        return result;
    }

    public static boolean canJump_v2(int[] nums) {
        int reachable = 0;
        for(int i = 0; i < nums.length; i ++) {
            if(i > reachable) return false;
            reachable = Math.max(reachable, i + nums[i]);
        } 
        return true;
    }

    public static void main(String[] args) {
        int nums1[] = {2,3,1,1,4};
        int nums2[] = {3,2,1,0,4};

        // print(nums1);
        // System.out.println(canJump(nums1));

        // print(nums2);
        // System.out.println(canJump(nums2));

        print(nums1);
        System.out.println(canJump_v2(nums1));

        print(nums2);
        System.out.println(canJump_v2(nums2));
    }
}
