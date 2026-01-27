import numpy as np #Importa a biblioteca numpy
import pandas as pd #Importa a biblioteca pandas
import seaborn as sns #Biblioteca seaborn, ela faz o grafico
import matplotlib.pyplot as plt #Biblioteca matplotlib, ela serve para o seaborn funcionar e com ela podemos manipular mais informacoes do grafico
import sklearn #Importa sklearn
from sklearn.datasets import fetch_california_housing #Importa os dados que vamos trabalhar do sklearn

def main():

    # -------------------- Recebimento dos dados com o Pandas -------------------- #

    #Especifico que os dados importados agora estão na variavel casa_california
    casa_california = fetch_california_housing()

    #Uma matriz, pega os valores de casa_california. Pega todas as linhas, e cria 10 colunas para cada linha
    X = casa_california.data[:, 0:6]

    #Aqui especificamos as informações que estarão impressas na primeira coluna, no caso as informacoes de cada casa
    casa_informacao = ['MedInc','HousAge','AveRooms','AveBedrms','Population','AveOccup']

    #Criamos o DataFrame usando o panda, e especificamos que na primeira coluna deve ser preenchido com a nossa matriz casa_informacao
    df = pd.DataFrame(X, columns=casa_informacao)

    # -------------------- Geraçao de grafico -------------------- #

    # Cria uma figura (fig) com uma grade de 2 linhas e 3 colunas de subplots (posicao)
    # figsize define o tamanho total da janela
    fig, posicao = plt.subplots(2, 3, figsize=(15, 10))

    #Cria o histograma de MedInc na primeira posicao (linha 0, coluna 0)
    sns.histplot(data=df, x='MedInc',kde=True, ax=posicao[0,0])
    posicao[0,0].set_title("MedInc") #Titulo do histograma

    #Cria o histograma de HousAge na segunda posicao (linha 0, coluna 1)
    sns.histplot(data=df, x='HousAge',kde=True, ax=posicao[0,1])
    posicao[0,1].set_title("HousAge") 
    
    #Cria o histograma de AveRooms na terceira posica (linha 0, coluna 2)
    sns.histplot(data=df, x='AveRooms',kde=True, ax=posicao[0,2])
    posicao[0,2].set_title("AveRooms")

    #Cria o histograma de AveBedrms na primeira posicao segunda linha (linha 1, coluna 0)
    sns.histplot(data=df, x='AveBedrms',kde=True, ax=posicao[1,0])
    posicao[1,0].set_title("AveBedrms")                                                 

    #Cria o histograma de Population na segunda posicao segunda linha (linha 1, coluna 1)
    sns.histplot(data=df, x='Population',kde=True, ax=posicao[1,1])
    posicao[1,1].set_title("Population")

    #Cria o histograma de AveOccup na ultima posica de todas (linha 1, coluna 2)
    sns.histplot(data=df, x='AveOccup',kde=True, ax=posicao[1,2])
    posicao[1,2].set_title("AveOccup")

    # Exibe o grafico
    plt.show()


if __name__ == "__main__":
    main()

