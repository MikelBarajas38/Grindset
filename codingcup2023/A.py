n = int(input())

synonyms = dict()

for _ in range(n):
  a, b = input().split()
  synonyms[a] = b
  synonyms[b] = a

sentence = input()

cambios = ""

resultado = []

palabras = sentence.split()

for palabra in palabras:

    a = ''
    c = 0;
    while c < len(palabra) and not palabra[c].isalpha():
        a += palabra[c];
        c += 1;
    
    b = ''
    while c < len(palabra) and palabra[c].isalpha():
        b += palabra[c];
        c += 1;

    d = ''
    while c < len(palabra) and not palabra[c].isalpha():
        d += palabra[c];
        c += 1;
    
    if a != '':
        resultado.append(a)

    if b != '':
        resultado.append(b)

    if d != '':
        resultado.append(d)
    
    resultado.append('')

oracion = ''
for palabra in resultado:
    if palabra == '':
        oracion += " "
    elif palabra in synonyms.keys():
        oracion += synonyms[palabra]
    else:
        oracion += palabra
        

print(oracion)