# 🃏 Guia de Tarot — Programa em C

Um programa de terminal interativo em C que permite explorar os **Arcanos Maiores** do Tarot.  
Você pode listar os nomes das cartas, pesquisar significados simbólicos e ler a **Jornada do Louco**, tudo diretamente pelo console.

---

## 📘 Funcionalidades

O programa oferece um menu inicial com duas opções:

1. **Arcanos Maiores**  
   - **Nomes dos Arcanos** → Lista todas as cartas dos Arcanos Maiores.  
   - **Símbolos** → Permite pesquisar uma carta pelo nome e exibe seu simbolismo.  
   - **Jornada do Louco** → Exibe um texto completo sobre a trajetória arquetípica do Louco através das cartas.  

2. **Arcanos Menores**  
   - (Ainda não implementado — mensagem informativa exibida.)

---

## 🧠 Estrutura do Programa

______________________________________________________________________________________________________
| Função                | Descrição                                                                  |
|-----------------------|----------------------------------------------------------------------------|
| `abertura()`          | Exibe o título estilizado “GUIA DE TAROT”.                                 |
| `nomesMaior()`        | Lê e imprime o conteúdo do arquivo `nomes.txt`.                            |
| `simbolosMaior()`     | Lê `simbolos.txt`, busca o nome digitado e mostra o significado simbólico. |
| `jornada()`           | Exibe o conteúdo de `jornada.txt`, com a narrativa da Jornada do Louco.    |
| `maiores()`           | Menu de navegação para as funções dos Arcanos Maiores.                     |
| `menores()`           | Placeholder para os Arcanos Menores (a ser implementado).                  |
| `main()`              | Função principal que inicializa o programa e apresenta o menu inicial.     |
______________________________________________________________________________________________________

## 📁 Estrutura de Arquivos

O programa depende de **arquivos de texto** externos, que devem estar na **mesma pasta** do executável.

```
📂 guia-tarot/
├── guia_tarot.c
├── nomes.txt
├── simbolos.txt
└── jornada.txt
```

### Formato esperado dos arquivos:

#### `nomes.txt`
Lista simples dos 22 Arcanos Maiores, por exemplo:
```
0 - O Louco
1 - O Mago
2 - A Sacerdotisa
...
21 - O Mundo
```

#### `simbolos.txt`
Cada carta é separada por uma linha com `---`:

NOME: O Louco
SIMBOLISMO:
O Abismo: O salto de fé, o início de uma jornada.
O Cão: Instinto e lealdade.
--------------------------------------------------
NOME: O Mago
SIMBOLISMO:
A Mesa: Representa o domínio sobre os quatro elementos.
Os Objetos: Indicam as ferramentas da criação consciente.
```

#### `jornada.txt`
Texto corrido descrevendo a Jornada do Louco:
```
O Louco inicia sua jornada rumo ao autoconhecimento, passando por todos os arquétipos dos Arcanos Maiores...
```


## 💻 Compilação e Execução

### Compilar:
```bash
gcc guia_tarot.c -o guia_tarot
```

### Executar:
```bash
./guia_tarot
```


## 🧩 Exemplo de Uso

**Entrada:**
```
Você quer saber sobre:
(1) Arcanos Maiores
(2) Arcanos Menores
Escolha: 1

O que você quer saber sobre os arcanos maiores?
(1) Nomes dos arcanos
(2) Símbolos
(3) Jornada do Louco
Escolha: 2

Digite o nome do Arcano: O Mago
```

**Saída:**
```
Carta: O Mago
SIMBOLISMO:
A Mesa: Representa o domínio sobre os quatro elementos.
Os Objetos: Indicam as ferramentas da criação consciente.
```



## 🪶 Autor
**Giovanna Campos**  
💫 Projeto pessoal para estudo de linguagem C e simbologia do Tarot.  