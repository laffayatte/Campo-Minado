#include <stdio.h>
#include <time.h>
#define N 9
// Cria uma matriz para o sistema com varias flags -2
void campo_minado(char M[][N], int n){
    int i, j;
    int bombas = 0.2 * n * n;
    srand(time(NULL));
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            M[i][j] = -2;
        }
    }
    while(bombas != 0){
        i = rand() % n;
        j = rand() % n;
        if (M[i][j] != -1){
            M[i][j] = -1;
            bombas--;
        }
    }
}
// cria uma matriz com varios ? 
void interface(char M[][N], int n){
    int i, j;
    char inter = '?';
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
        {
            M[i][j] = inter;
        }
    }
}
// imprime a matriz com ? 
void imprime_mat(char M[][N], int n){
    int i, j;
    for (i = 0; i < n; i++){
        printf("%d | ", i+1);
        for (j = 0; j < n; j++){
            printf(" %c   ", M[i][j]);
        }
        printf("\n");
    }
    printf("   ");
    for (j = 0; j < n; j++){
        printf("-----");
    }
    printf("\n");
    printf("     ");
    for (j = 0; j < n; j++){
        printf("%d    ", j+1);
    }
}
// Calcula a quantidade de bombas ao redor de uma localização
int n_bombas(int linha_jogador, int coluna_jogador, char m[][N], int n){
    int quant_bomb = 0;
    if (m[linha_jogador - 1][coluna_jogador - 1] == -1){
        quant_bomb++;
    }
    if (m[linha_jogador - 1][coluna_jogador] == -1){
        quant_bomb++;
    }
    if (m[linha_jogador - 1][coluna_jogador + 1] == -1){
        quant_bomb++;
    }
    if (m[linha_jogador][coluna_jogador - 1] == -1){
        quant_bomb++;
    }
    if (m[linha_jogador + 1][coluna_jogador - 1] == -1){
        quant_bomb++;
    }
    if (m[linha_jogador + 1][coluna_jogador] == -1){
        quant_bomb++;
    }
    if (m[linha_jogador + 1][coluna_jogador + 1] == -1){
        quant_bomb++;
    }
    if (m[linha_jogador][coluna_jogador + 1] == -1){
        quant_bomb++;
    }
    return quant_bomb;
}

int main(){
    char M[N][N];
    char Matriz_Interface[N][N];
    int tam, bombas_quant, livre;
    int n, linha_jogador, coluna_jogador;
    int vitorias = 0;
    int vida = 1;

    // Recebimento do tamanho

    printf("\nDigite o tamanho da matriz desejada: ");
    scanf("%d", &n);

    // Calculo de espaços livres sobrando

    bombas_quant = 0.2 * n * n;
    tam = n * n;
    livre = tam - bombas_quant;

    // Inicio do código do jogo

    campo_minado(M, n);
    interface(Matriz_Interface, n);

    while(vida == 1){
        
        printf("\n");
        imprime_mat(Matriz_Interface, n);
        printf("\n");
        printf("\nDigite a linha e coluna desejada: ");
        scanf("%d %d", &linha_jogador, &coluna_jogador);
        
        linha_jogador = linha_jogador -1;
        coluna_jogador = coluna_jogador -1;
        

        // Verificação de Limites da matriz
        if (linha_jogador < 0 || coluna_jogador < 0 || linha_jogador >= n || coluna_jogador >= n){
            printf("\nEntrada invalida \n\n");
            imprime_mat(Matriz_Interface, n);
            

            char altera;
            // Condicionais para verificar o
            if (n_bombas(linha_jogador, coluna_jogador, M, n) == 0){
                altera = '0';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 1){
                altera = '1';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 2){
                altera = '2';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 3){
                altera = '3';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 4){
                altera = '4';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 5){
                altera = '5';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 6){
                altera = '6';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 7){
                altera = '7';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 8){
                altera = '8';
            }
    
            printf("\nDigite a linha e coluna desejada: ");
            scanf("%d %d", &linha_jogador, &coluna_jogador);
           
            linha_jogador = linha_jogador -1;
            coluna_jogador = coluna_jogador -1;
           
            if (M[linha_jogador][coluna_jogador] == -2){
               
                char altera;
                // Condicionais para verificar a quantidade de bombas e transformar em char
                if (n_bombas(linha_jogador, coluna_jogador, M, n) == 0){
                    altera = '0';
                }
                else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 1){
                    altera = '1';
                }
                else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 2){
                    altera = '2';
                }
                else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 3){
                    altera = '3';
                }
                else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 4){
                    altera = '4';
                }
                else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 5){
                    altera = '5';
                }
                else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 6){
                    altera = '6';
                }
                else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 7){
                    altera = '7';
                }
                else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 8){
                    altera = '8';
                }
                M[linha_jogador][coluna_jogador] = -3;
                Matriz_Interface[linha_jogador][coluna_jogador] = altera;
                vitorias++;
            }
            if(linha_jogador < 0 || coluna_jogador < 0 || linha_jogador >= n || coluna_jogador >= n){
                printf("\n");
                printf("Entrada invalida");
                printf("\n\n");
                
            }
           
        }
        // Condição de derrota 
        else if (M[linha_jogador][coluna_jogador] == -1){
            int i, j;
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    if (M[i][j] == -1){
                        Matriz_Interface[i][j] = '*';
                    }
                }
            }
            
            printf("\nVOCE PERDEU! FIM DO JOGO.\n\n");
            imprime_mat(Matriz_Interface, n);
            vida--;
        }
        // Condição de acerto de posição
        else if (M[linha_jogador][coluna_jogador] == -2){
            char altera;
            if (n_bombas(linha_jogador, coluna_jogador, M, n) == 0){
                altera = '0';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 1){
                altera = '1';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 2){
                altera = '2';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 3){
                altera = '3';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 4){
                altera = '4';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 5){
                altera = '5';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 6){
                altera = '6';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 7){
                altera = '7';
            }
            else if (n_bombas(linha_jogador, coluna_jogador, M, n) == 8){
                altera = '8';
            }
            M[linha_jogador][coluna_jogador] = -3;
            Matriz_Interface[linha_jogador][coluna_jogador] = altera;
            vitorias++;
            
        }
        // Condição de repetição de local
        else if (M[linha_jogador][coluna_jogador] == -3){
           
            printf("\n");
            imprime_mat(Matriz_Interface, n);
            printf("\n");
            printf("\nDigite a linha e coluna desejada: ");
            scanf("%d %d", &linha_jogador, &coluna_jogador);
            linha_jogador = linha_jogador -1;
            coluna_jogador = coluna_jogador -1;
            
        }
        // Condição de Vitória
        if (vitorias == livre){
            int i, j;
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    if (M[i][j] == -1){
                        Matriz_Interface[i][j] = '*';
                    }
                }
            }
            printf("\nVOCE VENCEU! PARABENS!\n\n");
            imprime_mat(Matriz_Interface, n);
            break;
        }
    }
    return 0;
}
