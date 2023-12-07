/**
* ConsoleCursor.h 헤더파일을 #include 합니다
* 정의된 getChroor() 메서드를 사용하기 위함입니다
*/

#include "Screen.h"
#include "ConsoleCursor.h"

int NextBlock[6][6] = {
	1,1,1,1,1,1,
	1,0,0,0,0,1,
	1,0,0,0,0,1,
	1,0,0,0,0,1,
	1,0,0,0,0,1,
	1,1,1,1,1,1,
};

void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void GameTitle() {
	int TETRIS_X = 13;
	int TETRIS_Y = 5;
	int picture_X = TETRIS_X + 5 * 2;
	int picture_Y = TETRIS_Y + 7;
	char introduce[20] = { "BY.OhGeumBin" };

	GotoXY(4, 4);
	int tetris[5][24] = {
		1,1,1,1,1,2,2,2,3,3,3,3,3,4,4,4,4,3,3,3,0,5,5,5,
		0,0,1,0,0,2,0,0,0,0,3,0,0,4,0,0,4,0,3,0,5,0,0,0,
		0,0,1,0,0,2,0,0,0,0,3,0,0,4,4,4,4,0,3,0,0,5,5,0,
		0,0,1,0,0,2,0,0,0,0,3,0,0,4,0,4,0,0,3,0,0,0,0,5,
		0,0,1,0,0,2,2,2,0,0,3,0,0,4,0,0,4,3,3,3,5,5,5,0
	};
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 24; x++) {
			GotoXY(TETRIS_X + x * 2, TETRIS_Y + y);
			if (tetris[y][x] == 0) {
				printf("  "); Sleep(3);
			}
			else {
				if (tetris[y][x] == 1) textcolor(YELLOW);
				else if (tetris[y][x] == 2) textcolor(BLUE);
				else if (tetris[y][x] == 3) textcolor(GREEN);
				else if (tetris[y][x] == 4) textcolor(SKYBLUE);
				else if (tetris[y][x] == 5) textcolor(RED);

				printf("■");
				textcolor(WHITE); Sleep(30);
			}
		}
	}

	for (int i = 0; i < 20; i++) {
		GotoXY(TETRIS_X + 18 + i, 1);
		putchar(introduce[i]); Sleep(50);
	} Sleep(500);

	GotoXY(TETRIS_X, picture_Y);
	textcolor(WHITE); printf("게임 난이도");
	GotoXY(TETRIS_X + 11, picture_Y);
	textcolor(YELLOW); printf("( 쉬움 = 0, 보통 = 1, 어려움 = 2, 종료 = 3)\n");
	GotoXY(TETRIS_X, picture_Y + 1);
	textcolor(WHITE); printf("난이도 입력 :");

	CursorView(true); scanf_s("%d", &level); CursorView(false);

	if (level == 0) gameLevel = easy;
	else if (level == 1) gameLevel = normal;
	else if (level == 2) gameLevel = hard;
	else if (level == 3) exit(false);
	system("cls");
}

void InGameFrame() {
	int picture_X = 36;
	int picture_Y = 0;
	int SecPicture[3][18] = {
		0,0,2,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,
		0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0
	};
	int picture[9][20] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,
		0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,2,0,2,2,2,
		0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,2,2,
		0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,
		0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,2,
		0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,3,5,3,3,3,3,0,0,0,0,3,0,0,0,0,
		4,4,4,4,3,3,3,3,3,3,3,3,3,4,3,3,4,4,4,4,
		4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4
	};
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 20; x++) {
			GotoXY(picture_X + x * 2, picture_Y + y);
			if (picture[y][x] == 0) textcolor(SKYBLUE);
			else if (picture[y][x] == 1) textcolor(WHITE);
			else if (picture[y][x] == 2) textcolor(RED);
			else if (picture[y][x] == 3) textcolor(BLUE);
			else if (picture[y][x] == 4) textcolor(DARK_BLUE);
			else if (picture[y][x] == 5) textcolor(WHITE);

			if (picture[y][x] == 5) printf("▣");
			else printf("■");

			Sleep(10);
		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 18; x >= 0; x--) {
			GotoXY(x * 2, y);
			if (SecPicture[y][x] == 0) {
				textcolor(SKYBLUE); printf("■");
			}
			else if (SecPicture[y][x] == 1) {
				textcolor(YELLOW); printf("★");
			}
			else if (SecPicture[y][x] == 2) {
				textcolor(DAKR_YELLOW); printf("☆");
			}
			Sleep(10);
		}
	}

	textcolor(WHITE);
	GotoXY(picture_X, picture_Y + 19);
	if (level == 0) printf("⊙ 게임 난이도 : 쉬움");
	else if (level == 1) printf("⊙ 게임 난이도 : 보통");
	else if (level == 2) printf("⊙ 게임 난이도 : 어려움");

	GotoXY(picture_X, picture_Y + 21);
	printf("⊙ 게임 키 설명");
	printScore();
	GotoXY(picture_X, picture_Y + 22);
	printf("  ▲         : 블럭 회전");
	GotoXY(picture_X, 23);
	printf("◀  ▶       : 왼쪽 이동 / 오른쪽 이동");
	GotoXY(picture_X, 24);
	printf("  ▼         : 아래 이동");
	GotoXY(picture_X, 25);
	printf("■■■■     : Space BAR (맨 아래로...)");

	textcolor(RED);
	for (int i = 7; i > 1; i--) {
		GotoXY(46, 14);
		printf("곧 게임을 시작합니다 ! ! !");
		printf("게임 시작 %d초 전...!", i / 2);
		Sleep(300);
		GotoXY(46, 14);
		printf("                     ");
		Sleep(200);
	}
}
void ShowNextBlock() {
	GotoXY(52, 0 + 11);
	textcolor(DARK_VOILET);
	printf("다음블럭 모형");
	textcolor(WHITE);

	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			GotoXY(42 + 8 + x * 2, 12 + y);
			if (NextBlock[y][x] == 1) {
				textcolor(DAKR_YELLOW);
				printf("▩");
				textcolor(WHITE);
			}
			if (y > 0 && y < 5) {
				if (x > 0 && x < 5) {
					if (Blocks[nexShape][0][y - 1][x - 1] == 2) {
						NextBlock[y][x] = Blocks[nexShape][0][y - 1][x - 1];
						GotoXY(42 + 8 + x * 2, 12 + y);
						printf("■");
					}
				}
			}
		}
	}
}

