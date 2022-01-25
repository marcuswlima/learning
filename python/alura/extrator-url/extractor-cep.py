import re #Regular Expression -- RegEx

endereco = "Rua Ferreira Pena, No. 347, apto 303,66050-140 "

padrao = re.compile("[0-9]{5}[-]{0,1}[0-9]{3}")

busca = padrao.search(endereco) #Match

if busca:
    cep=busca.group()
    print(cep)