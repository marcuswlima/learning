import utilitarios
import exe01_01
import exe01_02
import exe01_03
import exe02_01

def escolhe_programa():
    
    programa = 1
    while (programa != 0 ):
        print("-----------------------------------------")
        utilitarios.titulo("Aula 01")
        print("(1) IMC")
        print("(2) Informações de um cículo")
        print("(3) Fórmula de Baskara")
        utilitarios.titulo("Aula 02")
        print("(4) IMC - qualificado")
        programa = int(input("Qual programa? (0 para sair): "))

        if   (programa == 1):
            exe01_01.executar()
        elif (programa == 2):
            exe01_02.executar()
        elif (programa == 3):
            exe01_03.executar()
        elif (programa == 4):
            exe02_01.executar()


if __name__ == "__main__":
    escolhe_programa()

