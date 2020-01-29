#include "../include/GV.h"
#include <stdio.h>

//�f�[�^�̃Z�[�u
void DataSave(save_data_t* save_data) {
	FILE *fp;
	errno_t error;

	//�f�[�^�Z�[�u�p�t�@�C�����J��
	//�i2�Ԗڂ̈�����"wb"��'w'�́u�������݁v�̈Ӗ��j
	//'b'�̓o�C�i���̈Ӗ�
	error = fopen_s(&fp, "../save_data/save_data.dat", "wb");

	//�I�[�v���ł��Ȃ������炻���ŏI��
	if (fp == NULL) {
		printfDx("file cannot open!!\n");
		return;
	}

	//�f�[�^�̏����o��
	fwrite(save_data, sizeof(*save_data), 1, fp);

	//�t�@�C�������
	fclose(fp);
}

//�f�[�^�̃��[�h
void DataLoad(save_data_t* save_data) {
	FILE *fp;
	errno_t error;

	//�f�[�^�Z�[�u�p�t�@�C�����J��
	//�i2�Ԗڂ̈�����"rb"��'r'�́u�ǂݍ��݁v�̈Ӗ��j
	//'b'�̓o�C�i���̈Ӗ�
	error = fopen_s(&fp, "../save_data/save_data.dat", "rb");

	//�I�[�v���ł��Ȃ�������t�@�C���������Ƃ݂Ȃ��A�W���̒l���Z�b�g
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
		//�f�[�^�̓ǂݍ���
		fread(save_data, sizeof(*save_data), 1, fp);

		//�t�@�C�������
		fclose(fp);
	}
}