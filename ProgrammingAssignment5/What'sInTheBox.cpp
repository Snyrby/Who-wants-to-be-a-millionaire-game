/*****************************************************************************************
*  Program Name: What'sInTheBox.cpp
*  Created Date: 11/14/18
*  Created By: Shawn Ruby
*  Purpose: Plays a game to guess which box has 1 million dollars in it
*  Acknowledgements: None
*****************************************************************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

/*****************************************************************************************
*  Function Name:  BoxSelection
*  Parameters:     BoxWin, Boxlose1, Boxlose2
*  Return Value:   int
*  Purpose: Sets value for the 2 losing boxes in the game
*****************************************************************************************/

void BoxSelection(int BoxWin, int& Boxlose1, int& Boxlose2)
{	
	/* if statements that determine which boxes are the losing boxes based on which box is the winning box */
	if (BoxWin == 1)
	{
		Boxlose1 = 2;
		Boxlose2 = 3;
	}
	else if (BoxWin == 2)
	{
		Boxlose1 = 1;
		Boxlose2 = 3;
	}
	else if (BoxWin == 3)
	{
		Boxlose1 = 1;
		Boxlose2 = 2;
	}
}

/*****************************************************************************************
*  Function Name:  main()
*  Parameters:     None
*  Return Value:   int
*  Purpose: plays the game to determine if the player is a winner of 1 million dollars
*****************************************************************************************/

int main()
{
	/* allows the number to be random */
	srand((unsigned int)time(0));

	/* variable for decision of which box to pick */
	int decision;

	/* Random number for which box is the winner */
	int BoxWin = (rand() % 3) + 1;

	/* Assigns variable of the 2 losing boxes */
	int Boxlose1;
	int Boxlose2;

	/* variable that asks the user if they would like to change their answer */
	string change;

	/* Calls the function that calculates which boxes are the losing boxes */
	BoxSelection(BoxWin, Boxlose1, Boxlose2);

	/* cout statement for the intro / instructions */
	cout << "Welcome to the \"Who wants to be a millionaire\" game!\n\nThe game is simple! \n\nAll you have to do is pick a box for a" <<
		" chance to win a million dollars!\n\nBehind one of these doors we have 1 million dollars and behind the other two doors we" <<
		" have 1 million dollars of monopoly money.\n\n";

	/* Asks the user which box they would like to pick */
	cout << "Which door would you like to pick; 1, 2 or 3? ";
	cin >> decision;

	/* while loop for input validation (only integer values) */
	while (decision < 1 || decision > 3)
	{
		/* asks the user to pick a number between 1 and 3 */
		cout << "\nPlease pick a number between 1 and 3: ";
		cin >> decision;
		
		/* if user enters a correct integer, it breaks the loop returning to main code */
		if (decision <= 3 && decision >= 1)
		{
			break;
		}
	}

	/* if statement to determine if the user did not pick boxlose1 */
	if (decision != Boxlose1)
	{
		/* reveals 1 of the losing boxes */
		cout << "\nBefore we reveal your prize, let's show you what you would have won if you have picked box " << Boxlose1 <<
			".\n\nBehind box " << Boxlose1 << " is 1 million dollars in monopoly money! You now have a 50% chance of winning 1 million " <<
			"dollars!\n\n";

		/* if statement checking if the user picked the winning box */
		if (decision == BoxWin)
		{
			/* pauses the system */
			system("pause");

			/* asks the user if they would like to change their box to the other losing box */
			cout << "\nWould you like to change your box to box " << Boxlose2 << "? (y/n) ";
			cin >> change;

			/* input validation for the changing input */
			while (change != "y" && change != "Y" && change != "N" &&
				change != "n")
			{
				/* lets the user know the input was incorrect */
				cout << "\nSorry, that is not a correct response! Please try again. ";
				cin >> change;

				/* if the user wants to change the box, it will change to the losing box */
				if (change == "y" || change == "Y")
				{
					decision = Boxlose2;
					break;
				}
				/* if the user does not want to change the box, it will stay the winning box */
				else if (change == "n" || change == "N")
				{
					decision = BoxWin;
					break;
				}
			}
		}
		else
		{
			/* pauses the system */
			system("pause");

			/* asks the user if they want to change to the winning box */
			cout << "\nWould you like to change your box to box " << BoxWin << "? (y/n) ";
			cin >> change;

			/* input validation for the changing input */
			while (change != "y" && change != "Y" && change != "N" && change != "n")
			{
				/* lets the user know the input was incorrect */
				cout << "\nSorry, that is not a correct response! Please try again. ";
				cin >> change;

				/* if the user wants to change the box, it will change to the winning box */
				if (change == "y" || change == "Y")
				{
					decision = BoxWin;
					break;
				}
				/* if the user does not want to change the box, it will stay the losing box */
				else if (change == "n" || change == "N")
				{
					decision = Boxlose2;
					break;
				}
			}
		}
	}

	/* if statement to determine if the user did not pick boxlose2 */
	else if (decision != Boxlose2)
	{
		/* reveals 1 of the losing boxes */
		cout << "\nBefore we reveal your prize, let's show you what you would have won if you have picked box " << Boxlose2 <<
			".\n\nBehind box " << Boxlose2 << " is 1 million dollars in monopoly money! You now have a 50% chance of winning 1 million " <<
			"dollars!\n\n";

		/* if statement checking if the user picked the winning box */
		if (decision == BoxWin)
		{
			/* pauses the system */
			system("pause");

			/* asks the user if they would like to change their box to the other losing box */
			cout << "\nWould you like to change your box to box " << Boxlose1 << "? (y/n) ";
			cin >> change;

			/* input validation for the changing input */
			while (change != "y" && change != "Y" && change != "N" && change != "n")
			{
				/* lets the user know the input was incorrect */
				cout << "\nSorry, that is not a correct response! Please try again. ";
				cin >> change;

				/* if the user wants to change the box, it will change to the losing box */
				if (change == "y" || change == "Y")
				{
					decision = Boxlose1;
					break;
				}

				/* if the user does not want to change the box, it will stay the winning box */
				else if (change == "n" || change == "N")
				{
					decision = BoxWin;
					break;
				}
			}
		}
		else
		{
			/* pauses the system */
			system("pause");

			/* asks the user if they would like to change to the winning box */
			cout << "\nWould you like to change your box to box " << BoxWin << "? (y/n) ";
			cin >> change;

			/* input validation for the changing input */
			while (change != "y" && change != "Y" && change != "N" && change != "n")
			{
				/* lets the user know the input was incorrect */
				cout << "\nSorry, that is not a correct response! Please try again. ";
				cin >> change;

				/* if the user wants to change the box, it will change to the winning box */
				if (change == "y" || change == "Y")
				{
					decision = BoxWin;
					break;
				}

				/* if the user does not want to change the box, it will stay the losing box */
				else if (change == "n" || change == "N")
				{
					decision = Boxlose1;
					break;
				}
			}
		}
	}

	/* if statement that determines if the user wins the 1 million dollars and congradulates them */
	if (decision == BoxWin)
	{
		cout << "\nCongradulations! You have won 1 million dollars!\n\n";
	}

	/* else if statement that determines if the user loses and wins 1 million dollars in monopoly money */
	else if (decision == Boxlose1 || decision == Boxlose2)
	{
		cout << "\nSorry! You are unlucky! At least you can be rich at monopoly!\n\n";
	}

	/* pauses the system */
	system("pause");

	/* returns nothing */
	return 0;
}
