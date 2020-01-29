#include "../include/GV.h"

//1発だけ、自機に向かって直線発射
void shot_bullet_H000(int n) {
	int k;
	if (shot[n].cnt == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
				shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
				shot[n].bullet[k].angle = shotatan2(n);
				shot[n].bullet[k].flag = 1;
				shot[n].bullet[k].x = enemy[shot[n].num].x;
				shot[n].bullet[k].y = enemy[shot[n].num].y;
				shot[n].bullet[k].col = enemy[shot[n].num].col;
				shot[n].bullet[k].cnt = 0;
				shot[n].bullet[k].spd = 3;
				shot[n].bullet[k].gflag = 0;
				se_flag[0] = 1;
			}
		}
	}
}

//100カウント中に10発、自機に向かって直線発射(常に自機狙い)
void shot_bullet_H001(int n) {
	int t = shot[n].cnt;
	int k;
	if (t >= 0 && t<100 && t % 10 == 0) {//100カウント中10カウントに1回
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {//敵がいて、弾が登録可能なら
				shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;//弾登録
				shot[n].bullet[k].angle = shotatan2(n);//角度
				shot[n].bullet[k].flag = 1;//フラグ
				shot[n].bullet[k].x = enemy[shot[n].num].x;//座標
				shot[n].bullet[k].y = enemy[shot[n].num].y;
				shot[n].bullet[k].col = enemy[shot[n].num].col;//色
				shot[n].bullet[k].cnt = 0;//カウンタ
				shot[n].bullet[k].spd = 3;//スピード
				shot[n].bullet[k].gflag = 0;
				se_flag[0] = 1;
			}
		}
	}
}

//100カウント中に10発、自機に向かって直線発射(角度記憶)
void shot_bullet_H002(int n) {
	int t = shot[n].cnt;
	int k;
	if (t >= 0 && t<100 && t % 10 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			if (t == 0)
				shot[n].base_angle[0] = shotatan2(n);
			if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
				shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
				shot[n].bullet[k].angle = shot[n].base_angle[0];
				shot[n].bullet[k].flag = 1;
				shot[n].bullet[k].x = enemy[shot[n].num].x;
				shot[n].bullet[k].y = enemy[shot[n].num].y;
				shot[n].bullet[k].col = enemy[shot[n].num].col;
				shot[n].bullet[k].cnt = 0;
				shot[n].bullet[k].spd = 3;
				shot[n].bullet[k].gflag = 0;
				se_flag[0] = 1;
			}
		}
	}
}

//100カウント中に10発、自機に向かってスピード変化直線発射
void shot_bullet_H003(int n) {
	int t = shot[n].cnt;
	int k;
	if (t >= 0 && t<100 && t % 10 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
				shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
				shot[n].bullet[k].angle = shotatan2(n);
				shot[n].bullet[k].flag = 1;
				shot[n].bullet[k].x = enemy[shot[n].num].x;
				shot[n].bullet[k].y = enemy[shot[n].num].y;
				shot[n].bullet[k].col = enemy[shot[n].num].col;
				shot[n].bullet[k].cnt = 0;
				shot[n].bullet[k].spd = 1 + 5.0 / 100 * t;
				shot[n].bullet[k].gflag = 0;
				se_flag[0] = 1;
			}
		}
	}
}

//0.5秒に1回ずつ円形発射
void shot_bullet_H004(int n) {
	int t = shot[n].cnt;
	int k;
	if (t >= 0 && t<120 && t % 20 == 0) {
		double angle = shotatan2(n);
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (int i = 0; i<20; i++) {
				if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
					shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
					shot[n].bullet[k].angle = angle + PI2 / 20 * i;
					shot[n].bullet[k].flag = 1;
					shot[n].bullet[k].x = enemy[shot[n].num].x;
					shot[n].bullet[k].y = enemy[shot[n].num].y;
					shot[n].bullet[k].col = enemy[shot[n].num].col;
					shot[n].bullet[k].cnt = 0;
					shot[n].bullet[k].spd = 4;
					shot[n].bullet[k].gflag = 0;
					se_flag[0] = 1;
				}
			}
		}
	}
}

//ばらまきショット
void shot_bullet_H005(int n) {
	int t = shot[n].cnt;
	int k;
	if (t >= 0 && t<120 && t % 2 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
				shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
				shot[n].bullet[k].angle = shotatan2(n) + rang(PI / 4);
				shot[n].bullet[k].flag = 1;
				shot[n].bullet[k].x = enemy[shot[n].num].x;
				shot[n].bullet[k].y = enemy[shot[n].num].y;
				shot[n].bullet[k].col = enemy[shot[n].num].col;
				shot[n].bullet[k].cnt = 0;
				shot[n].bullet[k].spd = 3 + rang(1.5);
				shot[n].bullet[k].gflag = 0;
				se_flag[0] = 1;
			}
		}
	}
}

