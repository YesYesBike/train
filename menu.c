#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "quiz.h"

int chr2hex(char ch);

void menu_select(void)
{
while (1) {
	char ch;
	printf("Select Menu(0: list)\n> ");
	ch = getchar();
	if (ch == EOF)
		exit(EXIT_SUCCESS);
	else if (ch == '\n')
		continue;
	while (getchar() != '\n')
		;
	if (ch == 'q') exit(EXIT_SUCCESS);
	ch = chr2hex(ch);

	switch (ch) {
	case 0x0:
		menu_list();
		continue;
	case 0x1:
		quiz_hex2bin();
		break;
	case 0x2:
		quiz_bin2hex();
		break;
	case 0xf:
		return;
	}
}
}

void menu_list(void)
{
	printf("1 - Hex to Bin Quiz\n");
	printf("2 - Bin to Hex Quiz\n");
	printf("q - Quit\n");
	printf("\n");
}
