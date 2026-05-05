import java.util.Scanner;

public class Prim {
    static void MSTPrim(int[][] cost, int n, int source) {
        
        int[] tvertex = new int[n];
        int a = 0, b = 0, min, mincost = 0, ne = 0;
        
        tvertex[source] = 1;

        while (ne < n - 1) {
            min = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                if (tvertex[i] == 1) {
                    for (int j = 0; j < n; j++) {
                        if (cost[i][j] < min && tvertex[j] == 0) {
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }

            if (min == Integer.MAX_VALUE) {
                System.out.println("Graph is disconnected; MST cannot be completed.");
                return;
            }

            System.out.println("Pipeline from city " + a + " to city " + b + " costs " + min + " units.");

            tvertex[b] = 1;
            ne++;
            mincost += min;
        }

        System.out.println("Minimum cost of urban water supply network is " + mincost + " units.");
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter the number of cities: ");
        int n = s.nextInt();

        int[][] cost = new int[n][n];

        System.out.print("Enter the cost matrix: ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = s.nextInt();
                
                if (cost[i][j] == 0) {
                    cost[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        System.out.print("Enter the source: ");
        int source = s.nextInt();

        MSTPrim(cost, n, source);
    }
}