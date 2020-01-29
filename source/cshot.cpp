#include "../include/GV.h"

int cshot0num[2] = { 2,4 };
int cshot0pos_x[4] = { -10, 10,-30, 30 };
int cshot0pos_y[4] = { -30,-30,-10,-10 };

#define OPTION_X 25
#define OPTION_Y 25
#define OPTION_2X 15
#define OPTION_2Y 20
int option0num[2] = { 2,4 };
double option0ang[4] = { -PI / 2,-PI / 2,-PI / 2 - PI / 6,-PI / 2 + PI / 6 };//�I�v�V�����̔��ˊp�x(49)

																			 //���@�V���b�g�̓o�^�\�ԍ���Ԃ�
int search_cshot() {
	for (int i = 0; i<CSHOT_MAX; i++) {
		if (cshot[i].flag == 0)
			return i;
	}
	return -1;
}

////�ʏ�V���b�g�o�^
//void ch0_shot_pattern() {
//	int k;
//	int n = cshot0num[ch.power<200 ? 0 : 1];
//	for (int i = 0; i<n; i++) {
//		if ((k = search_cshot()) != -1) {
//			cshot[k].flag = 1;
//			cshot[k].cnt = 0;
//			cshot[k].angle = -PI / 2;
//			cshot[k].spd = 20;
//			cshot[k].x = ch.x + cshot0pos_x[i];
//			cshot[k].y = ch.y + cshot0pos_y[i];
//			cshot[k].power = (n<2 ? 20 : 12) + ch.power / 100;//2�؂Ȃ�20,4�؂Ȃ�12(50)
//			cshot[k].knd = 0;
//			cshot[k].img = img_cshot[0];//�摜�ԍ����(49)
//		}
//	}
//	se_flag[2] = 1;//���ˉ��I��
//	if (ch.power >= 100) {
//		for (int i = 0; i<(ch.power<300 ? 2 : 4); i++) {
//			if ((k = search_cshot()) != -1) {
//				cshot[k].flag = 1;
//				cshot[k].cnt = 0;
//				cshot[k].angle = option0ang[i];
//				cshot[k].spd = 20;
//				cshot[k].x = option_bb[i % 2].x;
//				cshot[k].y = option_bb[i % 2].y;
//				cshot[k].power = 10 - 7 * (i / 2);//�}�C�i�X�ɂȂ�Ȃ��悤����(50)
//				cshot[k].knd = 1;
//				cshot[k].img = img_cshot[1];//�摜�ԍ����(49)
//			}
//		}
//	}
//}

//�ʏ�V���b�g�o�^
void ch0_shot_pattern() {
	int k;
	int n = (int)ch.power / 100;
	if (ch.shot_cnt % ch.cycle == 0) {
		for (int i = 0; i<2; i++) {
			if ((k = search_cshot()) != -1) {
				cshot[k].flag = 1;
				cshot[k].cnt = 0;
				cshot[k].angle = -PI / 2;
				cshot[k].spd = 12;
				cshot[k].x = ch.x + cshot0pos_x[i];
				cshot[k].y = ch.y + 10;
				cshot[k].knd = 0;
				cshot[k].img = img_cshot[0];//�摜�ԍ����
				switch (n) {
					case 0:
						cshot[k].power = 65;
						break;
					case 1:
						cshot[k].power = 55;
						break;
					case 2:
						cshot[k].power = 48;
						break;
					case 3:
						cshot[k].power = 40;
						break;
					case 4:
						cshot[k].power = 22;
						break;
					default:
						cshot[k].power = 22;
						break;
				}
			}
		}
		se_flag[2] = 1;//���ˉ��I��
	}
	switch (n) {
		case 1:
			if (ch.shot_cnt % 120 == 0) {
				if ((k = search_cshot()) != -1) {
					cshot[k].flag = 1;
					cshot[k].cnt = 0;
					cshot[k].angle = option0ang[0];
					cshot[k].spd = 6;
					cshot[k].x = option_bb[0 % 2].x;
					cshot[k].y = option_bb[0 % 2].y;
					cshot[k].power = 400;
					cshot[k].knd = 1;
					cshot[k].img = img_cshot[1];//�摜�ԍ����
				}
				se_flag[4] = 1;
			}
			break;
		case 2:
			if (ch.shot_cnt % 60 == 0) {
				for (int i = 0; i<2; i++) {
					int lr = (ch.shot_cnt % 120) / 60;
					if (i == lr) {
						if ((k = search_cshot()) != -1) {
							cshot[k].flag = 1;
							cshot[k].cnt = 0;
							cshot[k].angle = option0ang[i];
							cshot[k].spd = 6;
							cshot[k].x = option_bb[i % 2].x;
							cshot[k].y = option_bb[i % 2].y;
							cshot[k].power = 360;
							cshot[k].knd = 1;
							cshot[k].img = img_cshot[1];//�摜�ԍ����
						}
					}
				}
				se_flag[4] = 1;
			}
			break;
		case 3:
			if (ch.shot_cnt % 30 == 0) {
				for (int i = 0; i<2; i++) {
					int lr = (ch.shot_cnt % 60) / 30;
					if (i == lr) {
						if ((k = search_cshot()) != -1) {
							cshot[k].flag = 1;
							cshot[k].cnt = 0;
							cshot[k].angle = option0ang[i];
							cshot[k].spd = 6;
							cshot[k].x = option_bb[i % 2].x;
							cshot[k].y = option_bb[i % 2].y;
							cshot[k].power = 230;
							cshot[k].knd = 1;
							cshot[k].img = img_cshot[1];//�摜�ԍ����
						}
					}
				}
				se_flag[4] = 1;
			}
			break;
		case 4:
			if (ch.shot_cnt % 15 == 0) {
				for (int i = 0; i<4; i++) {
					int lr = (ch.shot_cnt % 60) / 15;
					if (i == lr) {
						if ((k = search_cshot()) != -1) {
							cshot[k].flag = 1;
							cshot[k].cnt = 0;
							cshot[k].angle = option0ang[i];
							cshot[k].spd = 6;
							cshot[k].x = option_bb[i % 4].x;
							cshot[k].y = option_bb[i % 4].y;
							cshot[k].power = 155;
							cshot[k].knd = 1;
							cshot[k].img = img_cshot[1];//�摜�ԍ����
						}
					}
				}
				se_flag[4] = 1;
			}
			break;
	}
}

