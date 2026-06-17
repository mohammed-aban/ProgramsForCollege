import java.util.Scanner;

public class Floyd {

    // Applies Floyd-Warshall algorithm to find shortest paths
    // between all pairs of stations.
    static void floyd(int D[][], int n) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    // Returns the smaller of two integers.
    static int min(int a, int b) {
        return (a < b ? a : b);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n;
        System.out.println("Enter no. of Stations");
        n = s.nextInt();

        int[][] cost = new int[n][n];

        // Enter the cost matrix:
        // 0 for principal diagonal axis.
        // 0 for no direct edge between different stations.
        // 999 represents no direct edge from i to j.
        System.out.println("Enter the travel time between subway lines");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = s.nextInt();

                if (cost[i][j] == 0 && i != j) {
                    cost[i][j] = 999;
                }
            }
        }

        floyd(cost, n);

        System.out.println("Shortest Travel Time between all stations");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(cost[i][j] + " ");
            }
            System.out.println();
        }
    }
}