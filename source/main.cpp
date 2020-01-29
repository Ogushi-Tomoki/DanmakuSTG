#define GLOBAL_INSTANCE 
#include "../include/GV.h"

//���[�v�ŕK���s���R�又��
int ProcessLoop() {
	if (ProcessMessage() != 0)return -1;//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if (ClearDrawScreen() != 0)return -1;//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	GetHitKeyStateAll_2();//���݂̃L�[���͏������s��
	GetHitPadStateAll();  //���݂̃p�b�h���͏������s��
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//ChangeWindowMode(TRUE);//�E�B���h�E���[�h
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//�������Ɨ���ʉ�

	menu_t MenuElement[3] = {
		{200, 190, "�Q�[���X�^�[�g"},
		{200, 240, "�ݒ�"},
		{200, 290, "�Q�[���I��"},
	};
	int MenuLength = ARRAY_LENGTH(MenuElement);
	int SelectNum = 0;		//���݂̑I��ԍ�
	int SettingNum = 0;

	menu_t PoseElement[3] = {
		{150, 190, "�Q�[���ĊJ"},
		{150, 240, "���j���[��ʂɖ߂�"},
		{150, 290, "�ŏ������蒼��"},
	};
	int PoseLength = ARRAY_LENGTH(PoseElement);
	int PoseNum = 0;

	while (ProcessLoop() == 0) {//���C�����[�v
		music_ini();
		switch (func_state) {
			case 0://����̂ݓ��鏈��
				load();		//�f�[�^���[�h
				first_ini();//����̏�����
				func_state = 50;
				break;
			case 50://���j���[���
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
						DrawFormatString(MenuElement[i].x - 50, MenuElement[i].y, GetColor(255, 255, 255), "��");
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
			case 99://STG���n�߂�O�ɍs��������
				ini();
				load_story();
				func_state = 100;
				break;
			case 100://�ʏ폈��
				enter_func_tm("�ŏ�");
				calc_ch();       enter_func_tm("�L�����v�Z");
				ch_move();       enter_func_tm("�L�����ړ�");
				cshot_main();    enter_func_tm("���@�V���b�g���C��");
				enemy_main();	 enter_func_tm("�G�������C��");
				boss_shot_main(); enter_func_tm("�{�X�V���b�g���C��");
				shot_main();	 enter_func_tm("�V���b�g���C��");
				out_main();  	 enter_func_tm("�����蔻��");
				effect_main();   enter_func_tm("�G�t�F�N�g���C��");
				calc_main();	 enter_func_tm("�v�Z���C��");
				graph_main();    enter_func_tm("�`�惁�C��");
				bgm_main();		 enter_func_tm("BGM���C��");
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
			case 101://�ꎞ��~���
				graph_main();    enter_func_tm("�`�惁�C��");
				bgm_main();		 enter_func_tm("BGM���C��");
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
						DrawFormatString(PoseElement[i].x - 50, PoseElement[i].y, GetColor(255, 255, 255), "��");
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
				printfDx("�s����func_state\n");
				break;
		}
		music_play();			 enter_func_tm("���y�Đ�");
		fps_wait();				 enter_func_tm("�ҋ@��������", 1);
		//if (CheckStateKey(KEY_INPUT_ESCAPE) == 1) break;	//�G�X�P�[�v�����͂��ꂽ��u���C�N
		ScreenFlip();//����ʔ��f
		count++;
	}
	MAINLOOP_END:
	DxLib_End();//�c�w���C�u�����I������
	return 0;
}