////�ᑬ�ʏ�V���b�g�o�^
//void ch1_shot_pattern() {
//	int k;
//	int n = cshot0num[ch.power<200 ? 0 : 1];
//	for (int i = 0; i<n; i++) {
//		if ((k = search_cshot()) != -1) {
//			cshot[k].flag = 1;
//			cshot[k].cnt = 0;
//			cshot[k].angle = -PI / 2;
//			cshot[k].spd = 20;
//			cshot[k].x = ch.x + cshot0pos_x[i] / 3;//�ᑬ���Ȃ�ʒu�𒆐S����
//			cshot[k].y = ch.y + cshot0pos_y[i] / 2;
//			cshot[k].power = (n<2 ? 20 : 12) + ch.power / 100;//2�؂Ȃ�20,4�؂Ȃ�12(50)
//			cshot[k].knd = 0;
//			cshot[k].img = img_cshot[0];//�摜�ԍ����(49)
//		}
//	}
//	se_flag[2] = 1;
//	if (ch.power >= 100) {
//		for (int i = 0; i<(ch.power<300 ? 2 : 4); i++) {
//			if ((k = search_cshot()) != -1) {
//				cshot[k].flag = 1;
//				cshot[k].cnt = 0;
//				cshot[k].angle = option0ang[i];
//				cshot[k].spd = 20;
//				cshot[k].x = option_bb[i % 2].x;
//				cshot[k].y = option_bb[i % 2].y;
//				cshot[k].power = 10 - 7 * (i / 2);//�}�C�i�X�ɂȂ�Ȃ��悤����(50)
//				cshot[k].knd = 1;
//				cshot[k].img = img_cshot[1];//�摜�ԍ����(49)
//			}
//		}
//	}
//}

