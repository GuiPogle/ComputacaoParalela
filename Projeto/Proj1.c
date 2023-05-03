#include <stdio.h>
#include <gmp.h>

int main(void) 
{
    mpf_t e, temp, fat;

    mpf_init2(e, 10000);
    mpf_init2(temp, 64);
    mpf_init2(fat, 64);

    mpf_set_d(e, 1.0);
    mpf_set_ui(temp, 1);
    mpf_set_ui(fat, 1);

    for(int i = 1; i <= 10000; i++)
    {
        mpf_mul_ui(fat, fat, i);
        mpf_div(temp, temp, fat);
        mpf_add(e, e, temp);
    }

    gmp_printf("%.*Ff", 10000, e);
    return 0;
}
