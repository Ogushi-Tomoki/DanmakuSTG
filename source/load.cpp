#include "../include/GV.h"

void load() {
	int t;
	SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMPRESS);

	t = GetNowCount();
	img_board[10] = LoadGraph("../dat/img/board/10.png");
	img_board[11] = LoadGraph("../dat/img/board/11.png");
	img_board[12] = LoadGraph("../dat/img/board/12.png");
	img_board[20] = LoadGraph("../dat/img/board/20.png");
	img_board[30] = LoadGraph("../dat/img/board/kekka_board.png");
	img_chetc[0] = LoadGraph("../dat/img/char/atari.png");
	//	img_chetc[2]	= LoadGraph( "../dat/img/char/ball.png" );
	img_eff_bom[0] = LoadGraph("../dat/img/effect/bom0.png");
	img_eff_bom[1] = LoadGraph("../dat/img/effect/bom1.png");
	img_eff_bom[2] = LoadGraph("../dat/img/char/body.png");
	img_eff_bom[3] = LoadGraph("../dat/img/bullet/bom_title0.png");
	img_eff_bom[4] = LoadGraph("../dat/img/effect/superbom.png");
	img_etc[1] = LoadGraph("../dat/img/enemy/hp.png");
	img_etc[2] = LoadGraph("../dat/img/enemy/bossback.png");
	img_etc[5] = LoadGraph("../dat/img/enemy/bossback3.png");
	img_etc[6] = LoadGraph("../dat/img/enemy/bossback4.png");
	img_etc[7] = LoadGraph("../dat/img/enemy/hp_boss.png");//ボスのHP
	img_etc[8] = LoadGraph("../dat/img/board/hoshi.png");//☆(41)
	LoadDivGraph("../dat/img/bullet/b0.png", 5, 5, 1, 76, 76, img_bullet[0]);
	LoadDivGraph("../dat/img/bullet/b1.png", 6, 6, 1, 22, 22, img_bullet[1]);
	LoadDivGraph("../dat/img/bullet/b2.png", 10, 10, 1, 5, 120, img_bullet[2]);
	LoadDivGraph("../dat/img/bullet/b3.png", 5, 5, 1, 19, 34, img_bullet[3]);
	LoadDivGraph("../dat/img/bullet/b4.png", 10, 10, 1, 38, 38, img_bullet[4]);
	LoadDivGraph("../dat/img/bullet/b5.png", 3, 3, 1, 14, 16, img_bullet[5]);
	LoadDivGraph("../dat/img/bullet/b6.png", 3, 3, 1, 14, 18, img_bullet[6]);
	LoadDivGraph("../dat/img/bullet/b7.png", 10, 10, 1, 16, 16, img_bullet[7]);
	LoadDivGraph("../dat/img/bullet/b8.png", 10, 10, 1, 12, 18, img_bullet[8]);
	LoadDivGraph("../dat/img/bullet/b9.png", 3, 3, 1, 13, 19, img_bullet[9]);
	LoadDivGraph("../dat/img/bullet/b10.png", 8, 8, 1, 8, 8, img_bullet[10]);
	LoadDivGraph("../dat/img/bullet/b11.png", 8, 8, 1, 35, 32, img_bullet[11]);
	LoadDivGraph("../dat/img/bullet/l0.png", 2, 2, 1, 30, 460, img_lazer[0]);
	LoadDivGraph("../dat/img/bullet/l0_moto.png", 2, 2, 1, 70, 70, img_lazer_moto[0]);
	LoadDivGraph("../dat/img/enemy/hit_effect.png", 5, 5, 1, 140, 140, img_del_effect);
	LoadDivGraph("../dat/img/char/riria.png", 8, 8, 1, 100, 100, img_dot_riria);
	LoadDivGraph("../dat/img/char/0.png", 12, 4, 3, 73, 73, img_ch[0]);
	LoadDivGraph("../dat/img/enemy/0.png", 9, 3, 3, 32, 32, img_enemy[0]);
	LoadDivGraph("../dat/img/item/p0.png", 2, 2, 1, 35, 35, img_item[0]);
	LoadDivGraph("../dat/img/item/p1.png", 2, 2, 1, 35, 35, img_item[1]);
	LoadDivGraph("../dat/img/item/p2.png", 2, 2, 1, 15, 15, img_item[2]);
	LoadDivGraph("../dat/img/item/p3.png", 2, 2, 1, 35, 35, img_item[3]);
	LoadDivGraph("../dat/img/item/p4.png", 2, 2, 1, 35, 35, img_item[4]);
	LoadDivGraph("../dat/img/item/p5.png", 2, 2, 1, 35, 35, img_item[5]);
	LoadDivGraph("../dat/img/num/2.png", 10, 10, 1, 16, 18, img_num[0]);//(41)
	LoadDivGraph("../dat/img/char/option.png", 4, 1, 4, 18, 32, img_option);
	LoadDivGraph("../dat/img/effect/bakuhatsu.png", 6, 6, 1, 32, 32, img_bakuhatsu);
	img_boss[0] = LoadGraph("../dat/img/char/middle_boss.png");
	img_boss[1] = LoadGraph("../dat/img/char/last_boss.png");
	img_cshot[0] = LoadGraph("../dat/img/char/bl_03.png");
	img_cshot[1] = LoadGraph("../dat/img/char/bl_02.png");
	img_cshot[2] = LoadGraph("../dat/img/char/ball.png");
	img_back[0] = LoadGraph("../dat/img/back/0/back0.png");
	img_back[10] = LoadGraph("../dat/img/back/10/kotei0.png");
	img_back[11] = LoadGraph("../dat/img/back/10/scroll0.png");
	sound_se[0] = LoadSoundMem("../dat/se/enemy_shot.wav");
	sound_se[1] = LoadSoundMem("../dat/se/enemy_death.wav");
	sound_se[2] = LoadSoundMem("../dat/se/cshot2.wav");
	sound_se[3] = LoadSoundMem("../dat/se/char_death.wav");
	sound_se[4] = LoadSoundMem("../dat/se/cannon2.wav");
	sound_se[5] = LoadSoundMem("../dat/se/cursor7.wav");
	sound_se[6] = LoadSoundMem("../dat/se/decision.wav");
	sound_se[8] = LoadSoundMem("../dat/se/hit.wav");
	sound_se[9] = LoadSoundMem("../dat/se/boss_death.wav");
	sound_se[11] = LoadSoundMem("../dat/se/boss_change.wav");
	sound_se[12] = LoadSoundMem("../dat/se/full_charge.wav");
	sound_se[14] = LoadSoundMem("../dat/se/bom0.wav");
	sound_se[15] = LoadSoundMem("../dat/se/bom1.wav");
	sound_se[16] = LoadSoundMem("../dat/se/emperor_time_start.wav");
	sound_se[17] = LoadSoundMem("../dat/se/emperor_time_end.wav");
	sound_se[33] = LoadSoundMem("../dat/se/lazer.wav");
	sound_se[34] = LoadSoundMem("../dat/se/item_get.wav");
	//sound_se[99]=LoadSoundMem("../dat/music/youmu.wav");//反魂蝶のBGMを再生する場合はココに音楽ファイルを用意して下さい

	ChangeVolumeSoundMem(255 * 70 / 100, sound_se[0]);		//各素材の再生ボリュームを設定
	ChangeVolumeSoundMem(255 * 70 / 100, sound_se[1]);
	//ChangeVolumeSoundMem(255 * 50 / 100, sound_se[2]);
	//ChangeVolumeSoundMem(255 * 30 / 100, sound_se[3]);
	//ChangeVolumeSoundMem(255 * 30 / 100, sound_se[8]);
	//ChangeVolumeSoundMem(255 * 30 / 100, sound_se[9]);
	//ChangeVolumeSoundMem(255 * 20 / 100, sound_se[11]);
	//ChangeVolumeSoundMem(255 * 50 / 100, sound_se[14]);
	//ChangeVolumeSoundMem(255 * 50 / 100, sound_se[15]);
	//ChangeVolumeSoundMem(255 * 30 / 100, sound_se[33]);
	//ChangeVolumeSoundMem(255 * 60 / 100, sound_se[34]);
	ChangeVolumeSoundMem(255 * 90 / 100, sound_se[4]);
	ChangeVolumeSoundMem(255 * 60 / 100, sound_se[5]);

	color[0] = GetColor(255, 255, 255);//白
	color[1] = GetColor(0, 0, 0);//黒
	color[2] = GetColor(255, 0, 0);//赤
	color[3] = GetColor(0, 255, 0);//緑
	color[4] = GetColor(0, 0, 255);//青
	color[5] = GetColor(255, 255, 0);//黄色
	color[6] = GetColor(0, 255, 255);//青緑
	color[7] = GetColor(255, 0, 255);//紫

	font[0] = CreateFontToHandle("HGPｺﾞｼｯｸE", 15, 2, DX_FONTTYPE_ANTIALIASING_EDGE);
}

