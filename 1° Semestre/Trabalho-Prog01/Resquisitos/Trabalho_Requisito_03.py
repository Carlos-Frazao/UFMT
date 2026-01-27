import numpy as np #Importa a biblioteca numpy
import pandas as pd #Importa a biblioteca pandas
import sklearn #Importa sklearn
import flet as ft #Importa flet (cria paginas)

from sklearn.datasets import fetch_california_housing #Importa os dados que vamos trabalhar do sklearn

def main(pagina): #Especificamos que está funçao é a que o Flet vai inserir as informações

    # -------------------- Recebimento dos dados com o Pandas -------------------- #

    #Especifico que os dados importados agora estão na variavel casa_california
    casa_california = fetch_california_housing()

    #Uma matriz, pega os valores de casa_california. Pega todas as linhas, e cria 10 colunas para cada linha
    X = casa_california.data[:, 0:9]

    #Aqui especificamos as informações que estarão impressas na primeira coluna, no caso as informacoes de cada casa
    casa_informacao = ['MedInc','HousAge','AveRooms','AveBedrms','Population','AveOccup','Latitude','Longitude']

    #Criamos o DataFrame usando o panda, e especificamos que na primeira coluna deve ser preenchido com a nossa matriz casa_informacao
    df = pd.DataFrame(X, columns=casa_informacao)

    # -------------------- Calcular media, mediana, etc -------------------- #

    media = df.iloc[:, 0:6].mean() #Calculamos a média
    mediana = df.iloc[:, 0:6].median() #Calculamos a mediana
    moda = df.iloc[:,0:6].mode() #Calculamos a moda
    variancia = df.iloc[:,0:6].var() #Calculamos a variancia
    desvio_padrao = df.iloc[:,0:6].std() #Calculamos o desvio padrao
    Q1 = df.iloc[:,0:6].quantile(0.25) #Calculamos o Q1
    Q2 = df.iloc[:,0:6].quantile(0.5) #Calculamos o Q2
    Q3 = df.iloc[:,0:6].quantile(0.75) #Calculamos o Q3
    IQR = Q3 - Q1 #Calculamos o IQR

    # -------------------- Criar janela do Flet -------------------- #
    
    #Titulo da pagina no topo do Flet
    pagina.title = "Dados california"

    #Habilita a função de rolar a janela
    pagina.scroll = ft.ScrollMode.ADAPTIVE

    # -------------------- Elementos da janela -------------------- #

    #Aqui adicionamos os elemntos que vão estar na janela
    pagina.add(
        #Adiciona um texto a janela, esse texto é o titulo, em seguida alguns parametros para deixar mais bonito, como a cor e o tamanho da fonte
        ft.Text("Média:", size=16, color=ft.Colors.RED, weight=ft.FontWeight.BOLD), 

        #Adiciona um texto tendo o resultado da variavel media
        ft.Text(media),

        #E assim sucessivamente

        ft.Divider(),

        ft.Text("Mediana:", size=16, color=ft.Colors.RED, weight=ft.FontWeight.BOLD),
        ft.Text(mediana),

        ft.Divider(),

        ft.Text("Moda:", size=16, color=ft.Colors.RED, weight=ft.FontWeight.BOLD),
        ft.Text(moda),
        
        ft.Divider(),

        ft.Text("Variancia:", size=16, color=ft.Colors.RED, weight=ft.FontWeight.BOLD),
        ft.Text(variancia),

        ft.Divider(),

        ft.Text("Desvio Padrão:", size=16, color=ft.Colors.RED, weight=ft.FontWeight.BOLD),
        ft.Text(desvio_padrao),

        ft.Divider(),

        ft.Text("Q1:", size=16, color=ft.Colors.RED, weight=ft.FontWeight.BOLD),
        ft.Text(Q1),

        ft.Divider(),

        ft.Text("Q2:",size=16, color=ft.Colors.RED, weight=ft.FontWeight.BOLD),
        ft.Text(Q2),

        ft.Divider(),

        ft.Text("Q3:", size=16, color=ft.Colors.RED, weight=ft.FontWeight.BOLD),
        ft.Text(Q3),

        ft.Divider(),

        ft.Text("IQR:", size=16, color=ft.Colors.RED, weight=ft.FontWeight.BOLD),
        ft.Text(IQR),

    )

#Chamamos o Flet e inicializamos a função main
ft.app(target=main)
