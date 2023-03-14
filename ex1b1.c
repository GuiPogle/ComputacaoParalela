# Define o tamanho da matriz
n = 3

# Cria uma matriz vazia
matrix = []

# Preenche a matriz com os dados de entrada
for i in range(n):
    row = input().split()
    row = [int(x) for x in row]
    matrix.append(row)

# Encontra o menor número e sua linha correspondente
min_num = float('inf')
min_row = 0
for i in range(n):
    for j in range(n):
        if matrix[i][j] < min_num:
            min_num = matrix[i][j]
            min_row = i+1

# Imprime o número da linha com o menor número
print("A linha com o menor número é: ", min_row)
