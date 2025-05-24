import java.util.Scanner;

public class Aula02Ex04 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

      
        int[] nuns = {1, 2, 3, 4, 5};
        
       
        System.out.print("Os números do vetor original são: ");
        for (int i = 0; i < nuns.length; i++) {
            System.out.print("|" + nuns[i]);
        }
        System.out.println("|");

        int[] vetorInvertido = new int[nuns.length];

        
        for (int i = 0; i < nuns.length; i++) {
            vetorInvertido[i] = nuns[nuns.length - 1 - i]; 
        }

        System.out.print("Os números do vetor invertido são: ");
        for (int i = 0; i < vetorInvertido.length; i++) {
            System.out.print("|" + vetorInvertido[i]);
        }
        System.out.println("|");
    }
}
