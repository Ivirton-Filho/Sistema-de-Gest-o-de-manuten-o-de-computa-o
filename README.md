# Sistema de Gestão de Manutenção de Computação

Este é um projeto acadêmico desenvolvido em linguagem C para gerenciar uma oficina de manutenção de computadores. O sistema permite cadastrar consertos, atualizar o status dos reparos e gerenciar o estoque de peças.

## Funcionalidades

- **Cadastro de Conserto**: Permite registrar novos clientes, equipamentos e problemas, iniciando o status como "Em análise".
- **Atualização de Status**: Atualiza o progresso de um conserto específico.
- **Gerenciamento de Estoque**: Adiciona e visualiza peças no estoque, com ID, nome e quantidade.
- **Persistência de Dados**: Salva os consertos e peças em arquivos de texto (`consertos.txt`).

## Instalação

1. Clone o repositório: `git clone https://github.com/usuario/sistema-gestao-manutencao.git` (substitua pelo link real se aplicável).
2. Certifique-se de ter um compilador C instalado (ex.: GCC no Linux/Mac ou MinGW no Windows).
3. Navegue até a pasta do projeto e compile: `gcc main.c -o gestao_oficina`.

## Como Executar

1. Execute o programa: `./gestao_oficina` (ou `gestao_oficina.exe` no Windows).
2. Navegue pelo menu interativo para usar as funcionalidades.

## Exemplos de Uso

- **Cadastro**: Selecione opção 1, insira nome do cliente, equipamento e problema.
- **Status**: Selecione opção 2, escolha o número do conserto e atualize o progresso.
- **Estoque**: Selecione opção 3 para visualizar ou adicionar peças.

## Estrutura do Código

- `main.c`: Arquivo principal com as funções de menu, cadastro, status e estoque.
- `consertos.txt`: Arquivo de saída para salvar os dados dos consertos e peças.

## Importante

- Os dados são salvos em arquivos de texto locais; certifique-se de que o programa tenha permissões para escrever no diretório.
- Limitações: Máximo de 10 consertos e 10 peças. O projeto é para fins educacionais e pode conter bugs.



Este projeto foi desenvolvido como parte de uma atividade acadêmica para demonstrar conceitos de programação em C, structs, arquivos e controle de fluxo.
