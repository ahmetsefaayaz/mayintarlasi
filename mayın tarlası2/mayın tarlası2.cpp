#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <vector>
using namespace std;
//Genel Değişkenler.
const int HEIGHT = 5;
const int WIDTH = 5;
char tablo[HEIGHT][WIDTH];
int x, y;
int totalMines;
bool gameOver = false, Playerwon = false, playerLose = false;
char HiddenMines = '.';
char Player = 'P';
char Mines = 'M';
char EMPTY = ' ';
//Sınıflar.
class Minesweeper {
public:
	int CircleMines;
	char coordinations;




}Ctablo[HEIGHT][WIDTH];
//Fonksiyon tanımları.
void System();
void tabloOlustur();
void Input();
void Print();
void EndTheGame();


int main() {
	tabloOlustur();
	System();


}
//fonksiyon icerikleri.
void System() {
	while (!gameOver) {
		Input();
		Print();
	}
	EndTheGame();
}
void tabloOlustur() {
	srand(time(0));
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {

			tablo[i][j] = EMPTY;

		}
	}
	cout << "5x5 Tabloda Kac Adet Mayin Olmasini Istersiniz:";
	cin >> totalMines;

	int i, j;
	for (int k = 0; k < totalMines; k++) {
		i = rand() % HEIGHT;
		j = rand() % WIDTH;
		if (tablo[i][j] == EMPTY)
			tablo[i][j] = Mines;
		else
			k--;
	}
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (tablo[i][j] == EMPTY) {
				Ctablo[i][j].coordinations = EMPTY;
			}
			else if (tablo[i][j] == Mines) {
				Ctablo[i][j].coordinations = HiddenMines;
			}

		}
	}


}
void Input() {
	cout << "\nsatir ve sutun giriniz:";
	cin >> y >> x;
	system("cls");
	if (Ctablo[y - 1][x - 1].coordinations == HiddenMines) {
		playerLose = true;
		gameOver = true;
	}
	else
		Ctablo[y - 1][x - 1].coordinations = Player;
}
void Print() {
	//oyuncu kazandı mı kontrol.
	int control = 0;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (Ctablo[i][j].coordinations == EMPTY)
				control++;

		}
	}
	if (control == 0 && !playerLose) {
		Playerwon = true;
		gameOver = true;
	}
	//Oyuncunun etrafındaki mayınları kontrol etme
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (Ctablo[i][j].coordinations == Player) {
				int count = 0;
				// Komşu hücreleri kontrol et
				for (int r = -1; r <= 1; r++) {
					for (int c = -1; c <= 1; c++) {
						int newRow = i + r;
						int newCol = j + c;
						if (newRow >= 0 && newRow < HEIGHT && newCol >= 0 && newCol < WIDTH) {
							if (Ctablo[newRow][newCol].coordinations == HiddenMines) {
								count++;
							}
						}
					}
				}
				Ctablo[i][j].CircleMines = count;
			}
		}
	}
	//Tabloyu yazdırma.
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (Ctablo[i][j].coordinations == Player)
				cout << Ctablo[i][j].CircleMines << " ";
			else if (Ctablo[i][j].coordinations == EMPTY)
				cout << ". ";
			else
				cout << Ctablo[i][j].coordinations << " ";
		}
		cout << endl;
	}





}
void EndTheGame() {
	if (Playerwon == true)
		cout << "Kazandiniz!!" << endl;
	if (playerLose == true)
		cout << "Kaybettiniz:(" << endl;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (Ctablo[i][j].coordinations == HiddenMines)
				Ctablo[i][j].coordinations = Mines;


			cout << Ctablo[i][j].coordinations << " ";

		}
		cout << "\n";
	}
}