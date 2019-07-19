public class Telefone {
  // Atributos
  private String numero;
  private int ddd;
  private String tipo;
  // Método construtor
  public Telefone(int ddd, String numero, int tipo) {
    int tamMaxTelefone = 0;
    this.ddd = (ddd < 0) ? (ddd * -1) : ddd; // Se for negativo, converte para positivo
    this.tipo = (tipo == 0) ? "Movel" : "Fixo"; // 0 para móvel e 1 para fixo
    // Verificar o tamanho máximo do número do telefone, baseado no seu tipo
    if (tipo == 0)
      tamMaxTelefone = 9;
    else
      tamMaxTelefone = 8;
    /* Realizar a formatação do número de telefone, se for maior que o máximo
    permitido os números em excesso serão ignorados, se for menor ele será
    preenchido com zeros */
    if(numero.length() > tamMaxTelefone)
      numero = numero.substring(0, tamMaxTelefone);
    else if (numero.length() < tamMaxTelefone) {
      for (int i = tamMaxTelefone - numero.length(); i != 0; i--)
        numero += "0";
    }
    this.numero = numero;
  }
  // Métodos GET
  public String getNumeroCompleto() {
    String numeroCompleto = "0" + ddd + numero;
    if (tipo.equals("Movel"))
      numeroCompleto = String.valueOf(numeroCompleto).replaceFirst("(\\d{3})(\\d{5})(\\d{4})",
        "($1)$2-$3");
    else
      numeroCompleto = String.valueOf(numeroCompleto).replaceFirst("(\\d{3})(\\d{4})(\\d{4})",
        "($1)$2-$3");

    return numeroCompleto;
  }
}
