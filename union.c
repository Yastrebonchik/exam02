#include <unistd.h>

int		main(int argc, char **argv)
{
	char	*s1 = argv[1];
	char 	*s2 = argv[2];
	int		i = 0;
	int		j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[j] != s1[i])
		{
			if (j != i && s1[i] == s1[j])
			{
				j = 0;
				break;
			}
			j++;
		}
		if (j == i)
            write(1, &s1[j], 1);
		i++;
	}
    i = 0;
    while (s2[i] != '\0')
	{
		j = 0;
		while (s1[j] != '\0' && s2[i] != s1[j])
			j++;
		if (s1[j] == '\0')
		{
            j = 0;
            while (s2[j] != s2[i])
		    {
			    if (j != i && s2[i] == s2[j])
			    {
				    j = 0;
				    break;
			    }
			    j++;
		    }
            if (j == i)
                write(1, &s2[j], 1);
		}
		i++;
	}
    write(1, "\n", 1);
    return (0);
}
