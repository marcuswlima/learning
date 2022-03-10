lista1 = ["Orozimbo Maia", "Alferes Poli", "Anita Garibaldi", "Claudio Torres Junior", "Anne Frank", "Daisy Lucy Berno"]

qdt_o=0
for item in lista1:
    for letra in item:
        if letra.upper() == 'O':
            qdt_o += 1

print('qdt_o',qdt_o)