# playground

Código escrito ao vivo durante as lives de estudo de C++, uma pasta por live.

## Por quê

Estudar uma linguagem só lendo deixa a dúvida escondida: o código parece certo até o compilador discordar. Aqui o estudo é feito do zero, em lives solo (Twitch e YouTube), e cada live termina com um programa completo compilado e executado diante de quem assiste. O código fica neste repositório para ser relido e refeito depois, sem depender de gravação.

## Status

Em andamento. A primeira trilha tem 6 lives de C++ (semana 1). Os roteiros e as notas de estudo ficam fora deste repositório; aqui só entra o código.

## Próximas lives

Cada live dura cerca de 3 horas, com um intervalo, e termina com um programa executado ao vivo. Todas começam às 08h00 e terminam às 11h00 (horário de Brasília).

| Data | Dia | Live | Programa final |
|---|---|---|---|
| 09/11 | segunda | 01: instalação e primeiros passos | Conversor de temperatura |
| 10/11 | terça | 02: controle de fluxo, funções e vetores | Adivinhe o número |
| 11/11 | quarta | 03: referências, ponteiros e `const` | Estatísticas de uma lista de números |
| 12/11 | quinta | 04: structs, classes e agenda de contatos | Agenda de contatos (em memória) |
| 13/11 | sexta | 05: memória, RAII e `unique_ptr` | `IntVec`, um vetor de inteiros |
| 14/11 | sábado | 06: arquivos e agenda persistente | Agenda persistente em arquivo |

## Estrutura

```
cpp/live-NN/   código da live NN (a pasta é criada quando a live começa)
```

## Instalação

Só é preciso o `g++` com suporte a C++20 (os exemplos foram verificados com g++ 16). Confira com `g++ --version`.

## Uso

Compile e execute a pasta de uma live:

```bash
cd cpp/live-01
g++ -std=c++20 -Wall -Wextra -o main main.cpp && ./main
```

Para as lives sobre memória (ponteiros, RAII, `unique_ptr`), acrescente `-fsanitize=address` ao comando.

Os avisos do `-Wall -Wextra` fazem parte do estudo: leia cada um antes de ignorar.

## Segurança

Os programas rodam só na máquina local: não abrem portas, não usam a rede e não guardam credenciais. Algumas lives leem e gravam arquivos locais (por exemplo, uma agenda em CSV), sempre no diretório de onde o programa é executado.

## Licença

Ainda não definida: o repositório não tem arquivo `LICENSE`.
