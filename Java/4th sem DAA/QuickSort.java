import java.util.*;

public class QuickSort {
    static int count = 0;

    static int partition(int[] a, int l, int r) {
        int s = a[l], temp, i = l, j = r + 1;

        do { 
            do { 
                i++;
                count++;
            } while (i < r && a[i] <= s);

            do { 
                j--;
                count++;
            } while (j > l && a[j] > s);

            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp; 
            }

        } while (i < j);

        temp = a[l];
        a[l] = a[j];
        a[j] = temp;

        return j;
    }

    static void quickSort(int[] a, int l, int r) {
        if (l < r) {
            int s = partition(a, l, r);
            quickSort(a, l, s - 1);
            quickSort(a, s + 1, r);
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Random r = new Random();

        System.out.print("Enter the number of vertices: ");
        int n = s.nextInt();

        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = r.nextInt(10000);
        }

        quickSort(a, 0, n - 1);

        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }

        System.out.println("Best case: " + (int)(n * Math.log(n) / Math.log(2)));
        System.out.println("Basic operation count: " + count);
        System.out.println("Worst case: " + (n * n));
    }
}