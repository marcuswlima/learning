#-----------------------
# histogram
#-----------------------
def monta_histograma(s):
    d = dict()
    for c in s:
        if c not in d:
            d[c] = 1
        else:
            d[c] += 1
    return d

def print_histogram(s):
    print(s)
    for item in sorted(s):
        print(item,s[item])
    
#-----------------------
# inicio 
#-----------------------

m = monta_histograma('marcus william dos santos lima')
print_histogram(m)


m = monta_histograma('caetano costa e lima')
print_histogram(m)

m = monta_histograma('ignacio costa e lima')
print_histogram(m)

'''

m = histogram('maria do socorro lima')
print(m)
'''
