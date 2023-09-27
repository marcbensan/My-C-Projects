/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Denyl Marc Bensan
Student ID#: 171309222
Email      : mbensan@myseneca.ca
Section    : IPC144NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//declaration of variables
	char coffee1Type, coffee2Type, coffee3Type;
	int coffee1Weight, coffee2Weight, coffee3Weight;
	char coffee1Cream, coffee2Cream, coffee3Cream;
	char orderStrength;
	char orderCream;
	int orderServings;

	//printing the scanf functions
	printf("Take a Break - Coffee Shop\n==========================\n\n");
	printf("Enter the coffee product information being sold today...\n\n");

	//coffee 1 inputs
	printf("COFFEE-1...\n");
	printf("Type ([L]ight, [M]edium, [R]ich): ");
	scanf("%c", &coffee1Type);

	printf("Bag weight (g): ");
	scanf("%d", &coffee1Weight);

	printf("Best served with cream ([Y]es, [N]o): ");
	scanf(" %c", &coffee1Cream);
	printf("\n");

	//coffee 2 inputs
	printf("COFFEE-2...\n");
	printf("Type ([L]ight, [M]edium, [R]ich): ");
	scanf(" %c", &coffee2Type);

	printf("Bag weight (g): ");
	scanf("%d", &coffee2Weight);

	printf("Best served with cream ([Y]es, [N]o): ");
	scanf(" %c", &coffee2Cream);
	printf("\n");

	//coffee 3 inputs
	printf("COFFEE-3...\n");
	printf("Type ([L]ight, [M]edium, [R]ich): ");
	scanf(" %c", &coffee3Type);

	printf("Bag weight (g): ");
	scanf("%d", &coffee3Weight);

	printf("Best served with cream ([Y]es, [N]o): ");
	scanf(" %c", &coffee3Cream);

	//priting the receipt and ASCII

	printf("\n");
	printf("---+------------------------+---------------+-------+\n");
	printf("   |    Coffee              |   Packaged    | Best  |\n");
	printf("   |     Type               |  Bag Weight   | Served|\n");
	printf("   +------------------------+---------------+ With  |\n");
	printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
	printf("---+------------------------+---------------+-------+\n");
	printf(" 1 |   %d   |   %d    |   %d   |  %d  |  %5.3lf |   %d  |\n", coffee1Type == 'l' || coffee1Type == 'L', coffee1Type == 'm'|| coffee1Type == 'M', coffee1Type == 'r' || coffee1Type == 'R', coffee1Weight, coffee1Weight * 0.00220462, coffee1Cream == 'y' || coffee1Cream == 'Y');
	printf(" 2 |   %d   |   %d    |   %d   |  %d  |  %5.3lf |   %d  |\n", coffee2Type == 'l' || coffee2Type == 'L', coffee2Type == 'm' || coffee2Type == 'M', coffee2Type == 'r' || coffee2Type == 'R', coffee2Weight, coffee2Weight * 0.00220462, coffee2Cream == 'y' || coffee2Cream == 'Y');
	printf(" 3 |   %d   |   %d    |   %d   |  %d |  %5.3lf |   %d  |\n", coffee3Type == 'l' || coffee3Type == 'L', coffee3Type == 'm' || coffee3Type == 'M', coffee3Type == 'r' || coffee3Type == 'R', coffee3Weight, coffee3Weight * 0.00220462, coffee3Cream == 'y' || coffee3Cream == 'Y');

	//inputs for the order preference

	printf("\nEnter how you like your coffee...\n\n");

	printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
	scanf(" %c", &orderStrength);

	printf("Do you like your coffee with cream ([Y]es,[N]o): ");
	scanf(" %c", &orderCream);

	printf("Typical number of daily servings: ");
	scanf("%d", &orderServings);

	printf("\nThe below table shows how your preferences align to the available products:\n\n");

	printf("--------------------+-------------+-------+\n");
	printf("  |     Coffee      |  Packaged   | With  |\n");
	printf("ID|      Type       | Bag Weight  | Cream |\n");
	printf("--+-----------------+-------------+-------+\n");
	printf(" 1|      %d          |     %d       |  %d    |\n", orderStrength == coffee1Type || orderStrength == 'l' || orderStrength == 'L', orderServings <= 4, orderCream == coffee1Cream || orderCream == 'y' || orderCream == 'Y');
	printf(" 2|      %d          |     %d       |  %d    |\n", orderStrength == coffee2Type || orderStrength == 'r' || orderStrength == 'R', orderServings >= 5 && orderServings <= 9, orderCream == coffee2Cream || orderCream == coffee2Cream || orderCream == 'n' || orderCream == 'N');
	printf(" 3|      %d          |     %d       |  %d    |\n\n", orderStrength == coffee3Type || orderStrength == 'm' || orderStrength == 'M', orderServings >= 12, orderCream == coffee3Cream || orderCream == 'n' || orderCream == 'N');
	//redo the same input but more checker

	printf("Enter how you like your coffee...\n\n");

	printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
	scanf(" %c", &orderStrength);

	printf("Do you like your coffee with cream ([Y]es,[N]o): ");
	scanf(" %c", &orderCream);

	printf("Typical number of daily servings: ");
	scanf("%d", &orderServings);

	printf("\nThe below table shows how your preferences align to the available products:\n\n");

	//calculate the output (HAS TO BE IDENTICAL)

	printf("--------------------+-------------+-------+\n");
	printf("  |     Coffee      |  Packaged   | With  |\n");
	printf("ID|      Type       | Bag Weight  | Cream |\n");
	printf("--+-----------------+-------------+-------+\n");
	printf(" 1|      %d          |     %d       |  %d    |\n", orderStrength == coffee1Type || orderStrength == 'l' || orderStrength == 'L', orderServings <= 4, orderCream == coffee1Cream || orderCream == 'y' || orderCream == 'Y');
	printf(" 2|      %d          |     %d       |  %d    |\n", orderStrength == coffee2Type || orderStrength == 'r' || orderStrength == 'R', orderServings >= 5 && orderServings <= 9, orderCream == coffee2Cream || orderCream == coffee2Cream || orderCream == 'n' || orderCream == 'N');
	printf(" 3|      %d          |     %d       |  %d    |\n\n", orderStrength == coffee3Type || orderStrength =='m' || orderStrength == 'M', orderServings >= 12, orderCream == coffee3Cream || orderCream == 'n' || orderCream == 'N');
	
	printf("Hope you found a product that suits your likes!\n");


		
	return 0;
}
