import java.time.Instant;
import java.time.format.DateTimeParseException;
import java.util.*;

public class LogSearch {
    static class Log {
        Instant timestamp;
        String serviceName;
        String message;
    
        public Log(Instant t, String s, String m) {
            this.timestamp = t;
            this.serviceName = s;
            this.message = m;
        }
        
        @Override
        public String toString() {
            return "[" + timestamp + "]" + serviceName + " - " + message;
        }
    }

    static class LogSystem {
        private Map<String, TreeMap<Instant, List<Log>>> logMap = new HashMap<>();
        
        public void addLog(Log log) {
            logMap.putIfAbsent(log.serviceName, new TreeMap<>());
            logMap.get(log.serviceName).computeIfAbsent(log.timestamp, k -> new ArrayList<>()).add(log);
        }
    
        public List<Log> search(Instant start, Instant end, String serviceName) {
            List<Log> result = new ArrayList<>();
            if (!logMap.containsKey(serviceName)) return result;
            
            TreeMap<Instant, List<Log>> tree = logMap.get(serviceName);
            
            for (List<Log> logs : tree.subMap(start, true, end, true).values()) {
                result.addAll(logs);
            }
            return result;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LogSystem system = new LogSystem();
        
        System.out.print("Enter number of logs: ");
        int n = sc.nextInt();
        sc.nextLine();
        
        for (int i = 0; i < n; i++) {
            System.out.println("Log: "+ (i + 1) + ": ");
            System.out.print("Enter timestamp(ISO-8601 format e.g. 2025-09-22T10:15:30z): ");
            String ts = sc.nextLine();
            System.out.print("Enter service name: ");
            String service = sc.nextLine();
            System.out.print("Enter message: ");
            String msg = sc.nextLine();
            
            try {
                system.addLog(new Log(Instant.parse(ts), service, msg));
            } catch (DateTimeParseException e) {
                System.out.println("Invalid timestamp format, skipping log.");
            }
        }
        
        System.out.println("\nEnter search query:");
        System.out.print("Start time (ISO-8601): ");
        Instant start = Instant.parse(sc.nextLine());
        System.out.print("End time (ISO-8601): ");
        Instant end = Instant.parse(sc.nextLine());
        System.out.print("Service name: ");
        String serviceName = sc.nextLine();
        
        List<Log> results = system.search(start, end, serviceName);
        if (results.isEmpty()) {
            System.out.println("No logs found.");
        } else {
            System.out.println("Logs found: ");
            for (Log log : results) {
                System.out.println(log);
            }
        }
    }
}