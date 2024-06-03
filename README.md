
## Introdução

Este projeto surgiu da necessidade de aprimorar a segurança na comunicação entre computadores. Para abordar este problema, foi utilizado o conceito de fila, uma estrutura de dados que permite um tratamento eficiente das informações.

O desenvolvimento foi realizado em C++ devido à sua capacidade de criar códigos limpos, modularizados e organizados. O ambiente de desenvolvimento utilizado foi o Visual Studio 2019 no sistema operacional Windows 10.

## Instruções de Compilação e Execução

Para compilar o programa, siga os passos abaixo:

1. Abra o terminal na pasta `tp`.
2. Digite `make` e pressione Enter para compilar o programa.
3. Após a compilação, navegue até a pasta `bin`.
4. Execute o arquivo `run.out`.
5. No terminal aberto pelo executável, insira o caminho do arquivo de entrada.

## Implementação

Para resolver o problema proposto, foram criadas duas classes principais: `Node` (Nodo da fila) e `Queue` (Fila de nodos).

### Classe Node

A classe `Node` possui as seguintes funções:

- `Node()`: Construtor da classe, pode utilizar dados padrão ou especificados na chamada.
- `getContent()`: Retorna o conteúdo do nodo atual.
- `getNext()`: Retorna o próximo nodo.
- `setNext(Node* next)`: Define o próximo nodo na fila.
- `edit(ContentType content)`: Edita o conteúdo do nodo atual.
- `hasNext()`: Verifica se existe um nodo subsequente.
- `connections()`: Verifica quantos nodos existem após o atual.
- `isEmpty()`: Verifica se o nodo possui algum dado ou está vazio.

### Classe Queue

A classe `Queue` possui as seguintes funções:

- `Queue()`: Construtor da classe, pode utilizar dados padrão ou especificados na chamada.
- `getNode()`: Retorna o primeiro nodo da fila.
- `push(Node* newNode)`: Adiciona um novo nodo à fila, respeitando a política FIFO (First In, First Out).
- `pop()`: Remove o primeiro nodo da fila.
- `setOnTop(Node* node)`: Coloca o nodo especificado na primeira posição da fila.
- `print()`: Imprime na tela todos os elementos da fila, na ordem em que foram adicionados.

## Conclusão

O resultado é um sistema que atende às especificações e cumpre o objetivo proposto. Não foram desenvolvidas lógicas adicionais além do escopo inicial, como tratamento de erros de entrada.

## Referências

1. Material de aula (PDF e vídeos)
2. [Stack Overflow](https://stackoverflow.com)
3. [cplusplus.com](https://www.cplusplus.com)
4. [TutorialsPoint](https://www.tutorialspoint.com)
5. [cppreference.com](https://en.cppreference.com)
6. [GeeksforGeeks](https://www.geeksforgeeks.org)
7. [Wikipedia](https://en.wikipedia.org)
8. [LearnCpp](https://www.learncpp.com)
