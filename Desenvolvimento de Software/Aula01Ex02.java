import java.util.Scanner;
 /*2.
 Adicione a classe:

a) Leia o nome e a idade de uma pessoa e gere uma mensagem personalizada com esses dados.

b) Caso a idade seja menor que 16 anos, informe que a pessoa pode votar; caso contrário, informe que não pode.

c) Em um laço for, faça a estimativa de idade da pessoa nos próximos 20 anos.
 */
public class Aula01Ex02 {

    public static void main(String[] args) {
        
        
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite seu nome: ");
        String nome = scanner.nextLine();
        
        System.out.print("Digite sua idade: ");
        int idade = scanner.nextInt();

        System.out.println("Olá, " + nome + "! Você tem " + idade + " anos.");

        if (idade >= 16) {
            System.out.println("Você pode votar.");
        } else {
            System.out.println("Você não pode votar.");
        }

        System.out.println("Estimativa da sua idade nos próximos 20 anos:");
        for (int i = 1; i <= 20; i++) {
            int idadeFutura = idade + i;
            System.out.println("Em " + i + " ano(s), você terá " + idadeFutura + " anos.");
        }
    }
}
