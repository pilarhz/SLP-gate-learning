#include <iostream>
#include <vector>

int main()
{
	int trueTable[4] = { 0, 1, 1, 1 };
	int possIn[4][2] = { { 0, 0 },{ 0, 1 },{ 1, 0 },{ 1, 1 } };

	int x1 = NULL;
	int x2 = NULL;
	int w1 = 0;
	int w2 = 0;
	int b = 0;

	int sum = NULL;
	int answer = NULL;
	int mistake = NULL;
	int label = trueTable[0];

	for (int i = 1; i < 10; i++)
	{
		std::cout << "Epoch - " << i << std::endl;
		for (int j = 0; j < 4; j++)
		{
			x1 = possIn[j][0];
			x2 = possIn[j][1];
			label = trueTable[j];

			//std::cout << "x1 = " << x1 << "| x2 = " << x2 << std::endl;

			sum = w1 * x1 + w2 * x2 + b;

			if (sum > 0)
				answer = 1;
			else
				answer = 0;

			if (answer != label)
			{
				mistake = label - answer;

				w1 = w1 + mistake * x1;
				w2 = w2 + mistake * x2;
				b = b + mistake * 1;
			}

			std::cout << "Answer: " << answer << " Label: " << label << " w1: " << w1 << " w2: " << w2 << " b: " << b << std::endl;
		}
	}
}