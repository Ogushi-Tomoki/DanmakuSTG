extern void boss_shot_bulletH000();
extern void boss_shot_bulletH001();
extern void boss_shot_bulletH002();
extern void boss_shot_bulletH003();
extern void boss_shot_bulletH004();
extern void boss_shot_bulletH005();
extern void boss_shot_bulletH006();
extern void boss_shot_bulletH007();
extern void boss_shot_bulletH008();
extern void boss_shot_bulletH009();
extern void boss_shot_bulletH010();
extern void boss_shot_bulletH011();
extern void boss_shot_bulletH012();
extern void boss_shot_bulletH013();
extern void boss_shot_bulletH014();
extern void boss_shot_bulletH015();
extern void boss_shot_bulletH016();
extern void boss_shot_bulletH017();

void(*boss_shot_bullet[DANMAKU_MAX])() =
{
//中ボス
	boss_shot_bulletH000,	//ノーマル
	boss_shot_bulletH002,	//スペル～パーフェクトフリーズ～
	boss_shot_bulletH012,	//ノーマル
	boss_shot_bulletH015,	//スペル～刈安色の迷夢～
	boss_shot_bulletH004,	//スペル～ケロちゃん～
//ラスボス
	boss_shot_bulletH013,	//ノーマル
	boss_shot_bulletH005,	//スペル～☆弾～
	boss_shot_bulletH017,	//ノーマル～サイレントセレナ～
	boss_shot_bulletH016,	//スペル～エターナルミーク～
	boss_shot_bulletH001,	//ノーマル～サイレントセレナ～
	boss_shot_bulletH014,	//スペル～ミシャグジさま～
	boss_shot_bulletH007,	//スペル～そして誰もいなくなるか？～
	boss_shot_bulletH010,	//スペル～深弾幕結界～

//終り

	boss_shot_bulletH000,	//ぬるぽ回避用(この弾幕は出てこない)
};
