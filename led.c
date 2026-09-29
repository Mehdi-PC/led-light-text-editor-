#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		puts("ERROR: no filename given as argument");
		return 1;
	}
	else if(argc > 2)
	{
		puts("ERROR: too many arguments");
		return 1;
	}
	if(strcmp(argv[1], "--help") == 0)
	{
		puts("led [filename]\nto exit you have to press CTRL+V then CTRL+Q and press Enter");
		return 0;
	}
	FILE* text_file = fopen(argv[1], "w");
	if(text_file == NULL)
	{
		perror("Cant open file");
		return 1;
	}
	char last_char;
	while(true)
	{
		last_char = getchar();
		if(last_char == '\x11')
		{
			break;
		}
		fwrite(&last_char, sizeof(char), 1, text_file);
	}
	return 0;
}
