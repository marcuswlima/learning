import utilitarios
import exe01_01
import exe01_02
import exe01_03

def escolhe_programa():
    utilitarios.titulo("Aula 01")
    
    programa = 1
    while (programa != 0 ):
        print("(1) IMC")
        print("(2) Informações de um cículo")
        print("(3) Fórmula de Baskara")
        programa = int(input("Qual programa? (0 para sair): "))

        if   (programa == 1):
            exe01_01.executar()
        elif (programa == 2):
            exe01_02.executar()
        elif (programa == 3):
            exe01_03.executar()


if __name__ == "__main__":
    escolhe_programa()

