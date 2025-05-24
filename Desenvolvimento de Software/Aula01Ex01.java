import java.util.Scanner;
 /*Crie um novo class chamado Exercícios

1. Fazer um programa em Java que receba 2 números inteiros do usuário e calcule:

a) a soma dos números
b) a subtração do 1º pelo 2º
c) a multiplicação do 1º pelo 2º
d) a divisão do primeiro pelo 2º
e) o quadrado do 2º 
*/
public class Aula01Ex01 {

    public static void main(String[] args) {

        // Cria um objeto Scanner para ler os dados do usuário
        Scanner scanner = new Scanner(System.in);

        // Solicita e lê os dois números inteiros
        System.out.print("Digite o primeiro número inteiro: ");
        int num1 = scanner.nextInt();

        System.out.print("Digite o segundo número inteiro: ");
        int num2 = scanner.nextInt();

        // Calculando a soma
        int soma = num1 + num2;

        // Calculando a subtração
        int subtracao = num1 - num2;

        // Calculando a multiplicação
        int multiplicacao = num1 * num2;

        // Calculando a divisão
        double divisao = (double) num1 / num2;

        // Calculando o quadrado do segundo número
        int quadrado = num2 * num2;

        // Exibindo os resultados
        System.out.println("Resultado da soma: " + soma);
        System.out.println("Resultado da subtração (1º - 2º): " + subtracao);
        System.out.println("Resultado da multiplicação: " + multiplicacao);
        System.out.println("Resultado da divisão (1º / 2º): " + divisao);
        System.out.println("Resultado do quadrado do 2º número: " + quadrado);
    }
}


