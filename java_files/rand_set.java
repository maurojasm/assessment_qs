/*
 * Implement the RandomizedSet class:

    * RandomizedSet() Initializes the RandomizedSet object.
    * bool insert(int val) Inserts an item val into the set 
        if not present. Returns true if the item was not present, 
        false otherwise.
    * bool remove(int val) Removes an item val from the set if 
        present. Returns true if the item was present, false otherwise.
    * int getRandom() Returns a random element from the current 
        set of elements (it's guaranteed that at least one element 
        exists when this method is called). Each element must have 
        the same probability of being returned.

 * You must implement the functions of the class such that each 
 * function works in average O(1) time complexity.
 */

package java_files;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Set;

// my approach not very optimized, O(n) complexity
class RandomizedSet_v1 {
    private List<Integer> randSet;
    
    public RandomizedSet_v1() {
        randSet = new ArrayList<Integer>();
    }
    
    public boolean insert(int val) {
        if(!randSet.contains(val)) {
            randSet.add(val);
            return true;
        }
        return false;
    }
    
    public boolean remove(int val) {
        if(randSet.contains(val)) {
            int index = randSet.indexOf(val);
            randSet.remove(index);
            return true;
        }
        return false;
    }
    
    public int getRandom() {
        Random rand = new Random();
        int index = rand.nextInt(randSet.size());
        
        int result = randSet.get(index);

        return result;
    }

    void print_set() {
        System.out.print("[ ");
        for(Integer x: randSet) {
            System.out.print(x + " ");
        }
        System.out.println("]");    }

    public static void main(String[] args) {
        RandomizedSet_v1 randomSet = new RandomizedSet_v1();
        randomSet.print_set();
        System.out.println("insert 1: " + randomSet.insert(1));
        randomSet.print_set();
        System.out.println("remove 2: " + randomSet.remove(2));
        randomSet.print_set();
        System.out.println("insert 2: " + randomSet.insert(2));
        randomSet.print_set();
        System.out.println("get random: " + randomSet.getRandom());
        randomSet.print_set();
        System.out.println("remove 1: " + randomSet.remove(1));
        randomSet.print_set();
        System.out.println("insert 2: " + randomSet.insert(2));
        randomSet.print_set();
        System.out.println("get random: " + randomSet.getRandom());
        randomSet.print_set();
    }
}

// optimize approach with O(1) complexity
class RandomizedSet {
    Set<Integer> s;
    public RandomizedSet() {
        s=new HashSet<>();
    }
    
    public boolean insert(int val) {
        if(s.contains(val)){
            return false;
        }else{
            s.add(val);
            return true;
        }
    }
    
    public boolean remove(int val) {
        if(s.contains(val)){
            s.remove(val);
            return true;
        }else{
            return false;
        }
    }
    
    public int getRandom() {
        List<Integer> list=new ArrayList<Integer>(s);
        int r=(int)(Math.random()*s.size());

        return list.get(r);
    }
}

public class rand_set {
    public static void print(int[] nums) {
        
    }
}
