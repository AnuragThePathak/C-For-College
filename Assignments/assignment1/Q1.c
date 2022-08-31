#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool isValid(const char email[]);

int main() {
    char number[MAX];
    scanf("%s", number);

    if (isValid(number)) printf("%s is valid floating point number.", number);
    else printf("%s is not a valid floating point number.", number);
    return 0;
}

bool isValid(const char number[]) {
    if (number[0] == '.') return false;

    bool check = false;
    for (int i = 1; number[i] != '\0'; i++) {
        if (number[i] == '.') {
            if (!check) check = true;
            else return false;

            if (number[i + 1] == '\0') return false;
        }
    }
    return check;
}
