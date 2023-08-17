#Fundamentos de programação 01 | 2022.2
#Lista de Exercicíos 03 - Questão 04
#Aluna: Cristina Matsunaga
'''O IBGE realizou um concurso para contratar pessoas para trabalhar
no censo. Cada candidato fez uma prova de português com 50
questões, outra de matemática com 35 questões, e uma prova de
redação. Para ser aprovado, era necessário acertar pelo menos 80%
da prova de português, 60% da prova de matemática, e ter nota igual
ou superior a 7 na redação.
Escreva um programa que receba como entrada, para 3 candidatos, a
quantidade de questões certas em português e em matemática, e
também a nota na redação. Na sequência calcule o percentual de
acertos e exiba quantos candidatos foram aprovados.'''

import os 
os.system("cls")

cand = 1
cand_aprov = 0

while cand <= 3:
    port = int(input(f"Candidato {cand} digite seus acertos em português: \n"))
    mat = int(input(f"Candidato {cand} digite seus acertos em matemática: \n"))
    red = int(input(f"Candidato {cand} digite seus acertos em redação: \n"))
    
    
    percent_port = (port * 100)/50
    percent_mat = (mat * 100)/35
    percent_red = (red * 100)/10
    percent_cand = print("O candidato ", cand, " acertou ", percent_port,"% em portugues, ", percent_mat,"% em matemática e ", percent_red,"% da redação\n")


    if (percent_port >= 80) and (percent_mat >= 60) and (percent_red >= 70):
        cand_aprov +=1

    cand +=1

print("O total de candidatos aprovados foi ", cand_aprov, ".\n")