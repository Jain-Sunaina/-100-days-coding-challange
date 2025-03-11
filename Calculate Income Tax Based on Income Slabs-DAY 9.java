import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sr = new Scanner(System.in);
        
        double income = sr.nextDouble();

        if (income <= 250000) {
            System.out.println("0.0"); 
        } else if (income <= 500000) {
            System.out.println((income - 250000) * 0.05); 
        } else if (income <= 1000000) {
            System.out.println((income - 500000) * 0.20 + 12500); 
        } else {
            System.out.println((income - 1000000) * 0.30 + 112500);  
        }
    }
}