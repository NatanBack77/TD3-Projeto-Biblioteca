# Sistema de Biblioteca em C

<img src="image/diagrama.png" alt="Diagrama do Sistema" width="600"/>

Um sistema simples e didático para gerenciamento de biblioteca, feito em C, sem uso de arrays ou ponteiros para os livros. Cada livro é representado por variáveis separadas, facilitando o entendimento do fluxo e da lógica.

## 🚀 Funcionalidades

- **Adicionar livro**: Cadastro de até 5 livros, com verificação automática de duplicidade de título.
- **Listar livros**: Visualize rapidamente todos os livros cadastrados.
- **Alugar livro**: Alugue um livro se ele estiver disponível e o usuário não possuir multas. Caso o livro já esteja locado, o sistema informa o nome do locador e os dias restantes.
- **Devolver livro**: Devolva um livro. Se houver atraso, o sistema gera uma multa para o locador.
- **Renovar livro**: Renove o prazo de devolução de um livro locado.
- **Pagar multa**: Veja e quite multas pendentes de todos os locadores.
- **Consulta rápida**: Ao tentar alugar, se o livro estiver locado, o sistema mostra o nome do locador e os dias restantes.

## 📋 Regras de Negócio

- Não é possível cadastrar dois livros com o mesmo título.
- Não é possível alugar um livro se o usuário estiver multado em qualquer livro.
- Não é possível alugar um livro já locado (o sistema mostra o locador e dias restantes).
- Multas são geradas por atraso na devolução e devem ser pagas antes de novo aluguel.

## 🛠️ Como compilar e executar

```sh
gcc -Wall -g main.c -o main
./main
```

## 💡 Observações

- O sistema **não utiliza arrays ou ponteiros** para armazenar os livros, apenas variáveis separadas para cada livro.
- O controle de multas e locações é feito por variáveis separadas para cada livro.
- O menu principal permite acessar todas as funções do sistema de forma intuitiva.
- O projeto é ideal para estudos de lógica, controle de fluxo e manipulação de strings em C.

---

Atualizado em: 30/05/2025