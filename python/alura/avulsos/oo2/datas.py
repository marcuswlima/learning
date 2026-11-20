from datetime import date



data_atual = date.today()
print(data_atual)
data_em_texto = '{}/{}/{}'.format(data_atual.day, data_atual.month,data_atual.year)
print(data_em_texto)
data_em_texto = data_atual.strftime('%d/%m/%Y')
print(data_em_texto)


from datetime import datetime
data_e_hora_atuais = datetime.now()
data_e_hora_em_texto = data_e_hora_atuais.strftime('%d/%m/%Y %H:%M')

print(data_e_hora_em_texto)

data_e_hora_em_texto = '01/03/2018 12:30'
data_e_hora = datetime.strptime(data_e_hora_em_texto, '%d/%m/%Y %H:%M')


