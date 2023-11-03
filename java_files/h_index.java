/*
 * Given an array of integers citations where citations[i] is 
 * the number of citations a researcher received for their 
 * ith paper, return the researcher's h-index.

 * According to the definition of h-index on Wikipedia: 
 * The h-index is defined as the maximum value of h such 
 * that the given researcher has published at least h papers 
 * that have each been cited at least h times.
 */

package java_files;

import java.util.Arrays;

public class h_index {
    public static void print(int[] nums) {
        System.out.print("[ ");
        for(int x: nums) {
            System.out.print(x + " ");
        }
        System.out.println("]");
    }

    // works, similar to optimize solution :)
    public static int hIndex(int[] citations) {
        int h = 0, index = citations.length - 1;
        Arrays.sort(citations);
        while(index >= 0) {
            if(h >= citations[index]) {
                return Math.max(h, citations[index]);
            }
            h++;
            index--;
        }
        return h;
    }

    public static void main(String[] args) {
        int nums1[] = {3,0,6,1,5};
        int nums2[] = {1,3,1};
        int nums3[] = {4,4,0,0};

        print(nums1);
        System.out.println(hIndex(nums1));

        print(nums2);
        System.out.println(hIndex(nums2));

        print(nums3);
        System.out.println(hIndex(nums3));
    }
}
