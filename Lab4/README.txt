Universidade Presbiteriana Mackenzie 
FCI - Ciência da Computação
Computação Paralela 

Alunos:
- Guilherme de Souza Valente | TIA: 32034008
- Guilherme Guimarães Chiarelli | TIA: 32036647
- Laura C. Balbachan dos Santos | TIA: 32173008
_____________________________________________________________

Lab 4 - Pthreads (p. 1)

O arquivo "serial1.c" e "serial2.c" é o código serializado e o "thread1.c" e "thread2.c" é o código com threads.
De acordo com os testes realizados, os códigos serializados tiveram um tempo de execução de 0.001 segundos e os com threads 0.001 segundos.
Além disso, o speedup corresponde a ...
S = T(1)/T(P), onde 'S' é o Speedup e P é o tempo para n processadores.

O Speedup do programa rodando em serial é igual a T(1)/T(0,001) = 1000

O Speedup do programa rodando em threads é igual a T(1)/T(0,001) = 1000

Ou seja, o Speedup do programa em ambos os tipos de processamento possui tempos muito parecidos entre si.

Os exercícios foram desenvolvidos na plataforma AWS.