void DeleteNextBlock() {
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			if (y > 0 && y < 5) {
				if (x > 0 && x < 5) {
					if (NextBlock[y][x] == 2) {
						GotoXY(42 + 8 + x * 2, 12 + y);
						printf("  ");
					}
				}
			}
		}
	}
}

void createBoards() {
	for (int i = 0; i < BoardHeight; i++) {
		board[i][0] = 1;
		board[i][BoardWidth - 1] = 1;
		for (int j = 0; j < BoardWidth; j++) {
			if (i == 0) board[i][j] = 0;
			board[BoardHeight - 1][j] = 1;
			if (i > 0 && i < BoardHeight - 1)
				if (j > 0 && j < BoardWidth - 1) board[i][j] = 0;
		}
	}
}

void printBoards() {
	for (int x = 1; x < 13; x++) {
		GotoXY(BoardX + x * 2, BoardY + 1);
		printf("__");
	}

	for (int y = 0; y < BoardHeight; y++) {
		GotoXY(BoardX, BoardY + y);
		if (board[y][0] == 1) {
			textcolor(DAKR_YELLOW); printf("▩");
		}
		if (board[y][BoardWidth - 1] == 1) {
			GotoXY(BoardX + BoardWidth * 2 - 2, BoardY + y);
			textcolor(DAKR_YELLOW); printf("▩");
		}
		textcolor(WHITE);
	}
	for (int x = 0; x < BoardWidth; x++) {
		GotoXY(BoardX + x * 2, BoardY + BoardHeight - 1);
		if (board[BoardHeight - 1][x] == 1) {
			textcolor(DAKR_YELLOW); printf("▩");
		}
		textcolor(WHITE);
	}
}

void addBlock(int shape, int rotate) {
	COORD Pos = Cursor = getCursor();
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for (int y = 0; y < BlockSIZE; y++) {
		for (int x = 0; x < BlockSIZE; x++) {
			if (Blocks[shape][rotate][y][x] == 2) {
				board[BlockCOL + y][BlockROW + x] = 2;
				GotoXY(Pos.X + x * 2, Pos.Y + y);
				addCurrentBlockColor();
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y);
}

void deleteBlock() {
	COORD Pos = Cursor = getCursor();
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for (int y = 0; y < BlockSIZE; y++) {
		for (int x = 0; x < BlockSIZE; x++) {
			if (board[BlockCOL + y][BlockROW + x] == 2) {
				GotoXY(Pos.X + x * 2, Pos.Y + y);
				printf("  ");
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y);
}

void EndGameFrame() {
	for (int y = 1; y < BoardHeight - 1; y++) {
		for (int x = 1; x < BoardWidth - 1; x++) {
			if (board[y][x] >= 3) {
				GotoXY(BoardX + x * 2, BoardY + y);
				printf("▣");
			}
		}
		Sleep(150 - y * 5);
	}

	textcolor(RED);
	for (int i = 7; i > 1; i--) {
		GotoXY(BlockStartX, BlockStartY + 1);
		printf("게임 종료 ! ! ! \n");
		printf("다시 도전 ! ! !");
		GotoXY(BlockStartX - 4, BlockStartY + 2);
		printf("시작화면 %d초 전!!", i/2);
		Sleep(300);
		GotoXY(BlockStartX, BlockStartY + 1);
		printf("        ");
		GotoXY(BlockStartX - 4, BlockStartY + 2);
		printf("                   ");
		Sleep(200);
	}
	system("cls");
}