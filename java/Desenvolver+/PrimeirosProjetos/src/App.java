
public class App {

	public static void main(String[] args) {
		int numeroDeCasos = 100000;
		int casoAtual = 1;
		int veredito, culpado=0, inocente=0;

		while (casoAtual <= numeroDeCasos) {

			veredito = (int) (Math.random() * 2) + 1;

			if (veredito == 1) {
				inocente++;
			} else {
				culpado++;
			}

			casoAtual++;

		}
		
		System.out.println("Foram juldados "+(numeroDeCasos)+" casos");
		System.out.println(culpado + " culpados");
		System.out.println(inocente + " inocentes");
	}

}
