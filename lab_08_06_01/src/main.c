#include "matrix.h"
#include "operations.h"

int main()
{
    int rc = EXIT_SUCCESS;
    int m, n, p, q;
    int **a, **b;
    if ((rc = read_dimension(&m, &n)))
        return rc;
    a = allocate_matrix(m, n);
    if (!a)
        return ALLOCATE_ERR;
    if ((rc = read(a, m, n)))  
    {
        free_matrix(a, m);
        return rc;
    }

    if ((rc = read_dimension(&p, &q)))
    {
        free_matrix(a, m);
        return rc;
    }
    b = allocate_matrix(p, q);
    if (!b)
    {
        free_matrix(a, m);
        return ALLOCATE_ERR;
    }
    if ((rc = read(b, p, q)))  
    {
        free_matrix(a, m);
        free_matrix(b, p);
        return rc;
    }

    int orig_m = m, orig_p = p;

    square(a, &m, &n);
    square(b, &p, &q);

    int z = m;
    if (p > z)
        z = p;

    int **sqrt_a = allocate_matrix(z, z);
    if (!sqrt_a)
    {
        free_matrix(a, orig_m);
        free_matrix(b, orig_p);
        return ALLOCATE_ERR;
    }
    int **sqrt_b = allocate_matrix(z, z);
    if (!sqrt_b)
    {
        free_matrix(a, orig_m);
        free_matrix(b, orig_p);
        free_matrix(sqrt_a, z);
        return ALLOCATE_ERR;
    }

    for (int i = 0; i < m; i++)
        memmove(sqrt_a[i], a[i], n * sizeof(int));
    for (int i = 0; i < p; i++)
        memmove(sqrt_b[i], b[i], q * sizeof(int));
    
    free_matrix(a, orig_m);
    free_matrix(b, orig_p);
    
    append(sqrt_a, sqrt_b, &m, &n, &p, &q);

    int pow1, pow2;
    if (scanf("%d%d", &pow1, &pow2) != 2)
    {
        free_matrix(sqrt_a, z);
        free_matrix(sqrt_b, z);
        return READ_ERR;
    }
    if (pow1 < 0 || pow2 < 0)
    {
        free_matrix(sqrt_a, z);
        free_matrix(sqrt_b, z);
        return POW_ERR;
    }
    if (!pow1)
        make_identity(sqrt_a, z);
    if (!pow2)
        make_identity(sqrt_b, z);
    
    int **ans = allocate_matrix(z, z);
    if (!ans)
    {
        free_matrix(sqrt_a, z);
        free_matrix(sqrt_b, z);
        return ALLOCATE_ERR;
    }
    for (int i = 0; i < z; i++)
        memmove(ans[i], sqrt_a[i], z * sizeof(int));

    int **temp_res = allocate_matrix(z, z);
    if (!temp_res)
    {
        free_matrix(sqrt_a, z);
        free_matrix(sqrt_b, p);
        free_matrix(ans, z);
        return ALLOCATE_ERR;
    }

    while (pow1 > 1)
    {
        square_prod(ans, sqrt_a, temp_res, z);
        for (int i = 0; i < z; i++)
            memmove(ans[i], temp_res[i], z * sizeof(int));
        pow1--;
    }
    while (pow2 >= 1)
    {
        square_prod(ans, sqrt_b, temp_res, z);
        for (int i = 0; i < z; i++)
            memmove(ans[i], temp_res[i], z * sizeof(int));
        pow2--;
    }
    print(ans, z, z);
    free_matrix(sqrt_a, z);
    free_matrix(sqrt_b, z);
    free_matrix(temp_res, z);
    free_matrix(ans, z);
    return EXIT_SUCCESS;
}