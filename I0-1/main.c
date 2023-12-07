#include "Blocks.h"
#include "Controller.h"
#include "Screen.h"
#include "ConsoleCursor.h"

void main() {
	CursorView(false);
	system("mode con cols=76 lines=28 | title 오픈 소스 깃 업로드 테스트 ");

	while (true) {
		GameTitle();
		GameProcess();
	}
}