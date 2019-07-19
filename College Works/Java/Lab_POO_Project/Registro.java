import java.util.*;

public class Registro{
  // Atributos
  private List<Jogador> jogadores;
  private List<Funcionario> funcionarios;
  private List<Partida> partidas;
  private int qtdJogadores;
  // Método construtor
  public Registro() {
    jogadores = new ArrayList<Jogador>();
    funcionarios = new ArrayList<Funcionario>();
    partidas = new ArrayList<Partida>();
    qtdJogadores = 0;
  }
  // Métodos
  public int getQtdJogadores(){
    return qtdJogadores;
  }

  public void add(Jogador novoJogador) {
    jogadores.add(novoJogador);
    qtdJogadores++;
  }

  public List<Jogador> getListaJogadores() {
    return jogadores;
  }

  public void add(Funcionario novoFuncionario) {
    funcionarios.add(novoFuncionario);
  }

  public void add(Partida novaPartida) {
    partidas.add(novaPartida);
  }

  public void limpaJogos() {
    partidas.clear();
  }

  public String getRelatorioJogadores() {
    String relatorio = "Jogadores cadastrados:\n";

    for (Jogador temp : jogadores) {
      relatorio += "Jogador de ID: " + temp.getID() +
        "\n\tNome: " + temp.getNome() +
        "\n\tEmail: " + temp.getEmail() +
        "\n\tFuncao principal: " + temp.getFuncaoPrincipal() +
        "\n\tTelefones:\n" + temp.getTelefones() + "\n\n";
    }
    return relatorio;
  }

  public String getRelatorioFuncionarios() {
    String relatorio = "Funcionarios cadastrados:\n";

    for (Funcionario temp : funcionarios) {
      relatorio += "Funcionario de ID: " + temp.getID() +
        "\n\tNome: " + temp.getNome() +
        "\n\tEmail: " + temp.getEmail() +
        "\n\tCargo: " + temp.getCargo() +
        "\n\tTelefones:\n" + temp.getTelefones() + "\n\n";
    }
    return relatorio;
  }

  public String getSalarioJogadores() {
    String relatorio = "Salario dos jogadores:\n";
    Double total = 0.0;

    for (Jogador temp : jogadores) {
      relatorio += "Jogador de ID: " + temp.getID() +
        "\n\tNome: " + temp.getNome() +
        "\n\tSalario: R$" + temp.getSalario() + "\n\n";
      total += temp.getSalario();
    }
    relatorio += "Salario total de todos os jogadores: R$" + total + "\n\n";
    return relatorio;
  }

  public String getSalarioFuncionarios() {
    String relatorio = "Salario dos funcionarios:\n";
    Double total = 0.0;

    for (Funcionario temp : funcionarios) {
      relatorio += "Funcionario de ID: " + temp.getID() +
        "\n\tNome: " + temp.getNome() +
        "\n\tSalario: R$" + temp.getSalario() + "\n\n";
      total += temp.getSalario();
    }
    relatorio += "Salario total de todos os funcionarios: R$" + total + "\n\n";
    return relatorio;
  }

  public String getPontuacaoJogadores() {
    String relatorio = "Pontuacao de todos os jogadores:\n";

    for (Jogador temp : jogadores) {
      relatorio += "\tNome: " + temp.getNome() +
        "\n\tQuantidade de abates: " + temp.getQtdAbates() +
        "\n\tQuantidade de mortes: " + temp.getQtdMortes() +
        "\n\tQuantidade de assistencias: " + temp.getQtdAssistencias() + "\n\n";
    }

    return relatorio;
  }

  public String getResultadoPartidas() {
    int vitorias = 0;
    int derrotas = 0;
    for (Partida temp : partidas) {
      if(temp.getVitoria())
        vitorias++;
      else
        derrotas++;
    }
    return "O time obteve " + vitorias + " vitorias e " + derrotas + " derrotas!\n";
  }

  public String getPontuacaoPartidas() {
    int torresAliadasDestruidas = 0;
    int torresInimigasDestruidas = 0;
    int inibidoresAliadosDestruidos = 0;
    int inibidoresInimigosDestruidos = 0;
    for (Partida temp: partidas) {
      torresAliadasDestruidas += temp.getTorresAliadasDestruidas();
      torresInimigasDestruidas += temp.getTorresInimigasDestruidas();
      inibidoresAliadosDestruidos += temp.getInibidoresAliadosDestruidos();
      inibidoresInimigosDestruidos += temp.getInibidoresInimigosDestruidos();
    }
    return "Torres aliadas destruidas: " + torresAliadasDestruidas +
    "\nTorres inimigas destruidas: " + torresInimigasDestruidas +
    "\nInibidores alidos destruidos" + inibidoresAliadosDestruidos +
    "\nInibidores inimigos destruidos: " + inibidoresInimigosDestruidos + "\n";
  }
}
