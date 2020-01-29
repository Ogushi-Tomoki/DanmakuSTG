#include "../include/GV.h"

setting_menu_t SettingMenuElement[8] = {
	{ 150, 90, "ショット", 9 },
	{ 150, 130, "ボム", 4 },
	{ 150, 170, "低速移動", 8 },
	{ 150, 210, "スタート", 11 },
	{ 150, 250, "セレクト", 10 },
	{ 150, 290, "スペシャル", 5 },
	{ 150, 330, "初期化" },
	{ 150, 370, "戻る" },
};
int MenuLength = ARRAY_LENGTH(SettingMenuElement);

void set_config(int* SettingNum) {
	if (setting_menu_count == 0) {
		SettingMenuElement[0].key = configpad.shot;
		SettingMenuElement[1].key = configpad.bom;
		SettingMenuElement[2].key = configpad.slow;
		SettingMenuElement[3].key = configpad.start;
		SettingMenuElement[4].key = configpad.change;
		SettingMenuElement[5].key = configpad.special;
	}

	if (pad.key[configpad.down] == 1) {
		*SettingNum = (*SettingNum + 1) % MenuLength;
		se_flag[5] = 1;
	}
	else if (pad.key[configpad.up] == 1) {
		*SettingNum = (*SettingNum + MenuLength - 1) % MenuLength;
		se_flag[5] = 1;
	}
	for (int i = 0; i < MenuLength; i++) {
		DrawFormatString(SettingMenuElement[i].x, SettingMenuElement[i].y, GetColor(255, 255, 255), SettingMenuElement[i].name);
		if (i <= 5) {
			DrawFormatString(SettingMenuElement[i].x + 100, SettingMenuElement[i].y, GetColor(255, 255, 255), "%d", SettingMenuElement[i].key);
		}
		if (i == *SettingNum) {
			DrawFormatString(SettingMenuElement[i].x - 50, SettingMenuElement[i].y, GetColor(255, 255, 255), "＞");
		}
	}
	if (*SettingNum == 0) {
		for (int i = 4; i < 16; i++) {
			if (pad.key[i] == 1) {
				SettingMenuElement[0].key = i;
			}
		}
	}
	else if (*SettingNum == 1) {
		for (int i = 4; i < 16; i++) {
			if (pad.key[i] == 1) {
				SettingMenuElement[1].key = i;
			}
		}
	}
	else if (*SettingNum == 2) {
		for (int i = 4; i < 16; i++) {
			if (pad.key[i] == 1) {
				SettingMenuElement[2].key = i;
			}
		}
	}
	else if (*SettingNum == 3) {
		for (int i = 4; i < 16; i++) {
			if (pad.key[i] == 1) {
				SettingMenuElement[3].key = i;
			}
		}
	}
	else if (*SettingNum == 4) {
		for (int i = 4; i < 16; i++) {
			if (pad.key[i] == 1) {
				SettingMenuElement[4].key = i;
			}
		}
	}
	else if (*SettingNum == 5) {
		for (int i = 4; i < 16; i++) {
			if (pad.key[i] == 1) {
				SettingMenuElement[5].key = i;
			}
		}
	}
	else if (*SettingNum == 6 && pad.key[configpad.shot] == 1) {
		SettingMenuElement[0].key = 9;
		SettingMenuElement[1].key = 4;
		SettingMenuElement[2].key = 8;
		SettingMenuElement[3].key = 11;
		SettingMenuElement[4].key = 10;
		SettingMenuElement[5].key = 5;
		se_flag[6] = 1;
	}
	else if (*SettingNum == 7 && pad.key[configpad.shot] == 1) {
		//設定画面初期化
		*SettingNum = 0;
		setting_menu_count = 0;

		//更新したコンフィグをセーブしておく
		save_data = { SettingMenuElement[0].key, SettingMenuElement[1].key, SettingMenuElement[2].key, SettingMenuElement[3].key, SettingMenuElement[4].key, SettingMenuElement[5].key, HiScore };
		DataSave(&save_data);

		//設定したキーを変数に割り振る
		configpad.shot = save_data.shot;
		configpad.bom = save_data.bom;
		configpad.slow = save_data.slow;
		configpad.start = save_data.start;
		configpad.change = save_data.select;
		configpad.special = save_data.special;

		se_flag[6] = 1;

		func_state = 50;
	}

	setting_menu_count++;
}