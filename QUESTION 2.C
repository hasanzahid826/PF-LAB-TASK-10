#include<stdio.h>
int main()
{
    FILE *fp;
    int roll, lectures, leave;
    char name[20];
    float percentage;

    fp = fopen("attendance.txt", "wb");

    fprintf(fp, "%-3d %-15s %3d\n", 1, "Ayesha", 18);
    fprintf(fp, "%-3d %-15s %3d\n", 2, "Bilal", 14);
    fprintf(fp, "%-3d %-15s %3d\n", 3, "Hamza", 20);
    fprintf(fp, "%-3d %-15s %3d\n", 4, "Sana", 12);
    fprintf(fp, "%-3d %-15s %3d\n", 5, "Zainab", 16);

    fclose(fp);

    fp = fopen("attendance.txt", "rb+");

    printf("Roll number: ");
    scanf("%d", &roll);

    fseek(fp, (roll - 1) * 24, SEEK_SET);

    fscanf(fp, "%d %s %d", &roll, name, &lectures);

    percentage = (lectures / 20.0) * 100;

    printf("%s: %d / 20 (%.1f%%)", name, lectures, percentage);

    if(percentage < 75){
        printf(" Short attendance\n");
    }
    else{
        printf(" Good attendance\n");
    }
    
    printf("Roll number for leave: ");
    scanf("%d", &roll);

    printf("Lectures: ");
    scanf("%d", &leave);

    fseek(fp, (roll - 1) * 24, SEEK_SET);

    fscanf(fp, "%d %s %d", &roll, name, &lectures);

    lectures = lectures + leave;

    fseek(fp, (roll - 1) * 24, SEEK_SET);

    fprintf(fp, "%-3d %-15s %3d\n", roll, name, lectures);

    printf("%s: now %d / 20 (%.1f%%)\n", name, lectures, (lectures / 20.0) * 100);

    fseek(fp, -24, SEEK_END);

    fscanf(fp, "%d %s %d", &roll, name, &lectures);

    printf("Last record: %d %s %d\n", roll, name, lectures);

    fclose(fp);

    return 0;
}