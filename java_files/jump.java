package java_files;

public class jump {
    public static void print(int[] nums) {
        System.out.print("[ ");
        for(int x: nums) {
            System.out.print(x + " ");
        }
        System.out.println("]");
    }
    // my attempt
    public static int jump_v1(int[] nums) {
        int min_jumps = Integer.MAX_VALUE, jumps = 0;
        int index = 0, value = 0;
        int last_i = nums.length - 1;

        if(nums[0] > last_i || nums[0] == 0) {
            return 0;
        }

        while(nums[0] > 0) {
            value = nums[index];
            index += value;
            if(index < last_i && value != 0) {
                jumps++;
            } else if(index == last_i) {
                jumps++;
                if(min_jumps > jumps) {
                    min_jumps = jumps;
                }
                nums[0]--;
                value = 0; index = 0; jumps = 0;
            } else if(index > last_i || value == 0) {
                nums[0]--;
                value = 0; index = 0; jumps = 0;
            }
        }

        return min_jumps;
    }

    // optimized solution
    public static int jump_v0(int[] nums) {
        for(int i = 1; i < nums.length; i++) {
            nums[i] = Math.max(nums[i] + i, nums[i-1]);
        }
        int ind = 0;
        int ans = 0;
    
        while(ind < nums.length - 1) {
            ans++;
            ind = nums[ind];
        }
        return ans;
    }

    public static void main(String[] args) {
        int nums1[] = {2,3,1,1,4};
        int nums2[] = {2,3,0,1,4};
        int nums3[] = {1,2,3};

        // print(nums1);
        // System.out.println(jump_v1(nums1));
        
        // print(nums2);
        // System.out.println(jump_v1(nums2));

        print(nums1);
        System.out.println(jump_v0(nums1));
        
        print(nums2);
        System.out.println(jump_v0(nums2));

        print(nums3);
        System.out.println(jump_v0(nums3));
    }
}
