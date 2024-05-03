#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

char* generate_expression(int max_number, char* operators, int use_parentheses, int use_decimal) {
    int number = rand() % (max_number + 1);
    float decimal = (float)rand() / (float)(RAND_MAX / max_number);
    char operation = operators[rand() % strlen(operators)];
    char* expression = (char*)malloc(100 * sizeof(char));

    if (use_decimal) {
        snprintf(expression, 100, "%.2f %c %.2f", decimal, operation, decimal);
    }
    else {
        snprintf(expression, 100, "%d %c %d", number, operation, number);
    }

    if (use_parentheses && (rand() % 2 == 1)) {
        char* temp = expression;
        expression = (char*)malloc(100 * sizeof(char));
        snprintf(expression, 100, "(%s)", temp);
        free(temp);
    }

    return expression;
}

void generate_exercises(int num_exercises, int max_number, char* operators, int use_parentheses, int use_decimal) {
    for (int i = 0; i < num_exercises; ++i) {
        char* exercise = generate_expression(max_number, operators, use_parentheses, use_decimal);
        printf("题目 %d: %s\n", i + 1, exercise);
        free(exercise);
    }
}

int main() {
    srand((unsigned int)time(NULL));

    int num_exercises, max_number;
    char operators[10];
    int use_parentheses, use_decimal, output_to_file_option;
    char filename[100];

    printf("请输入题目数量：");
    scanf("%d", &num_exercises);

    printf("请输入最大数（如10、100等）：");
    scanf("%d", &max_number);

    printf("请输入运算符 (+ - * / 中的一个或多个，无空格）：");
    scanf("%s", operators);

    printf("是否使用括号？(1为是，0为否)：");
    scanf("%d", &use_parentheses);

    printf("是否使用小数？(1为是，0为否)：");
    scanf("%d", &use_decimal);

    generate_exercises(num_exercises, max_number, operators, use_parentheses, use_decimal);

    return 0;
}
