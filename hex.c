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

int chr2hex(char ch)
{
	switch (ch) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return ch - 48;

	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
		return ch - 87;

	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
		return ch - 55;
	}
}

void quiz_hex2bin(void)
{
L_HEX_START:
	srand((unsigned)time(0));
	int que = rand() % HEX_ARR_LEN;
	char ch = hex_digit[que];
	char buf[BUFSIZE];

L_HEX_ENTER_NUMBER:
	printf("%c: Enter the binary number   (m: main, q: quit)\n> ", ch);
	if (fgets(buf, BUFSIZE, stdin) != NULL) {
		int i = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;
		if (buf[i] == '\n')
			buf[i] = '\0';
		else
			while (getchar() != '\n')
				;
	} else {
		exit(EXIT_SUCCESS);
	}

	if (buf[0] == 0)
		goto L_HEX_ENTER_NUMBER;
	else if (buf[0] == 'q')
		exit(EXIT_SUCCESS);
	else if (buf[0] == 'm')
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
	char ans;

	printf("%04d: Enter the hex number   (m: main, q: quit)\n> ", bin_decode(que));
	ans = getchar();
	if (ans == EOF)
		exit(EXIT_SUCCESS);
	else if (ans == '\n')
		continue;
	while (getchar() != '\n')
		;
	if (ans == 'q')
		exit(EXIT_SUCCESS);
	else if (ans == 'm')
		return;
	ans = chr2hex(ans);

	if (ans == que)
		printf("Correct!\n");
	else
		printf("Wrong! Correct Answer: %x\n", que);
}
}
