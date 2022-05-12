#include <stdio.h>
#include <stdlib.h>

// #define DEBUG

void showdata(int id[], int score[], int size);
void showans(int id[], int score[], int size);
void swap(int *a, int *b);
void quicksort(int id[], int score[], int size, int left, int right);

int main(void){
    int num;
    scanf("%d", &num);

    int *id = malloc(sizeof(int)*num);
    int *score = malloc(sizeof(int)*num);
    int left = 0;
    int right = num-1 ;

    for(int i = 0; i < num ; i++)
        scanf("%d %d",&id[i], &score[i]);
    
    quicksort(id, score, num, left, right);
    showans(id, score, num);


}

void showdata(int id[], int score[], int size){
    printf("ID:");
    for(int i = 0; i < size ; i++)
        printf("[%2d]",id[i]);

    printf("\n");

    printf("score:");
    for(int i = 0; i < size ; i++)
        printf("[%2d]",score[i]);
    printf("\n");
}


void showans(int id[], int score[], int size){
    printf("ID\tscore\n");
    for(int i = 0; i < size ; i++)
        printf("%d\t%d\n",id[i], score[i]);
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
【Quicksort】
採用Divide&Conquer方法，指定數列最左邊的數字為PK，依照此PK，將數列分成兩部分，[小於PK] PK [大於PK]
再以同樣的方式處理左右兩數列，直到數列只剩下1個數字(判斷式: left !< right 時)，即代表排序完成
*/

void quicksort(int id[], int score[], int size, int left, int right){
    /*傳入參數
        id[]: 欲排序的id陣列
        size: 整個陣列的大小
        left: 當前排序陣列之最左索引值
        right: 當前陣列之最右索引值
    */ 

    /*宣告追蹤用的變數
        PK: 當前sort的比較對象，比PK小的要排序到PK右邊
        l_idx: left index，從左至右，用以追蹤比PK小的數字
        r_idx: right index，從右至左，用以追蹤比PK大的數字
    */
    int PK = left;
    int l_idx = left + 1;
    int r_idx = right;

    //當left(最左索引值) < right(最右索引值)，表示當前陣列還有兩個以上的數字，尚未排序完成
    if(left < right){
        while(1){
            #ifdef DEBUG
                showdata(id, score, size);
            #endif

            //由左至右，找到比PK大的數字的索引值，將其存進l_idx
            for(int i = l_idx ; i <= right ; i++){
                if(id[i] >= id[PK]){
                    l_idx = i;
                    break;
                }
                l_idx++;
            }

            //由右至左，找到比PK小的數字的索引值，將其存進r_idx
            for(int j = right ; j >=  left+1 ; j--){
                if(id[j] < id[PK]){
                    r_idx = j;
                    break;
                }
                r_idx--;
            }

            #ifdef DEBUG
                printf("PK:%d\n", id[PK]);
                printf("l_idx:%d\n", l_idx);
                printf("r_idx:%d\n", r_idx);
            #endif

            if(l_idx < r_idx){
                swap(&id[l_idx], &id[r_idx]);
                swap(&score[l_idx], &score[r_idx]);
            }
            
            // 當l_idx > r_idx，跳出while迴圈，表示 [小於PK] [大於PK] 的數列已經排序好
            else{
                //將PK移到 [小於PK], [大於PK]的中間，完成當前數組的排序，意即: [小於PK] PK [大於PK]
                swap(&id[PK], &id[r_idx]);
                swap(&score[PK], &score[r_idx]);
                break;
            }
        }

        //完成了[小於PK] PK [大於PK]，在分別進入左、右邊的[ ]，進行相同的sort
        quicksort(id, score, size, left, r_idx-1);
        quicksort(id, score, size, r_idx+1, right);
    }

    // 當left >= right，代表需排序的數字只剩下一筆，相當於整組數字已排序完成
    else{
        #ifdef DEBUG
            printf("PK:%d Sorted\n", id[PK]);
        #endif
    }
    
}