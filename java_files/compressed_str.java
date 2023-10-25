package java_files;

import java.util.ArrayList;
import java.util.List;

/*
 * Problem: Consider a string, S, that is a series of characters, each followed
 *          by its frequency as an integer. The string is not compressed 
 *          correctly, so there may be multiple occurrences of the same 
 *          character. A properly compressed string will consist of one 
 *          instance of each character in alphabetical order followed by 
 *          the total count of that character within the string.
 * 
 * Input: {String} "a3b5c2a2"
 * 
 * Output: ?
 */

public class compressed_str {
    public static String properCompression(String s) {
        StringBuilder compressedStr = new StringBuilder();
        List<Character> chars = new ArrayList<>();
        List<Integer> counts = new ArrayList<>();
        int index = 0;

        for (int i = 0; i < s.length(); i += 2) { 
            char c = s.charAt(i); 
            int count = Character.getNumericValue(s.charAt(i + 1)); 
            // while (count > 0) {
            //     compressedStr.append(c);
            //     count--;
            // }
            if(chars.indexOf(c) == -1) {
                chars.add(c);
                counts.add(count);
            } else {
                index = chars.indexOf(c);
                counts.set(index, counts.get(index) + count);
            }
        }

        for(int i = 0; i < chars.size(); i++) {
            compressedStr.append(chars.get(i));
            compressedStr.append(counts.get(i));
        }

        return compressedStr.toString();
    }

    public static void main(String[] args) {
        String inputStr = "a3b5c2a2";
        String compressedResult = properCompression(inputStr);
        System.out.println(compressedResult);  // Output: "aaabbbbbcc"
    }
}