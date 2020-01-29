#include "../include/GV.h"

void enter_dn(int size, int time) {
	dn.flag = 1;
	dn.cnt = 0;
	dn.time = time;
	dn.size = size;
}

//ドガーンとゆれる画面の処理
void dn_calc() {
	if (dn.flag == 1) {
		if (emperor_time.flag == 0) {		//エンペラータイムが発動していなければ
			dn.x = (int)rang(dn.size);
			dn.y = (int)rang(dn.size);
			dn.cnt++;
		}
		else {		//エンペラータイム中なら
			dn.x = (int)(rang(dn.size)*emperor_time.spd_rate);
			dn.y = (int)(rang(dn.size)*emperor_time.spd_rate);
			if (count % EMPEROR_TIME_RATE == 0) {
				dn.cnt++;
			}
		}
		if (dn.cnt>dn.time) {//指定された時間がたつと終わる
			dn.flag = 0;
			dn.x = 0;
			dn.y = 0;
		}
	}
}

