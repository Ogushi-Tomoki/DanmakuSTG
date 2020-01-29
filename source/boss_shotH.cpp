#include "../include/GV.h"

extern int search_boss_shot();
extern int search_lazer();
extern int search_child();
extern double bossatan2();
extern double bossatan3(int k, double x, double y);//�w����W�ƒe�Ƃ̐����p
extern double bossatan4(double x1, double y1, double x2, double y2);
extern int move_boss_pos(double x1, double y1, double x2, double y2, double dist, int t);
extern void input_phy_pos(double x, double y, int t);
extern void input_lphy(lazer_t *laz, int time, double angle);

//�����̉~�`����
void boss_shot_bulletH000() {
#define TM000 120
	int i, k, t = boss_shot.cnt%TM000, t2 = boss_shot.cnt;
	double angle;
	//60�J�E���g�ȉ���10�J�E���g��1��
	if (t<60 && t % 10 == 0) {
		angle = bossatan2();//���@�ƃ{�X�Ƃ̐����p
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (i = 0; i<30; i++) {
				if ((k = search_boss_shot()) != -1) {
					boss_shot.bullet[k].col = 0;//�e�̐F
					boss_shot.bullet[k].x = boss.x;//���W
					boss_shot.bullet[k].y = boss.y;
					boss_shot.bullet[k].knd = 8;//�e�̎��
					boss_shot.bullet[k].angle = angle + PI2 / 30 * i;//�p�x
					boss_shot.bullet[k].flag = 1;
					boss_shot.bullet[k].cnt = 0;
					boss_shot.bullet[k].spd = 3;//�X�s�[�h
					boss_shot.bullet[k].gflag = 0;
				}
			}
			se_flag[0] = 1;
		}
	}
	//    for(i=0;i<BOSS_BULLET_MAX;i++){
	//        if(boss_shot.bullet[i].flag>0){
	//
	//        }
	//    }
}

//�T�C�����g�Z���i
void boss_shot_bulletH001() {
#define TM001 60
	int i, k, t = boss_shot.cnt%TM001, t2 = boss_shot.cnt;
	static int cnum;
	double angle;
	if (t2 == 0)//�ŏ��Ȃ�
		cnum = 0;
	if (t == 0) {//1�����̍ŏ��Ȃ�
		boss_shot.base_angle[0] = bossatan2();//��Ɛ���p�x���Z�b�g
		if (cnum % 4 == 3) {//4��4��ڂȂ�
			if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
				move_boss_pos(40, 30, FMX - 40, 120, 60, 60);
			}
		}
	}
	if (t == TM001 / 2 - 1) {		//�����̔����Ŋp�x��ς���
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			boss_shot.base_angle[0] += PI2 / 20 / 2;
		}
	}
		
	//�~�`
	if (t % (TM001 / 10) == 0) {//10�J�E���g��1�񂸂�
		angle = bossatan2();//�{�X�Ǝ��@�Ƃ̐����p
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (i = 0; i<20; i++) {//PI2/20�x����1��
				if ((k = search_boss_shot()) != -1) {
					boss_shot.bullet[k].col = 4;
					boss_shot.bullet[k].x = boss.x;
					boss_shot.bullet[k].y = boss.y;
					boss_shot.bullet[k].knd = 8;
					boss_shot.bullet[k].angle = boss_shot.base_angle[0] + PI2 / 20 * i;
					boss_shot.bullet[k].flag = 1;
					boss_shot.bullet[k].cnt = 0;
					boss_shot.bullet[k].spd = 2.7;
					boss_shot.bullet[k].gflag = 0;
				}
			}
			se_flag[0] = 1;
		}
	}
	//�����_����������
	if (t % 4 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			if ((k = search_boss_shot()) != -1) {
				boss_shot.bullet[k].col = 0;
				boss_shot.bullet[k].x = GetRand(FMX);
				boss_shot.bullet[k].y = GetRand(200);
				boss_shot.bullet[k].knd = 8;
				boss_shot.bullet[k].angle = PI / 2;
				boss_shot.bullet[k].flag = 1;
				boss_shot.bullet[k].cnt = 0;
				boss_shot.bullet[k].spd = 1 + rang(0.5);
				boss_shot.bullet[k].gflag = 0;
				se_flag[0] = 1;
			}
		}
	}
	//    for(i=0;i<BOSS_BULLET_MAX;i++){
	//        if(boss_shot.bullet[i].flag>0){
	//
	//        }
	//    }
	if (t == TM001 - 1) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			cnum++;
		}
	}	
}
//�p�[�t�F�N�g�t���[�Y
void boss_shot_bulletH002() {
#define TM002 650
	int i, k, t = boss_shot.cnt%TM002;
	double angle;
	if (t == 0 || t == 210) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			//40<x<FMX-40  50<y<150�@�͈̔͂�100���ꂽ�ʒu��80�J�E���g�ňړ�����
			move_boss_pos(40, 50, FMX - 40, 150, 100, 80);
		}
	}
	//�ŏ��̃����_������
	if (t<180) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (i = 0; i<2; i++) {//1�J�E���g��2�񔭎�
				if ((k = search_boss_shot()) != -1) {
					boss_shot.bullet[k].col = GetRand(6);//7��ނ̐F�������_����
					boss_shot.bullet[k].x = boss.x;//���ˏ������W�̓{�X�̈ʒu
					boss_shot.bullet[k].y = boss.y;
					boss_shot.bullet[k].knd = 7;//�e�̎��
					boss_shot.bullet[k].angle = rang(PI2 / 20) + PI2 / 10 * t;
					boss_shot.bullet[k].flag = 1;
					boss_shot.bullet[k].cnt = 0;
					boss_shot.bullet[k].spd = 3.2 + rang(2.1);
					boss_shot.bullet[k].state = 0;//�e�̃X�e�[�^�X
					boss_shot.bullet[k].kaiten = 1;//�e����]���邩�ǂ����̃t���O
					boss_shot.bullet[k].gflag = 0;
				}
			}
			if (t % 10 == 0)
				se_flag[0] = 1;
		}
	}
	//���@�ˑ��ɂ��8��������
	if (210<t && t<270 && t % 3 == 0) {
		angle = bossatan2();
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (i = 0; i<8; i++) {
				if ((k = search_boss_shot()) != -1) {
					boss_shot.bullet[k].col = 0;
					boss_shot.bullet[k].x = boss.x;
					boss_shot.bullet[k].y = boss.y;
					boss_shot.bullet[k].knd = 7;
					//���@�ƃ{�X�Ƃ̐����p����ɂW�����ɔ��˂���
					boss_shot.bullet[k].angle = angle - PI / 2 * 0.8 + PI * 0.8 / 7 * i + rang(PI / 180);
					boss_shot.bullet[k].flag = 1;
					boss_shot.bullet[k].cnt = 0;
					boss_shot.bullet[k].spd = 3.0 + rang(0.3);
					boss_shot.bullet[k].state = 2;
					boss_shot.bullet[k].kaiten = 1;
					boss_shot.bullet[k].gflag = 0;
				}
			}
			if (t % 10 == 0)
				se_flag[0] = 1;
		}
	}
	for (i = 0; i<BOSS_BULLET_MAX; i++) {
		if (boss_shot.bullet[i].flag>0) {
			if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
				//t��190�̎��ɑS�ăX�g�b�v�����A�������A�J�E���g���Z�b�g
				if (boss_shot.bullet[i].state == 0) {
					if (t == 190) {
						boss_shot.bullet[i].kaiten = 0;//�e�̉�]���~�߂�
						boss_shot.bullet[i].spd = 0;
						boss_shot.bullet[i].col = 9;
						boss_shot.bullet[i].cnt = 0;
						boss_shot.bullet[i].state = 1;
					}
				}
				//�����_���ȕ����Ɉړ����n�߂�
				if (boss_shot.bullet[i].state == 1) {
					if (boss_shot.bullet[i].cnt == 200) {
						boss_shot.bullet[i].angle = rang(PI);
						boss_shot.bullet[i].kaiten = 1;
					}
					if (boss_shot.bullet[i].cnt>200)
						boss_shot.bullet[i].spd += 0.01;
				}
			}
		}
	}
}
//���̖��H
void boss_shot_bulletH003() {
#define TM003 600
#define DF003 20 
	int i, j, k, t = boss_shot.cnt%TM003, t2 = boss_shot.cnt;
	static int tcnt, cnt, cnum;
	double angle;
	if (t2 == 0) {//�ŏ��Ȃ�
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			//40<x<FMX-40  50<y<150�@�͈̔͂�100���ꂽ�ʒu��80�J�E���g�ňړ�����
			input_phy_pos(FMX / 2, FMY / 2, 50);
			cnum = 0;
		}
	}
	if (t == 0) {//�P�����̍ŏ��Ȃ�
		boss_shot.base_angle[0] = bossatan2();//���@�_��
		cnt = 0;
		tcnt = 2;
	}
	if (t<540 && t % 3) {
		angle = bossatan2();
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			//�����Ȃ������Ȃ猂���Ȃ�
			if (tcnt - 2 == cnt || tcnt - 1 == cnt) {
				if (tcnt - 1 == cnt) {
					//�x�[�X�ƂȂ�p�x���Z�b�g
					boss_shot.base_angle[1] = boss_shot.base_angle[0] + PI2 / DF003 * cnt*(cnum ? -1 : 1) - PI2 / (DF003 * 6) * 3;
					tcnt += DF003 - 2;
				}
			}
			//���ꂶ��Ȃ���΂���
			else {
				for (i = 0; i<6; i++) {//�P��ɂU��������
					if ((k = search_boss_shot()) != -1) {
						boss_shot.bullet[k].col = cnum ? 1 : 4;
						boss_shot.bullet[k].x = boss.x;
						boss_shot.bullet[k].y = boss.y;
						boss_shot.bullet[k].knd = 8;
						boss_shot.bullet[k].angle
							= boss_shot.base_angle[0] + PI2 / DF003 * cnt*(cnum ? -1 : 1) + PI2 / (DF003 * 6)*i*(cnum ? -1 : 1);
						boss_shot.bullet[k].flag = 1;
						boss_shot.bullet[k].cnt = 0;
						boss_shot.bullet[k].spd = 2;
						boss_shot.bullet[k].gflag = 0;
					}
				}
				se_flag[0] = 1;
			}
			cnt++;
		}
	}
	//�����傫�Ȓe�ŉ~�`����
	if (40<t&&t<540 && t % 30 == 0) {
		for (j = 0; j<3; j++) {
			angle = boss_shot.base_angle[1] - PI2 / 36 * 4;
			if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
				for (i = 0; i<27; i++) {
					if ((k = search_boss_shot()) != -1) {
						boss_shot.bullet[k].col = cnum ? 6 : 0;
						boss_shot.bullet[k].x = boss.x;
						boss_shot.bullet[k].y = boss.y;
						boss_shot.bullet[k].knd = 7;
						boss_shot.bullet[k].angle = angle;
						boss_shot.bullet[k].flag = 1;
						boss_shot.bullet[k].cnt = 0;
						boss_shot.bullet[k].spd = 4 - 1.6 / 3 * j;
						boss_shot.bullet[k].gflag = 0;
					}
					angle -= PI2 / 36;
				}
				se_flag[0] = 1;
			}
		}
	}
	//    for(i=0;i<BOSS_BULLET_MAX;i++){
	//        if(boss_shot.bullet[i].flag>0){
	//
	//        }
	//    }
	if (t == TM003 - 1) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			cnum++;
		}
	}	
}

