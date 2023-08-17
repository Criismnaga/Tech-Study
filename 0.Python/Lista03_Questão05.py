#Fundamentos de programação 01 | 2022.2
#Lista de Exercicíos 03 - Questão 05
#Aluna: Cristina Matsunaga
'''Esse ano Robson pretende montar uma bela árvore de Natal na
empresa em que trabalha. Ele combinou com os outros 20
funcionários de seu setor de comprar tudo e depois ratear o valor.
Pesquisando numa loja, ele encontrou a árvore prefeita e três tipos
de enfeites com bons preços.
Escreva um programa que receba como entrada o valor da árvore, a
quantidade e o preço unitário de cada tipo de enfeite, calcule e exiba
o total gasto e o valor a ser pago por cada funcionário do setor.'''

import os 
os.system("cls")

cont = 1
enfeite_total = 0.0

arvore = float(input(f"Digite o valor da árvore de Natal: \n"))

while cont <= 3:
    enfeite  = int(input(f"Digite o valor do efeite {cont} : \n"))
    enfeite_total = enfeite_total + enfeite
    cont +=1

total_gasto = arvore + enfeite_total
valor_func = (total_gasto)/20

print("O total gasto foi ", total_gasto, " e cada funcionário deverá pagar ", valor_func)
