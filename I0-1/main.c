#include "Blocks.h"
#include "Controller.h"
#include "Screen.h"
#include "ConsoleCursor.h"

void main() {
	CursorView(false);
	system("mode con cols=76 lines=28 | title â�ǽǹ�������Ʈ_��Ʈ���� �ǽ�");
	/*
	�Ʒ��� PlaySound �޼���� .wav ���� ������ ��������ִ� �Լ��Դϴ�.
	Controller.h ������Ͽ� include�� mmsystem.h ��������� ���� .wav������ ��½�Ű�µ�
	������ ����� ��� �ش� ��θ� Controller.h�� BGM�� ��θ� ���ڿ��� �����ϸ� �˴ϴ�
	���� �Ʒ� PlaySound �ּ� ����
	������ ���۱� ������ ���� x */

	// PlaySound(Text(BGM), NULL, SND_FILENAME | SAN_ASYNC | SND_LOOP);

	while (true) {
		GameTitle();
		GameProcess();
	}
}