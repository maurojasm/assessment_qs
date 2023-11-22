/*
 * There are n gas stations along a circular route, where the amount of gas at the
 * ith station is gas[i]. You have a car with an unlimited gas tank and it costs 
 * cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
 * You begin the journey with an empty tank at one of the gas stations. Given 
 * two integer arrays gas and cost, return the starting gas station's index if 
 * you can travel around the circuit once in the clockwise direction, otherwise 
 * return -1. If there exists a solution, it is guaranteed to be unique
 */

package java_files;

public class gas_station {
    public static void print(int[] nums) {
        System.out.print("[ ");
        for(int x: nums) {
            System.out.print(x + " ");
        }
        System.out.println("]");
    }
    // my attempt... does not work: infinite loop
    public static int canCompleteCircuit_v1(int[] gas, int[] cost) {
        int tank = 0, curr_gas = 0, next_gas = -1;
        for(int i = 0; i < gas.length; i++) {
            curr_gas = i;
            next_gas = curr_gas + 1;
            if(next_gas > gas.length - 1) {
                    next_gas = 0;
                }
            tank = 0;
            System.err.println("i: " + i);
            System.err.println("tank: " + tank);
            System.err.println("curr: " + curr_gas);
            System.out.println("next: " + next_gas + "\n");
            do {
                tank += gas[curr_gas] - cost[curr_gas];
                curr_gas = next_gas;
                next_gas++;
                if(next_gas > gas.length - 1) {
                    next_gas = 0;
                }
                System.err.println("i: " + i);
                System.err.println("tank: " + tank);
                System.err.println("curr: " + curr_gas);
                System.out.println("next: " + next_gas + "\n");
            } while(tank >= 0 && next_gas != i + 1);
            
            if(tank >= 0 && next_gas == i + 1) {
                return i;
            }
            tank = 0;
        }

        return -1;
    }

    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int total_surplus = 0;
        int surplus = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++){
            total_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if(surplus < 0){
                surplus = 0;
                start = i + 1;
            }
        }
        return (total_surplus < 0) ? -1 : start;
    }

    public static void main(String[] args) {
        int gas1[] = {1,2,3,4,5}, cost1[] = {3,4,5,1,2};
        int gas2[] = {2,3,4}, cost2[] = {3,4,3};
        int gas3[] = {5,1,2,3,4}, cost3[] = {4,4,1,5,1};

        System.out.print("Gas: "); print(gas1);
        System.out.print("Cost: "); print(cost1);
        System.out.println("Gas to start: " + canCompleteCircuit_v1(gas1, cost1));

        System.out.println("");

        System.out.print("Gas: "); print(gas2);
        System.out.print("Cost: "); print(cost2);
        System.out.println("Gas to start: " + canCompleteCircuit_v1(gas2, cost2));

        System.out.println("");

        System.out.print("Gas: "); print(gas3);
        System.out.print("Cost: "); print(cost3);
        System.out.println("Gas to start: " + canCompleteCircuit_v1(gas3, cost3));
    }
}
