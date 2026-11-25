#include<stdio.h>
int main()
{
    FILE *fp;
    char category[13];
    float amount, total = 0;
    int entry, i;

    fp = fopen("expenses.txt", "wb");

    fprintf(fp, "%-12s %9.2f\n", "Food", 1200.00);
    fprintf(fp, "%-12s %9.2f\n", "Transport", 500.00);
    fprintf(fp, "%-12s %9.2f\n", "Books", 850.00);
    fprintf(fp, "%-12s %9.2f\n", "Mobile", 300.00);

    fclose(fp);

    fp = fopen("expenses.txt", "ab");

    printf("Category: ");
    scanf("%12s", category);

    printf("Amount: ");
    scanf("%f", &amount);

    fprintf(fp, "%-12s %9.2f\n", category, amount);

    fclose(fp);

    fp = fopen("expenses.txt", "rb+");

    fseek(fp, -2 * 23, SEEK_END);

    fscanf(fp, "%12s %f", category, &amount);

    printf("Latest two: %s %.2f, ", category, amount);

    fscanf(fp, "%12s %f", category, &amount);

    printf("%s %.2f\n", category, amount);

    printf("Entry to fix: ");
    scanf("%d", &entry);

    printf("Correct amount: ");
    scanf("%f", &amount);

    fseek(fp, (entry - 1) * 23, SEEK_SET);

    fscanf(fp, "%12s", category);

    fseek(fp, (entry - 1) * 23, SEEK_SET);

    fprintf(fp, "%-12s %9.2f\n", category, amount);

    rewind(fp);

    total = 0;

    for(i = 0; i < 5; i++){
        fscanf(fp, "%12s %f", category, &amount);

        printf("%s %.2f\n", category, amount);

        total = total + amount;
    }

    printf("Total: %.2f\n", total);

    fclose(fp);

    return 0;
}