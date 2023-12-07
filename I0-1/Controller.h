#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>

/**
* 게임에 출력될 음악 헤더파일과 정의입니다.
* BGM은 예를 들어 "C:\\Users\\Desktop\\tetris\\음악명" 경로를 문자열로 저장해야함
* 경로는 \ 가 아니라 \\를 해야함 
* #define으로 BGM 정의 하고 main함수에서 사용 가능
* main()문에 BGM 부분 직접 경로를 작성 해도 됨
*/
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")
// 음원은 저작권의 문제로 따로 제공하지 않습니다 
// #define BGM " C:\\User\\Desktop\\terris\\음악명.wav" // WAV Full Path

enum voardProperty {
	BoardWidth = 14,		// 보드 가로 길이
	BoardHeight = 22,       // 보드 세로 길이
	BoardX = 4,				// 콘솔창에서 출력될 보드 X좌표
	BoardY =3				// 콘솔창에서 출력될 보드 Y좌표
};

enum Keys {
	LEFT = 75,				// 키보드 왼쪽 키
	RIGHT = 77,				// 키보드 오른쪽 키
	UP = 72,				// 키보드 위 키	
	DOWN = 80,				// 키보드 아래 키
	ARROW = 224,			// 키보드 방향키 판별
	SPACEBAR = 32			// 키보드 스페이스 키
};

typedef enum gameSpeed {
	easy = 200,				// 게임 난이도 쉬움
	normal = 150,			// 게임 난이도 보통
	hard = 100				// 게임 난이도 어려움
}SPEED;

enum blockProperty {
	BlockSIZE =4,			// 블록의 크기
	BlockRotate = 4,		// 블록의 회전
	BlockType = 7,			// 블록의 종류
	BlockStartX = 14,		// 블록이 커서창에서 시작될 x 좌표
	BlockStartY = 4			// 블록이 커서창에서 시작될 y 좌표
};

// 사용자가 입력한 특정 방향키 아스키 코드 값
int nkey;

// 현재 블록 모양
short curShape;
void CurrentShape();
//다음 블록 모양
short nexShape;
void NextShape();
//블록의 현재 좌표 !!!
short BlockCOL;
short BlockROW;
//블록의 이전 좌표
short prevBlockCOL;
short prevBlockROW;
// 테트리스 보드 내 현재 위치하는 커서 
COORD Cursor;
// 이전 블록 지우기 
void deletePrevBlock();
//스코어
int static score;
void printScore();
// 게임 난이도
short gameLevel;
// 새로운 블록 종류 생성
void newBlock();

/**
* 새로운 블록인가? (flag느낌)
* 새로운 블록 == true이람녀 새로운 블록을 false 처리 한 후에 
* ShowNextBlock()을 호출시키며 다음에 나올 블록을 인 게임 화면 
* 테트리스 보드 옆에 보여준다
*/
boolean IsNextBlock;

/**
* 회전 기능의 방향키를 입력 받을 시 
* turn(현재 블록의 회전 상태 0,1,2,3중 예를 들어 turn == 0번쨰 회전 상태 (초기 블럭이라면)
* ' -> ' 방향키를 통해 turn == 1이 되고, 이에 따라서
* block에서 정의한 
* block[특정한 블럭 모양] [0][][]에서
* block[특정한 블럭 모양] [1][][]로 회전된 블록이 출력될 수 있도록 turn의 상태를 
* RotateBlock() 메서드를 통해 변환한다
*/
short turn;
void RotateBlock(); // 방햐이 받을 시 rotate를 통해 방향키 변경


/**
* IsCollision(int shape, int rotate, int curX, int curY)
* 현재 콘솔창의 커서값 Cursor에서 한칸 내려갔을 때
* 그 좌표에서 그려지는 블록이 테트리스 보드의 바닥과 닿거나,
* bottom에  블록이 닿아 고정된 블록과 닿는다면, true 반환
* 그럴 경우 현재 좌표값이 보드의 바닥과 닿거나, 바닥화?된(고착화된? 바닥에 얹혀진) 블록이라고 판단되기에
* 현재 좌표에 출력된 블록을 블록의 바닥으로 인식시킵니다. blockFixed(int shape, int rotate)
*/
boolean IsCollision(int shape, int rotate, int curX, int curY);
//블록이 bottom에 닿았을 경우
void blockFixed(int dhape, int rotate);


/**
* 보드의 특정 가로줄이 블록으로 저장되었는가? IsMzxLine()
* yes? -> deleteLine()
*/
boolean IsMaxLine();
void deleteLine();
// 처음 생성된 블록이 천장과 닿았는가?
boolean IsOverHeight();

// 미리보기 블록 만들고 지울 때 해당 좌표 저장해야합니다
COORD previewPoint;
// 미리보기 블록, 현재 블록 이후에 나올 블록 화면에 표현
void previewBlock(int shape, int rotate);
// 테트리스 돌아가는데 있어 가장 중요한 함수 (메인함수급입니다)
void GameProcess();