//敵の出現情報をエクセルから読み込んで格納する関数
void load_story() {
	int n, num, i, fp;
	char fname[32] = { "../dat/csv/47章/storyH1.csv" };
	int input[64];
	char inputc[64];

	fp = FileRead_open(fname);//ファイル読み込み
	if (fp == NULL) {
		printfDx("read error\n");
		return;
	}
	for (i = 0; i<2; i++)//最初の2行読み飛ばす
		while (FileRead_getc(fp) != '\n');

	n = 0, num = 0;
	while (1) {
		for (i = 0; i<64; i++) {
			inputc[i] = input[i] = FileRead_getc(fp);//1文字取得する
			if (inputc[i] == '/') {//スラッシュがあれば
				while (FileRead_getc(fp) != '\n');//改行までループ
				i = -1;//カウンタを最初に戻して
				continue;
			}
			if (input[i] == ',' || input[i] == '\n') {//カンマか改行なら
				inputc[i] = '\0';//そこまでを文字列とし
				break;
			}
			if (input[i] == EOF) {//ファイルの終わりなら
				goto EXFILE;//終了
			}
		}
		switch (num) {
		case 0:	enemy_order[n].cnt = atoi(inputc); break;
		case 1:	enemy_order[n].pattern = atoi(inputc); break;
		case 2:	enemy_order[n].knd = atoi(inputc); break;
		case 3:	enemy_order[n].x = atof(inputc); break;
		case 4:	enemy_order[n].y = atof(inputc); break;
		case 5:	enemy_order[n].sp = atof(inputc); break;
		case 6:	enemy_order[n].bltime = atoi(inputc); break;
		case 7:	enemy_order[n].blknd = atoi(inputc); break;
		case 8:	enemy_order[n].col = atoi(inputc); break;
		case 9:	enemy_order[n].hp = atoi(inputc); break;
		case 10:enemy_order[n].blknd2 = atoi(inputc); break;
		case 11:enemy_order[n].wait = atoi(inputc); break;
		case 12:enemy_order[n].item_n[0] = atoi(inputc); break;
		case 13:enemy_order[n].item_n[1] = atoi(inputc); break;
		case 14:enemy_order[n].item_n[2] = atoi(inputc); break;
		case 15:enemy_order[n].item_n[3] = atoi(inputc); break;
		case 16:enemy_order[n].item_n[4] = atoi(inputc); break;
		case 17:enemy_order[n].item_n[5] = atoi(inputc); break;
		}
		num++;
		if (num == 18) {
			num = 0;
			n++;
		}
	}
EXFILE:
	FileRead_close(fp);
}
