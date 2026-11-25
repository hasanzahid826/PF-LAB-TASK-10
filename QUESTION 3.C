#include<stdio.h>
int main()
{
    FILE *fp;
    char city[20];
    float temp, newTemp, highest;
    int i, number;

    fp = fopen("temperature.txt", "wb");

    fprintf(fp, "%-10s %5.1f\n", "Karachi", 32.5);
    fprintf(fp, "%-10s %5.1f\n", "Lahore", 30.1);
    fprintf(fp, "%-10s %5.1f\n", "Islamabad", 24.3);
    fprintf(fp, "%-10s %5.1f\n", "Quetta", 18.7);
    fprintf(fp, "%-10s %5.1f\n", "Peshawar", 28.9);

    fclose(fp);

    fp = fopen("temperature.txt", "rb+");

    printf("City number: ");
    scanf("%d", &number);

    fseek(fp, (number - 1) * 17, SEEK_SET);

    fscanf(fp, "%s %f", city, &temp);

    printf("%s %.1f\n", city, temp);

    printf("City number to correct: ");
    scanf("%d", &number);

    printf("New temperature: ");
    scanf("%f", &newTemp);

    fseek(fp, (number - 1) * 17, SEEK_SET);

    fscanf(fp, "%s %f", city, &temp);

    fseek(fp, (number - 1) * 17, SEEK_SET);

    fprintf(fp, "%-10s %5.1f\n", city, newTemp);

    printf("%s updated to %.1f\n", city, newTemp);

    rewind(fp);

    highest = -100;

    for (i = 0; i < 5; i++){
        fscanf(fp, "%s %f", city, &temp);

        if (temp > highest){
            highest = temp;
            number = i;
        }
    }

    fseek(fp, number * 17, SEEK_SET);

    fscanf(fp, "%s %f", city, &temp);

    printf("Hottest city: %s (%.1f)\n", city, temp);

    fclose(fp);

    return 0;
}