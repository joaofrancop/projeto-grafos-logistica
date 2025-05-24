public class Aula03 {
    public static void main(String[] args) {
        Cliente cli = new Cliente("João", "0123", "1234");

        Conta c = new Conta(101, cli);
        c.depositar(200);

        System.out.println("Conta: " + c.getNumero() + ", Nome do cliente: " + c.getCliente().getNome() + ", telefone: " + c.getCliente().getTelefone());
        System.out.println("Conta: " + c.getNumero() + ", CPF do cliente: " + c.getCliente().getCpf() + ", telefone: " + c.getCliente().getTelefone());

        c.depositar(125);
        c.mostrar();

        c.sacar(450);
        c.mostrar();

        Cliente cli2 = new Cliente("Cliente", "2222", "9876");
        Cliente cli3 = new Cliente("Cliente", "2222", "9876");

        cli2 = cli3;  // cli2 passa a referenciar o mesmo objeto que cli3

        if (cli2 == cli3) {
            System.out.println("Iguais");
        } else {
            System.out.println("Diferentes");
        }

        System.out.println("cli2: " + cli2 + ", cli3: " + cli3);
    }
}