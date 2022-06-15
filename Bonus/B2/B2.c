#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define BOOL int
#define MAX_ROW 1000
#define MAX_COL 1000

struct Point{
    int x;
    int y;
};

struct queue{
    struct Point coordinate;
    int dist;
};

struct room{
    char ch;
    int visted;
};

struct room map[MAX_ROW][MAX_COL];
BOOL isFind = false;
int step = 0;

void _BFS(int x, int y, int max_row , int max_col){
    printf("Cur[%d][%d]:%c,v:%d\n", x, y, map[x][y].ch, map[x][y].visted);

    map[x][y].visted = true;

    //遇到邊界
    if((x < 0) || (x >= max_row) || (y < 0) || (y >= max_col || isFind)){
        return;
    }

    //若是已經走訪過的點或是障礙物，return
    if(map[x][y].visted == true || map[x][y].ch == '#'){
        return;
    }

    //將此座標標記為已走訪
    if(map[x][y].ch == '.'){
        printf("step++\n");
        step++;
    }

    //檢查該座標是否為B
    if(map[x][y].ch == 'B'){
        isFind = true;
        printf("YES\n");
        printf("%d\n",step-1);
        // return;
    }

    //繼續拜訪其他點
    _BFS(x - 1, y, max_row , max_col); //往上
    _BFS(x, y + 1, max_row , max_col); //往右
    _BFS(x + 1, y, max_row , max_col); //往下
    _BFS(x, y - 1, max_row , max_col); //往左


}

int main (void){
    //Create maze
    int row, col;
    int start_x, start_y;
    scanf("%d %d", &row, &col);

    char flush_ch = getchar();

    char ch;
    for(int i = 0 ; i < row ; i++){
        int j = 0;
        while((ch = getchar()) != '\n' && ch != EOF){
            // printf("[%d][%d]:%c\n", i, j, ch);
            if(ch == 'A'){
                start_x = i;
                start_y = j;
            }
            map[i][j].ch = ch;
            map[i][j].visted = false;
            j++;
        }
    }

    _BFS(start_x, start_y, row, col);

    if(isFind == 0)
        printf("NO\n");
}


// //print
// for(int i = 0 ; i < row ; i++){
//     for(int j = 0 ; j < col ; j++){
//         printf("%c", map[i][j].ch);
//     }
//     printf("\n");
// }
