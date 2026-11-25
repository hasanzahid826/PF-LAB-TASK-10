#include<stdio.h>
int main()
{
    FILE *fp;
    int itemNo, quantity, stock;
    char name[21];
    float price, totalBill = 0;

    fp = fopen("item.txt", "w");
    if(fp == NULL){
        printf("File cannot be opened! ");
        return 1;
    }

    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 1, "Rice", 250.00, 40);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 2, "Sugar", 160.00, 25);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 3, "Milk", 220.00, 30);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 4, "CookingOil", 560.00, 12);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 5, "Tea", 450.00, 18);

    fclose(fp);

    fp = fopen("item.txt", "rb+");
    if(fp == NULL){
        printf("File cannot be opened!");
        return 1;
    }

    while(1){
        printf("\nItem no: ");
        scanf("%d", &itemNo);
        if(itemNo == 0){
            break;
        }

        printf("Quantity: ");
        scanf("%d", &quantity);
        if(itemNo < 1 || itemNo > 5 || quantity <= 0){
            printf("Invalid input!\n");
            continue;
        }

        fseek(fp, (itemNo - 1) * 42, SEEK_SET);

        fscanf(fp, "%d %20s %f %d", &itemNo, name, &price, &stock);

        if(stock >= quantity){
            float bill = price * quantity;
            printf("%s %d x %.2f = %.2f\n", name, quantity, price, bill);

            totalBill += bill;
            stock -= quantity;

            fseek(fp, (itemNo - 1) * 42, SEEK_SET);

            fprintf(fp, "%-4d %-20s %9.2f %5d\n", itemNo, name, price, stock);
        }
        else{
            printf("Only %d %s in stock\n", stock, name);
        }
    }
    printf("\nTotal bill: %.2f\n", totalBill);
    fclose(fp);

    return 0;
}