import pandas as pd #Importa a biblioteca pandas
import sklearn #Importa sklearn
from sklearn.datasets import fetch_california_housing #Importa os dados que vamos trabalhar do sklearn

def main():

    # -------------------- Recebimento dos dados com o Pandas -------------------- #
    
     #Especifico que os dados importados agora estão na variavel casa_california
    casa_california = fetch_california_housing()

    #Uma matriz, pega os valores de casa_california. Pega todas as linhas, e cria 10 colunas para cada linha
    X = casa_california.data[:, 0:9]

    #Aqui especificamos as informações que estarão impressas na primeira coluna, no caso as informacoes de cada casa
    casa_informacao = ['MedInc','HousAge','AveRooms','AveBedrms','Population','AveOccup','Latitude','Longitude']

    #Criamos o DataFrame usando o panda, e especificamos que na primeira coluna deve ser preenchido com a nossa matriz casa_informacao
    df = pd.DataFrame(X, columns=casa_informacao)

    #Imprimimos as principais métricas e estatisticas
    print(df.describe())

if __name__ == "__main__":
    main()