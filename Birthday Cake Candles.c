import java.util.Scanner;

public class Solution {

    public static int birthdayCakeCandles(int[] candles) {
        
        int tallest = candles[0];
        int count = 1;

        for (int i = 1; i < candles.length; i++) {
            if (candles[i] > tallest) {
                tallest = candles[i];
                count = 1; 
            } else if (candles[i] == tallest) {
                count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
       
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int[] candles = new int[n];

        for (int i = 0; i < n; i++) {
            candles[i] = scanner.nextInt();
        }

        int result = birthdayCakeCandles(candles);
   
        System.out.println(result);

        scanner.close();
    }
}
