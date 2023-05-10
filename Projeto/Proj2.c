#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <omp.h>

void factorial_list(mpf_t *list, int n);

int main()
{
    int n = 10000;
    mpf_t euler, fat, temp;
    mpf_t *listfat = malloc((n + 1) * sizeof(mpf_t));
    mpf_set_default_prec(1000000);

    mpf_init_set_ui(euler, 1);
    mpf_init_set_ui(fat, 1);
    mpf_init_set_ui(temp, 1);

    factorial_list(listfat, n);
    gmp_printf("Lista Pronta\n");

    #pragma omp parallel for reduction(+:euler) private(fat,temp)
    for(int i = 1; i <= n; i++)
    {
        mpf_set_ui(temp, 1);

        mpf_div(temp, temp, listfat[i]);
        mpf_add(euler, euler, temp);

    }

    gmp_printf("Euler = %.35655Ff\n", euler);

    mpf_clear(euler);
    mpf_clear(fat);
    mpf_clear(temp);

    for (int i = 0; i <= n; i++) {
        mpf_clear(listfat[i]);
    }
    free(listfat);

    return 0;
}

void factorial_list(mpf_t *list, int n)
{
    mpf_t temp;
    mpf_init(temp);

    for (int i = 0; i <= n; i++) {
        mpf_init(list[i]);
        mpf_set_ui(temp, i);
        if (i > 0) {
            mpf_mul(list[i], list[i - 1], temp);
        } else {
            mpf_set_ui(list[i], 1);
        }
    }

    mpf_clear(temp);
}
