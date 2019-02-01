#include "generators.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>

struct { unsigned char value : 6; } six;

void checksum(BYTE* password)
{
	size_t total = 0;
	for (int i = 0; i < 17; i++)
		total += password[i];
	password[17] = total & 0xff;
}

/* Flawed implementation, and isn't needed for random password generation either
void shift_byte(BYTE* password)
{
	for (int i = 0; i < password[16]; i++)
	{
		BYTE carry = 0;
		for (int j = 0; j < 16; j++)
		{
			if (carry != 0)
				password[j] &= carry;
			carry = password[j] & 1;
			carry = (carry == 1) ? 0xff : 0x7f;
			password[j] = password[j] >> 1;
		}
		password[0] &= carry;
	}
}
*/

void metroid()
{
	BYTE password[18];
	srand(time(NULL));

	for (int i = 0; i < 16; i++)
		password[i] = rand() % 0xff;
	password[16] = 0;

	checksum(password);
//	shift_byte(password);

	BYTE unravel[144];
	BYTE z = 0;
	for (BYTE x = 0; x < 18; x++)
	{
		for (BYTE y = 0; y < 8; y++)
		{
			BYTE temp = password[x];
			temp = temp << y;
			temp = temp >> 7;
			unravel[z] = temp;
			z++;
		}
	}

	z = 0;
	char m_alphabet[64] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz?-";
	for (int i = 0; i < 24; i++)
	{
		six.value = 0;
		for (int j = 5; j >= 0; j--)
		{
			BYTE temp = unravel[z] << j;
			six.value |= temp;
			z++;
		}
		printf("%c", m_alphabet[six.value]);
		if ((i+1) % 6 == 0)
			printf("\t");
	}
}