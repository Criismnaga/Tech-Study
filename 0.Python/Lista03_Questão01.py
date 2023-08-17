#Fundamentos de programação 01 | 2022.2
#Lista de Exercicíos 03 - Questão 01
#Aluna: Cristina Matsunaga
''' Faça um programa que peça ao usuário que insira um número inteiro
e calcule o seu fatorial. O fatorial é a multiplicação do número
escolhido até 1.
Exemplo, o fatorial de 5 é 120 (5x4x3x2x1 = 120).'''

import os 
os.system("cls")

num = int(input("Insira um número: "))
cont = 1
mult_result = 1

while cont <= num:
    mult_result *= cont
       
    cont +=1

print("O fatorial de ", num, " é ", mult_result)    

