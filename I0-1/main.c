#include "Blocks.h"
#include "Controller.h"
#include "Screen.h"
#include "ConsoleCursor.h"

void main() {
	CursorView(false);
	system("mode con cols=76 lines=28 | title ���� �ҽ� �� ���ε� �׽�Ʈ ");

	while (true) {
		GameTitle();
		GameProcess();
	}
}