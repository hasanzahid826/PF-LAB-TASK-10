#include<stdio.h>
void grow(int heights[], int n)
{
    if(n == 0){
        return ;
    }
    heights[n - 1] = heights[n - 1] + heights[n - 1] *10/100;
    grow(heights, n - 1);
}

int tallest(int heights[], int n)
{
    if(n == 1){
        return 0;
    }
    int index = tallest(heights, n - 1);

    if(heights[n - 1] > heights[index]){
        return n - 1;
    }
    else{
        return index;
    }
}

int search(int heights[], int n, int target)
{
    if(n == 0){
        return -1;
    }

    if(heights[n - 1] == target){
        return n - 1;
    }
    return search(heights, n - 1, target);
}
int main()
{
    int ids[6] = {101, 102, 103, 104, 105, 106};
    int heights[6] = {45, 120, 78, 200, 95, 150};
    int i, target, index;

    grow (heights, 6);

    printf("New Heights: ");
    for(i = 0; i < 6; i++){
        printf("%d ", heights[i]);
    }

    index = tallest(heights, 6);
    printf("\nTallest tower: %d (%dm)", ids[index], heights[index]);

    printf("\nHeight to search: ");
    scanf("%d", &target);

    index = search(heights, 6, target);
    if(index != -1){
        printf("\nTower %d is %d m", ids[index], target);
    }
    else{
        printf("\nNo tower found: ");
    }

    return 0;
}