//�P������񕗉J�ɂ�������
void boss_shot_bulletH004() {
#define TM004 200
	int i, n, k, t = boss_shot.cnt%TM004, t2 = boss_shot.cnt;
	static int tm;
	double angle;
	if (t == 0)
		tm = (int)(190 + rang(30));
	//�ォ��ӂ炷�e�𔭎˂����̊p�x���Z�b�g
	angle = PI * 1.5 + PI / 6 * sin(PI2 / tm * t2);
	//�M���M������e
	if (t2 % 4 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (n = 0; n<8; n++) {//8�����ɂӂ�
				if ((k = search_boss_shot()) != -1) {
					boss_shot.bullet[k].flag = 1;
					boss_shot.bullet[k].state = 0;
					boss_shot.bullet[k].cnt = 0;
					boss_shot.bullet[k].knd = 4;
					boss_shot.bullet[k].col = 0;
					boss_shot.bullet[k].angle = 0;
					boss_shot.bullet[k].eff_detail = 1;//�s�J�s�J���点��
					boss_shot.bullet[k].x = boss.x;
					boss_shot.bullet[k].y = boss.y;
					boss_shot.bullet[k].vx = cos(angle - PI / 8 * 4 + PI / 8 * n + PI / 16) * 3;
					boss_shot.bullet[k].vy = sin(angle - PI / 8 * 4 + PI / 8 * n + PI / 16) * 3;
					boss_shot.bullet[k].gflag = 0;
				}
			}
			se_flag[0] = 1;
		}
	}
	//��������
	if (t % 1 == 0 && t2>80) {
		int num = 1;
		if (t % 2)
			num = 2;
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (n = 0; n<num; n++) {
				if ((k = search_boss_shot()) != -1) {
					angle = PI * 1.5 - PI / 2 + PI / 12 * (t2 % 13) + rang(PI / 15);
					boss_shot.bullet[k].flag = 1;
					boss_shot.bullet[k].state = 1;
					boss_shot.bullet[k].cnt = 0;
					boss_shot.bullet[k].knd = 8;
					boss_shot.bullet[k].eff_detail = 0;//�s�J�s�J�͌���Ȃ�
					boss_shot.bullet[k].col = 1;
					boss_shot.bullet[k].angle = 0;
					boss_shot.bullet[k].x = boss.x;
					boss_shot.bullet[k].y = boss.y;
					boss_shot.bullet[k].vx = cos(angle)*1.4*1.2;
					boss_shot.bullet[k].vy = sin(angle)*1.4;
					boss_shot.bullet[k].gflag = 0;
				}
			}
			se_flag[7] = 1;
		}
	}
	for (i = 0; i<BOSS_BULLET_MAX; i++) {
		if (boss_shot.bullet[i].flag>0) {
			if (boss_shot.bullet[i].state == 0) {//�X�e�[�^�X���O�Ȃ�
				if (boss_shot.bullet[i].cnt < 150) {
					if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
						boss_shot.bullet[i].vy += 0.03;//���������̉������ɉ�������
					}
				}
				if (emperor_time.flag == 0) {
					boss_shot.bullet[i].x += boss_shot.bullet[i].vx;
					boss_shot.bullet[i].y += boss_shot.bullet[i].vy;
				}
				else {
					boss_shot.bullet[i].x += boss_shot.bullet[i].vx*emperor_time.spd_rate;
					boss_shot.bullet[i].y += boss_shot.bullet[i].vy*emperor_time.spd_rate;
				}
			}
			if (boss_shot.bullet[i].state == 1) {//�X�e�[�^�X���P�Ȃ�
				if (boss_shot.bullet[i].cnt < 160) {
					if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
						boss_shot.bullet[i].vy += 0.03;//���������̉������ɉ�������
					}
				}
				if (emperor_time.flag == 0) {
					boss_shot.bullet[i].x += boss_shot.bullet[i].vx;
					boss_shot.bullet[i].y += boss_shot.bullet[i].vy;
				}
				else {
					boss_shot.bullet[i].x += boss_shot.bullet[i].vx*emperor_time.spd_rate;
					boss_shot.bullet[i].y += boss_shot.bullet[i].vy*emperor_time.spd_rate;
				}
				boss_shot.bullet[i].angle = atan2(boss_shot.bullet[i].vy, boss_shot.bullet[i].vx);
			}
		}
	}
}

