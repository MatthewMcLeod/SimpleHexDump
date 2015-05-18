#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE *infile;
	int /*cont = 0,*/characters = 0, n = 0,/*test = 1,*/remain, m, x;
	int char_array[15];
	char letter_arr[15];
	unsigned char letter;

	printf(" Offset                        Bytes                          Characters   \n");
	printf("--------  -----------------------------------------------  ----------------\n");
	infile = fopen("inputfile", "r");

	// Run while not end of file
	while (!feof(infile))
	{
		printf("%08x  ", characters);
		
		for (n = 0; n<16; n++, characters++)
		{
			fscanf(infile, "%c", &letter);
			if (feof(infile) != 0)
			{
				break;
			}

			// Prints out the byte value of each letter
			// Stores each section of 16 bytes into two arays
			if isprint(letter)
			{
				char_array[n] = (int)letter;
				printf("%02x ", char_array[n]);
				char_array[n] = 0;
				letter_arr[n] = letter;
			}
			else
			{
				char_array[n] = (int)letter;
				printf("%02x ", char_array[n]);
				char_array[n] = 0;
				letter_arr[n] = (char)46;
			}

		}

		// Prints out the acutal letters of the read text
		remain = 16 - n;
		for (m = 0; m<remain; m++)
		{
			printf("   ");
		}
		printf(" ");
		for (x = 0; x<n; x++)
		{
			printf("%c", letter_arr[x]);
			letter_arr[x] = 0;
		}
		for (m = 0; m<remain; m++)
		{
			printf(" ");
		}
		printf("\n");
	}
	fclose(infile);
	return 0;
}
