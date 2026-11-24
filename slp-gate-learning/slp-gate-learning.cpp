#include <iostream>
#include <conio.h> 

const bool TRUTH_TABLE_AND[4] = { 0, 0, 0, 1 };
const bool TRUTH_TABLE_OR[4] = { 0, 1, 1, 1 };
const bool TRUTH_TABLE_NAND[4] = { 1, 1, 1, 0 };
const bool TRUTH_TABLE_NOR[4] = { 1, 0, 0, 0 };

const int INPUTS[4][2] = { { 0, 0 },{ 0, 1 },{ 1, 0 },{ 1, 1 } };

void CopyTruthTable(const bool source[4], bool dest[4])
{
	for (int i = 0; i < 4; i++)
		dest[i] = source[i];
}

void LearningGate(bool table[4])
{
	system("cls");

	unsigned int epoch = 1;
	bool learning = true;
	unsigned int count = 0;
	int x1 = NULL; int x2 = NULL;
	int w1 = 0; int w2 = 0; int b = 0;
	int output = NULL; int mistake = NULL;
	bool answer = NULL;

	while (learning)
	{
		std::cout << "======= Epoch -  " << epoch << " =======" << std::endl;
		std::cout << "| a | b || y | slp ||" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			x1 = INPUTS[i][0];
			x2 = INPUTS[i][1];

			output = w1 * x1 + w2 * x2 + b;

			if (output > 0)
				answer = true;
			else
				answer = false;

			if (answer != table[i])
			{
				mistake = (int)table[i] - output;
				w1 = w1 + mistake * x1;
				w2 = w2 + mistake * x2;
				b = b + mistake;
				count = 0;
			}
			else
				count++;

			if (count == 4)
				learning = false;

			std::cout << "| " << x1 << " | " << x2 << " || "
				<< table[i] << " |  " << answer << "  || "
				<< w1 << " | " << w2 << " | " << b << " | " << std::endl;
		}
		epoch++;
	}
	learning = true;
}

int main()
{
	bool truTable[4] = {};
	while (true)
	{
		std::cout << "Choose gate for SLP to learn: " << std::endl;
		std::cout << "1 - AND" << std::endl;
		std::cout << "2 - OR" << std::endl;
		std::cout << "3 - NAND" << std::endl;
		std::cout << "4 - NOR" << std::endl;
		std::cout << "q - quit" << std::endl;

		char key = _getch();

		switch (key)
		{
		case '1':
			CopyTruthTable(TRUTH_TABLE_AND, truTable); 
			LearningGate(truTable); 
			break;
		case '2':
			CopyTruthTable(TRUTH_TABLE_OR, truTable); 
			LearningGate(truTable);
			break;
		case '3':
			CopyTruthTable(TRUTH_TABLE_NAND, truTable); 
			LearningGate(truTable);
			break;
		case '4':
			CopyTruthTable(TRUTH_TABLE_NOR, truTable); 
			LearningGate(truTable);
			break;
		case 'q':
			return 0; break;
		default:
			std::cout << "Use option from menu" << std::endl; system("pause");
			break;
		}

		system("pause");
		system("cls");
	}
}