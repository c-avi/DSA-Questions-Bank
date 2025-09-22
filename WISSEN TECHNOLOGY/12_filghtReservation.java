import java.util.*;

public class FlightReservationSystem {
    
    static class Flight {
        int flightId;
        String source, destination;
        int totalSeats, bookedSeats;
        List<Passenger> passengers = new ArrayList<>();
    
        public Flight(int id, String src, String dest, int seats) {
            this.flightId = id;
            this.source = src;
            this.destination = dest;
            this.totalSeats = seats;
            this.bookedSeats = 0;
        }

        public boolean bookSeat(Passenger p) {
            if (bookedSeats < totalSeats) {
                passengers.add(p);
                bookedSeats++;
                System.out.println("Booking successful for " + p.name);
                return true;
            } else {
                System.out.println("Booking failed! No seats available.");
                return false;
            }
        }

        public boolean cancelSeat(Passenger p) {
            if (passengers.remove(p)) {
                bookedSeats--;
                System.out.println("Cancellation successful for " + p.name);
                return true;
            } else {
                System.out.println(p.name + " is not booked on this flight.");
                return false;
            }
        }

        public void showPassengers() {
            if (passengers.isEmpty()) {
                System.out.println("No passengers booked yet.");
            } else {
                System.out.println("Passengers in Flight " + flightId + ":");
                for (Passenger p : passengers) {
                    System.out.println(p.name + " (ID: " + p.id + ")");
                }
            }
        }
    }

    static class Passenger {
        int id;
        String name;
    
        public Passenger(int id, String name) {
            this.id = id;
            this.name = name;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<Integer, Flight> flights = new HashMap<>();
        Map<Integer, Passenger> passengers = new HashMap<>();

        System.out.print("Enter number of flights: ");
        int flightCount = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < flightCount; i++) {
            System.out.println("Flight " + (i + 1) + ":");
            System.out.print("Flight ID: ");
            int fid = sc.nextInt();
            sc.nextLine();
            System.out.print("Source: ");
            String src = sc.nextLine();
            System.out.print("Destination: ");
            String dest = sc.nextLine();
            System.out.print("Total Seats: ");
            int seats = sc.nextInt();
            sc.nextLine();
            flights.put(fid, new Flight(fid, src, dest, seats));
        }

        System.out.print("Enter number of passengers: ");
        int passengerCount = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < passengerCount; i++) {
            System.out.println("Passenger " + (i + 1) + ":");
            System.out.print("Passenger ID: ");
            int pid = sc.nextInt();
            sc.nextLine();
            System.out.print("Name: ");
            String name = sc.nextLine();
            passengers.put(pid, new Passenger(pid, name));
        }

        while (true) {
            System.out.println("\n1. Book Ticket\n2. Cancel Ticket\n3. Show Passengers\n4. Exit");
            System.out.print("Enter choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            if (choice == 4) break;

            System.out.print("Enter Flight ID: ");
            int fid = sc.nextInt();
            sc.nextLine();
            Flight f = flights.get(fid);
            if (f == null) {
                System.out.println("Flight not found!");
                continue;
            }

            switch (choice) {
                case 1:
                    System.out.print("Enter Passenger ID: ");
                    int pidBook = sc.nextInt();
                    sc.nextLine();
                    Passenger pBook = passengers.get(pidBook);
                    if (pBook != null) f.bookSeat(pBook);
                    else System.out.println("Passenger not found!");
                    break;
                case 2:
                    System.out.print("Enter Passenger ID: ");
                    int pidCancel = sc.nextInt();
                    sc.nextLine();
                    Passenger pCancel = passengers.get(pidCancel);
                    if (pCancel != null) f.cancelSeat(pCancel);
                    else System.out.println("Passenger not found!");
                    break;
                case 3:
                    f.showPassengers();
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        }

        sc.close();
        System.out.println("Exiting Flight Reservation System.");
    }
}
