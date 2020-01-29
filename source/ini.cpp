#include "../include/GV.h"

void input_bullet_info(bullet_info_t *binfo, int size_x, int size_y, int col_num, double range, int kaiten) {
	binfo->size_x = size_x;	binfo->size_y = size_y;
	binfo->col_num = col_num;	binfo->range = range;
	binfo->kaiten = kaiten;
}

//一番最初の初期化
void first_ini() {
	DataLoad(&save_data);

	configpad.down = 0;
	configpad.left = 1;
	configpad.right = 2;
	configpad.up = 3;
	configpad.shot = save_data.shot;
	configpad.bom = save_data.bom;
	configpad.slow = save_data.slow;
	configpad.start = save_data.start;
	configpad.change = save_data.select;
	configpad.special = save_data.special;

	HiScore = save_data.hiscore;

	stage = 0;
	stage_title_count[0] = 350;
	setting_menu_count = 0;

	input_bullet_info(&bullet_info[0], 76, 76, 5, 17.0, 0);
	input_bullet_info(&bullet_info[1], 22, 22, 6, 4.0, 0);
	input_bullet_info(&bullet_info[2], 5, 120, 10, 2.5, 0);
	input_bullet_info(&bullet_info[3], 19, 34, 5, 2.0, 0);
	input_bullet_info(&bullet_info[4], 38, 38, 10, 2.0, 0);
	input_bullet_info(&bullet_info[5], 14, 16, 3, 3.5, 0);
	input_bullet_info(&bullet_info[6], 14, 18, 3, 2.0, 0);
	input_bullet_info(&bullet_info[7], 16, 16, 9, 2.5, 1);
	input_bullet_info(&bullet_info[8], 12, 18, 10, 1.5, 0);
	input_bullet_info(&bullet_info[9], 13, 19, 3, 2.0, 0);
	input_bullet_info(&bullet_info[10], 8, 8, 8, 1.0, 0);
	input_bullet_info(&bullet_info[11], 35, 32, 8, 2.0, 0);
}

/*ここは後からきちんとセットします*/
int back_knd[DANMAKU_MAX] = {
	0,1,0,1,1,
	0,1,0,1,0,1,1,1,
};
int boss_hp[DANMAKU_MAX] = {
	5000,10000,6000,10000,12000,
	12000,30000,14000,25000,16000,35000,40000,50000,
};
/*ここまで*/

//ゲームの初期化
void ini() {
	stage_count = 1;
	memset(&ch, 0, sizeof(ch_t));
	memset(enemy, 0, sizeof(enemy_t)*ENEMY_MAX);
	memset(lazer, 0, sizeof(lazer_t)*LAZER_MAX);
	memset(enemy_order, 0, sizeof(enemy_order_t)*ENEMY_ORDER_MAX);
	memset(shot, 0, sizeof(shot_t)*SHOT_MAX);
	memset(cshot, 0, sizeof(cshot_t)*CSHOT_MAX);
	memset(effect, 0, sizeof(effect_t)*EFFECT_MAX);
	memset(del_effect, 0, sizeof(del_effect_t)*DEL_EFFECT_MAX);
	memset(&bom, 0, sizeof(bom_t));
	memset(&bright_set, 0, sizeof(bright_set_t));
	memset(&dn, 0, sizeof(dn_t));
	memset(&boss, 0, sizeof(boss_t));
	memset(&emperor_time, 0, sizeof(emperor_time_t));
	memset(&charge_bom, 0, sizeof(charge_bom_t));
	memset(child, 0, sizeof(child_t)*CHILD_MAX);
	memset(&stage_title, 0, sizeof(stage_title_t));
	memset(&clear, 0, sizeof(clear_t));
	memset(item, 0, sizeof(item_t)*ITEM_MAX);
	memset(&area, 0, sizeof(area_t));//(48)
	memset(option_bb, 0, sizeof(option_bb_t) * 4);//(49)
	memset(&save_data, 0, sizeof(save_data_t));

	ch.x = FMX / 2;
	ch.y = FMY * 3 / 4;
	ch.power = 0;//初期パワー
	ch.num = 3;//初期残機数
	ch.gauge = 0;
	ch.gauge_flag = 1;

	emperor_time.flag = 0;			//エンペラータイムの初期設定
	emperor_time.cnt = 0;
	emperor_time.num = 3;
	emperor_time.spd_rate = 1;

	charge_bom.flag = 0;			//チャージボムの初期設定

	stage_title.appear_cnt = stage_title_count[stage];

	/*弾幕それぞれの設定。後々きちんと設定しましょう。*/
	//	boss.appear_count[0]=1700;//中ボスが出現する時刻(42)
	boss.appear_count[0] = 2660;//中ボスが出現する時刻(42)(47)
	boss.appear_count[1] = 6080;//最後ボスが出現する時刻(44)(47)

	boss.danmaku_num[0] = 4;//中ボスが何個目までの弾幕を出すか
	boss.danmaku_num[1] = 12;//最後に出るボスが何個目までの弾幕を出すか(47)

	for (int i = 0; i<DANMAKU_MAX; i++) {//弾幕それぞれのHP(47)
		boss.set_hp[i] = boss_hp[i];
	}
	boss.hp_max = boss.set_hp[0];
	for (int i = 0; i<DANMAKU_MAX; i++)//弾幕それぞれの背景の種類
		boss.back_knd[i] = back_knd[i];
	/*ここまで*/

	area.bgm.flag = 0;//音楽再生フラグを初期化(48)
	area.bgm.knd[0] = 0;//通常BGMをどういうタイミングで再生するか、取り決めはmusic.cpp(48)
	area.bgm.knd[1] = 0;//ボスBGMをどういうタイミングで再生するか、取り決めはmusic.cpp(48)
	area.bgm.loop_pos[0] = 26672;//通常BGMのループ位置(48)
	area.bgm.loop_pos[1] = 27010;//ボスBGMのループ位置(48)
	//area.bgm.loop_pos[0] = 0;//通常BGMのループ位置(48)
	//area.bgm.loop_pos[1] = 0;//ボスBGMのループ位置(48)

	//option_bb[0].img = img_cshot[2];//オプションボンボンの画像代入(49)
	//option_bb[1].img = img_cshot[2];
	//option_bb[2].img = img_cshot[2];
	//option_bb[3].img = img_cshot[2];

	option_bb[0].img = img_option[0];//オプションボンボンの画像代入(49)
	option_bb[1].img = img_option[2];
	option_bb[2].img = img_option[1];
	option_bb[3].img = img_option[3];

	bright_set.brt = 255;//初期輝度は最大
}