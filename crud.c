/* Importação de Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CONSTANTES */
#define TAM_INICIAL_VETOR 50
#define TAM_PADRAO_STRING 51

/* Struct que representa um produto */
typedef struct produto {
  char nome[TAM_PADRAO_STRING];
  char tipo[TAM_PADRAO_STRING];
  char codigo[TAM_PADRAO_STRING];
  int quantidade;
  float preco;
  int ativo;
} t_produto;

/* Declarando as funções de impressão */

void cabecalho() {

    printf("          -=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("            BEM VINDO AO MINERVA\n");
    printf("          -=-=-=-=-=-=-=-=-=-=-=-\n");

}

void menuInicial() {
    printf("\n                MENU INICIAL             ");
    printf("\nEscolha a operacao desejada conforme o numero:\n");
    printf("            [ 1 ] --------- CADASTRO\n");
    printf("            [ 2 ] --------- EXIBIR\n");
    printf("            [ 3 ] --------- ALTERAR\n");
    printf("            [ 4 ] --------- EXCLUIR\n");
    printf("            [-1 ] --------- SAIR\n");
}

void menuExibir() {

    printf("\n                ABA DE EXIBICAO             ");
    printf("\nEscolha a operacao desejada conforme o numero:\n");
    printf("            [ 1 ] --------- EXIBIR TODOS\n");
    printf("            [ 2 ] --------- EXIBIR UM\n");
    printf("            [ 3 ] --------- VOLTAR PARA A ABA ANTERIOR\n");
}

void menuExibirParametro() {
    printf("\n                ABA DE PARAMETROS             ");
    printf("\nEscolha a operacao desejada conforme o numero:\n");
    printf("            [ 1 ] --------- PESQUISA POR NOME\n");
    printf("            [ 2 ] --------- PESQUISA POR CODIGO\n");
    printf("            [ 3 ] --------- PESQUISA POR TIPO\n");
    printf("            [ 4 ] --------- VOLTAR PARA A ABA ANTERIOR\n");
}

void menuAlterar() {

    printf("\n                ABA DE PESQUISA              ");
    printf("\nEscolha a operacao desejada conforme o numero:\n");
    printf("            [ 1 ] --------- ALTERAR TODOS OS CAMPOS\n");
    printf("            [ 2 ] --------- ALTERAR UM CAMPO\n");
    printf("            [ 3 ] --------- VOLTAR PARA A ABA ANTERIOR\n");
}

void menuAlterarProduto() {
    printf("\n                ABA DE ALTERACAO CLIENTE             ");
    printf("\nEscolha a operaçao desejada conforme o numero:\n");
    printf("            [ 1 ] --------- NOME\n");
    printf("            [ 2 ] --------- CODIGO\n");
    printf("            [ 3 ] --------- TIPO\n");
    printf("            [ 4 ] --------- QUANTIDADE\n");
    printf("            [ 5 ] --------- PRECO\n");
    printf("            [ 6 ] --------- VOLTAR PARA A ABA ANTERIOR\n");
}

void relatorioGeral(t_produto *produto, int maxPro) {

    int counter = 0;
    int qtd = 0;

    for(int i = 0; i < maxPro; i++) {
        if(produto[i].ativo == 1) {
            counter++;
            qtd += produto[i].quantidade;
        }
    }

    printf("\n                  RELATORIO GERAL\n\n");
    printf("\nNumero de produtos unicos cadastrados no sistema: %d\n", counter);
    printf("Soma total de unidades cadastradas no sistema: %d\n", qtd);
}

/* Funcoes para tratamento de operacoes */
int cadastraProdutos(t_produto *produto, int tam, int quantidade) {
  
  for (int i = 0; i < quantidade; i++) {

    printf("\n\n                Operacao %d", i+1);

    printf("\nNome do Produto: ");
    scanf(" %50[^\n]s", produto[tam].nome);
    getchar();

    printf("\nCodigo do Produto: ");
    scanf(" %50[^\n]s", produto[tam].codigo);
    getchar();

    printf("\nTipo do Produto: ");
    scanf(" %50[^\n]s", produto[tam].tipo);
    getchar();

    printf("\nQuantidade do Produto: ");
    scanf("%d", &produto[tam].quantidade);
    getchar();

    printf("\nValor do Produto: R$");
    scanf("%f", &produto[tam].preco);
    getchar();

    produto[tam].ativo = 1;

    tam++;
    if(tam % TAM_INICIAL_VETOR == 0) {
      t_produto *temp_produto = (t_produto *) realloc(produto, (tam + TAM_INICIAL_VETOR) * sizeof(t_produto));
      if (temp_produto == NULL) {
        printf("PROBLEMA NA OPERACAO. Abortando...");
        free(produto);
        exit(1);
      } else {
        produto = temp_produto;
      }
    }

  }

  return tam;
}

void exibirProdutosTodos(t_produto *produto, int tam) {

  printf("        LISTAGEM GERAL\n\n");
  for (int i = 0; i < tam; i++) {
    if (produto[i].ativo) {
      printf("\nNome: %s", produto[i].nome);
      printf("\nCodigo: %s", produto[i].codigo);
      printf("\nTipo: %s", produto[i].tipo);
      printf("\nQuantidade: %d", produto[i].quantidade);
      printf("\nValor: R$%.2f\n", produto[i].preco);
    }
  }
}

void exibirProdutosParametros(t_produto *produto, int tam) {

  int operacao;
  char pesquisa[TAM_PADRAO_STRING];

  while (1) {

    menuExibirParametro();

    // Escolhe a operação
    scanf("%d", &operacao);
    getchar();

    if (operacao == 1) {

      printf("        PESQUISA\n\n");
      printf("Digite o NOME do Produto: ");

      scanf(" %50[^\n]s", pesquisa);
      getchar();

      for (int i = 0; i < tam; i++) {
        if (strstr(produto[i].nome, pesquisa) && produto[i].ativo) {
          printf("\nNome: %s", produto[i].nome);
          printf("\nCodigo: %s", produto[i].codigo);
          printf("\nTipo: %s", produto[i].tipo);
          printf("\nQuantidade: %d", produto[i].quantidade);
          printf("\nValor: R$%.2f\n", produto[i].preco);
        }
      }
      break;

    } else if (operacao == 2) {

      printf("        PESQUISA\n\n");
      printf("Digite o CODIGO do Produto: ");

      scanf(" %50[^\n]s", pesquisa);
      getchar();

      for (int i = 0; i < tam; i++) {
        if (strstr(produto[i].codigo, pesquisa) && produto[i].ativo) {
          printf("\nNome: %s", produto[i].nome);
          printf("\nCodigo: %s", produto[i].codigo);
          printf("\nTipo: %s", produto[i].tipo);
          printf("\nQuantidade: %d", produto[i].quantidade);
          printf("\nValor: R$%.2f\n", produto[i].preco);
        }
      }
      break;

    } else if (operacao == 3) {

      printf("        PESQUISA\n\n");
      printf("Digite o TIPO do Produto: ");

      scanf(" %50[^\n]s", pesquisa);
      getchar();

      for (int i = 0; i < tam; i++) {
        if (strstr(produto[i].tipo, pesquisa) && produto[i].ativo) {
          printf("\nNome: %s", produto[i].nome);
          printf("\nCodigo: %s", produto[i].codigo);
          printf("\nTipo: %s", produto[i].tipo);
          printf("\nQuantidade: %d", produto[i].quantidade);
          printf("\nValor: R$%.2f\n", produto[i].preco);
        }
      }
      break;

    } else if (operacao == 4) {
      system("CLS");
      break;

    } else {
      system("CLS");
      printf("Operacao Invalida. Por favor, escolha novamente.");
      continue;

    }
  }
}

int pesquisaProdutos(t_produto *produto, int *indexArray, int tam) {

  int operacao, j = 0;
  char pesquisa[TAM_PADRAO_STRING];

  while (1) {

    menuExibirParametro();

    // Escolhe a operação
    scanf("%d", &operacao);
    getchar();

    if (operacao == 1) {

      printf("        PESQUISA\n\n");
      printf("Digite o NOME do Produto: ");

      scanf(" %50[^\n]s", pesquisa);
      getchar();

      for (int i = 0; i < tam; i++) {
        if (strstr(produto[i].nome, pesquisa) && produto[i].ativo) {
          indexArray[j] = i;
          j++;
        }
      }
      break;

    } else if (operacao == 2) {

      printf("        PESQUISA\n\n");
      printf("Digite o CODIGO do Produto: ");

      scanf(" %50[^\n]s", pesquisa);
      getchar();

      for (int i = 0; i < tam; i++) {
        if (strstr(produto[i].codigo, pesquisa) && produto[i].ativo) {
          indexArray[j] = i;
          j++;
        }
      }
      break;

    } else if (operacao == 3) {

      printf("        PESQUISA\n\n");
      printf("Digite o TIPO do Produto: ");

      scanf(" %50[^\n]s", pesquisa);
      getchar();

      for (int i = 0; i < tam; i++) {
        if (strstr(produto[i].tipo, pesquisa) && produto[i].ativo) {
          indexArray[j] = i;
          j++;
        }
      }
      break;

    } else if (operacao == 4) {
      system("CLS");
      break;

    } else {
      system("CLS");
      printf("Operacao Invalida. Por favor, escolha novamente.");
      continue;

    }
  }
  return j;
}

void resultadoPesquisaProdutos(t_produto *produto, int *indexArray, int tamInd) {

  for (int i = 0; i < tamInd; i++) {
    printf("\nResultado %d", i+1);
    printf("\n\nNome: %s", produto[indexArray[i]].nome);
    printf("\nCodigo: %s", produto[indexArray[i]].codigo);
    printf("\nTipo: %s", produto[indexArray[i]].tipo);
    printf("\nQuantidade: %d", produto[indexArray[i]].quantidade);
    printf("\nValor: R$%.2f\n", produto[indexArray[i]].preco);   
  }
  
}

void salvaProdutosArquivo(t_produto *produto, int tam) {

    int i;

    FILE* fp = fopen("produtos.txt", "w");

    if (fp == 0)
        printf("Erro ao salvar o arquivo.\n");
    else {
        for (i = 0; i < tam; i++) {
            fprintf(fp, "%s\n", produto[i].nome);
            fprintf(fp, "%s\n", produto[i].codigo);
            fprintf(fp, "%s\n", produto[i].tipo);
            fprintf(fp, "%d\n", produto[i].quantidade);
            fprintf(fp, "%f\n", produto[i].preco);
            fprintf(fp, "%d\n", produto[i].ativo);
        }
        printf("\nDados salvos com sucesso!");
    }
    fclose(fp);
}

int carregaProdutosArquivo(t_produto *produto) {

    int i;

    FILE * fp = fopen("produtos.txt", "r");
    if(fp == NULL) {
      fclose(fp);
      return 0;
    } else {
      for (i = 0; feof(fp) == 0; i++) {

        fscanf(fp, " %50[^\n]s", produto[i].nome);
        fgetc(fp);
        fscanf(fp, " %50[^\n]s", produto[i].codigo);
        fgetc(fp);
        fscanf(fp, " %50[^\n]s", produto[i].tipo);
        fgetc(fp);
        fscanf(fp, "%d", &produto[i].quantidade);
        fscanf(fp, "%f", &produto[i].preco);
        fgetc(fp);
        fscanf(fp, "%d", &produto[i].ativo);
        fgetc(fp);

        if(i+1 % TAM_INICIAL_VETOR == 0) {
          t_produto *temp_produto = (t_produto *) realloc(produto, (i+1 + TAM_INICIAL_VETOR) * sizeof(t_produto));
          if (temp_produto == NULL) {
            printf("PROBLEMA NA OPERACAO. Abortando...");
            free(produto);
            exit(1);
          } else {
            produto = temp_produto;
          }
        }
      }
      fclose(fp);
      return (i);
    }
}

/* Função Main */
int main() {
  
  // Declaração de Variáveis
  int operacao, quantidade;

  t_produto *produto;
  produto = (t_produto *) malloc(TAM_INICIAL_VETOR * sizeof(t_produto));
  if (!produto) {
    printf("Erro ao alocar memoria\n");
    return 1;
  }

  int total_produtos = carregaProdutosArquivo(produto);

  // Mostra o cabeçalho
  cabecalho();

  // Roda o sistema até o usuário requisitar a saída
  while (1) {

    // Imprime o menu inicial
    menuInicial();

    // Escolhe a operação
    scanf("%d", &operacao);
    getchar();

    // Processa Operação de Cadastro
    if (operacao == 1) {

      printf("\n\nDigite a quantidade de operacoes que deseja fazer: ");
      scanf("%d", &quantidade);

      total_produtos = cadastraProdutos(produto, total_produtos, quantidade);

      printf("\n\nAperte ENTER para continuar: ");
      getchar();
    }

    // Processa Operacao de Exibicao
    else if (operacao == 2) {

      while (1) {
        // Menu de Listagenm
        menuExibir();

        // Escolhe Operacao
        scanf("%d", &operacao);
        getchar();

        // Exibe Todos
        if(operacao == 1) {

          system("CLS");

          exibirProdutosTodos(produto, total_produtos);
          break;

        } else if(operacao == 2) {

          system("CLS");

          exibirProdutosParametros(produto, total_produtos);
          break;
        }

        else if(operacao == 3) { //VOLTAR AO INICIO
            system("CLS");
            break;
        }
        else { //OPERACAO INVALIDA
            system("CLS");
            printf("Operacao Invalida. Por favor, escolha novamente.");
            continue;
        }
      }
      
      printf("\n\nAperte ENTER para continuar: ");
      getchar();

      system("CLS");
    }

    // Processa operacao de alteracao
    else if (operacao == 3) {
      
      int achados[total_produtos];
      int erro = 0;
      int k;


      while (1) {
        
        int tamAchados = pesquisaProdutos(produto, achados, total_produtos);
        if (tamAchados == 0) {
          printf("\nResultado nao encontrado.");
          erro = 1;
        } else {
          resultadoPesquisaProdutos(produto, achados, tamAchados);
          printf("\nDigite o numero do resultado que deseja alterar: ");
          scanf("%d", &k);
          getchar();
          system("CLS");
          if (k < 1 || k > tamAchados) {
            printf("Numero fora do intervalo.");
            erro = 1;
          }
        }
        break;
      }

      while(1 && !erro) {

        menuAlterar();

        scanf("%d", &operacao);
        getchar();

        if(operacao == 1) { //ALTERAR TODOS

          system("CLS");

          printf("\nNome do Produto: ");
          scanf(" %50[^\n]s", produto[achados[k-1]].nome);
          getchar();

          printf("\nCodigo do Produto: ");
          scanf(" %50[^\n]s", produto[achados[k-1]].codigo);
          getchar();

          printf("\nTipo do Produto: ");
          scanf(" %50[^\n]s", produto[achados[k-1]].tipo);
          getchar();

          printf("\nQuantidade do Produto: ");
          scanf("%d", &produto[achados[k-1]].quantidade);
          getchar();

          printf("\nValor do Produto: R$");
          scanf("%f", &produto[achados[k-1]].preco);
          getchar();
        }

        else if(operacao == 2) { //ALTERAR UM

          system("CLS");
          while(1) {
            menuAlterarProduto();
            scanf("%d", &operacao);
            getchar();
            if(operacao == 1) {
              printf("\nNome do Produto: ");
              scanf(" %50[^\n]s", produto[achados[k-1]].nome);
              getchar();
            }
            else if(operacao == 2) {
              printf("\nCodigo do Produto: ");
              scanf(" %50[^\n]s", produto[achados[k-1]].codigo);
              getchar();
            }
            else if(operacao == 3) {
              printf("\nTipo do Produto: ");
              scanf(" %50[^\n]s", produto[achados[k-1]].tipo);
              getchar();
            }
            else if(operacao == 4) {
              printf("\nQuantidade do Produto: ");
              scanf("%d", &produto[achados[k-1]].quantidade);
              getchar();
            }
            else if(operacao == 5) {
              printf("\nValor do Produto: R$");
              scanf("%f", &produto[achados[k-1]].preco);
              getchar();
            }
            else if(operacao == 6) {
              system("CLS");
              break;
            }
            else {
              printf("Operacao Invalida. Por favor, digite novamente.");
              system("CLS");
              continue;
            }
            break;
          }
        }
        else if(operacao == 3) { //VOLTAR
          break;
        }
        else { //INVALIDO
            system("CLS");
            printf("Operacao Invalida. Por favor, escolha novamente.");
            continue;
        }
        break;
      }

      printf("\n\nAperte ENTER para continuar: ");
      getchar();

      system("CLS");
    }
    
    else if (operacao == 4) {

      int achados[total_produtos];
      int k;

      while (1) {
        
        int tamAchados = pesquisaProdutos(produto, achados, total_produtos);
        if (tamAchados == 0) {
          printf("\nResultado nao encontrado.");
          continue;
        } else {
          resultadoPesquisaProdutos(produto, achados, tamAchados);
          printf("\nDigite o numero do resultado que deseja deletar: ");
          scanf("%d", &k);
          getchar();
          system("CLS");
          if (k < 1 || k > tamAchados) {
            printf("Numero fora do intervalo.");
            continue;
          } else {
            produto[achados[k-1]].ativo = 0;
            printf("Produto deletado com sucesso.");
          }
          break;
        }
      }

      printf("\n\nAperte ENTER para continuar: ");
      getchar();

      system("CLS");
    }
    

    // Processando Operação de Saída
    else if (operacao == -1) {
      salvaProdutosArquivo(produto, total_produtos);
      relatorioGeral(produto, total_produtos);
      printf("\n\nAperte ENTER para confirmar: ");
      getchar();
      system("CLS");
      break;
    }

    // Processando Operação Inválida
    else {
      system("CLS");
      printf("Operacao Invalida. Por favor, escolha novamente.");
      continue;
    }
    
    system("CLS");
  }
  
  free(produto);

  return 0;
}
