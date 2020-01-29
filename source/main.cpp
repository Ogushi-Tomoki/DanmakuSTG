#define GLOBAL_INSTANCE 
#include "../include/GV.h"

//ループで必ず行う３大処理
int ProcessLoop() {
	if (ProcessMessage() != 0)return -1;//プロセス処理がエラーなら-1を返す
	if (ClearDrawScreen() != 0)return -1;//画面クリア処理がエラーなら-1を返す
	GetHitKeyStateAll_2();//現在のキー入力処理を行う
	GetHitPadStateAll();  //現在のパッド入力処理を行う
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//ChangeWindowMode(TRUE);//ウィンドウモード
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//初期化と裏画面化

	menu_t MenuElement[3] = {
		{200, 190, "ゲームスタート"},
		{200, 240, "設定"},
		{200, 290, "ゲーム終了"},
	};
	int MenuLength = ARRAY_LENGTH(MenuElement);
	int SelectNum = 0;		//現在の選択番号
	int SettingNum = 0;

	menu_t PoseElement[3] = {
		{150, 190, "ゲーム再開"},
		{150, 240, "メニュー画面に戻る"},
		{150, 290, "最初からやり直し"},
	};
	int PoseLength = ARRAY_LENGTH(PoseElement);
	int PoseNum = 0;

	while (ProcessLoop() == 0) {//メインループ
		music_ini();
		switch (func_state) {
			case 0://初回のみ入る処理
				load();		//データロード
				first_ini();//初回の初期化
				func_state = 50;
				break;
			case 50://メニュー画面
				if (pad.key[configpad.down] == 1) {
					SelectNum = (SelectNum + 1) % MenuLength;
					se_flag[5] = 1;
				}
				else if (pad.key[configpad.up] == 1) {
					SelectNum = (SelectNum + MenuLength - 1) % MenuLength;
					se_flag[5] = 1;
				}
				for (int i = 0; i < MenuLength; i++) {
					DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(255, 255, 255), MenuElement[i].name);
					if (SelectNum == i) {
						DrawFormatString(MenuElement[i].x - 50, MenuElement[i].y, GetColor(255, 255, 255), "＞");
					}
				}
				if (SelectNum == 0 && pad.key[configpad.shot] == 1) {
					se_flag[6] = 1;
					func_state = 99;
				}
				else if (SelectNum == 1 && pad.key[configpad.shot] == 1) {
					se_flag[6] = 1;
					func_state = 60;
				}
				else if (SelectNum == 2 && pad.key[configpad.shot] == 1) {
					se_flag[6] = 1;
					goto MAINLOOP_END;
				}
				break;
			case 60:
				set_config(&SettingNum);
				break;
			case 99://STGを始める前に行う初期化
				ini();
				load_story();
				func_state = 100;
				break;
			case 100://通常処理
				enter_func_tm("最初");
				calc_ch();       enter_func_tm("キャラ計算");
				ch_move();       enter_func_tm("キャラ移動");
				cshot_main();    enter_func_tm("自機ショットメイン");
				enemy_main();	 enter_func_tm("敵処理メイン");
				boss_shot_main(); enter_func_tm("ボスショットメイン");
				shot_main();	 enter_func_tm("ショットメイン");
				out_main();  	 enter_func_tm("当たり判定");
				effect_main();   enter_func_tm("エフェクトメイン");
				calc_main();	 enter_func_tm("計算メイン");
				graph_main();    enter_func_tm("描画メイン");
				bgm_main();		 enter_func_tm("BGMメイン");
				if (boss.flag == 0) {
					if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
						stage_count++;
					}
				}
				if (pad.key[configpad.start] == 1) {
					/*StopSoundMem(area.bgm.handle);
					delete_bgm();
					termination();*/
					func_state = 101;
				}
				break;
			case 101://一時停止状態
				graph_main();    enter_func_tm("描画メイン");
				bgm_main();		 enter_func_tm("BGMメイン");
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
				DrawRotaGraph(FX + FMX / 2, FY + FMY / 2, 1.0, 0.0, img_board[30], TRUE, FALSE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				if (pad.key[configpad.down] == 1) {
					PoseNum = (PoseNum + 1) % PoseLength;
					for (int i = 0; i < PoseLength; i++) {
					}
					se_flag[5] = 1;
				}
				else if (pad.key[configpad.up] == 1) {
					PoseNum = (PoseNum + PoseLength - 1) % PoseLength;
					se_flag[5] = 1;
				}
				for (int i = 0; i < PoseLength; i++) {
					DrawFormatString(PoseElement[i].x, PoseElement[i].y, GetColor(255, 255, 255), PoseElement[i].name);
					if (PoseNum == i) {
						DrawFormatString(PoseElement[i].x - 50, PoseElement[i].y, GetColor(255, 255, 255), "＞");
					}
				}
				if (PoseNum == 0 && pad.key[configpad.shot] == 1) {
					se_flag[6] = 1;
					func_state = 100;
				}
				else if (PoseNum == 1 && pad.key[configpad.shot] == 1) {
					se_flag[6] = 1;
					PoseNum = 0;
					StopSoundMem(area.bgm.handle);
					delete_bgm();
					termination();
					func_state = 50;
				}
				else if (PoseNum == 2 && pad.key[configpad.shot] == 1) {
					se_flag[6] = 1;
					PoseNum = 0;
					StopSoundMem(area.bgm.handle);
					delete_bgm();
					termination();
					func_state = 99;
				}
				if (pad.key[configpad.start] == 1) {
					PoseNum = 0;
					func_state = 100;
				}
				break;
			default:
				printfDx("不明なfunc_state\n");
				break;
		}
		music_play();			 enter_func_tm("音楽再生");
		fps_wait();				 enter_func_tm("待機した時間", 1);
		//if (CheckStateKey(KEY_INPUT_ESCAPE) == 1) break;	//エスケープが入力されたらブレイク
		ScreenFlip();//裏画面反映
		count++;
	}
	MAINLOOP_END:
	DxLib_End();//ＤＸライブラリ終了処理
	return 0;
}
