/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 23:38:21 by qsymond           #+#    #+#             */
/*   Updated: 2020/08/14 21:31:44 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fd, char *str, int size);
size_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(char *str);

char *ft_strnew(int size, char c)
{
	char *new;

	new = malloc(sizeof(char) * (size + 1));
	new[size] = '\0';
	while (size--)
		new[size] = c;
	return (new);
}

int main(void)
{
    //TEST STRLEN
	int n1 = ft_strlen("");
	int n2 = strlen("");
	printf("ft_strlen : %d\t\tstrlen : %d\n", n1, n2);
	n1 = ft_strlen("Moscow never sleepMoscow never sleepMoscow never sleepMoscow never sleepMoscow never sleepMoscow never sleepMoscow never sleepMoscow never sleepMoscow never sleep");
	n2 = strlen("Moscow never sleepMoscow never sleepMoscow never sleepMoscow never sleepMoscow never sleepMoscow never sleepMoscow never sleepMoscow never sleepMoscow never sleep");
	printf("ft_strlen : %d\t\tstrlen : %d\n", n1, n2);
	//TEST STRCPY
	char *src = ft_strnew(0, 'A');
	char *dest1 = ft_strnew(12, '1');
	char *dest2 = ft_strnew(12, '1');
	printf("ft_strcpy : %s\tstrcpy : %s\n", ft_strcpy(dest1, src), strcpy(dest2, src));
	src = ft_strnew(100, 'A');
	dest1 = ft_strnew(12, '1');
	dest2 = ft_strnew(12, '1');
	printf("ft_strcpy : %s\tstrcpy : %s\n", ft_strcpy(dest1, src), strcpy(dest2, src));
	free(src);
	free(dest1);
	free(dest2);
    //TEST STRCMP
	char *str1 = "";
	char *str2 = "Moscow2 ca va";
	printf("ft_strcmp : %d\t\tstrcmp : %d\n", ft_strcmp(str1, str2), strcmp(str1, str2));
	str1 = "Moscow2 ca va";
	str2 = "";
	printf("ft_strcmp : %d\t\tstrcmp : %d\n", ft_strcmp(str1, str2), strcmp(str1, str2));
	//TEST WRITE
	ft_write(1, "ft_write  : test\t", 18);
	write(1, "ft_write  : test\t\n", 18);
	char q = 'a';
	write(566, &q, 1);
	perror("skfhdskfdfs");
	printf("%d\n", errno);
	ft_write(566, &q, 1);
	perror("skfhdskfdfs");
	printf("%d", errno);
    //TEST READ
	int fd = open("main.c", O_RDONLY);
	char *buffer = ft_strnew(6, '\0');
	n1 = ft_read(fd, buffer, 5);
	n2 = read(fd, buffer, 5);
	printf("ft_read : [%d] %s\tread : [%d] %s\n", n1, buffer, n2, buffer);
	free(buffer);
    //TEST STRDUP
	char *str3 = ft_strdup("");
	char *str4 = ft_strdup("");
	printf("ft_strdup : %s\tstrdup : %s\n", str3, str4);
	free(str3);
	free(str4);
	str3 = ft_strdup("Moscow_school_21Moscow_school_21Moscow_school_21Moscow_school_21Moscow_school_21");
	str4 = ft_strdup("Moscow_school_21Moscow_school_21Moscow_school_21Moscow_school_21Moscow_school_21");
	printf("ft_strdup : %s\tstrdup : %s\n", str3, str4);
	free(str3);
	free(str4);
	return(0);
}