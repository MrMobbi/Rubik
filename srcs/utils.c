#include "../incl/rubik.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned int	i;

	i = 0;
	if (start > strlen(str))
	{
		cpy = malloc(sizeof(char) * 1);
		if (!cpy)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	if (len > strlen(str) - start)
		len = strlen(str) - start;
	cpy = malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	while (i < len && str[start] != '\0')
	{
		cpy[i] = str[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*dup;

	dup = malloc(sizeof(char) * strlen(s1) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

unsigned int	ft_count_word(const char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!str[0] || !str)
		return (0);
	while (str[i + 1] != '\0')
	{
		if (str[i + 1] == c && str[i] != c)
			count++;
		i++;
	}
	if (str[i] != c)
		count++;
	return (count);
}

unsigned int	ft_strlen_c(const char *str, unsigned int index, char c)
{
	unsigned int	len;

	len = 0;
	while (str[index] != c && str[index] != '\0' && str[index] != '\n')
	{
		index++;
		len++;
	}
	return (len);
}

unsigned int	ft_find_next_word(const char *str, unsigned int index, char c)
{
	while (str[index] != c && str[index] != '\0')
		index++;
	while (str[index] == c && str[index] != '\0')
		index++;
	return (index);
}

char	**ft_split(char const *str, char c)
{
	unsigned int	index;
	unsigned int	i;
	char			**split;

	split = calloc(ft_count_word(str, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	index = 0;
	i = 0;
	if (str[0] == c)
		index = ft_find_next_word(str, index, c);
	while (i < ft_count_word(str, c))
	{
		split[i] = ft_substr(str, index, ft_strlen_c(str, index, c));
		index = ft_find_next_word(str, index, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
