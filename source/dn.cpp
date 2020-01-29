#include "../include/GV.h"

void enter_dn(int size, int time) {
	dn.flag = 1;
	dn.cnt = 0;
	dn.time = time;
	dn.size = size;
}

//�h�K�[���Ƃ����ʂ̏���
void dn_calc() {
	if (dn.flag == 1) {
		if (emperor_time.flag == 0) {		//�G���y���[�^�C�����������Ă��Ȃ����
			dn.x = (int)rang(dn.size);
			dn.y = (int)rang(dn.size);
			dn.cnt++;
		}
		else {		//�G���y���[�^�C�����Ȃ�
			dn.x = (int)(rang(dn.size)*emperor_time.spd_rate);
			dn.y = (int)(rang(dn.size)*emperor_time.spd_rate);
			if (count % EMPEROR_TIME_RATE == 0) {
				dn.cnt++;
			}
		}
		if (dn.cnt>dn.time) {//�w�肳�ꂽ���Ԃ����ƏI���
			dn.flag = 0;
			dn.x = 0;
			dn.y = 0;
		}
	}
}

