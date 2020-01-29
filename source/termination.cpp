#include "../include/GV.h"

//強制終了したときに呼び出される関数
void termination() {

	stage_count = 0;

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
	memset(child, 0, sizeof(child_t)*CHILD_MAX);
	memset(&stage_title, 0, sizeof(stage_title_t));
	memset(&clear, 0, sizeof(clear_t));
	memset(item, 0, sizeof(item_t)*ITEM_MAX);
	memset(&area, 0, sizeof(area_t));//(48)
	memset(option_bb, 0, sizeof(option_bb_t) * 4);
	memset(&save_data, 0, sizeof(save_data_t));
	memset(&boss_shot, 0, sizeof(boss_shot_t));//ボスの弾幕情報を初期化
	memset(&lazer, 0, sizeof(lazer_t)*LAZER_MAX);//ボスのレーザー情報を初期化

	boss.hp_max = 1;

	if (stage_title.img != NULL) {
		DeleteGraph(stage_title.img);//画像解放
	}
}