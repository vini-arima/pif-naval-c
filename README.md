# 🚢 Batalha Naval (C)

![Language](https://img.shields.io/badge/language-C-blue)
![Course](https://img.shields.io/badge/course-PIFSI%202025.2-orange)
![Status](https://img.shields.io/badge/status-completed-brightgreen)

> Projeto da disciplina **Programação de Inovação e Fundamentos de Sistemas de Informação** (PIFSI 2025.2) da **CESAR School**.

## 📋 Sobre o Projeto

Este projeto consiste na implementação do clássico jogo **Batalha Naval** (Battleship) via interface de linha de comando (CLI).

O objetivo pedagógico foi consolidar os fundamentos da programação estruturada em C, com ênfase estrita em:
* **Alocação Dinâmica de Memória** (`malloc`, `calloc`, `realloc`, `free`).
* **Estruturas de Dados** (`structs`, `enums`).
* **Ponteiros** e manipulação de endereços.
* **Modularização** e design de código sem o uso de bibliotecas externas.

---

## 👥 Equipe

| Aluno | Email | Responsabilidades (Módulos) |
| :--- | :--- | :--- |
| **Gabriel Tenório** | gtlt@cesar.school | • **IO** (Interface/Menus)<br>• **RND** (Aleatoriedade)<br>• **Docs** (Documentação) |
| **Vinícius Cardoso** | vca4@cesar.school | • **Game** (Lógica/Turnos)<br>• **Board** (Matriz Dinâmica)<br>• **Fleet** (Navios)<br>• **Main** & **Makefile** |

---

## 🛠️ Tecnologias

* **Linguagem:** C (Standard C99)
* **Build System:** GNU Make
* **Bibliotecas:** Apenas bibliotecas padrão (`stdio.h`, `stdlib.h`, `string.h`, `time.h`, `ctype.h`, `stdbool.h`).

---

## 🚀 Instalação e Execução

Certifique-se de ter o compilador `gcc` e o utilitário `make` instalados em seu ambiente.

### 1. Clonar e Compilar

```bash
# Clone o repositório
git clone <URL_DO_SEU_REPOSITORIO>

# Entre na pasta
cd batalha_naval

# Compile o projeto usando o Makefile
make
```

### 2. Executar

```bash
./batalha_naval
```

### 3. Limpar (Opcional)

Para remover os arquivos objetos (`.o`) e o executável gerado:

```bash
make clean
```

---

## 🎮 Como Jogar

O jogo segue as regras clássicas de batalha naval, adaptadas para o terminal.

1.  **Configuração Inicial:**
    * Selecione **"Novo Jogo"**.
    * Insira os **apelidos** dos dois jogadores.
    * Defina o **tamanho do tabuleiro** (mínimo 6x6, máximo 26x26).

2.  **Posicionamento da Frota:**
    * Cada jogador deve posicionar seus navios.
    * **Modo Manual:** O jogador digita a coordenada e orientação (Horizontal/Vertical).
    * **Modo Automático:** O computador distribui os navios aleatoriamente.

3.  **O Combate:**
    * Os jogadores alternam turnos tentando acertar os navios inimigos.
    * Digite a coordenada do tiro (ex: `A5`, `B10`).
    * O feedback é imediato: **ÁGUA 🌊**, **ACERTOU 💥** ou **AFUNDOU ☠️**.

4.  **Vitória:**
    * Vence quem afundar **todos** os navios da frota adversária primeiro.

### ⚓ A Frota (Por Jogador)

| Qtd | Navio | Tamanho |
| :---: | :--- | :---: |
| 1 | **Porta-aviões** | 5 células |
| 1 | **Encouraçado** | 4 células |
| 2 | **Cruzadores** | 3 células |
| 2 | **Destroyers** | 2 células |

---

## 🏗️ Estrutura do Projeto

A arquitetura foi pensada para separar a interface do usuário da lógica de negócios e gerenciamento de memória.

```text
.
├── Makefile          # Script de automação de compilação
├── README.md         # Documentação do projeto
├── src
│   ├── main.c        # Ponto de entrada (Entry point)
│   ├── game.c/h      # Controle de fluxo, turnos e regras de vitória
│   ├── board.c/h     # Gerenciamento da matriz e validação de limites
│   ├── fleet.c/h     # Definição de navios e frota
│   ├── io.c/h        # Entrada/Saída (printf/scanf centralizados)
│   └── rnd.c/h       # Gerador de números aleatórios (Wrapper)
```

---

**Professor:** João Victor Tinoco  
**Instituição:** CESAR School
