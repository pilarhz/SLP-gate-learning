#include <iostream>

const bool TRUTH_TABLE_AND[4] = { 0, 0, 0, 1 };
const bool TRUTH_TABLE_OR[4] = { 0, 1, 1, 1 };
const bool TRUTH_TABLE_NAND[4] = { 1, 1, 1, 0 };
const bool TRUTH_TABLE_NOR[4] = { 1, 0, 0, 0 };

const int INPUTS[4][2] = { { 0, 0 },{ 0, 1 },{ 1, 0 },{ 1, 1 } };

bool LEARNING = true;
unsigned int count = 0;

int x1 = NULL; int x2 = NULL;
int w1 = 0; int w2 = 0; int b = 0; 
int output = NULL; int mistake = NULL; 
bool answer = NULL;


int main()
{
	unsigned int epoch = 1;
	while (LEARNING)
	{
		std::cout << "======= Epoch -  " << epoch << " =======" << std::endl;
		std::cout << "+---+---+---+------------+ " << std::endl;
		std::cout << "| a | b | y | slp-output |" << std::endl;
		std::cout << "+---+---+---+------------+" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			x1 = INPUTS[i][0];
			x2 = INPUTS[i][1];

			output = w1 * x1 + w2 * x2 + b;

			if (output > 0)
				answer = true;
			else
				answer = false;

			if (answer != TRUTH_TABLE_OR[i])
			{
				mistake = (int)TRUTH_TABLE_OR[i] - output;
				w1 = w1 + mistake * x1;
				w2 = w2 + mistake * x2;
				b = b + mistake;
				count = 0;
			}
			else
				count++;

			if (count == 4)
				LEARNING = false;

			std::cout << "| " << x1 << " | " << x2 << " | " 
				<< TRUTH_TABLE_OR[i] << " | " << answer << "          |" << std::endl;
			std::cout << "+---+---+---+------------+" << std::endl << std::endl;
		}
		epoch++;
	}
}