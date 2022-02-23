import utilitarios

def ee02_04():
    utilitarios.titulo("exercicio extra 02.04")

    nota=0
    quantidade_notas=-1
    alunos_aprovados=0
    alunos_em_recuperacao=0
    alunos_reprovados=0
    while(nota!=-1):
        nota=int(input("informe a nota: "))
        quantidade_notas += 1
        if nota>70:
            alunos_aprovados += 1
        elif nota<70 and nota>=40:
            alunos_em_recuperacao += 1
        elif nota<40 and nota!=-1:
            alunos_reprovados += 1



    print("Foram informadas {} notas".format(quantidade_notas))
    print("{} aprovados".format(alunos_aprovados))
    print("{} em recuperacao".format(alunos_em_recuperacao))
    print("{} reprovados".format(alunos_reprovados))

if __name__ == "__main__":
    ee02_04()


