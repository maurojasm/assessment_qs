package java_files;

public class pref_array {
    public static int[] findOriginalArray(int[] pref) {
        int n = pref.length;
        int[] arr = new int[n];
        
        arr[0] = pref[0];
        for (int i = 1; i < n; i++) {
            arr[i] = pref[i] ^ pref[i - 1];
        }
        
        return arr;
    }

    public static void main(String[] args) {
        int[] pref = {3, 5, 2, 10};
        int[] originalArray = findOriginalArray(pref);
        
        System.out.print("Original Array: ");
        for (int num : originalArray) {
            System.out.print(num + " ");
        }
        // Output: Original Array: 3 8 10 2
    }
}