//���e
void boss_shot_bulletH005() {
#define TM005 820
#define RANGE005 100.0
#define LEM005 4
	int i, j, k, t = boss_shot.cnt%TM005, t2 = boss_shot.cnt;
	static int sst, bnum;
	static double sx, sy, sangle;
	//1�����̍ŏ��Ȃ�
	if (t == 0) {
		sst = 0;
		sx = boss.x;
		sy = boss.y - RANGE005;
		sangle = PI / 5 / 2 + PI / 2;
		bnum = 0;
	}
	//����`��
	if (sst <= 4) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (i = 0; i<2; i++) {
				sx += cos(sangle)*LEM005;//���W���v�Z
				sy += sin(sangle)*LEM005;
				//�~�ƌ��������
				if ((sx - boss.x)*(sx - boss.x) + (sy - boss.y)*(sy - boss.y)>RANGE005*RANGE005) {
					sangle -= (PI - PI / 5);//�����]��
					sst++;//�X�e�[�^�X�ϊ�
					if (sst == 5)break;//5�Ȃ�I���
				}
				for (j = 0; j<5; j++) {//�����T�`��
					if ((k = search_boss_shot()) != -1) {
						boss_shot.bullet[k].flag = 1;
						boss_shot.bullet[k].state = j;
						boss_shot.bullet[k].cnt = 0;
						boss_shot.bullet[k].spd = 0;
						boss_shot.bullet[k].knd = 10;
						boss_shot.bullet[k].col = j;
						boss_shot.bullet[k].angle = -PI / 2 + PI2 / 5 * j;
						boss_shot.bullet[k].x = sx;
						boss_shot.bullet[k].y = sy;
						boss_shot.bullet[k].vx = cos(sangle)*1.4*1.2;
						boss_shot.bullet[k].vy = sin(sangle)*1.4;
						boss_shot.bullet[k].base_angle[0] = sangle - PI + PI / 20 * bnum;
						boss_shot.bullet[k].gflag = 0;
					}
				}
				bnum++;
			}
			se_flag[0] = 1;
		}
	}
	for (i = 0; i<BOSS_BULLET_MAX; i++) {
		if (boss_shot.bullet[i].flag>0) {
			int cnt = boss_shot.bullet[i].cnt;
			if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
				//�X�e�[�^�X��10�����Ȃ�
				if (boss_shot.bullet[i].state<10) {
					if (t == 150) {//150�Ȃ琯���T�����ɔ���
						boss_shot.bullet[i].spd = 4;//�X�s�[�h
						boss_shot.bullet[i].cnt = 0;//�J�E���^���Z�b�g
						boss_shot.bullet[i].state += 10;//�X�e�[�^�X�ԍ��ύX
					}
				}
				else if (boss_shot.bullet[i].state<20) {//10~19�Ȃ�
					if (cnt <= 80) {//����
						boss_shot.bullet[i].spd -= 0.05;
					}
					if (cnt == 100) {//�Z�b�g������p�x�����Y��ȋȐ���`��
						boss_shot.bullet[i].angle = boss_shot.bullet[i].base_angle[0];
					}
					if (cnt >= 100 && cnt<160) {//����
						boss_shot.bullet[i].spd += 0.015;
					}
				}
			}
		}
	}
}
//���肩�璆���ւ̔���
void boss_shot_bulletH006() {
#define TM006 300
	//�����ɒu���e�̐�
#define DNUMX006 15
	int i, j, k, t = boss_shot.cnt%TM006, t2 = boss_shot.cnt;
	double xlen = FMX / DNUMX006;//��ʂ�DNUM���ׂ�ɂ�xlen�Ԋu�ŕ��ׂ�΂���
	int dnumy = (int)(FMY / xlen);//xlen���Ȃ�ׂ�Ɖ��������ɂ����͂��邩
	int cnum;
	if (dnumy == 0) { printfDx("boss_shot_bulletH006��0����\n"); return; }
	double ylen = FMY / dnumy;//ylen�������΂���
	double x, y, angle;
	static int num;
	if (t2 == 0)num = 0;
	if (t == 0) {
		x = 0, y = 0, angle = 0, cnum = 0;
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (j = 0; j<4; j++) {
				//���������Ȃ�DNUMX006�A���������Ȃ�dnumy
				int to = j % 2 ? dnumy : DNUMX006;
				//���������A���������ł͒u�������Ⴄ�̂ŁAto��u��
				for (i = 0; i <= to; i++) {
					if ((k = search_boss_shot()) != -1) {
						boss_shot.bullet[k].x = x;//���W
						boss_shot.bullet[k].y = y;
						boss_shot.bullet[k].knd = 4;//�e�̎��
						boss_shot.bullet[k].flag = 1;
						boss_shot.bullet[k].cnt = 0;
						boss_shot.bullet[k].gflag = 0;
						switch (num) {
						case 0://���ˎ�ނP
							boss_shot.bullet[k].col = 0;//�e�̐F
							boss_shot.bullet[k].angle = bossatan3(k, FMX / 2, FMY / 2);//�p�x
							boss_shot.bullet[k].spd = 1.3;//�X�s�[�h
							boss_shot.bullet[k].state = 0;//�X�e�[�^�X
							break;
						case 1://���ˎ�ނQ
							boss_shot.bullet[k].col = 3;//�e�̐F
							boss_shot.bullet[k].angle = bossatan3(k, FMX / 2, FMY / 2);//�p�x
							boss_shot.bullet[k].spd = 1.4 + ((j % 2 ? -1 : 1) * ((cos(PI2 / to * i - PI) + 1) / 2))*0.4;//�X�s�[�h
							boss_shot.bullet[k].state = 1;//�X�e�[�^�X
							break;
						case 2://���ˎ�ނR
							boss_shot.bullet[k].col = 6;//�e�̐F
							boss_shot.bullet[k].angle = bossatan3(k, FMX / 2, FMY / 2);//�p�x
							boss_shot.bullet[k].spd = 1.3;//�X�s�[�h
							boss_shot.bullet[k].state = 2;//�X�e�[�^�X
							boss_shot.bullet[k].base_angle[0]
								= PI / 1000 * (j % 2 ? -1 : 1) * ((cos(PI2 / to * i - PI) + 1) / 2);//���Z����p�x
							break;
						}
						se_flag[0] = 1;
						cnum++;
					}
					x += cos(angle)*xlen;
					y += sin(angle)*ylen;
				}
				angle += PI / 2;
			}
		}
	}
	for (i = 0; i<BOSS_BULLET_MAX; i++) {
		if (boss_shot.bullet[i].flag>0) {
			if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
				int cnt = boss_shot.bullet[i].cnt;
				switch (boss_shot.bullet[i].state) {
				case 2://���ˎ�ނR�Ȃ�
					   //�p�x�����Z
					boss_shot.bullet[i].angle += boss_shot.bullet[i].base_angle[0];
					break;
				default:
					break;
				}
			}
		}
	}
	if (t == TM006 - 1) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			num = (++num) % 3;
		}
	}	
}

