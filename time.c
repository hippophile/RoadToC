#include <stdio.h>

void time(int sec, int *hours, int *min, int *secs) {
    *hours = sec / 3600;
    int z = sec % 3600;
    *min = z / 60;
    *secs = z % 60;
}

int main(void) {
    int min, hours, sec;

    printf("\nGive me the seconds kid :\n ");
    scanf("%d", &sec);

    time(sec, &hours, &min, &sec);

    printf("\nyou got %d hours\n", hours);
    printf("you got %d minutes\n", min);
    printf("you got %d seconds\n", sec);

    return 0;
}
