/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeinado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:36:04 by ppeinado          #+#    #+#             */
/*   Updated: 2024/08/01 18:39:01 by ppeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *s)
{
	size_t n;

	n = 0;
	while(*s)
	{		
		n++;
		s++;
	}
	return (n);
}
char  *ft_strdup(char *s)
{
	int	i;
	char	*dup;
	
	i = 0;
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while(s[i] != '\0')
	{	
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
char *ft_strchr(const char *s, int c)
{
	unsigned char x;

	x = c;
	while (*s != '\0' && *s != x)
		++s;
	if (*s != x)
		return (NULL);
	return (char*)(s);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *p;
        int             i;

        i = 0;
        if (ft_strlen(s) < start)
                return (ft_strdup(""));
        if (ft_strlen(s + start) < len)
                len = ft_strlen(s + start);
        p = malloc (sizeof(char) * (len + 1));
        if (p != NULL)
        {
                while (len > 0 && s[start] != '\0')
                {
                        p[i] = s[start];
                        start++;
                        i++;
                        len--;
                }
                p[i] = '\0';
        }
        return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int	i;
	int	j;


	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if(!ret)
		return (NULL);
	i = 0;
	while(s1[i])
	{	
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while(s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return(ret);
}
/*
int main(void)
{
	printf("%s",ft_strjoin("hola","patata"));
	return(0);
}*/
