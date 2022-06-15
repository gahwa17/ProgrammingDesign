#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define BOOL int
#define MAX_ROW 1000
#define MAX_COL 1000

struct room{
    char ch;
    int visted;
};

struct room map[MAX_ROW][MAX_COL];

void _DFS(int x, int y, int max_row , int max_col){
    // printf("DFS[%d][%d]:%c\n", x, y, map[x][y].ch);
    //遇到邊界
    if((x < 0) || (x >= max_row) || (y < 0) || (y >= max_col )){
        return;
    }

    //若是已經走訪過的點或是障礙物，return
    if(map[x][y].visted == true || map[x][y].ch == '#'){
        return;
    }

    //將此座標標記為已走訪
    if(map[x][y].ch == '.'){
        map[x][y].visted = true;
    }

    //根據剛剛改為true的座標，繼續拜訪其他點
    _DFS(x - 1, y, max_row , max_col); //往上
    _DFS(x, y + 1, max_row , max_col); //往右
    _DFS(x + 1, y, max_row , max_col); //往下
    _DFS(x, y - 1, max_row , max_col); //往左
}

int main (void){
    //建立地圖
    int row, col;
    int room = 0;

    scanf("%d %d", &row, &col);
    char flush_ch = getchar(); //把上一句scanf的enter刷掉
    char ch;
    for(int i = 0 ; i < row ; i++){
        int j = 0;
        while((ch = getchar()) != '\n' && ch != EOF){
            // printf("[%d][%d]:%c\n", i, j, ch);
            map[i][j].ch = ch;
            map[i][j].visted = false;
            j++;
        }
    }

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            // printf("Cur[%d][%d]:%c\n", i, j, map[i][j].ch);
            if(map[i][j].ch == '.' && map[i][j].visted == false){
                // printf("Enter[%d][%d]\n",i, j);
                _DFS(i, j, row, col);
                room++;
            }
        }
    }

    printf("%d", room);

}


// //print
// for(int i = 0 ; i < row ; i++){
//     for(int j = 0 ; j < col ; j++){
//         printf("%c", map[i][j].ch);
//     }
//     printf("\n");
// }
