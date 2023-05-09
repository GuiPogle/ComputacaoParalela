#include <stdio.h>
#include <gmp.h>

int main(void) 
{
    mpf_set_default_prec(100000);
    mpf_t e, temp, fat;

    mpf_init2(e);
    mpf_init2(temp);
    mpf_init2(fat);

    mpf_set_d(e, 1.0);
    mpf_set_ui(temp, 1);
    mpf_set_ui(fat, 1);

    for(int i = 1; i <=20000; i++)
    {
        mpf_mul_ui(fat, fat, i);
        mpf_div(temp, 1, fat);
        mpf_add(e, e, temp);
    }

    gmp_printf("%.*Ff", 20000, e);
    return 0;
}
