#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>
#include <vector>

using namespace std;

void mainMenu();

void threeDots() {
	for (int i = 0; i < 3; i++) {
		cout << ".";
		Sleep(1000);
	}
	system("cls");
}

void firstStart() {
	cout << "~~~~~CONSOLE GAMES~~~~~";
	cout << "\n\n\nLoading";
	threeDots();
}

void Exit() {
	system("cls");
	cout << "~~~~~CONSOLE GAMES~~~~~\n\nThank you for playing this game.\nApplication will end soon\nLoading";
	threeDots();
	exit(0);
}

void Game(int choice) {
	switch (choice) {
	case 1: {
		system("cls");
		cout << "~~~~~CONSOLE GAMES~~~~~\n\nWelcome to \"GUESS THE NUMBER\" game\n\nLoading";
		threeDots();
		int random_number = rand() % 11, chances = 3;
		int player_number;
		cout << "~~~~~CONSOLE GAMES~~~~~\n\nGuess the number, the number is between [0,10]\n\nChances left: " << chances << "\n\nNumber: ";
		cout << random_number;
		cin >> player_number;
		if (player_number == random_number) {
			system("cls");
			cout << "~~~~~CONSOLE GAMES~~~~~\n\nCongratulations! You guessed the number!\n\nYou will be redirected to the main menu.\n\nLoading";
			threeDots();
			mainMenu();
		}
		else {
			chances--;
			while (chances != 0) {
				if (player_number == random_number) {
					cout << "~~~~~CONSOLE GAMES~~~~~\n\nCongratulations! You guessed the number!\n\nYou will be redirected to the main menu.\n\nLoading";
					threeDots();
					mainMenu();
				}
				else {
					system("cls");
					cout << "~~~~~CONSOLE GAMES~~~~~\n\nChances left: " << chances << "\n\nNumber: ";
					cin >> player_number;
					chances--;
				}
			}
			system("cls");
			cout << "~~~~~CONSOLE GAMES~~~~~\n\nYou lost! You will be redirected to the main menu.\n\nLoading";
			threeDots();
			mainMenu();
		}
		break;
	}
	case 2: {
		Exit();
		break;
	}
	default:
		mainMenu();
		break;
	}
}

void mainMenu() {
	int choice;
	system("cls");
	cout << "~~~~~CONSOLE GAMES~~~~~"; 
	cout << "\n\n\nMenu\n\n1.Guess the number\n2.Exit\n\nYour choice: "; cin >> choice;
	Game(choice);
}

int main() {
	srand(time(NULL));
	firstStart();
	mainMenu();
	return 0;
}