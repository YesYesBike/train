#include <stdio.h>
#include "menu.h"
#include "quiz.h"

void menu_select(void)
{
/* just use goto */
while (1) {
	int sel;
	char ch;
	printf("Select Menu(0: list)\n> ");
	while (scanf("%x", &sel) != 1) {
		while ((ch = getchar()) != '\n')
			if (ch == EOF) return;
		printf("Select Menu(0: list)\n> ");
	}
	while (getchar() != '\n')
		;

	switch (sel) {
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
	printf("f - Quit\n");
	printf("\n");
}
