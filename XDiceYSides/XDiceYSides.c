#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//This function finds the number of occurances of combinations of the dice
void findSumFrequencyOfCombinations(int sidesOfDice, int numberOfDice, int*StateOfEachDiceList, int*listOfCombinationFrequencies);

//This function creates empty list with the high value of the range + 1
//lowest value in range is trash
int* createCombinationList(int sidesOfDice, int numberOfDice);

//Creates list of the state of each dice.
//initialized to 1 as default values
int* createDiceList(int numberOfDice);

//Prints list of Combinations and Frequencies of them
void printList(int sidesOfDice, int numberOfDice, int* listOfCombinationFrequencies);

//Validation
void sumFrequencyOfCombinationsIsAccurate(int sidesOfDice, int numberOfDice, int* listOfCombinationFrequencies);

//Return sum of Dice
int findSumOfDice(int* StateOfEachDiceList, int numberOfDice);

//Free memory
void freeMemory(int* ListOfCombinationFrequencies, int*StateOfEachDiceList);

int setNumberOfDice();

int setNumberOfSides();


int main()
{
	int numberOfDice,
		numberOfSides,
		*diceList,
		*CombinationList;

	numberOfDice = setNumberOfDice();
	numberOfSides = setNumberOfSides();

	diceList = createDiceList(numberOfDice);
	CombinationList = createCombinationList(numberOfSides, numberOfDice);

	findSumFrequencyOfCombinations(numberOfSides, numberOfDice, diceList, CombinationList);

	printList(numberOfSides, numberOfDice, CombinationList);

	sumFrequencyOfCombinationsIsAccurate(numberOfSides, numberOfDice, CombinationList);


	//freeMemory(CombinationList, diceList);

	system("PAUSE");
}





//This function finds the number of occurances of combinations of the dice
void findSumFrequencyOfCombinations(int sidesOfDice, int numberOfDice, int*StateOfEachDiceList, int*listOfCombinationFrequencies)
{
	int maxValue = sidesOfDice;
	int minValue = 1;
	int numberOfValues = sidesOfDice;

	//Get total frequency of combinations
	for (int i = 1; i < numberOfDice; i++)
		numberOfValues *= sidesOfDice;

	for (int k = 0; k < numberOfValues; k++)
	{
		listOfCombinationFrequencies[findSumOfDice(StateOfEachDiceList, numberOfDice) - 1]++;

		StateOfEachDiceList[0]++;

		for (int d = 0; d < numberOfDice; d++)
		{
			if (StateOfEachDiceList[d] > maxValue)
			{
				StateOfEachDiceList[d + 1]++;
				StateOfEachDiceList[d] = minValue;
			}
		}
	}



}





//This function creates empty list with the high value of the range
//lowest value in range is trash
int* createCombinationList(int sidesOfDice, int numberOfDice)
{
	int* CombinationList;

	CombinationList = (int*)calloc(((sidesOfDice * numberOfDice)), sizeof(int));

	return CombinationList;
}





//Creates list of the state of each dice.
//initialized to 1 as default values
int*createDiceList(int numberOfDice)
{
	int *diceList = (int*)malloc(numberOfDice * sizeof(int));

	for (int i = 0; i < numberOfDice; i++)
		diceList[i] = 1;


	return diceList;
}





//Prints list of Combinations and Frequencies of them
void printList(int sidesOfDice, int numberOfDice, int* listOfCombinationFrequencies)
{
	int highestIndex = sidesOfDice * numberOfDice - 1,

		//starting index starts at lowest index
		startingIndex = numberOfDice - 1;

	while (startingIndex <= highestIndex)
	{
		printf("\nSum of %d: %d", (startingIndex + 1), listOfCombinationFrequencies[startingIndex]);
		startingIndex++;
	}

}





//Validation
void sumFrequencyOfCombinationsIsAccurate(int sidesOfDice, int numberOfDice, int* listOfCombinationFrequencies)
{
	int sumOfList = 0,
		//startingIndex is also lowest index
		startingIndex = numberOfDice - 1,
		highestIndex = numberOfDice * sidesOfDice - 1,
		numberOfTotalCombinations = sidesOfDice;

	//find total number of possible combinations
	for (int i = 1; i < numberOfDice; i++)
		numberOfTotalCombinations *= sidesOfDice;

	while (startingIndex <= highestIndex)
	{
		sumOfList += listOfCombinationFrequencies[startingIndex];
		startingIndex++;
	}

	if (sumOfList == numberOfTotalCombinations)
		printf("\nList is accurate");
	else
		printf("\nList is not accurate");
}




//Find sum for current state of dice
int findSumOfDice(int* StateOfEachDiceList, int numberOfDice)
{
	int sum = 0,
		index = 0;

	while (index < numberOfDice)
	{
		sum += StateOfEachDiceList[index];
		index++;
	}

	return sum;
}




void freeMemory(int* ListOfCombinationFrequencies, int*StateOfEachDiceList)
{
	free(ListOfCombinationFrequencies);
	free(StateOfEachDiceList);
}





int setNumberOfDice()
{
	int numberOfDice;

	printf("Enter number of dice: ");
	scanf_s("%d", &numberOfDice);

	return numberOfDice;
}





int setNumberOfSides()
{
	int numberOfSides;

	printf("Enter number of sides: ");
	scanf_s("%d", &numberOfSides);

	return numberOfSides;
}

