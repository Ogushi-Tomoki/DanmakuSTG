#include "../include/GV.h"
#include <stdio.h>

//データのセーブ
void DataSave(save_data_t* save_data) {
	FILE *fp;
	errno_t error;

	//データセーブ用ファイルを開く
	//（2番目の引数の"wb"の'w'は「書きこみ」の意味）
	//'b'はバイナリの意味
	error = fopen_s(&fp, "../save_data/save_data.dat", "wb");

	//オープンできなかったらそこで終了
	if (fp == NULL) {
		printfDx("file cannot open!!\n");
		return;
	}

	//データの書き出し
	fwrite(save_data, sizeof(*save_data), 1, fp);

	//ファイルを閉じる
	fclose(fp);
}

//データのロード
void DataLoad(save_data_t* save_data) {
	FILE *fp;
	errno_t error;

	//データセーブ用ファイルを開く
	//（2番目の引数の"rb"の'r'は「読み込み」の意味）
	//'b'はバイナリの意味
	error = fopen_s(&fp, "../save_data/save_data.dat", "rb");

	//オープンできなかったらファイルが無いとみなし、標準の値をセット
	if (fp == NULL) {
		configpad.bom = 4;
		configpad.shot = 9;
		configpad.slow = 8;
		configpad.start = 11;
		configpad.change = 10;
		configpad.special = 5;
		HiScore = 0;
	}
	else {
		//データの読み込み
		fread(save_data, sizeof(*save_data), 1, fp);

		//ファイルを閉じる
		fclose(fp);
	}
}