//���肩�璼������
void boss_shot_bulletH007() {
#define TM007 300
#define DNUMX 9
	int i, j, k, s, t = boss_shot.cnt%TM007, t2 = boss_shot.cnt;
	double xlen = FMX / DNUMX;//��ʂ�DNUM���ׂ�ɂ�xlen�Ԋu�ŕ��ׂ�΂���
	int dnumy = (int)(FMY / xlen);//xlen���Ȃ�ׂ�Ɖ��������ɂ����͂��邩
	int cnum;
	if (dnumy == 0) { printfDx("boss_shot_bulletH006��0����\n"); return; }
	double ylen = FMY / dnumy;//ylen�������΂���
	double x, y, angle;
	static int num;
	if (t2 == 0)num = 0;
	if (t == 0) {
		x = 0, y = 0, angle = 0, cnum = 0;
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (j = 0; j<4; j++) {
				int to = j % 2 ? dnumy : DNUMX;
				for (i = 0; i <= to; i++) {
					for (s = 0; s<2; s++) {
						if ((k = search_boss_shot()) != -1) {
							boss_shot.bullet[k].x = x;//���W
							boss_shot.bullet[k].y = y;
							boss_shot.bullet[k].knd = 4;//�e�̎��
							boss_shot.bullet[k].flag = 1;
							boss_shot.bullet[k].cnt = 0;
							boss_shot.bullet[k].gflag = 0;
							switch (num) {
							case 0:
								boss_shot.bullet[k].col = 0;//�e�̐F
								boss_shot.bullet[k].angle = angle + PI / 2;//�p�x
								boss_shot.bullet[k].spd = 1.1 + 0.5*s;//�X�s�[�h
								boss_shot.bullet[k].state = 0;//�X�e�[�^�X
								break;
							case 1:
								boss_shot.bullet[k].col = 3;//�e�̐F
								boss_shot.bullet[k].angle = angle + PI / 2 - PI / 14 + PI / 7 * s;//�p�x
								boss_shot.bullet[k].spd = 1.3;//�X�s�[�h
								boss_shot.bullet[k].state = 1;//�X�e�[�^�X
								break;
							}
							se_flag[0] = 1;
							cnum++;
						}
					}
					x += cos(angle)*xlen;
					y += sin(angle)*ylen;
				}
				angle += PI / 2;
			}
		}
	}
	if (t == TM006 - 1) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			num = (++num) % 2;
		}
	}
}

//���[�U�[�̃T���v��
void boss_shot_bulletH008() {
#define TM008 420
#define DIST 60
	int i, j, k, t = boss_shot.cnt%TM008, t2 = boss_shot.cnt;
	static int num;
	if (t2 == 0)num = 4;
	if (t == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (j = 0; j<2; j++) {
				for (i = 0; i<num; i++) {
					int plmn = (j ? -1 : 1);
					if ((k = search_lazer()) != -1) {
						lazer[k].col = j;//�e�̐F
						lazer[k].knd = 0;//�e�̎��
						lazer[k].angle = PI2 / num * i + PI2 / (num * 2)*j + PI2 / (num * 4)*((num + 1) % 2);//�p�x
						lazer[k].startpt.x = boss.x + cos(lazer[k].angle)*DIST;//���W
						lazer[k].startpt.y = boss.y + sin(lazer[k].angle)*DIST;
						lazer[k].flag = 1;
						lazer[k].cnt = 0;
						lazer[k].haba = 2;//��
						lazer[k].state = j;//�X�e�[�^�X
						lazer[k].length = 240;//���[�U�[�̒���
						lazer[k].hantei = 0;
						lazer[k].lphy.conv_flag = 1;//��]�t���O
						lazer[k].lphy.conv_base_x = boss.x;//��]��ʒu
						lazer[k].lphy.conv_base_y = boss.y;
						lazer[k].lphy.conv_x = lazer[k].startpt.x;//��]���̈ʒu
						lazer[k].lphy.conv_y = lazer[k].startpt.y;
						input_lphy(&lazer[k], 80, PI / num * plmn);//���
					}
				}
			}
			se_flag[33] = 1;
		}
	}
	//���[�U�[�v�Z
	for (i = 0; i<LAZER_MAX; i++) {
		if (lazer[i].flag>0) {
			int cnt = lazer[i].cnt;
			int state = lazer[i].state;
			if (state == 0 || state == 1) {
				if (cnt == 80) {
					lazer[i].haba = 30;//����30��
					lazer[i].hantei = 0.5;//�\�����̔����𔻒�͈͂�
				}
				if (cnt >= 260 && cnt <= 320) {
					if (cnt == 280)
						lazer[i].hantei = 0;
					lazer[i].haba = 10 * (60 - (cnt - 260)) / 60.0;
					if (cnt == 320)
						lazer[i].flag = 0;
				}
			}
		}
	}
	if (t == TM008 - 1) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			num = (++num);
		}
	}
}


