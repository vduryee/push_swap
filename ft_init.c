/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:15:39 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/19 10:17:45 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"

/*  
    conv_int: convertis les argv en int, return 1 et stocke
    la nouvelle valeur dans voodoo (tkt c'est magique)
    return 0 si l'input est invalide, ou si > int | < int
*/
static	int	conv_int(const char *s, int *voodoo)
{
	long	n;
	int		sign;

	sign = 1;
	n = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign *= -1;
	}
	if (*s < '0' || *s > '9')
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
	}
	if (*s)
		return (0);
	*voodoo = (int)(n * sign);
	return (1);
}
/*
    fill_stack: permet de remplir la stack (no s* Sherlock)
    le HAUT de la stack est values[size - 1], et le premier argv
    non flag doit etre sur le dessus. Donc args[i] -> 
    values[n - 1 - i].
    Ex: "42 0 -24" -> values = {-24, 0, 42}, values[2] = 42;
    
    ------------

    Pour chaque argument recu:
    - conv_int s'occupe d'ignorer les inputs non valide;
    - la boucle interieure le compare avec les i valeurs deja stocke
    (n - 1 - j pour i > j) return 0 s'il y a un doublon.

    On set la size a la fin, elle reste a 0 s'il y a une erreur.
*/

static	int	fill_stack(t_stack *a, size_t n, char **args)
{
	size_t	i;
	size_t	j;
	int		voodoo;

	i = 0;
	while (n > i)
	{
		if (!conv_int(args[i], &voodoo))
			return (0);
		j = 0;
		while (i > j)
		{
			if (a->values[n - 1 - j] == voodoo)
				return (0);
			j++;
		}
		a->values[n - 1 - i] = voodoo;
		i++;
	}
	a->size = n;
	return (1);
}

/*
    stack_init: ca init la stack pas grand chose a dire la dessus
*/
static	int	stack_init(t_stack *s, size_t n)
{
	s->values = malloc(sizeof(int) * (n + 1));
	if (s->values == NULL)
		return (0);
	s->size = 0;
	s->capacity = n;
	return (1);
}

/*
    ft_init: le chad qui init tout, apparition sauvage d'une stack
    qui carry des stacks (elle est ou la corde svp?)
    fonctionne uniquement quand ac >= 2 (sauf pour av[1] le coquin)
    
    ------

    Bon sinon, les deux pointeurs values sont set a NULL pour free
    plus tard si ca fail. (t_counter){0} init toutes les valeurs de la
    struct a 0, a voir si c'est norminette friendly.
    Si av[1] est un flag, on commence a av[2] avec le flag demande,
    par default utilise l'adaptive et commence a av[1].
    
    En ecrivant ceci je viens de me rapeller qu'il faut inclure le bench
    jpp.

    Ca alloue les deux stack avec ac - fst (le nombre d'args convertis
    en int), rempli la stack a.
*/

int	check_flags(t_data *d, char **av)
{
	int	fst;

	fst = 1;
	d->algo = algo_selector(av[1]);
	d->bench = bench_check(av[2]);
	if (d->algo != -1)
	{
		if (d->bench != 0)
			fst = 3;
		else
			fst = 2;
	}
	else
	{
		d->algo = 0;
		d->bench = 0;
		if(bench_check(av[1]))
		{
			d->bench = 1;
			fst = 2;
		}
	}
	return (fst);
}

int	ft_init(t_data *d, int ac, char **av)
{
	int	fst;

	fst = check_flags(d, av);
	d->a.values = NULL;
	d->b.values = NULL;
	d->count = (t_counter){0};
	if (!stack_init(&d->a, ac - fst) || !stack_init(&d->b, ac - fst))
		return (0);
	return (fill_stack(&d->a, ac - fst, av + fst));
}
