import java.util.*;

public abstract class Pessoa {
  // Atributos
  protected String nome;
  protected String email;
  protected List<Telefone> telefones = new ArrayList<Telefone>();
  protected int id;
  protected Double salario;
  // Método construtor
  public Pessoa(String nome, String email, int id, Double salario) {
    this.nome = nome;
    this.email = email;
    this.id = id;
    this.salario = (salario < 0.0) ? 0.0 : salario;
  }
  // Métodos GET
  public String getNome() {
    return nome;
  }
  public String getEmail() {
    return email;
  }
  public int getID() {
    return id;
  }
  public Double getSalario() {
    return salario;
  }
  public String getTelefones() {
    String aux = "";
    for (Telefone temp: telefones) {
      aux += "\t\t" + temp.getNumeroCompleto() + "\n";
    }
    return aux;
  }
  // Métodos SET
  public void setEmail(String novoEmail) {
    this.email = novoEmail;
  }
  // Outros métodos
  public void addTelefone(int ddd, String numero, int tipo) {
    telefones.add(new Telefone(ddd, numero, tipo));
  }
}
