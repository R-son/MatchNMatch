// B-CPE-100 : Match //

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int find_char(char const *str, char c)
{
	for (int i = 0; str[i] != '\0'; i++)
		if(str[i] == c)
			return 1;
	return 0;
}

int matching(char const *s1, char const *s2)
{
    int mod = 0;
    char *s2_copy = (char *)s2;

    for (int i = 0; s1[i] != '\0'; i++) {
		if(s2[i] == '*' && !mod) {
			for(int j = i; j < my_strlen(s1); j++)
				s2_copy[j] = '*';
			mod = 1;
		}
		if(s1[i] != s2[i] && s2_copy[i] != '*')
			return 0;
	}
	return 1;
}

int	match(char const *s1, char const *s2)
{
	if(s1[0] == '\0' || s2[0] == '\0')
		return 1;
    if(!find_char(s2, '*') && my_strlen(s1) != my_strlen(s2))
		return 0;
    return matching(s1, s2);
}

#include <stdio.h>

int main(int ac, char **av)
{
    printf("RETURN VALUE : %i", match(av[1], av[2]));
}