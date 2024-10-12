#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quiz.h"

#define HEX_ARR_LEN		16
#define BUFSIZE			5

char hex_digit[] = {
	'0', '1', '2', '3',
	'4', '5', '6', '7',
	'8', '9', 'A', 'B',
	'C', 'D', 'E', 'F',
};

int bin_decode(int hex)
{
	int ret = 0;

	if (hex&0b1000)
		ret += 1000;
	if (hex&0b100)
		ret += 100;
	if (hex&0b10)
		ret += 10;
	if (hex&0b1)
		ret += 1;

	return ret;
}

void quiz_hex2bin(void)
{
/* Why I used goto here
 * 1. I don't want to reset number while keep pressing enter
 * 2. See menu_select()
 * 3. I don't have a skill to write a good code
 */
L_HEX_START:
	srand((unsigned)time(0));
	int que = rand() % HEX_ARR_LEN;
	char ch = hex_digit[que];
	char buf[BUFSIZE];

L_HEX_ENTER_NUMBER:
	printf("%c: Enter the binary number\n> ", ch);
	fgets(buf, BUFSIZE, stdin);
	if (buf != NULL) {
		int i = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;
		if (buf[i] == '\n')
			buf[i] = '\0';
		else
			while (getchar() != '\n')
				;
	}

	if (buf[0] == 0)
		goto L_HEX_ENTER_NUMBER;
	else if (buf[0] == 'q')
		return;

	for (int i=0; i<BUFSIZE-1; i++) {
		if (buf[i] == '\0')
			break;
		if (buf[i] != '0' && buf[i] != '1') {
			printf("Enter the right number!!\n");
			goto L_HEX_ENTER_NUMBER;
		}
	}

	int ans = strtol(buf, NULL, 2);
	if (ans == que)
		printf("Correct!\n");
	else
		printf("Wrong! Correct Answer: %04d\n", bin_decode(que));
	goto L_HEX_START;
}

void quiz_bin2hex(void)
{
while (1) {
	srand((unsigned)time(0));
	int que = rand() % HEX_ARR_LEN;
	int ans;
	char ch;

	printf("%04d: Enter the hex number\n> ", bin_decode(que));
	while (scanf("%x", &ans) != 1) {
		while ((ch = getchar()) != '\n')
			if (ch == EOF) return;
		printf("%04d: Enter the hex number\n> ", bin_decode(que));
	}
	while (getchar() != '\n')
		;

	if (ans == que)
		printf("Correct!\n");
	else
		printf("Wrong! Correct Answer: %x\n", que);
}
}
