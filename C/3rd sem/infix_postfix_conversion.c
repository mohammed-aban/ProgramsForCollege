#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>  
#include<math.h>

char istack[20];
int itop = -1;

float stack[20];
int top = -1;

void ipush(char element) {
    itop++;
    istack[itop] = element;
}

int ipop() {
    if (itop == -1) {
        printf("Infix Stack Underflow\n");
        return -999;
    }

    else {
        char element = istack[itop];
        itop--;
        return element;
    }
}

int precedence(char symbol) {
    switch (symbol) {
        case '(':
        case ')':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
            return 4;
        default:
            return 0;
    }
}

void convert_ip(char infix[20], char postfix[20]) {
    int i, j = 0, n;
    char symbol;
    n = strlen(infix);
    ipush('(');
    infix[n] = ')';
    n += 1;

    for (i = 0; i < n; i++) {
        symbol = infix[i];

        switch (symbol) {
            case '(':
                ipush(symbol);
                break;
            
            case ')':
                while (istack[itop] != '(') {
                    postfix[j] = ipop();
                    j++;
                }
                ipop(); // Pop the '(' from stack
                break;

            case '^':
            case '*':
            case '/':
            case '%':
            case '+':
            case '-':
                while (precedence(istack[itop]) >= precedence(symbol)) {
                    postfix[j] = ipop();
                    j++;
                }
                ipush(symbol);
                break;
            
            default:   
                postfix[j] = symbol;
                j++;
                break;
        }
    }
    postfix[j] = '\0';
}

void push(float element) {
    top++;
    stack[top] = element;
}

int pop() {
    float element = stack[top];
    top--;
    return element;
}

void evaluate(char postfix[20]) {
    int i;
    char symbol;
    float op1, op2, result, x;

    for (i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];

        if (isalpha(symbol)) {
            printf("Enter the value of %c: ", symbol);
            scanf("%f", &x);
            push(x);
        }

        else {
            op2 = pop();
            op1 = pop();

            switch(symbol) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '%':
                    push((int)op1 % (int)op2);
                    break;
                case '^':
                    push(pow(op1, op2));
                    break;

                default:
                    printf("Invalid operator\n");
                    exit(0);
            }
        }

    }
    result = pop();
    printf("Result of expression: %0.2f\n", result);
}

int main() {
    char infix[20], postfix[20];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    convert_ip(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    evaluate(postfix);

    return 0;
}