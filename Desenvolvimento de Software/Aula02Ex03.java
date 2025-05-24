import java.util.Scanner;

public class Aula02Ex03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        
        int[] nuns = {1, 2, 3, 4, 5};
        int par = 0, impar = 0; 

       
        for (int i = 0; i < nuns.length; i++) {
            if (nuns[i] % 2 == 0) {
                par += 1;
            } else { 
                impar += 1;
            }
        }

       
        System.out.println("A quantidade de números pares é: " + par);
        System.out.println("A quantidade de números ímpares é: " + impar);

        
        System.out.print("Os números do vetor são: ");
        for (int i = 0; i < nuns.length; i++) {
            System.out.print("|" + nuns[i]);
        }
        System.out.print("|");
    }
}
