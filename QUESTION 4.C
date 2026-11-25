#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fp;
    int room, nights, rooms[10];
    int i, found;
    char status, name[21];
    char guests[10][21];
    float rate, bill;

    fp = fopen("hotel.txt", "wb");

    for(i = 101; i <= 110; i++){
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                i, 'F', "-", 0, 8000.0);
    }

    fclose(fp);

    fp = fopen("hotel.txt", "r+b");

    printf("Check-in room: ");
    scanf("%d", &room);

    printf("Name: ");
    scanf("%20s", name);

    printf("Nights: ");
    scanf("%d", &nights);

    fseek(fp, (room - 101) * 39, SEEK_SET);

    fscanf(fp, "%d %c %20s %d %f",
           &room, &status, guests[0], &i, &rate);

    if(status == 'F'){
        fseek(fp, (room - 101) * 39, SEEK_SET);

        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                room, 'B', name, nights, rate);

        printf("Room %d booked!\n", room);
    }
    else{
        printf("Room already booked\n");
    }

    rewind(fp);

    for(i = 0; i < 10; i++){
        fscanf(fp, "%d %c %20s %d %f",
               &rooms[i], &status, guests[i],
               &nights, &rate);
    }

    printf("Search name: ");
    scanf("%20s", name);

    found = 0;

    for(i = 0; i < 10; i++){
        if(strcmp(name, guests[i]) == 0){
            printf("%s is in room %d\n", name, rooms[i]);
            found = 1;
            break;
        }
    }

    if(found == 0){
        printf("Guest not found\n");
    }

    printf("Check-out room: ");
    scanf("%d", &room);

    fseek(fp, (room - 101) * 39, SEEK_SET);

    fscanf(fp, "%d %c %20s %d %f",
           &room, &status, name, &nights, &rate);

    if(status == 'B'){
        bill = nights * rate;

        printf("Bill: %d x %.2f = %.2f\n",
               nights, rate, bill);

        fseek(fp, (room - 101) * 39, SEEK_SET);

        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                room, 'F', "-", 0, rate);
    }

    fclose(fp);

    return 0;
}