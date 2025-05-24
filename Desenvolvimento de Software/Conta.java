class Conta {
    private int numero;
    private double saldo;
    private double limite;
    private Cliente cliente;

    public Conta(int numero, Cliente cliente) {
        this.numero = numero;
        this.cliente = cliente;
        this.limite = 200;
    }

    public double retornaSaldoMaisLimite() {
        return limite + saldo;
    }

    public void mostrar() {
        System.out.println("Conta: " + numero + ", saldo: " + saldo + ", limite: " + limite);
    }

    public void depositar(double quantidade) {
        saldo += quantidade;
    }

    public void sacar(double quantidade) {
        if (quantidade <= retornaSaldoMaisLimite()) {
            saldo -= quantidade;
        } else {
            System.out.println("Saldo indisponível.");
        }
    }

    // Getters e Setters
    public int getNumero() {
        return numero;
    }

    public double getSaldo() {
        return saldo;
    }

    public Cliente getCliente() {
        return cliente;
    }
}