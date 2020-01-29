#include "../include/Game.h"
#include "DxLib.h"

Game::Game(ISceneChanger* changer) : BaseScene(changer) {
}

//初期化
void Game::Initialize() {
	mImageHandle = LoadGraph("images/Scene_Game.png");    //画像のロード
}

//更新
void Game::Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
		mSceneChanger->ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}

//描画
void Game::Draw() {
	BaseScene::Draw();//親クラスの描画メソッドを呼ぶ
	DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}