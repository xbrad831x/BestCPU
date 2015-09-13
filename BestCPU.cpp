// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include <stdlib.h>

char* fetch(char* address, char *mem[][32]);
void store(char* addres, char *memory[][32], char* register_value);

char num_value[3] = { 0 };


int main()
{
	
	int program_counter;
	char* tmp_reg;
	char reg[20] = { 0 };
	char *memory[50][32] = { 0 };
	char * num_value = "00";
	char * fetch_value = "FE";
	char * store_value = "ST";
	char cpu_memory[30] = { 0 };
	for (int i = 0; i < 49; i++)
	{
		for (int j = 7; j <= 31; j = j + 8)
		{
			memory[i][j] = { "00" };
		}

	}

	memory[10][7] = { "00" };
	memory[10][15] = { "FE" };
	memory[10][23] = { "00" };
	memory[10][31] = { "16" };

	memory[15][7] = { "00" };
	memory[15][15] = { "ST" };
	memory[15][23] = { "00" };
	memory[15][31] = { "20" };

	memory[16][7] = { "00" };
	memory[16][15] = { "00" };
	memory[16][23] = { "00" };
	memory[16][31] = { "34" };

	memory[21][7] = { "00" };
	memory[21][15] = { "FE" };
	memory[21][23] = { "00" };
	memory[21][31] = { "27" };

	memory[24][7] = { "00" };
	memory[24][15] = { "ST" };
	memory[24][23] = { "00" };
	memory[24][31] = { "37" };

	memory[27][7] = { "00" };
	memory[27][15] = { "00" };
	memory[27][23] = { "00" };
	memory[27][31] = { "50" };

	for (program_counter = 0; program_counter < 49; program_counter++)
	{
		printf("Program Counter: %i\n", program_counter);

		if (strcmp(memory[program_counter][15], "00") == 0)
			continue;
		else if (strcmp(memory[program_counter][15], "FE") == 0)
		{
			tmp_reg = fetch(memory[program_counter][31], memory);
			strcpy_s(reg, "00 00 00 ");
			strcat_s(reg, tmp_reg);
			printf("The value in the register: %s\n", reg);
		}
		else if (strcmp(memory[program_counter][15], "ST") == 0)
		{
			printf("The value of reg: %s\n", reg);
			store(memory[program_counter][31], memory, reg);
		}
		else
			printf("Unknown error occured");

		for (int k = 0; k < 49; k++)
		{

			strcpy_s(cpu_memory, memory[k][7]);
			strcat_s(cpu_memory, " ");
			strcat_s(cpu_memory, memory[k][15]);
			strcat_s(cpu_memory, " ");
			strcat_s(cpu_memory, memory[k][23]);
			strcat_s(cpu_memory, " ");
			strcat_s(cpu_memory, memory[k][31]);

			printf("%s\n", cpu_memory);
		}

	}

	printf("Program Terminated.\n");

    return 0;
}

char* fetch(char* address, char *memory[][32])
{
	int index = atoi(address);
	return memory[index][31];
}

void store(char* address, char *mem[][32], char* register_value)
{
	memcpy(num_value, &register_value[9], 2);
	num_value[2] = '\0';
	int index = atoi(address);
	mem[index][31] = num_value;

}
