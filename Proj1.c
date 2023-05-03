#include <stdio.h>
#include <gmp.h>

int main(void) 
{
    mpf_t e, temp, fat;

    mpf_init2(e, 100000);
    mpf_init2(temp, 100000);
    mpf_init2(fat, 100000);

    mpf_set_d(e, 1.0);
    mpf_set_d(temp, 1.0);
    mpf_set_d(fat, 1.0);

    for(int i = 1; i <= 1000000; i++)
    {
        mpf_mul_ui(fat, fat, i);
        mpf_set_ui(temp, 1);
        mpf_div(temp, temp, fat);
        mpf_add(e, e, temp);
    }

    gmp_printf("%.*Ff", 10000, e);
    return 0;
}

