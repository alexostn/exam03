#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
	   dest[i] = src[i];
	   i++;
	}
	dest[i] = '\0';
	return (dest);
}
// Функция читает следующую строку из файла с дескриптором fd
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];// Статический буфер для чтения
	char		line[700000];		// Массив для текущей строки
	static int	buffer_read;		// Количество прочитанных байт в буфер
	static int 	buffer_pos;			// Текущая позиция в буфере
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)//Проверяем валидность дескриптора и размера буфера
		return (NULL);
	while (1)
	{// Если все данные из буфера прочитаны, читаем новые
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;//буфер заполняется новыми даными нужно начать с начала буфера
			if (buffer_read <= 0)// Если ничего не прочитали, выходим из цикла
				break ;
		}// Если символ новой строки, выходим из цикла
		if (buffer[buffer_pos] == '\n')
		{
			buffer_pos++; // Пропускаем символ новой строки?
			break ;
		}
		line[i] = buffer[buffer_pos++];// Копируем символ из буфера в line
		i++;
	}// Добавляем завершающий нулевой символ
	line[i] = '\0';
	if (i == 0)// Если строка пустая, возвращаем NULL
		return (NULL);
	return (ft_strdup(line));// Возвращаем копию строки line
}

int main()
{
	char* pointer;
	int fd = open("chapter24.txt", O_RDONLY);

	pointer = get_next_line(fd);
	printf("%s\n", pointer);
	free(pointer);

	pointer = get_next_line(fd);
	printf("%s\n", pointer);
	free(pointer);

	pointer = get_next_line(fd);
	printf("%s\n", pointer);
	free(pointer);

	pointer = get_next_line(fd);
	printf("%s\n", pointer);
	free(pointer);

	pointer = get_next_line(fd);
	printf("%s\n", pointer);
	free(pointer);

	pointer = get_next_line(fd);
	printf("%s\n", pointer);
	free(pointer);
	close(fd);
	return (0);
}
