#include <stdio.h>
// 4칙연산 4+5, scanf

int main(void)
{
    int a, b;
    char op;
    printf("integer : ");
    scanf("%d %c %d", &a, &op, &b);

    switch (op)
    {
    case '+':
        break;

    case '-':
        break;

    case '*':
        break;

    case '/':
        if (b == 0)

            printf("no divide by0");
         else printf("%d %c %d=%f\r\n", a, op, b, (float)a / (float)b);
        break;
    }
aaa:
    // if (op == '*')
    //     printf("%d %c %d = %d", a, op, b, a * b);
    // else if (op == '+')
    //     printf("%d %c %d=%d", a, op, b, a + b);

    // else if (op == '/') {
    //     if(b==0)

    //         printf("no divide by0")''
    //     else
    //          printf("%d %c %d=%d", a, op, b, a / b);

    // }
    return 0;
}
