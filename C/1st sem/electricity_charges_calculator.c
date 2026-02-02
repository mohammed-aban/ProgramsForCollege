#include <stdio.h>

int main() {
    char name[20];
    int units_consumed;
    int min_charges = 100;
    float final_charges = 0;

    printf("Enter your name: ");
    scanf("%[^\n]s", &name);
    printf("Enter the amounts of units you've consumed: ");
    scanf("%d", &units_consumed);

    if (units_consumed <= 200) {
        final_charges = (units_consumed * 0.80) + min_charges;
    }
    else {
        if (units_consumed > 300) {
            final_charges = 200 * 0.80 + 90 + (units_consumed - 300) + min_charges;
        }
        else {
            final_charges = 200 * 0.80 + (units_consumed - 200) * 0.90 + min_charges;
        }
    }
    
    if (final_charges > 400) {
        final_charges += 0.15 * final_charges;
    }

    printf("%s has to pay %f rupees.", name, final_charges);

    return 0;
}