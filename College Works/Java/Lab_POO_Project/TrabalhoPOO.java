import javax.swing.JOptionPane;

public class TrabalhoPOO {
  public static int cadastro(Registro registro, int id) {
    String nome, email, funcaoPrincipal, cargo, numero;
    String[] tipoCadastro = {"Jogador", "Funcionario"};
    String[] opcoes = {"Sim", "Nao"};
    String[] tipoTel = {"Movel", "Fixo"};
    Double salario = 0.0;
    int op1, op2, op3, ddd, valida;
    // Inicialização das variáveis para poder tratar os erros sem gerar erro de inicialização
    nome = email = funcaoPrincipal = cargo = numero = "";
    ddd = 0;

    do {
      op1 = JOptionPane.showOptionDialog(null, "Tipo de cadastro:", "Menu",
        JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
        tipoCadastro, tipoCadastro[0]);
      if (op1 == 0) { // Cadastro de um jogador
        if (registro.getQtdJogadores() < 5) {
          do {
            try {
              valida = 1;
              nome = JOptionPane.showInputDialog(null, "Nome:");
              email = JOptionPane.showInputDialog(null, "Email:");
              salario = Double.parseDouble(JOptionPane.showInputDialog(null, "Salario:"));
              funcaoPrincipal = JOptionPane.showInputDialog(null, "Funcao principal:");
            } catch(Exception e) {
              JOptionPane.showMessageDialog(null, "Entrada invalida!\nEntre novamente com os dados!");
              valida = 0;
            }
          } while (valida == 0);
          // Instanciação de um objeto auxiliar do tipo Jogador
          Jogador temp1 = new Jogador(nome, email, id, salario, funcaoPrincipal);
          do { // Adicionar telefones
            op2 = JOptionPane.showOptionDialog(null, "Adicionar telefone?", "Menu",
            JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
            opcoes, opcoes[0]);
            if (op2 == 0) {
              do {
                try {
                  valida = 1;
                  ddd = Integer.parseInt(JOptionPane.showInputDialog(null, "DDD:"));
                  numero = JOptionPane.showInputDialog(null, "Numero:");
                } catch(Exception e) {
                  JOptionPane.showMessageDialog(null, "Entrada invalida!\nEntre novamente com os dados!");
                  valida = 0;
                }
              } while (valida == 0);
              op3 = JOptionPane.showOptionDialog(null, "Tipo do telefone:", "Menu",
              JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
              tipoTel, tipoTel[0]);
              temp1.addTelefone(ddd, numero, op3); // Adiciona um novo telefone ao jogador
            }
          } while (op2 == 0);
          registro.add(temp1); // Insere o novo jogador na lista de jogadores
          id++;
        } else
          JOptionPane.showMessageDialog(null, "Erro: apenas 5 jogadores podem estar cadastrados");
      } else { // Cadastro de um funcionario
        do {
          try {
            valida = 1;
            nome = JOptionPane.showInputDialog(null, "Nome:");
            email = JOptionPane.showInputDialog(null, "Email:");
            salario = Double.parseDouble(JOptionPane.showInputDialog(null, "Salario:"));
            cargo = JOptionPane.showInputDialog(null, "Cargo:");
          } catch(Exception e) {
            JOptionPane.showMessageDialog(null, "Entrada invalida!\nEntre novamente com os dados!");
            valida = 0;
          }
        } while (valida == 0);
        // Instanciação de um objeto auxiliar do tipo Funcionario
        Funcionario temp2 = new Funcionario(nome, email, id, salario, cargo);
        do { // Adicionar telefones
          op2 = JOptionPane.showOptionDialog(null, "Adicionar telefone?", "Menu",
          JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
          opcoes, opcoes[0]);
          if (op2 == 0) {
            do {
              try {
                valida = 1;
                ddd = Integer.parseInt(JOptionPane.showInputDialog(null, "DDD:"));
                numero = JOptionPane.showInputDialog(null, "Numero:");
              } catch(Exception e) {
                JOptionPane.showMessageDialog(null, "Entrada invalida!\nEntre novamente com os dados!");
                valida = 0;
              }
            } while (valida == 0);
            op3 = JOptionPane.showOptionDialog(null, "Tipo do telefone:", "Menu",
              JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
              tipoTel, tipoTel[0]);
            temp2.addTelefone(ddd, numero, op3); // Adiciona um novo telefone ao funcionario
          }
        } while (op2 == 0);
        registro.add(temp2); // Insere o novo jogador na lista de jogadores
        id++;
      }
      op2 = JOptionPane.showOptionDialog(null, "Continuar cadastrando?", "Menu",
        JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
        opcoes, opcoes[0]);
    } while (op2 == 0);

    return id;
  }

