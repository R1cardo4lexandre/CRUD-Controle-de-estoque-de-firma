* Todos os arquivos fonte do projeto devem ficar na pasta src;
* Todos os arquivos de cabeçalho devem ficar na pasta include.

## Tabela 1: convenções para identificadores

| Identificando | Padrão | Exemplo |
| --- | --- | --- |
| Nomes de arquivos - não os de classe | em snake case (tudo em minúsculas, palavras separadas por sublinhas) | algum_arquivo.qualquerextensão |
| Nomes de arquivos de classe | Devem ter o mesmo nome da classe | AlgumaClasse.qualquerextensão |
| Header guarders | em screaming snake case (como snake case, mas tudo em maiúsculas) e terminando em  _H | ALGUM_CABECALHO_H |
| Tipos definidos | em pascal case (palavras juntas e somente a primeira letra de cada palavra deve ser maúscula) | AlgumTipo |
| Nomes de funções | em camel case (como pascal case, mas a primeira letra da primeira palavra é minúscula) | algumaFuncao |
| Tags para estruturas | O nome do tipo da estrutura em Pascal case, precedido por um “s” | sAlgumTipo |
| Nomes de campos | camel case |  |

# 1. Convenções de arquivos

- Todos os arquivos devem terminar com pelo menos uma linha vazia
- Grupos de entidades de código devem ser separados por separadores adequados
- Os **#include**s referentes a arquivos de cabeçalho devem aparecer agrupados:
    - Primeiro os cabeçalhos de usuário (que usam aspas), depois os de sistema (que usam <>)
        
        Isso é para diminuir a probabilidade de arquivos de cabeçalho não autossuficientes — ver 1.2 — passarem despercebidos
        
    - Os arquivos em cada grupo devem aparecer em ordem alfabética
    - Os grupos de arquivos de usuário devem aparecer em ordem alfabética
    - Deve haver pelo menos uma linha vazia entre o último grupo e a primeira linha de código depois dele
- Todo **#endif** deve ter ao seu lado um comentário com a condição que eles testam na forma /*  CONDIÇÃO  */;
- Dois nomes de arquivos não devem diferir somente pelos nomes;
- As definições nos arquivos fonte devem acompanhar a ordem das declarações nos arquivos de cabeçalho;
- Uma tabulação deve valer 8 espaços

## 1.1 Arquivos fonte

## 1.1.1 Arquivos com definições de funções

- O nome do arquivo e o nome da função devem ser o mesmo, só mudando o padrão;
- O primeiro arquivo de cabeçalho a ser incluído deve ser o da própria função;
- Imediatamente antes do cabeçalho da função deve haver um bloco de comentários no formato do Doxygen informando como a função funciona;

## 1.2 Arquivos de cabeçalho

- Deve conter somente declarações;
- As duas primeiras linhas devem ser o *header guarder*;
- A última linha não vazia dever ser o **#endif** do *header guarder*;
- Não devem ser incluídos arquivos desnecessários ao cabeçalho;
- Devem ser autossuficientes (se for o único incluído por um programa, o programa deve compilar sem erros);
- Se um tipo estrutura ou união será usado somente via ponteiro e foi definido com **typedef**, deve-se usar *forward-declaration* em vez de incluir o cabeçalho inteiro;
- *forward-declarations* devem acontecer antes de qualquer outra declaração;
- Declarações de tipos (estruturas, uniões, enumerações) devem ocorrer antes de declarações de variáveis
    
    Isso é para garantir que uma variável não será declarada sem o compilador conhecer seu tipo
    
- Declarações devem ser agrupadas tanto quanto possível: funções juntas, variáveis juntas, estruturas juntas, etc.

## 1.2.1 Arquivos com declarações de funções

- O nome do arquivo e o nome da função devem ser o mesmo, só mudando o padrão
- Devem conter todos os **#include**s necessários à declaração da função
- Imediatamente antes da declaração da função deve haver um bloco de comentários no formato do Doxygen informando o que a função faz

# 2. Convenções de struturas, uniões e enumerações

- As estruturas fundamentais para o código devem ser declaradas da seguinte maneira:
    
    ```c
    typedef tag_da_estrutura {
    	/* campos */
    } TipoDefinido;
    ```
    
    O uso da tag é para diminuir o tempo de preprocessamento
    
- A tag da estrutura e o tipo definido devem ter o mesmo nome, só mudando o padrão
- Estruturas que não são fundamentais ao código podem ser declaradas com **typedef** também, mas deve-se tomar cuidado pois isso polui o *namespace*

# 3. Convenções gerais de código

- Para inicializar ponteiros nulos, deve-se preferir `nullptr` ;
