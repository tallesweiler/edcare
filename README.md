# EDCare

## Introdução:
EDCare é um trabalho da disciplina de Estrutura de Dados I da Universidade Federal do Espírito Santo.
Todas as especificações do trabalho estão presentes no pdf, mas em resumo, seu objetivo é de construir um sistema de monitoramento de idosos, através de TADs e listas encadeadas.
Desenvolvido por: João Victor Morais e Talles Weiler

## Guia de utilização do programa:
O programa consiste em três pastas principais:
- <b>include/</b> -> possui os headers de todas as bibliotecas implementadas
- <b>src/</b> -> possui os arquivos-fonte de todas as bibliotecas implementadas e o arquivo principal (main.c)
- <b>Entrada/</b> -> possui os arquivos fornecidos pelo cliente

Toda a utilização do programa é feita através de um makefile, onde seus principais comandos são:
- <b>"make start r=x"</b> -> O valor 'x' representa o número de leituras que o programa irá realizar nos arquivos de entrada (ex: "make start r=15" efetua 15 leituras). Este comando considera que a pasta Entrada/ já existe e possui todos os arquivos necessários, então cria as pastas temporárias obj/ (onde ficam os arquivos-objeto), bin/ (onde fica o arquivo executável) e Saida/ (onde ficam os arquivos-saida). Após isso, compila o programa, roda e gera os arquivos-saida.
- <b>"make clean"</b> -> exclui todas os arquivos temporários, inclusive os arquivos-saida

## Funcionamento do programa:
Na construção do programa foram utilizados cinco TADs:
Todos os tipos possuem funções de alocar e liberar memória.
- Os tipos "Idoso" e "Cuidador" representam as estruturas mais básicas do programa. Suas funções se limitam a obter ou modificar suas variáveis.

- Os tipos "Lista_idoso" e "Lista_cuidador" representam estruturas de agrupamento dos tipos anteriores. Foram implementadas utilizando o conceito de lista duplamente encadeada e suas principais funções são de inserção, retirada e busca.

- O tipo "Apoio" é o único no qual o cliente tem acesso, ele é composto por duas listas (uma de cada tipo) que representam toda a equipe de apoio. Suas funções efetuam a leitura dos arquivos de entrada e a escrita dos arquivos de saída.

Primeiramente o programa preenche as duas listas através dos arquivos "apoio.txt" e "cuidadores.txt", depois são preenchidas as listas de amigos e de cuidadores de cada idoso. Após isso, são criados instantes que vão de zero até o número de leituras passado pelo cliente, cada instante atualiza as variáveis internas de cada idoso e cuidador e efetua uma verificação, além de escrever na saída de cada idoso o resultado desta verificação (os resultados possíveis estão detalhados no arquivo em pdf), o único resultado que afeta o restante da lista é o "falecimento", que remove o idoso da lista de amigo de cada idoso e por fim da lista do apoio. Por fim o programa libera toda a memória alocada.

Cada idoso e cuidador são alocados apenas uma vez (quando o programa preenche as duas listas), para preencher as listas de amigos e de cuidadores o programa realiza uma busca nessas duas listas e insere somente o ponteiro. Por isso as funções de retirada não liberam a memória alocada pelo tipo.

## Implementação do programa e conclusão:
Como forma de deixar mais claro o entendimento do programa, as variáveis e as funções possuem nomes significativos, mas mesmo assim cada função possui uma pequena explicação nos headers e ao longo de seu arquivo-fonte.

A maior dificuldade do projeto foi trabalhar com alocação dinâmica, e praticamente todos os problemas que surgiram foram provenientes disso. Porém, a utilização do comando valgrind auxiliou muito o desenvolvimento do trabalho.

## Bibliografia:
Para o desenvolvimento do projeto foram utilizados principalmente os materiais fornecidos pela professora Patricia Dockhorn, o livro "Introdução a Estrutura de Dados" de Waldermar Celes e o site "stackoverflow.com".




# edcare
