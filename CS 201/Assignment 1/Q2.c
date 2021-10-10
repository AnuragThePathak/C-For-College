#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

bool isValid(const char email[]);

bool isAllowedFirstChar(char ch);

int main() {
    char email[MAX];
    scanf("%s", email);

    if (isValid(email)) printf("%s is valid email.", email);
    else printf("%s is not a valid email.", email);
    return 0;
}

bool isValid(const char email[]) {
    if (email[0] == '.') return false;

    int dotPosition = -1;
    int i;
    for (i = 1; i < strlen(email) - 2; i++) {
        if (email[i] == '@') {
            dotPosition = ++i;
            break;
        }

        if (email[i] == '.') {
            if (email[i + 1] == '.') return false;
        }
    }

    if (dotPosition == -1) return false;

    if (!isAllowedFirstChar(email[dotPosition])) return false;

    for (i = dotPosition + 1; email[i] != '\0'; i++) {
        if (email[i] == '.') {
            if (email[i + 1] == '\0') return false;
            if (email[++i] == '.') return false;
        }

        if (!(email[i] == '-' || isAllowedFirstChar(email[i]))) return false;
    }

    if (email[i - 1] == '-') return false;

    return true;
}

bool isAllowedFirstChar(char ch) {
    if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9' || ch >= 'A' && ch <= 'Z') {
        return true;
    } else return false;
}