public class Partida {
  private Boolean vitoria;
  private int torresAliadasDestruidas;
  private int torresInimigasDestruidas;
  private int inibidoresAliadosDestruidos;
  private int inibidoresInimigosDestruidos;
  public Partida(int vitoria, int tAliadasDestr, int tInimigasDestr, int inibAliadosDestr, int inibInimigosDestr) {
    this.vitoria = (vitoria == 0) ? true : false; // true = vitoria, false = derrota
    // Validar a pontuação dos objetivos dos inimigos
    if (torresAliadasDestruidas < 0)
      this.torresAliadasDestruidas = 0;
    else if (torresAliadasDestruidas > 11)
      this.torresAliadasDestruidas = 11;
    else
      this.torresAliadasDestruidas = torresAliadasDestruidas;
    // Validar a pontuação dos objetivos dos aliados
    if (torresInimigasDestruidas < 0)
      this.torresInimigasDestruidas = 0;
    else if (torresInimigasDestruidas > 11)
      this.torresInimigasDestruidas = 11;
    else
      this.torresInimigasDestruidas = torresInimigasDestruidas;
    // Validar inibidores aliados destruidos
    this.inibidoresAliadosDestruidos = (inibidoresAliadosDestruidos < 0) ? 0 : inibidoresAliadosDestruidos;
    // Validar inibidores inimigos destruidos
    this.inibidoresInimigosDestruidos = (inibidoresInimigosDestruidos < 0) ? 0 : inibidoresInimigosDestruidos;
  }

  public Boolean getVitoria(){
    return vitoria;
  }

  public int getTorresAliadasDestruidas(){
    return torresAliadasDestruidas;
  }

  public int getTorresInimigasDestruidas(){
    return torresInimigasDestruidas;
  }

  public int getInibidoresAliadosDestruidos(){
    return inibidoresAliadosDestruidos;
  }

  public int getInibidoresInimigosDestruidos(){
    return inibidoresInimigosDestruidos;
  }
}
