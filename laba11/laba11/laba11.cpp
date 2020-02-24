#include <stdio.h>
#include <ctime>
#include <Windows.h>
#include <cstdlib>
#define SIZE 256


void ConcatString(char* o_str, int* io_pos, char* i_str, int i_begin_pos, int i_end_pos)
{
	if (*io_pos > 0)
	{
		o_str[*io_pos] = ' ';
		(*io_pos)++;
	}
	for (int i = i_begin_pos; i < i_end_pos; ++i)
	{
		o_str[*io_pos] = i_str[i];
		(*io_pos)++;
	}
}

bool ShoudDeleteWordHelp(char* i_str, int i_begin_pos, int i_end_pos, char* check_str)
{
	int check_size = sizeof(check_str) / sizeof(check_str[0])-1;
	int word_size = i_end_pos - i_begin_pos;
	if (word_size < check_size)
		return false;
	int check_pos = 0;
	for (int word_pos = i_end_pos - check_size; word_pos < i_end_pos; ++word_pos)
	{
		if (i_str[word_pos] != check_str[check_pos])
			return false;
		++check_pos;
	}
	return true;
}

bool ShoudDeleteWord(char* i_str, int i_begin_pos, int i_end_pos)
{
	char check_str1[] = "tur";
	char check_str2[] = "ter";
	if (!ShoudDeleteWordHelp(i_str, i_begin_pos, i_end_pos, check_str1))
		return ShoudDeleteWordHelp(i_str, i_begin_pos, i_end_pos, check_str2);
	return true;
}

int main() {
	char input_str[SIZE];
	char output_str[SIZE]="\n";
	int i = 0;
	int begin_word = 0;
	int end_word = 0;
	int output_pos = 0;
	char cur_ch;
	gets_s(input_str, SIZE);
	while (true)
	{
		cur_ch = input_str[i];
		if ((cur_ch == ' ') || (cur_ch == '\0'))
			end_word = i;
		if (begin_word < end_word)
		{
			bool is_space = (end_word - begin_word == 1) && (input_str[begin_word] == ' ');
			if (!is_space)
			{
				bool is_delete_word = ShoudDeleteWord(input_str, begin_word, end_word);
				if (!is_delete_word)
					ConcatString(output_str, &output_pos, input_str, begin_word, end_word);
			}
			begin_word = end_word + 1;
		}

		if (cur_ch == '\0')
			break;
		++i;
	}
	output_str[output_pos] = '\0';
	printf(output_str);

}