void boss_shot_bulletH009() {
#define TM009 420
#define DIST 60
	int i, j, k, s, t = boss_shot.cnt%TM009, t2 = boss_shot.cnt;
	double angle;
	static int num;
	if (t2 == 0)num = 4;
	if (t == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (j = 0; j<2; j++) {
				for (i = 0; i<num; i++) {
					int plmn = (j ? -1 : 1);
					if ((k = search_lazer()) != -1) {
						lazer[k].col = j;//�e�̐F
						lazer[k].knd = 0;//�e�̎��
						lazer[k].angle = PI2 / num * i + PI2 / (num * 2)*j + PI2 / (num * 4)*((num + 1) % 2);//�p�x
						lazer[k].startpt.x = boss.x + cos(lazer[k].angle)*DIST;//���W
						lazer[k].startpt.y = boss.y + sin(lazer[k].angle)*DIST;
						lazer[k].flag = 1;
						lazer[k].cnt = 0;
						lazer[k].haba = 2;//�X�s�[�h
						lazer[k].state = j;
						lazer[k].length = 310;
						lazer[k].hantei = 0;
						lazer[k].lphy.conv_flag = 1;
						lazer[k].lphy.conv_base_x = boss.x;
						lazer[k].lphy.conv_base_y = boss.y;
						lazer[k].lphy.conv_x = lazer[k].startpt.x;
						lazer[k].lphy.conv_y = lazer[k].startpt.y;
						input_lphy(&lazer[k], 80, PI / num * plmn);
					}
				}
			}
			se_flag[33] = 1;
		}
	}
	//60�J�E���g�ȉ���10�J�E���g��1��
	if (t == 50) {
		angle = rang(PI);//���@�ƃ{�X�Ƃ̐����p
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (s = 0; s<2; s++) {
				for (t = 0; t<3; t++) {
					for (j = 0; j<3; j++) {
						for (i = 0; i<30; i++) {
							if ((k = search_boss_shot()) != -1) {
								boss_shot.bullet[k].col = s;//�e�̐F
								boss_shot.bullet[k].x = boss.x;//���W
								boss_shot.bullet[k].y = boss.y;
								boss_shot.bullet[k].knd = 11;//�e�̎��
								boss_shot.bullet[k].angle = angle + PI2 / 30 * i + PI2 / 60 * s;//�p�x
								boss_shot.bullet[k].flag = 1;
								boss_shot.bullet[k].cnt = 0;
								boss_shot.bullet[k].spd = 1.8 - 0.2*j + 0.1*s;//�X�s�[�h
								boss_shot.bullet[k].eff = 0;
								boss_shot.bullet[k].state = t;
								boss_shot.bullet[k].gflag = 0;
							}
							se_flag[0] = 1;
						}
					}
				}
			}
		}
	}
	if (t >= 170 && t<310 && (t - 170) % 35 == 0) {
		int div = ((t - 170) % 70 == 0) ? -1 : 1;
		angle = rang(PI);//���@�ƃ{�X�Ƃ̐����p
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (s = 0; s<2; s++) {//���x�̈Ⴄ2�̒e������
				for (t = 0; t<3; t++) {//1�ӏ�����3�ɂ킩���
					for (i = 0; i<30; i++) {//1��30��
						if ((k = search_boss_shot()) != -1) {
							boss_shot.bullet[k].col = 2;//�e�̐F
							boss_shot.bullet[k].x = boss.x;//���W
							boss_shot.bullet[k].y = boss.y;
							boss_shot.bullet[k].knd = 11;//�e�̎��
							boss_shot.bullet[k].angle = angle + PI2 / 30 * i;//�p�x
							boss_shot.bullet[k].flag = 1;
							boss_shot.bullet[k].cnt = 0;
							boss_shot.bullet[k].spd = 2 - 0.3*s;//�X�s�[�h
							boss_shot.bullet[k].eff = 0;
							boss_shot.bullet[k].state = 10 + t;
							boss_shot.bullet[k].base_angle[0] = PI / 300 * div;
							boss_shot.bullet[k].gflag = 0;
						}
					}
				}
				se_flag[0] = 1;
			}
		}
	}
	if (t == 360) {
		angle = rang(PI);//���@�ƃ{�X�Ƃ̐����p
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (t = 0; t<3; t++) {//1�ӏ�����R�ɕ������
				for (i = 0; i<30; i++) {
					if ((k = search_boss_shot()) != -1) {
						boss_shot.bullet[k].col = 1;//�e�̐F
						boss_shot.bullet[k].x = boss.x;//���W
						boss_shot.bullet[k].y = boss.y;
						boss_shot.bullet[k].knd = 0;//�e�̎��
						boss_shot.bullet[k].angle = angle + PI2 / 30 * i;//�p�x
						boss_shot.bullet[k].flag = 1;
						boss_shot.bullet[k].cnt = 0;
						boss_shot.bullet[k].spd = 1.8;//�X�s�[�h
						boss_shot.bullet[k].eff = 1;
						boss_shot.bullet[k].state = 20 + t;
						boss_shot.bullet[k].gflag = 0;
					}
				}
			}
			se_flag[0] = 1;
		}
	}
	for (i = 0; i<BOSS_BULLET_MAX; i++) {
		if (boss_shot.bullet[i].flag>0) {
			int cnt = boss_shot.bullet[i].cnt;
			int state = boss_shot.bullet[i].state;
			if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
				if (state % 10 == 0) {
					if (cnt>90 && cnt <= 100)
						boss_shot.bullet[i].spd -= boss_shot.bullet[i].spd / 220;
				}
				if (state % 10 == 1) {
					if (cnt>50)
						boss_shot.bullet[i].spd += boss_shot.bullet[i].spd / 45;
				}
				if (state % 10 == 2) {
					if (cnt>65)
						boss_shot.bullet[i].spd += boss_shot.bullet[i].spd / 90;
				}
				if (10 <= state && state <= 12) {
					if (cnt>15 && cnt <= 80)
						boss_shot.bullet[i].angle += boss_shot.bullet[i].base_angle[0];
				}
			}
		}
	}
	for (i = 0; i<LAZER_MAX; i++) {
		if (lazer[i].flag>0) {
			int cnt = lazer[i].cnt;
			int state = lazer[i].state;
			if (state == 0 || state == 1) {
				if (cnt == 80) {
					lazer[i].haba = 10;
					lazer[i].hantei = 0.5;
				}
				if (cnt >= 260 && cnt <= 320) {
					if (cnt == 280)
						lazer[i].hantei = 0;
					lazer[i].haba = 10 * (60 - (cnt - 260)) / 60.0;
					if (cnt == 320)
						lazer[i].flag = 0;
				}
			}
		}
	}
	if (t == TM009 - 1) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			num = (++num);
		}
	}
}

