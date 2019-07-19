public class Funcionario extends Pessoa {
  private String cargo;
  public Funcionario(String nome, String email, int id, Double salario, String cargo) {
    super(nome, email, id, salario);
    this.cargo = cargo;
  }
  public String getCargo(){
    return cargo;
  }
}
