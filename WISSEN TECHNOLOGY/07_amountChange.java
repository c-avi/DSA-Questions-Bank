import java.util.*;

public class GreedyChangeUserInput {
    public static Map<Integer, Integer> getChange(int amountChange, Map<Integer, Integer> available) {
        
        List<Integer> denominations = new ArrayList<>(available.keySet());
        denominations.sort(Collections.reverseOrder());
        
        Map<Integer, Integer> used = new LinkedHashMap<>();
        
        for (int denom : denominations) {
            int maxCanUse = Math.min(amountChange / denom, available.get(denom));
            if (maxCanUse > 0) {
                used.put(denom, maxCanUse);
                amountChange -= denom * maxCanUse;
            }
        }
        
        if (amountChange != 0) {
            System.out.println("Exact change may not be possible with given denominations!");
            return Collections.emptyMap();
        }
        
        return used;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the amount of change: ");
        int amountChange = sc.nextInt();
        System.out.print("Enter the number of denominations: ");
        int n = sc.nextInt();
        
        Map<Integer, Integer> available = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            System.out.print("Enter denomination: ");
            int denom = sc.nextInt();
            System.out.print("Enter available quantity for " + denom + ": ");
            int qty = sc.nextInt();
            available.put(denom, qty);
        }
        
        Map<Integer, Integer> result = getChange(amountChange, available);
        
        if (!result.isEmpty()) {
            System.out.println("Deno0minations used: " + result);
        }
    }
}