//ばらまきショット(減速)
void shot_bullet_H006(int n) {
	int t = shot[n].cnt;
	int k;
	if (t >= 0 && t<120 && t % 2 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
				shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
				shot[n].bullet[k].angle = shotatan2(n) + rang(PI / 4);
				shot[n].bullet[k].flag = 1;
				shot[n].bullet[k].x = enemy[shot[n].num].x;
				shot[n].bullet[k].y = enemy[shot[n].num].y;
				shot[n].bullet[k].col = enemy[shot[n].num].col;
				shot[n].bullet[k].cnt = 0;
				shot[n].bullet[k].spd = 4 + rang(2);
				shot[n].bullet[k].gflag = 0;
				se_flag[0] = 1;
			}
		}
	}
	for (int i = 0; i<SHOT_BULLET_MAX; i++) {
		if (shot[n].bullet[i].spd > 1.5) {
			if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
				shot[n].bullet[i].spd -= 0.04;
			}
		}		
	}
}


//みょん弾幕
void shot_bullet_H007(int n) {
	int t = shot[n].cnt;
	int k;
	if (t >= 0 && t <= 150 && t % 10 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (int i = 0; i<20; i++) {
				if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
					shot[n].bullet[k].knd = 7;
					shot[n].bullet[k].angle = PI2 / 20 * i;
					shot[n].bullet[k].flag = 1;
					shot[n].bullet[k].x = enemy[shot[n].num].x + cos(PI / 2 + PI / 150 * t) * 100;
					shot[n].bullet[k].y = enemy[shot[n].num].y + sin(PI / 2 + PI / 150 * t) * 100;
					shot[n].bullet[k].col = 2;
					shot[n].bullet[k].cnt = 0;
					shot[n].bullet[k].spd = 1.2;
					shot[n].bullet[k].gflag = 0;
				}
			}
			for (int i = 0; i<20; i++) {
				if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
					shot[n].bullet[k].knd = 7;
					shot[n].bullet[k].angle = PI2 / 20 * i;
					shot[n].bullet[k].flag = 1;
					shot[n].bullet[k].x = enemy[shot[n].num].x + cos(PI / 2 - PI / 150 * t) * 100;
					shot[n].bullet[k].y = enemy[shot[n].num].y + sin(PI / 2 - PI / 150 * t) * 100;
					shot[n].bullet[k].col = 4;
					shot[n].bullet[k].cnt = 0;
					shot[n].bullet[k].spd = 1.2;
					shot[n].bullet[k].gflag = 0;
					se_flag[0] = 1;
				}
			}
		}
	}
}

//ミシャグジさま
void shot_bullet_H008(int n) {
	int t = shot[n].cnt;
	int k;
	if (t >= 0 && t<1200 && t % 90 == 0) {
		double angle = rang(PI);
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (int j = 0; j<2; j++) {//途中から２分裂する分
				for (int i = 0; i<60; i++) {//一度に60個
					if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
						shot[n].bullet[k].knd = 8;//8番の弾
						shot[n].bullet[k].angle = angle + PI2 / 60 * i;//円形60個
						shot[n].bullet[k].flag = 1;
						shot[n].bullet[k].x = enemy[shot[n].num].x;
						shot[n].bullet[k].y = enemy[shot[n].num].y;
						shot[n].bullet[k].col = enemy[shot[n].num].col;
						shot[n].bullet[k].cnt = 0;
						shot[n].bullet[k].state = j;//ステータス。0か1かで回転がかわる
						shot[n].bullet[k].spd = 2;
						shot[n].bullet[k].gflag = 0;
						se_flag[0] = 1;//発射音鳴らす
					}
				}
			}
		}
	}
	for (int i = 0; i<SHOT_BULLET_MAX; i++) {//全弾分
		if (shot[n].bullet[i].flag>0) {//登録されている弾があれば
			int state = shot[n].bullet[i].state;
			int cnt = shot[n].bullet[i].cnt;
			if (30<cnt && cnt<120) {//30～120カウントなら
				if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
					shot[n].bullet[i].spd -= 1.2 / 90.0;//90カウントかけて1.2減らす
					shot[n].bullet[i].angle += (PI / 2) / 90.0*(state ? -1 : 1);//90カウントかけて90°傾ける
				}
			}
		}
	}
}

//自機方向に密度の低いばらまき弾幕
void shot_bullet_H009(int n) {
	int t = shot[n].cnt;
	int k;
	if (t >= 0 && t<210 && t % 5 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
				shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
				shot[n].bullet[k].angle = shotatan2(n) + rang(PI / 3);
				shot[n].bullet[k].flag = 1;
				shot[n].bullet[k].x = enemy[shot[n].num].x;
				shot[n].bullet[k].y = enemy[shot[n].num].y;
				shot[n].bullet[k].col = enemy[shot[n].num].col;
				shot[n].bullet[k].cnt = 0;
				shot[n].bullet[k].spd = 3 + rang(1);
				shot[n].bullet[k].gflag = 0;
				se_flag[0] = 1;
			}
		}
	}
}

