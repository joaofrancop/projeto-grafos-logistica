/*
    5. Crie um vetor de 5 posições do tipo double, preencha em um loop e, ao final, calcule a média dos valores informados. 
*/
import java.util.Scanner;

public class Aula02Ex05 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = 15;
        int nuns[] = new int[10];

        // int dias[];
        System.out.println("escreva 10 numeros");
        for (int i = 0; i < nuns.length; i++) {
            System.out.println("Indice " + i + " numero:");
            nuns[i] = sc.nextInt();

            for (int j = 0; i < nuns.length; j++) {
                System.out.print("|" + nuns[j]);
            }

            System.out.print("|");
        }
    }

}