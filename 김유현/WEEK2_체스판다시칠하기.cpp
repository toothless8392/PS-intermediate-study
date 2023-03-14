#include<stdio.h>
#include<stdlib.h>
int check_board_Wtype(char **, int, int);
int check_board_Btype(char **, int, int);
int main () {
    int i, j;
    int NandM[2];
    char **chess;
    int answer = 3000, pre_answer;
    scanf("%d %d", &NandM[0], &NandM[1]);
    chess = (char **)malloc(sizeof(char *) * NandM[0]);
    for(i = 0; i < NandM[0]; i++)
       chess[i] = (char *)malloc(sizeof(char) * (NandM[1] + 1));
    for(i = 0; i < NandM[0]; i++)
        scanf("%s", chess[i]);

    for(i = 0; i < NandM[0] - 7; i++)
    for(j = 0; j < NandM[1] - 7; j++){
        pre_answer = check_board_Wtype(chess, i, j);
        if(pre_answer < answer) answer = pre_answer;
        pre_answer = check_board_Btype(chess, i, j);
        if(pre_answer < answer) answer = pre_answer;
    }

    printf("%d", answer);

    return 0;
}
int check_board_Wtype(char **arr, int Y, int X){
    int change = 0;     int i, j;
    for(i = Y; i < Y + 8; i++)
        for(j = X; j < X + 8; j++){
            if((i - Y) % 2 == 0 && (j - X) % 2 == 0){
                if(arr[i][j] == 'W')
                    continue;
                else if(arr[i][j] == 'B'){
                    change++;
                }
            } else if((i - Y) % 2 == 0 && (j - X) % 2 == 1){
                if(arr[i][j] == 'B')
                    continue;
                else if(arr[i][j] == 'W'){
                    change++;
                }
            } else if((i - Y) % 2 == 1 && (j - X) % 2 == 0){
                if(arr[i][j] == 'B')
                    continue;
                else if(arr[i][j] == 'W'){
                    change++;
                }
            } else if((i - Y) % 2 == 1 && (j - X) % 2 == 1){
                if(arr[i][j] == 'W')
                    continue;
                else if(arr[i][j] == 'B'){
                    change++;
                }
            }
        }
    return change;
}
int check_board_Btype(char **arr, int Y, int X){
    int change = 0;     int i, j;
    for(i = Y; i < Y + 8; i++)
        for(j = X; j < X + 8; j++){
            if((i - Y) % 2 == 0 && (j - X) % 2 == 0){
                if(arr[i][j] == 'B')
                    continue;
                else if(arr[i][j] == 'W'){
                    change++;
                }
            } else if((i - Y) % 2 == 0 && (j - X) % 2 == 1){
                if(arr[i][j] == 'W')
                    continue;
                else if(arr[i][j] == 'B'){
                    change++;
                }
            } else if((i - Y) % 2 == 1 && (j - X) % 2 == 0){
                if(arr[i][j] == 'W')
                    continue;
                else if(arr[i][j] == 'B'){
                    change++;
                }
            } else if((i - Y) % 2 == 1 && (j - X) % 2 == 1){
                if(arr[i][j] == 'B')
                    continue;
                else if(arr[i][j] == 'W'){
                    change++;
                }
            }
        }
    return change;
}
