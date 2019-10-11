#ifndef FT_BIGINT_H
#define FT_BIGINT_H
#include <stdint.h>
#include <stdio.h>

#define MAX_BLOCKS 34000
typedef struct	s_bigint
{
	int			len;
	uint32_t	arr[MAX_BLOCKS];
}				t_bigint;

void			ft_bigint_get(t_bigint *res, uint64_t a);
int				ft_bigint_cmp(const t_bigint *a, const t_bigint *b);
void			ft_bigint_copy(t_bigint *dst, const t_bigint *src);
void			ft_bigint_sum(t_bigint *res, const t_bigint *a,
				const t_bigint *b);
void			ft_bigint_mult(t_bigint *res, const t_bigint *a,
				const t_bigint *b);
void			ft_bigint_pow2(t_bigint *res, int32_t exp);
void			ft_bigint_pow5(t_bigint *res, int32_t exp);
void			get_double(double value, int *sign, uint64_t *frac, int *exp);
void			print_bigint(t_bigint *a);

#endif
