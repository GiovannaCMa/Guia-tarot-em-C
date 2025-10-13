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


| Função              | Descrição                                                                   |
|---------------------|-----------------------------------------------------------------------------|
| `abertura()`        | Exibe o título estilizado “GUIA DE TAROT”.                                  |
| `nomesMaior()`      | Lê e imprime o conteúdo do arquivo `nomes.txt`.                             |
| `simbolosMaior()`   | Lê `simbolos.txt`, busca o nome digitado e mostra o significado simbólico.  |
| `jornada()`         | Exibe o conteúdo de `jornada.txt`, com a narrativa da Jornada do Louco.     |
| `maiores()`         | Menu de navegação para as funções dos Arcanos Maiores.                      |
| `menores()`         | Placeholder para os Arcanos Menores (a ser implementado).                   |
| `main()`            | Função principal que inicializa o programa e apresenta o menu inicial.      |


---

## 📁 Estrutura de Arquivos

O programa depende de **arquivos de texto** externos, que devem estar na **mesma pasta** do executável.

```
📂 Guia-tarot-C/
├── tarot.c
├── nomes.txt
├── simbolos.txt
└── jornada.txt
```

### Formato esperado dos arquivos:

#### `nomes.txt`
Lista simples dos 22 Arcanos Maiores, por exemplo:
```
0 - O Louco
I - O Mago
II - A Sacerdotisa
...
XXI - O Mundo
```

#### `simbolos.txt`
Cada carta tem o seu significado, por exemplo:

```
NOME: O Louco
N°: 0

SIMBOLISMO:
O Abismo/Precipício: O desconhecido, o salto de fé, o perigo (ou oportunidade) que Louco não está vendo porque está olhando para cima.
A Trouxa na Varinha: Contém todas as experiências das vidas passadas ou o mínimo essencial (o que ele realmente precisa, não o que ele pensa que precisa).
A Rosa Branca: Inocência, pureza de intenção.
O Cão Branco: O instinto, o subconsciente, ou um amigo fiel que está latindo avisando do perigo (a voz da prudência que ele ignora).

REPRESENTA: O Ponto Zero. O potencial bruto, a Vontade Pura de começar, sem medo.
```

#### `jornada.txt`
Texto corrido descrevendo a Jornada do Louco:
```
No princípio, havia apenas silêncio. Então algo despertou — uma consciência tênue, curiosa, sem forma...
```

---

## 💻 Compilação e Execução

### Compilar:
```bash
gcc tarot.c -o tarot.out
```

### Executar:
```bash
./tarot.out
```

---

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
NOME: O Louco
N°: 0

SIMBOLISMO:
O Abismo/Precipício: O desconhecido, o salto de fé, o perigo (ou oportunidade) que Louco não está vendo porque está olhando para cima.
A Trouxa na Varinha: Contém todas as experiências das vidas passadas ou o mínimo essencial (o que ele realmente precisa, não o que ele pensa que precisa).
A Rosa Branca: Inocência, pureza de intenção.
O Cão Branco: O instinto, o subconsciente, ou um amigo fiel que está latindo avisando do perigo (a voz da prudência que ele ignora).

REPRESENTA: O Ponto Zero. O potencial bruto, a Vontade Pura de começar, sem medo.
```

---

## 🪶 Autor
**Giovanna Campos Marchesin**  
💫 Projeto pessoal para estudo de linguagem C e simbologia do Tarot.    
