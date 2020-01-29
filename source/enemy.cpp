#include "../include/GV.h"

extern void enemy_pattern0(int); extern void enemy_pattern1(int); extern void enemy_pattern2(int);
extern void enemy_pattern3(int); extern void enemy_pattern4(int); extern void enemy_pattern5(int);
extern void enemy_pattern6(int); extern void enemy_pattern7(int); extern void enemy_pattern8(int);
extern void enemy_pattern9(int); extern void enemy_pattern10(int); extern void enemy_pattern11(int);
extern void enemy_pattern12(int); extern void enemy_pattern13(int); extern void enemy_pattern14(int);

void(*enemy_pattern[ENEMY_PATTERN_MAX])(int) = {
	enemy_pattern0,    enemy_pattern1,    enemy_pattern2,    enemy_pattern3,    enemy_pattern4,
	enemy_pattern5,    enemy_pattern6,    enemy_pattern7,    enemy_pattern8,    enemy_pattern9,
	enemy_pattern10,	enemy_pattern11,	enemy_pattern12,	enemy_pattern13,	enemy_pattern14,
};

//空いている敵番号を検索
int enemy_num_search() {
	for (int i = 0; i<ENEMY_MAX; i++) {//フラグのたって無いenemyを探す
		if (enemy[i].flag == 0) {
			return i;//使用可能番号を返す
		}
	}
	return -1;//全部埋まっていたらエラーを返す
}

//敵情報を登録
void enemy_enter() {//敵の行動を登録・制御する関数
	int i, j, t;
	if (boss.flag != 0)return;
	for (t = 0; t<ENEMY_ORDER_MAX; t++) {
		if (enemy_order[t].cnt == stage_count) {//現在の瞬間がオーダーの瞬間なら
			if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
				if ((i = enemy_num_search()) != -1) {
					enemy[i].flag = 1;//フラグ
					enemy[i].cnt = 0;//カウンタ
					enemy[i].pattern = enemy_order[t].pattern;//移動パターン
					enemy[i].muki = 1;//向き
					enemy[i].knd = enemy_order[t].knd;//敵の種類
					enemy[i].x = enemy_order[t].x;//座標
					enemy[i].y = enemy_order[t].y;
					enemy[i].sp = enemy_order[t].sp;//スピード
					enemy[i].bltime = enemy_order[t].bltime;//弾の発射時間
					enemy[i].blknd = enemy_order[t].blknd;//弾幕の種類
					enemy[i].blknd2 = enemy_order[t].blknd2;//弾の種類
					enemy[i].col = enemy_order[t].col;//色
					enemy[i].wait = enemy_order[t].wait;//色
					enemy[i].hp = enemy_order[t].hp;//体力
					enemy[i].hp_max = enemy[i].hp;//体力最大値
					enemy[i].back_col = GetRand(4);
					enemy[i].vx = 0;//水平成分の速度
					enemy[i].vy = 0;//鉛直成分の速度
					enemy[i].ang = 0;//角度
					for (j = 0; j<6; j++)
						enemy[i].item_n[j] = enemy_order[t].item_n[j];//落とすアイテム
				}
			}
		}
	}
}

void enter_shot(int i) {
	int j;
	for (j = 0; j<SHOT_MAX; j++) {//フラグのたって無いenemyを探す
		if (shot[j].flag == 0) {//未使用の弾幕データがあれば
			memset(&shot[j], 0, sizeof(shot_t));//初期化して登録
			shot[j].flag = 1;//フラグをたてる
			shot[j].knd = enemy[i].blknd;//弾の種類
			shot[j].num = i;//num=どの敵から発射されたものか。
			shot[j].cnt = 0;
			return;
		}
	}
}

//敵の行動制御
void enemy_act() {
	int i;
	for (i = 0; i<ENEMY_MAX; i++) {
		if (enemy[i].flag == 1) {//その敵のフラグがオンになってたら
			if (emperor_time.flag == 0) {		//エンペラータイムが発動していなければ
				if (0 <= enemy[i].pattern && enemy[i].pattern<ENEMY_PATTERN_MAX) {
					enemy_pattern[enemy[i].pattern](i);
					enemy[i].x += cos(enemy[i].ang)*enemy[i].sp;
					enemy[i].y += sin(enemy[i].ang)*enemy[i].sp;
					enemy[i].x += enemy[i].vx;
					enemy[i].y += enemy[i].vy;
					enemy[i].cnt++;
					enemy[i].img = enemy[i].muki * 3 + (enemy[i].cnt % 18) / 6;
					//敵が画面外に外れたら消す
					if (enemy[i].x<-20 || FMX + 20<enemy[i].x || enemy[i].y<-20 || FMY + 20<enemy[i].y)
						enemy[i].flag = 0;
					if (enemy[i].bltime == enemy[i].cnt)
						enter_shot(i);
				}
				else
					printfDx("enemy[i].patternの%d値が不正です。", enemy[i].pattern);
			}
			else {		//エンペラータイムが発動していたら
				if (0 <= enemy[i].pattern && enemy[i].pattern<ENEMY_PATTERN_MAX) {
					enemy_pattern[enemy[i].pattern](i);
					enemy[i].x += cos(enemy[i].ang)*enemy[i].sp*emperor_time.spd_rate;
					enemy[i].y += sin(enemy[i].ang)*enemy[i].sp*emperor_time.spd_rate;
					enemy[i].x += enemy[i].vx * emperor_time.spd_rate;
					enemy[i].y += enemy[i].vy * emperor_time.spd_rate;
					if (count % EMPEROR_TIME_RATE == 0) {		//4フレームに1回
						enemy[i].cnt++;
					}
					enemy[i].img = enemy[i].muki * 3 + (enemy[i].cnt % 18) / 6;
					//敵が画面外に外れたら消す
					if (enemy[i].x<-20 || FMX + 20<enemy[i].x || enemy[i].y<-20 || FMY + 20<enemy[i].y)
						enemy[i].flag = 0;
					if (count % EMPEROR_TIME_RATE == 0) {
						if (enemy[i].bltime == enemy[i].cnt)
							enter_shot(i);
					}
				}
				else
					printfDx("enemy[i].patternの%d値が不正です。", enemy[i].pattern);
			}
		}
	}
}

//敵処理メイン
void enemy_main() {
	enemy_enter();
	enemy_act();
}