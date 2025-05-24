
/*
1. Crie um vetor de 10 posições c/ valores inteiros, preencha em um loop for e some os valores de cada posição em um segundo loop. 
*/
import java.util.Scanner;
public class Aula02Ex01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

int nuns[] = new int[10];
int soma= 0;

System.out.println("escreva 10 numeros");

    for(int i = 0  ; i < nuns.length;i++ ){
System.out.println("Indice "+i+" numero:");
nuns[i] = sc.nextInt();
    }
    
    
    for(int i = 0  ; i < nuns.length;i++ ){
        System.out.print("|"+nuns[i]);
            }


            for(int i = 0  ; i < nuns.length;i++ ){
               soma = soma + nuns[i];
                    }
             System.out.print("|");
            System.out.print("soma = " + soma);
    }
}
