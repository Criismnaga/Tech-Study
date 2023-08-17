#Fundamentos de programação 01 | 2022.2
#Lista de Exercicíos 05 - Questão 03
#Aluna: Cristina Matsunaga
#https://www.thehuxley.com/problem/51?quizId=8141

import os 
os.system("cls")

marc_ambrosio = {1: 5.3, 2: 6.0, 3:3.20, 4:2.5}

compra = int(input())
qtd = int(input())

if compra in marc_ambrosio.keys():
    valor = qtd * marc_ambrosio[compra]
    if qtd >= 15 or compra >= 40.0:
        valor = valor * 0.85

print(f"R$ {valor:.2f}") 