//�[�e�����E
void boss_shot_bulletH010() {
#define TM010 9000
#define DIST010  (FMX/2*1.18)
#define DIST0101 (FMX/2*0.95)
#define DIST010_2_0 (FMX/2)
#define DIST010_2_ (FMY/2)
#define HANSHU 120 //child���������鎞��
#define HANSHU1 180 //child���������鎞��
#define HANSHU2_0 180 //child���������鎞��
#define HANSHU2_1 120 //child���������鎞��
#define GOOUT010 90    //child����������O�֍s������
#define KAISHI010 (HANSHU)
#define KAISHI010_1 (HANSHU1*0.6)
#define CHILD_TIME (HANSHU*5+HANSHU/3)            //child�����݂��鎞��
#define CHILD_TIME1 (HANSHU1*3+HANSHU1*0.4)            //child�����݂��鎞��
#define CHILD_SHOT_TIME (CHILD_TIME-KAISHI010)//child�����ۂɔ��˂��Ă��鎞��
#define CHILD_SHOT_TIME1 (CHILD_TIME1-KAISHI010_1)//child�����ۂɔ��˂��Ă��鎞��
#define ANG0 PI/9
#define ANG1 PI/6
#define TIME1 900
#define RAG 20
#define TERM0 20
#define ST_ED 130
#define ST0 (CHILD_SHOT_TIME+TERM0)
#define ED0 (CHILD_SHOT_TIME+TERM0+ST_ED)
#define TERM1 47
#define ST_ED1 105
#define ST1 (CHILD_SHOT_TIME1+TERM1)
#define ED1 (CHILD_SHOT_TIME1+TERM1+ST_ED1)

	int i, j, k, t = boss_shot.cnt%TM010, t2 = boss_shot.cnt;
	int tt1 = boss_shot.cnt - TIME1;
	static int num, flag, knum;
	static double child_dist, child_angle, child_dist2, child_angle2;
	if (t2 == 0) {//�ŏ��Ȃ�
		input_phy_pos(FMX / 2, FMY / 2, 50);
		num = -1;
		flag = 0;
	}
	//�����̍ŏ�
	if (t == 0 || t2 == TIME1) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			num++;
			//child�f�[�^�̏�����
			child_dist = 0;
			child_angle = 0;
			child_dist2 = 0;
			child_angle2 = 0;
			knum = 0;
		}
	}
	//child�̓o�^
	if (t2 == GOOUT010 || t2 == TIME1) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			int j = 2;
			for (i = j - 2; i<j; i++) {
				child[i].flag = 1;
				child[i].x = boss.x;
				child[i].y = boss.y;
				child[i].range = 0.5;
				child[i].spd = 1;
				child[i].angle = 0;
				child[i].knd = 0;
				child[i].col = 0;
				child[i].cnt = 0;
				child[i].state = i;
			}
		}
	}
	//1����
	if (num == 0) {
		if (GOOUT010 <= t) {
			if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
				//�o�����Ă���O�����ɍL�����Ă����܂�
				if (GOOUT010 <= t && t<GOOUT010 + KAISHI010)
					child_dist += DIST010 / KAISHI010;
				//��ɉ�]
				child_angle += PI / HANSHU;
			}
		}
	}
	//2����
	if (num == 1) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			//�o�����Ă���O�����ɍL�����Ă����܂�
			if (child[0].cnt<KAISHI010_1)
				child_dist += DIST0101 / KAISHI010_1;
			//��ɉ�]
			child_angle -= PI / HANSHU1;
		}
	}
	//child�f�[�^�v�Z
	for (i = 0; i<CHILD_MAX; i++) {
		if (child[i].flag>0) {//�o�^����Ă�����
							  //�O���v�Z
			child[i].x = boss.x + cos(child_angle + PI * child[i].state)*child_dist*emperor_time.spd_rate;
			child[i].y = boss.y + sin(child_angle + PI * child[i].state)*child_dist*emperor_time.spd_rate;
			//1���
			if (num == 0) {
				if (KAISHI010<child[i].cnt) {//���ˊJ�n�J�E���g�ȏ�Ȃ�
					if (((t + 6) % 36) / 4 <= 5 && t % 4 == 0) {//���̎��e�o�^
						if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
							for (j = 0; j<3; j++) {//�O����3way����
								k = knum++;
								boss_shot.bullet[k].col = child[i].state;//�e�̐F
								boss_shot.bullet[k].x = child[i].x;//���W
								boss_shot.bullet[k].y = child[i].y;
								boss_shot.bullet[k].knd = 6;//�e�̎��
								boss_shot.bullet[k].angle
									= bossatan3(k, boss.x, boss.y) + PI - PI / 6 + PI / 6 * j;//�p�x
								boss_shot.bullet[k].flag = 1;
								boss_shot.bullet[k].cnt = 0;
								boss_shot.bullet[k].state = 10 + j + 10 * child[i].state;//���
								boss_shot.bullet[k].spd = 0.4;//�X�s�[�h
								boss_shot.bullet[k].gflag = 0;
								se_flag[0] = 1;
							}
						}
					}
					else if (t % 4 == 0) {//����ȊO�̎��ŁA4��Ɉ��
						if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
							for (j = 0; j<3; j++) {
								k = knum++;
								boss_shot.bullet[k].col = child[i].state;//�e�̐F
								boss_shot.bullet[k].x = child[i].x;//���W
								boss_shot.bullet[k].y = child[i].y;
								boss_shot.bullet[k].knd = 6;//�e�̎��
								boss_shot.bullet[k].angle
									= bossatan3(k, boss.x, boss.y) + PI - PI / 6 + PI / 6 * j;//�p�x
								boss_shot.bullet[k].flag = 1;
								boss_shot.bullet[k].cnt = 0;
								boss_shot.bullet[k].state = 30;
								boss_shot.bullet[k].spd = 0.4;//�X�s�[�h
								boss_shot.bullet[k].gflag = 0;
							}
						}
					}
				}
				//�����鎞�ԂȂ����
				if (child[i].cnt>CHILD_TIME)
					child[i].flag = 0;
			}
			//1���end
			//2���
			if (num == 1) {
				//���˃J�E���g�ȏ�Ȃ�
				if (KAISHI010_1<child[i].cnt) {
					if ((tt1 - 55) % (3 * 22)<(3 * 15) && t % 3 == 0) {//���̎��o�^
						if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
							for (j = 0; j<3; j++) {//�O��������
								k = knum++;
								boss_shot.bullet[k].col = child[i].state;//�e�̐F
								boss_shot.bullet[k].x = child[i].x;//���W
								boss_shot.bullet[k].y = child[i].y;
								boss_shot.bullet[k].knd = 6;//�e�̎��
								boss_shot.bullet[k].angle
									= bossatan3(k, boss.x, boss.y) + PI - PI / 6 + PI / 6 * j;//�p�x
								boss_shot.bullet[k].flag = 1;
								boss_shot.bullet[k].cnt = 0;
								boss_shot.bullet[k].state = 10 + j + 10 * child[i].state;
								boss_shot.bullet[k].spd = 0.4;//�X�s�[�h
								boss_shot.bullet[k].gflag = 0;
								se_flag[0] = 1;
							}
						}
					}
					else if (t % 3 == 0) {//����ȊO�̎���3���1��
						if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
							for (j = 0; j<3; j++) {//�O����3way
								k = knum++;
								boss_shot.bullet[k].col = child[i].state;//�e�̐F
								boss_shot.bullet[k].x = child[i].x;//���W
								boss_shot.bullet[k].y = child[i].y;
								boss_shot.bullet[k].knd = 6;//�e�̎��
								boss_shot.bullet[k].angle
									= bossatan3(k, boss.x, boss.y) + PI - PI / 6 + PI / 6 * j;//�p�x
								boss_shot.bullet[k].flag = 1;
								boss_shot.bullet[k].cnt = 0;
								boss_shot.bullet[k].state = 30;
								boss_shot.bullet[k].spd = 0.4;//�X�s�[�h
								boss_shot.bullet[k].gflag = 0;
							}
						}
					}
				}
				//�����鎞�ԂȂ����
				if (child[i].cnt>CHILD_TIME1)
					child[i].flag = 0;
			}
		}
	}
	for (i = 0; i<BOSS_BULLET_MAX; i++) {
		if (boss_shot.bullet[i].flag>0) {
			if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
				int cnt = boss_shot.bullet[i].cnt;
				int state = boss_shot.bullet[i].state;
				//0��1���ڂ̓������˒e�A100��2�T�ڂ̓������˒e
				if (state == 0 || state == 100) {
					//��~���鎞�ԂȂ�~�߂ăX�e�[�^�X��ς���
					if (boss_shot.bullet[i].cnt_till == cnt) {
						boss_shot.bullet[i].spd = 0;
						boss_shot.bullet[i].state = 1;
						if (state == 100)
							boss_shot.bullet[i].state += 100;

					}
				}
				//1,101�͏�L��Ԃ���~�܂������
				if (state == 1 || state == 101) {
					//�����o�����ԂȂ瓮���o�����ăX�e�[�^�X��ς���
					if (boss_shot.bullet[i].cnt_stt == cnt) {
						boss_shot.bullet[i].state++;
						if (flag == 0)
							flag = 1;
						boss_shot.bullet[i].cnt = 0;
					}
				}
				//2,102�͏�L��Ԃ���������n�߂Ă���(�����Ă���)���
				if (state == 2 || state == 102) {
					if (flag == 1)
						boss_shot.bullet[i].spd += 0.05;
					if (boss_shot.bullet[i].spd>2.0 && flag == 1)
						flag = 2;
					if (flag == 2) {
						if (state == 2)
							if (boss_shot.bullet[i].spd<2.0)
								boss_shot.bullet[i].spd += 0.05;
						if (state == 102)
							if (boss_shot.bullet[i].spd<2.7)
								boss_shot.bullet[i].spd += 0.05;
					}
				}
				//11,21�͂��ꂼ��1���ځA2�T�ڂ̊O�����˒e
				if (state == 11 || state == 21) {
					if (cnt == RAG) {
						double zero_one;
						double ang, spd;
						if (num == 0) {
							zero_one = (double)(t - GOOUT010 - RAG - HANSHU) / CHILD_SHOT_TIME;
							ang = ANG0 * zero_one;
							spd = 2.3;
						}
						if (num == 1) {
							zero_one = (double)(tt1 - RAG - KAISHI010_1) / CHILD_SHOT_TIME1;
							ang = PI / 6 - (PI / 6 + PI / 4)*zero_one;
							if (tt1 == 143)
								ang = PI / 3;
							spd = 2.3*0.55;
						}
						k = knum++;
						boss_shot.bullet[k].col = boss_shot.bullet[i].state == 11 ? 0 : 1;//�e�̐F
						boss_shot.bullet[k].x = boss_shot.bullet[i].x;//���W
						boss_shot.bullet[k].y = boss_shot.bullet[i].y;
						boss_shot.bullet[k].knd = 6;//�e�̎��
						boss_shot.bullet[k].angle = bossatan3(k, boss.x, boss.y) + ang;//�p�x
						boss_shot.bullet[k].flag = 1;
						boss_shot.bullet[k].cnt = 0;
						if (num == 0) {
							boss_shot.bullet[k].state = 0;
							boss_shot.bullet[k].cnt_till = (int)(150 * zero_one + 10);
							boss_shot.bullet[k].cnt_stt
								= (int)((ST0 - (ST_ED + TERM0))*(1 - zero_one) + (ST_ED + TERM0) + 10);
						}
						if (num == 1) {
							boss_shot.bullet[k].state = 100;
							boss_shot.bullet[k].cnt_till = (int)(150 * zero_one);
							boss_shot.bullet[k].cnt_stt
								= (int)((ST1 - (ST_ED1 + TERM1))*(1 - zero_one) + (ST_ED1 + TERM1));
						}
						boss_shot.bullet[k].spd = spd;
					}
				}
			}
		}
	}
}

