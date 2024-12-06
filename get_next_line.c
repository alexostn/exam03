#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	i = 0;
	while (src[i])//вычисляем длину стринга
		i++;//аллоцируем под новый стринг + '\0'
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;//обнуляем
	while (src[i])//копируем пока src[i]
	{
	   dest[i] = src[i];
	   i++;
	}
	dest[i] = '\0';//завершаем нулем
	return (dest);//возвращаем копию стринга без *
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	line[8000000];
	int		b;
	int		i;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	b = read(fd, &buffer, 1);//czy ma czytac BUFFER_SIZE czy 1 //2) without & : b = read(fd, buffer, 1);
	while (b > 0)
	{
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
		b = read(fd, &buffer, 1);
	}
	line[i] = '\0';
	if (b <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int main()
{
	char* proverka;
	int fd = open("chapter24.txt", O_RDONLY);
	proverka = get_next_line(fd);
	printf("%s", proverka);
	free(proverka);
		proverka = get_next_line(fd);
	printf("%s", proverka);
	free(proverka);
		proverka = get_next_line(fd);
	printf("%s", proverka);
	free(proverka);
		proverka = get_next_line(fd);
	printf("%s", proverka);
	free(proverka);

		proverka = get_next_line(fd);
	printf("%s", proverka);
	free(proverka);
		proverka = get_next_line(fd);
	printf("%s", proverka);
	free(proverka);
	return (0);
}