  public static void relatorio(Registro registro) {
    String[] opcoes = {"Sim", "Nao"};
    String[] tipoPessoa = {"Jogador", "Funcionario"};
    String[] operacao = {"Geral", "Salario", "Pontuacoes"};
    int op1, op2, op3;

    do {
      op1 = JOptionPane.showOptionDialog(null, "Tipo do relatorio:", "Menu",
        JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
        operacao, operacao[0]);
      switch (op1) {
        case 0:
          op2 = JOptionPane.showOptionDialog(null, "De quais pessoas?", "Menu",
            JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
            tipoPessoa, tipoPessoa[0]);
          if (op2 == 0)
            System.out.println(registro.getRelatorioJogadores());
          else
            System.out.println(registro.getRelatorioFuncionarios());
          break;
        case 1:
          op2 = JOptionPane.showOptionDialog(null, "De quais pessoas?", "Menu",
            JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
            tipoPessoa, tipoPessoa[0]);
          if (op2 == 0)
            System.out.println(registro.getSalarioJogadores());
          else
            System.out.println(registro.getSalarioFuncionarios());
          break;
        case 2:
          System.out.println(registro.getPontuacaoJogadores());
      }
      op3 = JOptionPane.showOptionDialog(null, "Continuar a ver relatorios?", "Menu",
        JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
        opcoes, opcoes[0]);
    } while (op3 == 0);
  }

  public static void jogos(Registro registro) {
    String[] opcoes = {"Sim", "Nao"};
    int vitoria, abates, mortes, assist, valida;
    int tAliadasDestr; // Torres aliadas destruidas
    int tInimigasDestr; // Torres inimigas destruidas
    int inibAliadosDestr; // Inibidores aliados destruidos
    int inibInimigosDestr; // Inibidores inimigos destruidos
    valida = 1;

    if (registro.getQtdJogadores() == 5) {
        for (int i = 0; i < 5; i++) {
          vitoria = JOptionPane.showOptionDialog(null, "O time ganhou?",
            "Partida" + (i + 1), JOptionPane.DEFAULT_OPTION,
            JOptionPane.INFORMATION_MESSAGE, null, opcoes, opcoes[0]);
            do {
              try {
                valida = 1;
                tAliadasDestr = Integer.parseInt(JOptionPane.showInputDialog(null, "Quantidade de torres aliadas destruidas:"));
                tInimigasDestr = Integer.parseInt(JOptionPane.showInputDialog(null, "Quantidade de torres inimigas destruidas:"));
                inibAliadosDestr = Integer.parseInt(JOptionPane.showInputDialog(null, "Quantidade de inibidores aliados destruidos:"));
                inibInimigosDestr = Integer.parseInt(JOptionPane.showInputDialog(null, "Quantidade de inibidores inimigos destruidos:"));
                registro.add(new Partida(vitoria, tAliadasDestr, tInimigasDestr, inibAliadosDestr, inibInimigosDestr));
              } catch (Exception e) {
                JOptionPane.showMessageDialog(null, "Entrada invalida!\nEntre novamente com o placar desta partida!");
                valida = 0;
              }
            } while (valida == 0);
          for (Jogador temp: registro.getListaJogadores()) {
            do {
              try {
                valida = 1;
                abates = Integer.parseInt(JOptionPane.showInputDialog(null, "Abates realizados pelo jogador " + temp.getNome() + ":"));
                mortes = Integer.parseInt(JOptionPane.showInputDialog(null, "Mortes sofridas pelo jogador " + temp.getNome() + ":"));
                assist = Integer.parseInt(JOptionPane.showInputDialog(null, "Assistencias realizadas pelo jogador " + temp.getNome() + ":"));
                temp.addQtdAbates(abates);
                temp.addQtdMortes(mortes);
                temp.addQtdAssistencias(assist);
              } catch(Exception e) {
                JOptionPane.showMessageDialog(null, "Entrada invalida!\nEntre novamente com a pontuadao dos jogadores nesta partida!");
                valida = 0;
              }
            } while (valida ==0);
          }
        }
        System.out.println(registro.getResultadoPartidas());
        System.out.println(registro.getPontuacaoPartidas());
        registro.limpaJogos();
    } else {
      JOptionPane.showMessageDialog(null, "Insira 5 jogadores para comecar!");
    }
  }

  public static void main(String[] args) {
    String[] opcoes = {"Cadastro", "Relatorios", "Jogos", "Sair"};
    int op, id;
    Registro registro = new Registro();
    id = 0;
    do {
      op = JOptionPane.showOptionDialog(null, "O que deseja fazer?", "Menu",
        JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null,
        opcoes, opcoes[0]);
      switch (op) {
        case 0:
          id = cadastro(registro, id);
          break;
        case 1:
          relatorio(registro);
          break;
        case 2:
          jogos(registro);
          break;
      }
    } while (op != 3);
  }
}