//�t���b�V���T���v��
void boss_shot_bulletH011() {
#define TM009 420
#define DIST 60
	int t = boss_shot.cnt%TM009, t2 = boss_shot.cnt;
	if (t2 == 60) {
		flash.flag = 1;
		flash.knd = 0;//�i�X���邭�A�i�X�Â�
		flash.to_cnt = 30;//30�J�E���g�ŕω�
		flash.cnt = 0;
	}
	if (t2 == 180) {
		flash.flag = 1;
		flash.knd = 1;//�t���b�V���I
		flash.to_cnt = 90;//90�J�E���g�ŕω�
		flash.cnt = 0;
	}
	if (t2 == 260) {
		flash.flag = 1;
		flash.knd = 0;//�i�X���邭�A�i�X�Â�
		flash.to_cnt = 15;//15�J�E���g�ŕω�
		flash.cnt = 0;
	}
	if (t2 == 380) {
		flash.flag = 1;
		flash.knd = 1;//�t���b�V���I
		flash.to_cnt = 30;//30�J�E���g�ŕω�
		flash.cnt = 0;
	}

}

//�ʏ�2
void boss_shot_bulletH012() {
#define TM000 120
	int i, k, t = boss_shot.cnt%TM000, t2 = boss_shot.cnt;
	double angle;
	//80�J�E���g�ȉ���8�J�E���g��1��
	if (t<80 && t % 8 == 0) {
		angle = bossatan2();//���@�ƃ{�X�Ƃ̐����p
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (i = 0; i<30; i++) {
				if ((k = search_boss_shot()) != -1) {
					boss_shot.bullet[k].col = 0;//�e�̐F
					boss_shot.bullet[k].x = boss.x;//���W
					boss_shot.bullet[k].y = boss.y;
					boss_shot.bullet[k].knd = 8;//�e�̎��
					boss_shot.bullet[k].angle = angle + PI2 / 30 * i;//�p�x
					boss_shot.bullet[k].flag = 1;
					boss_shot.bullet[k].cnt = 0;
					boss_shot.bullet[k].spd = 3;//�X�s�[�h
					boss_shot.bullet[k].gflag = 0;
				}
			}
			se_flag[0] = 1;
		}
	}
	//    for(i=0;i<BOSS_BULLET_MAX;i++){
	//        if(boss_shot.bullet[i].flag>0){
	//
	//        }
	//    }
}

//�ʏ�3�i�t�����̒ʏ�2�j
void boss_shot_bulletH013() {
#define TM013 160
	int i, k, t = boss_shot.cnt%TM013, t2 = boss_shot.cnt;
	double angle;
	if (t == 130) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			//40<x<FMX-40  50<y<150�@�͈̔͂�40���ꂽ�ʒu��20�J�E���g�ňړ�����
			move_boss_pos(50, 70, FMX - 50, 130, 50, 30);
		}
	}
	//60�J�E���g�ȉ���10�J�E���g��1��
	if (t % 40 == 0) {
		angle = bossatan2();//���@�ƃ{�X�Ƃ̐����p
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (i = 0; i<60; i++) {
				for (int j = 0; j < 2; j++) {
					if ((k = search_boss_shot()) != -1) {
						boss_shot.bullet[k].col = 5;//�e�̐F
						boss_shot.bullet[k].x = boss.x;//���W
						boss_shot.bullet[k].y = boss.y;
						boss_shot.bullet[k].knd = 8;//�e�̎��
						boss_shot.bullet[k].angle = angle + PI2 / 60 * i;//�p�x
						boss_shot.bullet[k].flag = 1;
						boss_shot.bullet[k].cnt = 0;
						boss_shot.bullet[k].spd = 2.5 + 0.5 * j;//�X�s�[�h
						boss_shot.bullet[k].gflag = 0;
					}
				}
			}
			se_flag[0] = 1;
		}
	}
	//    for(i=0;i<BOSS_BULLET_MAX;i++){
	//        if(boss_shot.bullet[i].flag>0){
	//
	//        }
	//    }
}

