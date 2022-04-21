#include <stdio.h>

int main(void){
    char input[10];
    int x = 0,y = 0,area = 0;
    printf("Enter:");
    scanf("%s",input);
    sscanf(input,"(%d,%d)",&x,&y);

    area = (x * x) + (y * y);
    if(x == 0 && y ==0)
        printf("(%d,%d) is at the origin\n", x, y);
    else if(x == 0)
        printf("(%d,%d) is on the x-axis\n", x, y);
    else if(y == 0)
        printf("(%d,%d) is on the x-axis\n", x, y);
    else if(( x > 0) && ( y > 0 ))
        printf("(%d,%d) is on Quadrant I\n", x, y);
    else if(( x < 0) && ( y > 0 ))
        printf("(%d,%d) is on Quadrant II\n", x, y);
    else if(( x < 0) && ( y < 0 ))
        printf("(%d,%d) is on Quadrant III\n", x, y);
    else if(( x > 0) && ( y < 0 ))
        printf("(%d,%d) is on Quadrant IIII\n", x, y);

    printf("The value of squared distance is %d",area);
    return 0;
}