#Fundamentos de programação 01 | 2022.2
#Lista de Exercicíos 03 - Questão 03
#Aluna: Cristina Matsunaga
'''Desenvolva um programa que leia o comprimento de três retas e
informe ao usuário se elas podem ou não formar um triângulo. A
condição para ser um triângulo é que uma das retas seja menor que a
soma das outras duas.'''

reta1 = float(input(f"Digite o comprimento da primeira reta: \n"))
reta2 = float(input(f"Digite o comprimento da segunda reta: \n"))
reta3 = float(input(f"Digite o comprimento da terceira reta: \n"))

if reta1 < (reta2 + reta3):
    print("É um tringulo")
elif reta2 < (reta1 + reta3):
    print("É um tringulo")
elif reta3 < (reta1 + reta2):
    print("É um tringulo")
else:
    print("Não é um tringulo")
