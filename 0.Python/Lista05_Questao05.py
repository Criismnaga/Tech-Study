#Fundamentos de programação 01 | 2022.2
#Lista de Exercicíos 05 - Questão 04
#Aluna: Cristina Matsunaga
#https://www.thehuxley.com/problem/3760?quizId=8141

numero_de_cadeias = int(input())
regra_dna = {'T':'A', 'A':'T', 'C':'G', 'G':'C'}
cadeia_1_lista = []
cadeia_2_lista = []
cadeia_teste_lista = []
for i in range(numero_de_cadeias):
  cadeia_teste = []
  cadeia_1 = input()
  cadeia_2 = input()
  for letra in cadeia_1:
    cadeia_teste.append(regra_dna[letra])
  cadeia_1_lista.append(cadeia_1)
  cadeia_2_lista.append(cadeia_2)
  cadeia_teste_lista.append(''.join(cadeia_teste))

for i in range(numero_de_cadeias):
  if cadeia_2_lista[i] == cadeia_teste_lista[i]:
    print('COMPLEMENTARES')
  if cadeia_2_lista[i] != cadeia_teste_lista[i]:
    print('NAO COMPLEMENTARES')
    print(cadeia_teste_lista[i])