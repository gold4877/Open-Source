#pragma once
#include "Blocks.h"
#include "Controller.h"

//색상
typedef enum Color {
	BLACK,			// 0
	DARK_BLUE,		// 1
	DARK_GREEN,		// 2
	DARK_SKYBLUE,	// 3
	DARK_RED,		// 4
	DARK_VOILET,	// 5
	DAKR_YELLOW,	// 6
	GRAY,			// 7
	DARK_GRAY,		// 8
	BLUE,			// 9
	GREEN,			// 10
	SKYBLUE,		// 11
	RED,			// 12
	VIOLET,			// 13
	YELLOW,			// 14
	WHITE,			// 15
	PINK,
	HOT_PINK,
	ORANGE,
	LIME,
} COLOR;

int static level;

// 두번째 게임 Scene
void InGameFrame();
// 게임에서 출력될 다음 블록 미리보기 
void ShowNextBlock();
// 게임에서 출력될 가음 블록 미리보기 삭제
void DeleteNextBlock();
// 미리 보여질 블록을 배열로 정의헀습니다
int NextBlock[6][6]; // nextshape
int static Rotation = 0;

void EndGameFrame();
void GameTitle();

/**
* Controller.c 소스파일의 tetris_process()메서드에서
* 테트리스 보드 안 현재 블록이 출력 "addBlock(shpae,rotate)">"되고,
* 한칸 내려가면 현재 출력된 블록을 삭제<deleteBlock()> 후
* y값 증가된 상태로 (내려간 상태) 현재 블록 다시 출력! <addBlock(shape,rotate)
* 블록을 출력, 삭제 하는 함수입니다.
*/
void addBlock(int shape, int rotate);
void deleteBlock();

// 보드 생성, 0과 1로 구성 1 = 벽, 0 = 빈 공간, 자세하게는 blockFixed()메서드 주석 참고
void createBoards();
int board[BoardHeight][BoardWidth];
void printBoards();
// 블록에 컬러를 넣기 위해 textcolor정의
void textcolor(int colo_number);