//密度の高い自機狙い全方向19-way弾
void shot_bullet_H010(int n) {
	int t = shot[n].cnt;
	int k;
	int way = 27;
	if (t >= 0 && t<150 && t % 10 == 0) {
		double angle = shotatan2(n);
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (int i = 0; i<way; i++) {
				if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
					shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
					shot[n].bullet[k].angle = angle + PI2 / way * i;
					shot[n].bullet[k].flag = 1;
					shot[n].bullet[k].x = enemy[shot[n].num].x;
					shot[n].bullet[k].y = enemy[shot[n].num].y;
					shot[n].bullet[k].col = enemy[shot[n].num].col;
					shot[n].bullet[k].cnt = 0;
					shot[n].bullet[k].spd = 4;
					shot[n].bullet[k].gflag = 0;
				}
			}
			se_flag[0] = 1;
		}
	}
}

//自機狙い全方位粒弾
void shot_bullet_H011(int n) {
	int t = shot[n].cnt;
	int k;
	int way = 11;
	if (t >= 0 &&(t % 90 == 0 || t % 90 == 10)) {
		double angle = shotatan2(n);
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (int i = 0; i<way; i++) {
				if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
					shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
					shot[n].bullet[k].angle = angle + rang(PI * 4 / 180) + PI2 / way * i;
					shot[n].bullet[k].flag = 1;
					shot[n].bullet[k].x = enemy[shot[n].num].x;
					shot[n].bullet[k].y = enemy[shot[n].num].y;
					shot[n].bullet[k].col = enemy[shot[n].num].col;
					shot[n].bullet[k].cnt = 0;
					shot[n].bullet[k].spd = 2;
					shot[n].bullet[k].gflag = 0;
				}
			}
			se_flag[0] = 1;
		}
	}
}

//全方位ランダム弾（1.5秒に1回発射）
void shot_bullet_H012(int n) {
	int t = shot[n].cnt;
	int k;
	int way = 7;
	if (t >= 0 && t % 90 == 0) {
		double angle = rang(PI);
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (int i = 0; i<way; i++) {
				if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
					shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
					shot[n].bullet[k].angle = angle + PI2 / way * i;
					shot[n].bullet[k].flag = 1;
					shot[n].bullet[k].x = enemy[shot[n].num].x;
					shot[n].bullet[k].y = enemy[shot[n].num].y;
					shot[n].bullet[k].col = enemy[shot[n].num].col;
					shot[n].bullet[k].cnt = 0;
					shot[n].bullet[k].spd = 1.5;
					shot[n].bullet[k].gflag = 0;
					se_flag[0] = 1;
				}
			}
		}
	}
}

//全方位ランダム弾+自機狙い弾2つ
void shot_bullet_H013(int n) {
	int t = shot[n].cnt;
	int k;
	int way = 7;
	if (t == 30) {
		double angle = rang(PI);
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (int i = 0; i<way; i++) {
				if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
					shot[n].bullet[k].knd = 8;
					shot[n].bullet[k].angle = angle + PI2 / way * i;
					shot[n].bullet[k].flag = 1;
					shot[n].bullet[k].x = enemy[shot[n].num].x;
					shot[n].bullet[k].y = enemy[shot[n].num].y;
					shot[n].bullet[k].col = enemy[shot[n].num].col;
					shot[n].bullet[k].cnt = 0;
					shot[n].bullet[k].spd = 1;
					shot[n].bullet[k].gflag = 0;
				}
			}
			se_flag[0] = 1;
		}
	}
	if (t == 30 || t == 60) {
		double angle = shotatan2(n);
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (int i = 0; i<way; i++) {
				if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
					shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
					shot[n].bullet[k].angle = angle + PI2 / way * i;
					shot[n].bullet[k].flag = 1;
					shot[n].bullet[k].x = enemy[shot[n].num].x;
					shot[n].bullet[k].y = enemy[shot[n].num].y;
					shot[n].bullet[k].col = enemy[shot[n].num].col;
					shot[n].bullet[k].cnt = 0;
					shot[n].bullet[k].spd = 4.5;
					shot[n].bullet[k].gflag = 0;
				}
			}
			se_flag[0] = 1;
		}
	}
}

//下方向に密度の高いばらまき弾
void shot_bullet_H014(int n) {
	int t = shot[n].cnt;
	int k;
	if (t >= 0 && t<180 && t % 3 == 0) {
		if (emperor_time.flag == 0 || count % EMPEROR_TIME_RATE == 0) {
			for (int i = 0; i < 2; i++) {
				if (shot[n].flag != 2 && (k = shot_search(n)) != -1) {
					shot[n].bullet[k].knd = enemy[shot[n].num].blknd2;
					shot[n].bullet[k].angle = PI / 2 + rang(PI / 3);
					shot[n].bullet[k].flag = 1;
					shot[n].bullet[k].x = enemy[shot[n].num].x;
					shot[n].bullet[k].y = enemy[shot[n].num].y;
					shot[n].bullet[k].col = enemy[shot[n].num].col;
					shot[n].bullet[k].cnt = 0;
					shot[n].bullet[k].spd = 1.2 + rang(0.3);
					shot[n].bullet[k].gflag = 0;
					se_flag[0] = 1;
				}
			}
		}
	}
}
void shot_bullet_H015(int n) {}
void shot_bullet_H016(int n) {}
void shot_bullet_H017(int n) {}
