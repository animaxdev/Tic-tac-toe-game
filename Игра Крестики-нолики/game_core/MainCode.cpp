#include "BasicFunctions.h"


void Tic_tac_toe_Game::null_cells()
{
	setlocale(LC_ALL, "ru");

	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++)
			MAP[i][j] = NULL_FIELD;
}


void Tic_tac_toe_Game::drawing_cells()
{
	setlocale(LC_ALL, "ru");

	for (int i = 0; i < A; i++)
		std::cout << "--";
	std::cout << "-" << std::endl;
}

short int Tic_tac_toe_Game::getMove()
{
	return Nmove;
}

void Tic_tac_toe_Game::show_map()
{
	setlocale(LC_ALL, "ru");

	std::cout << "Step � " << getMove() << std::endl;
	std::cout << std::endl;

	std::cout << "\t X";
	for (int i = 0; i < A; i++)
		std::cout << " " << i + 1 << "  ";
	std::cout << std::endl;



	std::cout << "\tY";
	drawing_cells();

	for (int i = 0; i < A; i++)
	{
		std::cout << "\t" << i + 1 << "| ";
		for (int j = 0; j < B; j++)
		{
			std::cout << MAP[i][j] << " | ";
		}
		std::cout << std::endl;
		std::cout << "\t ";
		drawing_cells();
	}
	std::cout << std::endl << std::endl;
	X = Y = 0;
}


bool Tic_tac_toe_Game::input_coordinates()
{
	std::cout << "The player is walking " << whoMove << std::endl;
	std::cout << "Enter the X Y coordinate from 1 to " << A << ": ";
	if ((!(std::cin >> X) || !(std::cin >> Y)) || ((!(X < (A + 1) && X > 0) || !(Y < (B + 1) && Y > 0))) || (!(MAP[--Y][--X] == NULL_FIELD)))
	{
		std::cin.clear();
	}
	else
		return true;
}


uint8_t Tic_tac_toe_Game::display()
{
	Nmove++;

	setlocale(LC_ALL, "ru");

	if (whoMove == symbol_cross)
	{
		MAP[Y][X] = symbol_cross;
		return symbol_cross;
	}

	if (whoMove == symbol_zero)
	{
		MAP[Y][X] = symbol_zero;
		return symbol_zero;
	}
}


void Tic_tac_toe_Game::exit_game()
{
	std::cout << "Continue to play (check 1 or 2)?" << std::endl;
	std::cout << std::endl;
	std::cout << "\t" << "1." << exitGame << "\t" << "2." << dontExitGame << std::endl;

	std::cin >> Choice;

	switch (Choice)
	{
	case 1:
		null_cells();
		selectCrossZero();

		do
		{
			system("cls");
			show_map();

			while (!input_coordinates())
			{
				system("cls");
				show_map();
			}
			display();
			algorithm_search_winner();
			next_move();
		} while ((win == NULL_FIELD) && (Nmove < A * A + 1));

		Winner();
		exit_game();
		break;

	case 2:
		_getch();
		break;
	}
}


void Tic_tac_toe_Game::next_move()
{
	setlocale(LC_ALL, "ru");

	if (whoMove == symbol_cross) {
		whoMove = symbol_zero;
	}
	else {
		whoMove = symbol_cross;
	}

}

void Tic_tac_toe_Game::select_mode() {
	int num_mode = 0;
	std::cout << "Choose a mode: " << std::endl;
	std::cout << "1. 2 players \t" << "2. with AI"  << std::endl;
	std::cin >> num_mode;
	system("cls");

	switch (num_mode)
	{
	case 1:
		selectCrossZero();
		break;

	case 2:
		
		
		break;

	default:
		break;
	}
}


void Tic_tac_toe_Game::selectCrossZero()
{
	char cross = 'X';
	char zero = 'O';
	char cross_Or_zero;

link:
	std::cout << "Choose a sign: " << std::endl;
	std::cout << "\t" << cross << "\t" << zero << std::endl;

	std::cin >> cross_Or_zero;

	switch (cross_Or_zero)
	{
	case 'x':
		whoMove = symbol_cross;
		break;


	case 'o':
		whoMove = symbol_zero;
		break;


	default:
		std::cout << "There is no such sign. Choose a sign. Press \"Enter\"" << std::endl;
		system("cls");
		goto link;
		break;
	}


	system("cls");
}


short int Tic_tac_toe_Game::algorithm_search_winner()
{
	setlocale(LC_ALL, "ru");

	short int a = 0;

	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B - 1; j++)
			if ((MAP[i][j] == MAP[i][j + 1]) && (MAP[i][j] != NULL_FIELD))
				a++;

		if (a == B - 1)
		{
			win = whoMove;
			return i + 1;
		}
		else
			a = 0;
	}

	a = 0;

	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B - 1; j++)
			if ((MAP[j][i] == MAP[j + 1][i]) && (MAP[j][i] != NULL_FIELD))
				a++;
		if (a == B - 1)
		{
			win = whoMove;
			return i + 4;
		}
		else
			a = 0;
	}


	for (int i = 0, j = A - 1; i < A; i++, j--)
		if ((MAP[i][j] == MAP[i + 1][j - 1]) && (MAP[i][j] != NULL_FIELD))
			a++;
	if (a == B - 1)
	{
		win = whoMove;
		return 7;
	}
	else
		a = 0;

	for (int i = 0, j = 1; i < A; i++, j++)
		if ((MAP[i][i] == MAP[j][j]) && (MAP[i][i] != NULL_FIELD))
			a++;

	if (a == B - 1)
	{
		win = whoMove;
		return 8;
	}
	else
		a = 0;
}


void Tic_tac_toe_Game::Winner()
{
	system("cls");
	show_map();

	win != NULL_FIELD ? std::cout << "The player wins - " << win << "!\n" : std::cout << "Standoff!\n";

	std::cout << std::endl;
}



int main()
{
	setlocale(LC_ALL, "ru");

	Tic_tac_toe_Game ttg;

	ttg.null_cells();
	ttg.select_mode();
	do
	{
		system("cls");
		ttg.show_map();

		while (!ttg.input_coordinates())
		{
			system("cls");
			ttg.show_map();
		}
		ttg.display();
		ttg.algorithm_search_winner();
		ttg.next_move();
	} while ((ttg.win == NULL_FIELD) && (ttg.getMove() < pow(ttg.A, 2) + 1));

	ttg.Winner();
	ttg.exit_game();
	return 0;
}