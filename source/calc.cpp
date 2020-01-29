#include "../include/GV.h"

void calc_stage_title() {
	if (stage_title.appear_cnt == stage_count) {//今が表示開始時なら
		stage_title.flag = 1;
		stage_title.img = LoadGraph("../dat/img/board/subject0.png");
	}

	if (stage_title.flag == 0)return;

	if (stage_title.cnt<128)//最初の128の間段々明るく
		stage_title.brt += 2;
	if (stage_title.cnt>128 + 128)//段々暗く
		stage_title.brt -= 2;
	if (stage_title.cnt>128 + 128 + 128) {//終り
		stage_title.cnt = 0;
		stage_title.brt = 0;
		stage_title.flag = 0;
		DeleteGraph(stage_title.img);//画像解放
		return;
	}

	stage_title.cnt++;
	//強制終了した時の画像解放処理が必要
}

//アイテムの吸収処理。
void calc_item_indraw(int i) {
	double v = item[i].state ? 8 : 3;//state1ならスピード8、違うなら2
	double angle = atan2(ch.y - item[i].y, ch.x - item[i].x);//自機への角度を計算して
	item[i].x += cos(angle)*v;
	item[i].y += sin(angle)*v;
}

//アイテム移動など計算
void calc_item() {
	for (int i = 0; i<ITEM_MAX; i++) {
		if (item[i].flag>0) {
			if (item[i].state == 0) {
				if (ch.y<ITEM_GET_BORDER_LINE)//吸収状態なら
					item[i].state = 1;
				if (charge_bom.flag == 1 && charge_bom.cnt == 1)
					item[i].state = 1;
			}	
			if (item[i].state == 0) {//普通の状態なら
				double x = ch.x - item[i].x, y = ch.y - item[i].y;
				//低速状態で自機付近なら
				if (CheckStatePad(configpad.slow)>0 &&
					x*x + y * y<ITEM_INDRAW_RANGE*ITEM_INDRAW_RANGE) {
					calc_item_indraw(i);//吸収
				}
				else {
					if (item[i].v<2.5)//速度アップ
						item[i].v += 0.06;
					if (emperor_time.flag == 0) {		//エンペラータイムが発動していなければ
						item[i].y += item[i].v;//移動
					}
					else {		//エンペラータイム中なら
						item[i].y += item[i].v*emperor_time.spd_rate;//移動
					}
				}
			}
			else {//吸収状態なら
				calc_item_indraw(i);
			}
			if (emperor_time.flag == 0) {		//エンペラータイムが発動していなければ
				item[i].cnt++;
			}
			else {		//エンペラータイム中なら
				if (count % EMPEROR_TIME_RATE == 0) {
					item[i].cnt++;
				}
			}
			if (item[i].y>FMY + 50)
				item[i].flag = 0;
		}
	}
}
//フラッシュ(42)
void calc_flash() {
	if (flash.flag>0) {
		if (flash.knd == 0) {
			if (flash.cnt == 0)flash.brt = 0;
			if (flash.cnt<flash.to_cnt)
				flash.brt += 255.0 / flash.to_cnt;
			else
				flash.brt -= 255.0 / flash.to_cnt;
		}
		if (flash.knd == 1) {
			if (flash.cnt == 0)flash.brt = 255;
			flash.brt -= 255.0 / flash.to_cnt;
		}
		flash.cnt++;
		if (flash.knd == 0) {
			if (flash.cnt>flash.to_cnt * 2)
				flash.flag = 0;
		}
		if (flash.knd == 1) {
			if (flash.cnt>flash.to_cnt)
				flash.flag = 0;
		}
	}
}

//ハイスコア計算
void calc_hiscore() {
	if (ch.score > HiScore) {
		HiScore = ch.score;
	}
}

//クリア表示
void calc_clear() {
	if (boss.appear_count[1] + 120 == stage_count) {//今が表示開始時なら
		clear.flag = 1;
		clear.img = LoadGraph("../dat/img/board/29.png");
	}

	if (clear.flag == 0)return;

	if (clear.cnt<128)//最初の128の間段々明るく
		clear.brt += 2;
	if (clear.cnt == 128 + 64)
		ch.score += 100000 + ch.num * 20000 + emperor_time.num * 1000;
	if (clear.cnt>128 + 128)//段々暗く
		clear.brt -= 2;
	if (clear.cnt>128 + 128 + 128) {//終り
		clear.cnt = 0;
		clear.brt = 0;
		clear.flag = 0;
		DeleteGraph(clear.img);//画像解放
		return;
	}

	clear.cnt++;
	//強制終了した時の画像解放処理が必要
}

//終了処理
void calc_end() {
	if (boss.appear_count[1] + 120 + 128 * 3 + 60 == stage_count) {//今が表示開始時なら
		StopSoundMem(area.bgm.handle);
		delete_bgm();

		//データの保存
		save_data.shot = configpad.shot;
		save_data.bom = configpad.bom;
		save_data.slow = configpad.slow;
		save_data.start = configpad.start;
		save_data.select = configpad.change;
		save_data.special = configpad.special;
		save_data.hiscore = HiScore;
		DataSave(&save_data);

		termination();
		func_state = 50;
		return;
	}
}

void calc_main() {
	calc_stage_title();
	calc_clear();
	calc_item();
	calc_flash();//フラッシュ
	calc_hiscore();
	calc_end();
}