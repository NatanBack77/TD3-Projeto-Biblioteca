# Sistema de Gerenciamento de Empréstimo de Livros

Este projeto implementa um sistema para gerenciar o empréstimo, devolução e renovação de livros em uma biblioteca, incluindo controle de prazos e aplicação de multas por atraso.

## Funcionalidades

- **Alugar Livros**
  - Permite ao usuário realizar o empréstimo de livros.
- **Devolução de Livros**
  - Usuário devolve livros emprestados.
  - O sistema solicita a quantidade de dias que o livro ficou locado.
- **Renovar Livros**
  - Possibilita ao usuário renovar o prazo de devolução, adicionando mais dias ao empréstimo.
- **Controle de Prazo**
  - Ao devolver um livro, o usuário informa quantos dias ficou com o livro.
  - Caso ultrapasse o prazo, o sistema calcula e informa o valor da multa com base nos dias em atraso.

## Fluxo do Sistema

1. **Aluguel**
   - Usuário seleciona o livro e realiza o empréstimo.
2. **Renovação**
   - Usuário pode solicitar a renovação, aumentando o prazo de devolução.
3. **Devolução**
   - Usuário devolve o livro e informa o tempo de posse.
   - Se houver atraso, o sistema calcula a multa e informa o valor a ser pago.

## Regras de Negócio

- O prazo de devolução pode ser renovado.
- O valor da multa é proporcional à quantidade de dias em atraso.
- O usuário é informado do valor da multa no momento da devolução, caso haja atraso.

---

> **Diagrama de requisitos**  
> - Alugar Livros → Renovar Livros → Adicionar mais dias para devolução  
> - Devolução Livros → Informar quantidade de dias locado → Se ultrapassar prazo, gerar multa e informar valor ao usuário

---

## Como executar

1. Compile o projeto usando o `makefile` fornecido.
2. Execute o binário gerado para interagir com o sistema via terminal.

---

Desenvolvido para fins acadêmicos.