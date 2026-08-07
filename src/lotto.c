#include <stdio.h>

void input_nums(int *lotto);
void print_nums(int *lotto);

int main(int argc, char const *argv[])
{
    int lotto_nums[6];

    input_nums(lotto_nums);
    print_nums(lotto_nums);

    return 0;
}

void input_nums(int *lotto)
{
    int num;
    int duplicate;

    for (int i = 0; i < 6; i++)
    {
        printf("번호 입력: ");
        scanf("%d", &num);

        duplicate = 0;

        for (int j = 0; j < i; j++)
        {
            if (num == lotto[j])
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
        {
            lotto[i] = num;
        }
        else
        {
            printf("같은 번호가 있습니다.\n");
            i--;
        }
    }
}

void print_nums(int *lotto)
{
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", lotto[i]);
    }
}
