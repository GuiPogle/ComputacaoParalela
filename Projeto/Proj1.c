#include <stdio.h>
#include <gmp.h>

int main()
{
    mpf_t euler, fat, temp;
    mpf_set_default_prec(1000000);

    mpf_init_set_ui(euler, 1);
    mpf_init_set_ui(fat, 1);
    mpf_init_set_ui(temp, 1);

    for(int i = 1; i < 10000; i++)
    {
        mpf_set_ui(temp, 1);
        mpf_mul_ui(fat, fat, i);
        mpf_div(temp, temp, fat);
        mpf_add(euler, euler, temp);
    }

    gmp_printf("Euler = %*.35655Ff\n", 0, euler);

    mpf_clear(euler);
    mpf_clear(fat);
    mpf_clear(temp);

    return 0;
}
