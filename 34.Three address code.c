Skip to content
Navigation Menu
Product
Solutions
Resources
Open Source
Enterprise
Pricing

Search or jump to...
Sign in
Sign up
Narasingdharani
/
CSA1406-COMPILER-DESIGN-192210295
Public
Code
Issues
Pull requests
Actions
Projects
Security
Insights
Commit
Create 34.Three address code.c
 main
@Narasingdharani
Narasingdharani authored 4 hours ago 
1 parent c88fbff
commit 36778c4
Showing 1 changed file with 85 additions and 0 deletions.
 85 changes: 85 additions & 0 deletions85  
34.Three address code.c
Original file line number	Diff line number	Diff line change
@@ -0,0 +1,85 @@
#include <stdio.h>
#include <stdlib.h>

int tempCount = 0;

char* newTemp() {
    char* temp = (char*)malloc(5); 
    sprintf(temp, "t%d", tempCount++);
    return temp;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

const char* skipWhitespace(const char* input) {
    while (*input == ' ' || *input == '\t') {
        input++;
    }
    return input;
}

char* parseNext(const char* input, char* buffer) {
    input = skipWhitespace(input);
    int i = 0;
    while (*input != '\0' && *input != ' ' && !isOperator(*input)) {
        buffer[i++] = *input++;
    }
    buffer[i] = '\0';

    return buffer;
}

void genAdd(char* op1, char* op2, char* result) {
    printf("%s = %s + %s\n", result, op1, op2);
}

void genSub(char* op1, char* op2, char* result) {
    printf("%s = %s - %s\n", result, op1, op2);
}

void genMul(char* op1, char* op2, char* result) {
    printf("%s = %s * %s\n", result, op1, op2);
}

void genDiv(char* op1, char* op2, char* result) {
    printf("%s = %s / %s\n", result, op1, op2);
}

int main() {
    char expression[100];
    char buffer[100];

    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    const char* input = expression;
    char* op1 = parseNext(input, buffer);

    while (*input != '\0') {
        input = skipWhitespace(input);
        if (*input == '\0') {
            break;
        }

        char op = *input++;

        char* op2 = parseNext(input, buffer);

        char* result = newTemp();
        if (op == '+') {
            genAdd(op1, op2, result);
        } else if (op == '-') {
            genSub(op1, op2, result);
        } else if (op == '*') {
            genMul(op1, op2, result);
        } else if (op == '/') {
            genDiv(op1, op2, result);
        }

        op1 = result;
    }

    return 0;
}
1 comment on commit 36778c4
@Narasingdharani
Owner
Author
Narasingdharani commented on 36778c4 4 hours ago
Image

Please sign in to comment.
Footer
© 2024 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact
Manage cookies
Do not share my personal information
Create 34.Three address code.c · Narasingdharani/CSA1406-COMPILER-DESIGN-192210295@36778c4 · GitHub
