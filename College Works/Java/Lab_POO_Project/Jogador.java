public class Jogador extends Pessoa {
  // Atributos
  private int qtdAbates = 0;
  private int qtdMortes = 0;
  private int qtdAssistencias = 0;
  private String funcaoPrincipal;
  // Método construtor
  public Jogador(String nome, String email, int id, Double salario,
    String funcaoPrincipal) {
      super(nome, email, id, salario);
      this.funcaoPrincipal = funcaoPrincipal;
  }
  // Métodos GET
  public String getFuncaoPrincipal() {
    return funcaoPrincipal;
  }
  public int getQtdAbates() {
    return qtdAbates;
  }
  public int getQtdMortes() {
    return qtdMortes;
  }
  public int getQtdAssistencias() {
    return qtdAssistencias;
  }
  public String getRelatorioGeral() {
    String relatorio = " ";
    return relatorio;
  }
  // Métodos SET
  public void setQtdAbates(int qtdAbates) {
    this.qtdAbates = (qtdAbates < 0) ? 0 : qtdAbates;
  }
  public void setQtdMortes(int qtdMortes) {
    this.qtdMortes = (qtdMortes < 0) ? 0 : qtdMortes;
  }
  public void setQtdAssistencias(int qtdAssistencias) {
    this.qtdAssistencias = (qtdAssistencias < 0) ? 0 : qtdAssistencias;
  }
  // Outros métodos
  public void addQtdAbates(int incremento) {
    this.qtdAbates += (incremento < 0) ? -incremento : incremento;
  }
  public void addQtdMortes(int incremento) {
    this.qtdMortes += (incremento < 0) ? -incremento : incremento;
  }
  public void addQtdAssistencias(int incremento) {
    this.qtdAssistencias += (incremento < 0) ? -incremento : incremento;
  }
}
