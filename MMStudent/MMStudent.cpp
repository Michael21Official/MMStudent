#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


#define SPACE ' '
char matrix[3][3] = { 
{SPACE, SPACE, SPACE},
{SPACE, SPACE, SPACE},
{SPACE, SPACE, SPACE}
};
void get_computer_move(void), get_player_move(void);
void disp_matrix(void);
char check(void);
int main()
{
	SetConsoleCP(852);
	setlocale(LC_ALL, "");
	char done;
	printf("Zagraj z komputerem.\n");
	done = SPACE;
	do {
		disp_matrix(); 
		get_player_move(); 
		done = check(); 
		if (done != SPACE) break; 
		get_computer_move(); 
		done = check(); 
	} while (done == SPACE);
	if (done == 'X') printf("Ty wygrałeś!\n");
	else printf("Ja wygrałem!!!!\n");
	disp_matrix(); 
	return 0;
}


void get_player_move(void)
{
	int x, у;
	printf("Wpisz kordynaty dla X.\n");
	printf("Wiersz? ");
	cin >>x;
	printf("Kolumna? ");
	cin >> у;
	x--; у--;
	if (x < 0 || у < 0 || x>2 || у>2 || matrix[x][у] != SPACE)
	{
		printf("Nieprawidłowy ruch, spróbuj jeszcze.\n");
		get_player_move();
	}
	else matrix[x][у] = 'X';
}


void get_computer_move(void)
{
	register int t;
	char* p;
	p = (char*)matrix;
	for (t = 0; *p != SPACE && t < 9; ++t) p++;
	if (t == 9)
	{
		printf("draw\n");
		exit(0); 
	}
	else *p = 'O';
}


void disp_matrix(void)
{
	int t;
	for (t = 0; t < 3; t++)
	{
		printf(" %c  |  %c  |  %c", matrix[t][0], matrix[t][1], matrix[t][2]);
		if (t != 2) printf("\n----|-----|----\n");
	}
	printf("\n");
}


char check(void)
{
	int t;
	char* p;
	for (t = 0; t < 3; t++) { 
		p = &matrix[t][0];
		if (*p == *(p + 1) && *(p + 1) == *(p + 2)) return *p;
	}
	for (t = 0; t < 3; t++) { 
		p = &matrix[0][t];
		if (*p == *(p + 3) && *(p + 3) == *(p + 6)) return *p;
	}

	
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		return matrix[0][0];
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		return matrix[0][2];
	return SPACE;
}