//�~�V���O�W����
void boss_shot_bulletH014() {
#define TM014 12000
	int t = boss_shot.cnt % TM014;
	int t2 = boss_shot.cnt;
	int k;
	int t3 = (t / 300) * 10;
	if (t >= 0 && t<12000 && t % (90 - t3) == 0) {
		double angle = rang(PI);
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (int j = 0; j<2; j++) {//�r������Q���􂷂镪
				for (int i = 0; i<(60 + t3 / 3); i++) {//��x��60��
					if ((k = search_boss_shot()) != -1) {
						boss_shot.bullet[k].knd = 8;//8�Ԃ̒e
						boss_shot.bullet[k].angle = angle + PI2 / (60 + t3 / 3) * i;//�~�`60��
						boss_shot.bullet[k].flag = 1;
						boss_shot.bullet[k].x = boss.x;
						boss_shot.bullet[k].y = boss.y;
						boss_shot.bullet[k].col = 1;
						boss_shot.bullet[k].cnt = 0;
						boss_shot.bullet[k].state = j;//�X�e�[�^�X�B0��1���ŉ�]�������
						boss_shot.bullet[k].spd = 2;
						boss_shot.bullet[k].gflag = 0;
						se_flag[0] = 1;//���ˉ��炷
					}
				}
			}
		}
	}
	for (int i = 0; i<SHOT_BULLET_MAX; i++) {//�S�e��
		if (boss_shot.bullet[i].flag>0) {//�o�^����Ă���e�������
			int state = boss_shot.bullet[i].state;
			int cnt = boss_shot.bullet[i].cnt;
			if (30<cnt && cnt<120) {//30�`120�J�E���g�Ȃ�
				if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
					boss_shot.bullet[i].spd -= 1.2 / 90.0;//90�J�E���g������1.2���炷
					boss_shot.bullet[i].angle += (PI / 2) / 90.0*(state ? -1 : 1);//90�J�E���g������90���X����
				}
			}
		}
	}
}

double chx = 0;	//�����F�̖����Ɏg�����@���W�ۑ��p�ϐ�
double chy = 0;

//�����F�̖���
void boss_shot_bulletH015() {
#define TM015 300
#define LONGR 150
#define SHORTR 30
	int i, k, t = boss_shot.cnt%TM015, t2 = boss_shot.cnt;
	double angle;
	if (t == 22) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			chx = ch.x;
			chy = ch.y;
		}
	}
	if (t >= 22 && t < 130 && t % 2 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			double lr = (t2 / TM015) % 2 == 0 ? -1.0 : 1.0;
			double tx = chx + LONGR * cos(PI2 * (t - 22)*lr / 72);
			double ty = chy + LONGR * sin(PI2 * (t - 22)*lr / 72);
			angle = bossatan4(chx, chy, tx, ty);
			for (i = 0; i < 8; i++) {
				if ((k = search_boss_shot()) != -1) {
					boss_shot.bullet[k].knd = 8;//8�Ԃ̒e
					boss_shot.bullet[k].angle = angle + PI2 / 8 * i + (((t - 22) / 2) % 2)*PI2 / 16;
					boss_shot.bullet[k].flag = 1;
					boss_shot.bullet[k].x = tx + SHORTR * lr;
					boss_shot.bullet[k].y = ty;
					boss_shot.bullet[k].col = 3;
					boss_shot.bullet[k].cnt = 0;
					boss_shot.bullet[k].spd = 1.0;
					boss_shot.bullet[k].gflag = 0;
					se_flag[0] = 1;//���ˉ��炷
				}
			}
		}
	}
	//for (int i = 0; i<SHOT_BULLET_MAX; i++) {//�S�e��
	//	if (boss_shot.bullet[i].flag>0) {//�o�^����Ă���e�������
	//		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
	//			boss_shot.bullet[i].spd += 0.01;//90�J�E���g������1.2���炷
	//		}
	//	}
	//}
}

//�G�^�[�i���~�[�N
void boss_shot_bulletH016() {
	int i, k, t = boss_shot.cnt;
	int n = 0;
	if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
		for (i = 0; i<2; i++) {//1�J�E���g��2�񔭎�
			n = GetRand(10000) * 8 / 10000;
			if ((k = search_boss_shot()) != -1) {
				boss_shot.bullet[k].col = 1;//7��ނ̐F�������_����
				boss_shot.bullet[k].x = boss.x;//���ˏ������W�̓{�X�̈ʒu
				boss_shot.bullet[k].y = boss.y;
				boss_shot.bullet[k].knd = 1;//�e�̎��
				boss_shot.bullet[k].angle = rang(PI2 / 4) + (n <= 2 ? PI2 / 4 : -PI2 / 4);
				boss_shot.bullet[k].flag = 1;
				boss_shot.bullet[k].cnt = 0;
				boss_shot.bullet[k].spd = 4.5 + rang(1.2);
				boss_shot.bullet[k].gflag = 0;
			}
		}
		if (t % 10 == 0)
			se_flag[0] = 1;
	}
}

//�ʏ�4�i�������̒ʏ�3�j
void boss_shot_bulletH017() {
#define TM017 240
	int i, k, t = boss_shot.cnt%TM017, t2 = boss_shot.cnt;
	if (t == 180) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			//40<x<FMX-40  50<y<150�@�͈̔͂�40���ꂽ�ʒu��40�J�E���g�ňړ�����
			move_boss_pos(60, 50, FMX - 60, 150, 40, 40);
		}
	}
	//60�J�E���g�ȉ���10�J�E���g��1��
	if (t >= 0 && t < 38 && t % 2 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			int t3 = t / 2;
			double angle = rang(PI2);
			double lr = (t2 / TM017) % 2 == 0 ? -1.0 : 1.0;
			double cx = boss.x + 30 * (t3 * (PI2 / 20)) * cos(PI / 2 + t3 * (PI2 / 20) * lr);
			double cy = boss.y + 30 * (t3 * (PI2 / 20)) * sin(PI / 2 + t3 * (PI2 / 20) * lr);
			for (i = 0; i<18; i++) {
				if ((k = search_boss_shot()) != -1) {
					boss_shot.bullet[k].col = 5;//�e�̐F
					boss_shot.bullet[k].x = cx;//���W
					boss_shot.bullet[k].y = cy;
					boss_shot.bullet[k].knd = 8;//�e�̎��
					boss_shot.bullet[k].angle = angle + PI2 / 18 * i;//�p�x
					boss_shot.bullet[k].flag = 1;
					boss_shot.bullet[k].cnt = 0;
					boss_shot.bullet[k].spd = 1.5;//�X�s�[�h
					boss_shot.bullet[k].gflag = 0;
				}
			}
			se_flag[0] = 1;
		}
	}
	//    for(i=0;i<BOSS_BULLET_MAX;i++){
	//        if(boss_shot.bullet[i].flag>0){
	//
	//        }
	//    }
}