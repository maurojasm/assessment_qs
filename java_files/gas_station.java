package java_files;

public class gas_station {
    public static void print(int[] nums) {
        System.out.print("[ ");
        for(int x: nums) {
            System.out.print(x + " ");
        }
        System.out.println("]");
    }
    // my attempt... does not work
    public static int canCompleteCircuit(int[] gas, int[] cost) {
        int tank = 0, next_gas;
        for(int i = 0; i < gas.length; i++) {
            next_gas = i + 1;
            while(tank >= 0 && next_gas != i) {
                tank += gas[next_gas - 1] - cost[next_gas - 1];
                next_gas++;
                if(next_gas > gas.length) {
                    next_gas = 1;
                }
                System.err.println("i: " + i);
                System.err.println("tank: " + tank);
                System.out.println("next: " + next_gas + "\n");
            }
            if(tank >= 0 && next_gas == i) {
                return i;
            }
            tank = 0;
        }

        return -1;
    }

    public static void main(String[] args) {
        // int gas1[] = {1,2,3,4,5}, cost1[] = {3,4,5,1,2};
        int gas2[] = {2,3,4}, cost2[] = {3,4,3};

        // System.out.print("Gas: "); print(gas1);
        // System.out.print("Cost: "); print(cost1);
        // System.out.println("Gas to start: " + canCompleteCircuit(gas1, cost1));

        // System.out.println("");

        System.out.print("Gas: "); print(gas2);
        System.out.print("Cost: "); print(cost2);
        System.out.println("Gas to start: " + canCompleteCircuit(gas2, cost2));
    }
}
