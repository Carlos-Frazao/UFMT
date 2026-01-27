from sklearn.datasets import fetch_california_housing #Biblioteca 
import pandas as pd #Biblioteca panda
import seaborn as sns  #Biblioteca seaborn, ela faz o grafico
import matplotlib.pyplot as plt #Biblioteca matplotlib, ela serve para o seaborn funcionar e com ela podemos manipular mais informacoes do grafico

def main():

    # -------------------- Recebimento dos dados com o Pandas -------------------- #
    
    #Pegamos todos os que importamos e armazenamos nessa variavel
    dados_casa_california = fetch_california_housing() 

    #Cria o data frame com o panda
    df = pd.DataFrame(dados_casa_california.data, columns=dados_casa_california.feature_names)
    
    #Cria um grafico com as informacoes do df, no eixo "X" ele ira representar os dados de longitude, no "Y" os dados da latitude. "alpha" é a opacidade e "s" é o tamanho
    sns.scatterplot(data=df, x="Longitude", y="Latitude", alpha=0.5, s=15)

    #Exibe o grafico na tela
    plt.show()

if __name__ == "__main__":
    main()

