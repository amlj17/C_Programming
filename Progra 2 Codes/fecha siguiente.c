//
//  fecha siguiente.c
//  
//
//  Created by Andres Moguel on 1/24/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct date {
    int month;
    int day;
    int year;
};

int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leapyear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

int validdate(struct date now) {
    int daysmon;
    if (now.year <= 1582)                   // pre-Gregorian
        return 0;
    if (now.month < 1 || now.month > 12)
        return 0;
    daysmon = daysPerMonth[now.month-1];
    if (leapyear(now.year) && now.month == 2)
        daysmon++;
    if (now.day < 1 || now.day > daysmon)
        return 0;
    return 1;
}

struct date bumpdate(struct date now) {
    int daysmon = daysPerMonth[now.month-1];
    if (leapyear(now.year) && now.month == 2)
        daysmon++;
    if (++now.day > daysmon) {
        now.day = 1;
        if (++now.month > 12) {
            now.month = 1;
            now.year++;
        }
    }
    return now;
}

int main (void) {
    struct date today, tomorrow;
    printf("Enter today's date (mm/dd/yyyy): ");
    if (3 != scanf("%d %*[/-] %d %*[/-] %d", &today.month, &today.day, &today.year)) {
        printf ("Need the proper date format\n");
        return 1;
    }
    if (!validdate(today)) {
        printf ("Invalid date\n");
        return 1;
    }
    tomorrow = bumpdate(today);
    printf("Tomorrow's date is %02d/%02d/%04d", tomorrow.month, tomorrow.day, tomorrow.year);
    return 0;
}