//�ᑬ�ʏ�V���b�g�o�^
void ch1_shot_pattern() {
	int k;
	int n = (int)ch.power / 100;
	if (ch.shot_cnt % ch.cycle == 0) {
		for (int i = 0; i<2; i++) {
			if ((k = search_cshot()) != -1) {
				cshot[k].flag = 1;
				cshot[k].cnt = 0;
				cshot[k].angle = -PI / 2;
				cshot[k].spd = 20;
				cshot[k].x = ch.x + cshot0pos_x[i] / 3;//�ᑬ���Ȃ�ʒu�𒆐S����
				cshot[k].y = ch.y + 10;
				cshot[k].knd = 0;
				cshot[k].img = img_cshot[0];//�摜�ԍ����(49)
				switch (n) {
					case 0:
						cshot[k].power = 65;
						break;
					case 1:
						cshot[k].power = 55;
						break;
					case 2:
						cshot[k].power = 48;
						break;
					case 3:
						cshot[k].power = 40;
						break;
					case 4:
						cshot[k].power = 22;
						break;
					default:
						cshot[k].power = 22;
						break;
				}
			}
		}
		se_flag[2] = 1;
	}
	switch (n) {
		case 1:
			if (ch.shot_cnt % 120 == 0) {
				if ((k = search_cshot()) != -1) {
					cshot[k].flag = 1;
					cshot[k].cnt = 0;
					cshot[k].angle = option0ang[0];
					cshot[k].spd = 6;
					cshot[k].x = option_bb[0 % 2].x;
					cshot[k].y = option_bb[0 % 2].y;
					cshot[k].power = 400;
					cshot[k].knd = 1;
					cshot[k].img = img_cshot[1];//�摜�ԍ����
				}
				se_flag[4] = 1;
			}
			break;
		case 2:
			if (ch.shot_cnt % 60 == 0) {
				for (int i = 0; i<2; i++) {
					int lr = (ch.shot_cnt % 120) / 60;
					if (i == lr) {
						if ((k = search_cshot()) != -1) {
							cshot[k].flag = 1;
							cshot[k].cnt = 0;
							cshot[k].angle = option0ang[i];
							cshot[k].spd = 6;
							cshot[k].x = option_bb[i % 2].x;
							cshot[k].y = option_bb[i % 2].y;
							cshot[k].power = 360;
							cshot[k].knd = 1;
							cshot[k].img = img_cshot[1];//�摜�ԍ����
						}
					}
				}
				se_flag[4] = 1;
			}
			break;
		case 3:
			if (ch.shot_cnt % 30 == 0) {
				for (int i = 0; i<2; i++) {
					int lr = (ch.shot_cnt % 60) / 30;
					if (i == lr) {
						if ((k = search_cshot()) != -1) {
							cshot[k].flag = 1;
							cshot[k].cnt = 0;
							cshot[k].angle = option0ang[i];
							cshot[k].spd = 6;
							cshot[k].x = option_bb[i % 2].x;
							cshot[k].y = option_bb[i % 2].y;
							cshot[k].power = 230;
							cshot[k].knd = 1;
							cshot[k].img = img_cshot[1];//�摜�ԍ����
						}
					}
				}
				se_flag[4] = 1;
			}
			break;
		case 4:
			if (ch.shot_cnt % 15 == 0) {
				for (int i = 0; i<4; i++) {
					int lr = (ch.shot_cnt % 60) / 15;
					if (i == lr) {
						if ((k = search_cshot()) != -1) {
							cshot[k].flag = 1;
							cshot[k].cnt = 0;
							cshot[k].angle = option0ang[i];
							cshot[k].spd = 6;
							cshot[k].x = option_bb[i % 4].x;
							cshot[k].y = option_bb[i % 4].y;
							cshot[k].power = 155;
							cshot[k].knd = 1;
							cshot[k].img = img_cshot[1];//�摜�ԍ����
						}
					}
				}
				se_flag[4] = 1;
			}
			break;
	}
}

//�I�v�V�����̂ڂ�ڂ�v�Z
void calc_option_bb() {
	if (ch.power >= 100 && ch.power < 200) {//�p���[100�ȏ�400�����Ȃ�I�v�V������2����
		if (CheckStatePad(configpad.slow) == 0) {//�ᑬ�ړ�������Ȃ��Ȃ�
			option_bb[0].x = ch.x + OPTION_X * -1;
			option_bb[0].y = ch.y + OPTION_Y + sin(PI2 / 150 * option_bb[0].cnt) * 10;
		}
		else {
			option_bb[0].x = ch.x + OPTION_X / 2 * -1;
			option_bb[0].y = ch.y + OPTION_Y / 2;
		}
		option_bb[0].cnt++;
		option_bb[0].flag = 1;
		option_bb[1].flag = 0;
		option_bb[2].flag = 0;
		option_bb[3].flag = 0;
	}
	else if (ch.power >= 200 && ch.power < 400) {//�p���[100�ȏ�400�����Ȃ�I�v�V������2����
		for (int i = 0; i<2; i++) {
			if (CheckStatePad(configpad.slow) == 0) {//�ᑬ�ړ�������Ȃ��Ȃ�
				option_bb[i].x = ch.x + OPTION_X * (i == 0 ? -1 : 1);
				option_bb[i].y = ch.y + OPTION_Y + sin(PI2 / 150 * option_bb[0].cnt) * 10;
			}
			else {
				option_bb[i].x = ch.x + OPTION_X / 2 * (i == 0 ? -1 : 1);
				option_bb[i].y = ch.y + OPTION_Y / 2;
			}
			option_bb[i].cnt++;
		}
		option_bb[0].flag = 1;
		option_bb[1].flag = 1;
		option_bb[2].flag = 0;
		option_bb[3].flag = 0;
	}
	else if (ch.power >= 400) {
		for (int i = 0; i<4; i++) {
			if (CheckStatePad(configpad.slow) == 0) {//�ᑬ�ړ�������Ȃ��Ȃ�
				option_bb[i].x = ch.x + (OPTION_X + OPTION_2X * (i > 1 ? 1 : 0)) * ((i % 2) == 0 ? -1 : 1);
				option_bb[i].y = ch.y + OPTION_Y - OPTION_2Y * (i > 1 ? 1 : 0) + sin(PI2 / 150 * option_bb[0].cnt) * 10;
			}
			else {
				option_bb[i].x = ch.x + (OPTION_X + OPTION_2X * (i > 1 ? 1 : 0)) / 2 * ((i % 2) == 0 ? -1 : 1);
				option_bb[i].y = ch.y + (OPTION_Y - OPTION_2Y * (i > 1 ? 1 : 0)) / 2;
			}
			option_bb[i].cnt++;
		}
		option_bb[0].flag = 1;
		option_bb[1].flag = 1;
		option_bb[2].flag = 1;
		option_bb[3].flag = 1;
	}
	else {
		option_bb[0].flag = 0;
		option_bb[1].flag = 0;
		option_bb[2].flag = 0;
		option_bb[3].flag = 0;
	}
}

