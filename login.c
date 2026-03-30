#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char username[100];
    char password[100];

    char correct_username[] = "admin";
    char correct_password[] = "Pass123";

    int total = 0;
    int success = 0;
    int failed = 0;

    file = fopen("logins.txt", "r");

    if (file == NULL) {
        printf("Error: cannot open file\n");
        return 1;
    }

    while (fscanf(file, "%s %s", username, password) != EOF) {
        total++;

        if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0) {
            success++;
        } else {
            failed++;
        }
    }

    fclose(file);

    printf("Total attempts: %d\n", total);
    printf("Successful logins: %d\n", success);
    printf("Failed logins: %d\n", failed);

    return 0;
}