import java.util.*;

public class MeetingRooms {
    public static int minMeetingRooms(int[][] intervals) {
        if (intervals.length == 0) return 0;
    
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        minHeap.add(intervals[0][1]);
        
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= minHeap.peek()) {
                minHeap.poll();
            }
            
            minHeap.add(intervals[i][1]);
        }
        return minHeap.size();
        
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter number of meetings: ");
        int n = sc.nextInt();
        
        int[][] intervals = new int[n][2];
         
        for (int i = 0; i < n; i++) {
            System.out.print("Enter start time of meeting " + (i+1) + ": ");
            intervals[i][0] = sc.nextInt();
            System.out.print("Enter end time of meeting " + (i+1) + ": ");
            intervals[i][1] = sc.nextInt();
        }
        
        int rooms = minMeetingRooms(intervals);
        System.out.println("Minimum number of rooms required: " + rooms);
    }
} 
