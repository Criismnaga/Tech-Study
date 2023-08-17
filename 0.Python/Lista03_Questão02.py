#Fundamentos de programação 01 | 2022.2
#Lista de Exercicíos 03 - Questão 02
#Aluna: Cristina Matsunaga
"""Uma empresa possui 5 funcionários e resolveu oferecer um auxílio
família de R$ 150,00 por filho. O sistema deverá perguntar a
quantidade de filhos e informar o valor total do bônus para cada
funcionário."""

import os 
os.system("cls")

num_func = 1

while num_func <= 5:
    num_filho = int(input(f"Funcionário {num_func} insira a quantidade de filhos: \n"))
    bonus = num_filho * 150
    
    print("Funcionario ", num_func, "seu bônus é ", bonus)
    num_func += 1