//�V���b�g�o�^��
void enter_shot() {
	int n = (int)ch.power / 100;
	switch (n) {
		case 0:
			ch.cycle = 15;
			break;
		case 1:
			ch.cycle = 12;
			break;
		case 2:
			ch.cycle = 9;
			break;
		case 3:
			ch.cycle = 6;
			break;
		default:
			ch.cycle = 3;
			break;
	}
	//�V���b�g�{�^����������Ă�����
	if (CheckStatePad(configpad.shot)>0) {
		ch.shot_cnt++;
		if (CheckStatePad(configpad.slow)>0)//�ᑬ�ړ����Ȃ�
			ch1_shot_pattern();
		else
			ch0_shot_pattern();
	}
	else
		ch.shot_cnt = 0;
}

//��ԋ߂��G��T���Ċp�x���Z�b�g����
void calc_homing(int k) {
	int i, d, num = -1, min = -1;
	double x, y;
	if (boss.flag == 0) {//�{�X�����Ȃ���
		for (i = 0; i<ENEMY_MAX; i++) {//�G�̑�����
			if (enemy[i].flag == 1) {
				x = (enemy[i].x - cshot[k].x);
				y = (enemy[i].y - cshot[k].y);
				d = (int)(x*x + y * y);//�V���b�g�ƓG�̋���
				if (d<min || min == -1) {//�v�Z���ʂ��ŏ��l���܂��i�[���Ă��Ȃ��Ȃ�
					num = i;//�ԍ��L�^
					min = d;//�����L�^
				}
			}
		}
	}
	//�߂��G������������A���邢�̓{�X�����āAHP������Ƃ��͊p�x���Z�b�g
	if (num != -1 || boss.flag == 1 && boss.hp>0) {
		if (boss.flag == 0) {
			x = enemy[num].x - cshot[k].x;
			y = enemy[num].y - cshot[k].y;
		}
		else {
			x = boss.x - cshot[k].x;
			y = boss.y - cshot[k].y;
		}
		cshot[k].angle = atan2(y, x);
	}
}

//�V���b�g�̈ړ��v�Z
void calc_cshot() {
	for (int i = 0; i<CSHOT_MAX; i++) {
		if (cshot[i].flag == 1) {
			int dranx = (int)(cshot[i].spd + 11 / 2), drany = (int)(cshot[i].spd + 55 / 2);
			if (cshot[i].knd == 1)
				calc_homing(i);
			cshot[i].x += cos(cshot[i].angle)*cshot[i].spd;
			cshot[i].y += sin(cshot[i].angle)*cshot[i].spd;
			cshot[i].cnt++;
			if (cshot[i].x<-dranx || cshot[i].x>FMX + dranx ||
				cshot[i].y<-drany || cshot[i].y>FMY + drany)//��ʂ���O�ꂽ��
				cshot[i].flag = 0;
		}
	}
}

//�L�����N�^�V���b�g�Ɋւ���֐�
void cshot_main() {
	calc_option_bb();//�I�v�V�����̂ڂ�ڂ�v�Z(49)
	calc_cshot();//�V���b�g�̋N���v�Z
	enter_shot();//�V���b�g�o�^
}
