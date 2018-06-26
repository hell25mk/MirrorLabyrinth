#include "Laby.h"
#include "DxLib.h"
#include "../Manager/FileManager.h"
#include "../System/Position.h"
#include "../Base/BaseBlock.h"
#include "BlockList.h"

const int C_Laby::Laby_Height = 15;
const int C_Laby::Laby_Width = 20;
const int Image_Width = 5;
const int Image_Height = 3;
const int Block_Size = 32;

//�ǂݍ��܂�Ȃ������ꍇ�̃e�X�g�}�b�v
std::vector<int> LabySampleVector{
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	 1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,
	 1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,0,0,1,
	 1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,
	 1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,0,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
	 1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

C_Laby::C_Laby(int argNowStageNum){

	labyVector.resize(Laby_Height * Laby_Width);
	blockVector.resize(Laby_Height * Laby_Width);

	gameState = State_GamePlay;
	getKeyNum = 0;

	StageCreate(argNowStageNum);

}

C_Laby::~C_Laby(){
	
	std::vector<int>().swap(labyVector);
	keyList.clear();
	delete door;
	breakWallList.clear();

}

void C_Laby::StageCreate(int argNowStageNum){

	char fileName[64];
	sprintf_s(fileName, sizeof(fileName), "Stage/Stage%d.csv", argNowStageNum);

	int fp;
	char inputc;
	int keyNum = 0;
	pos.x = 0;
	pos.y = 0;

	fp = C_FileManager::GetInstance().FileOpen(fileName);

	if(fp == NULL){
		labyVector = LabySampleVector;
		return;
	}

	while(1){

		//�ꕶ���擾
		inputc = FileRead_getc(fp);

		//�X���b�V���̓R�����g�Ȃ̂œǂݔ�΂�
		if(inputc == '/'){
			while(FileRead_getc(fp) != '\n');
			continue;
		}

		//��؂���΂�
		if(inputc == ',' || inputc == '\n' || inputc == '\r'){
			continue;
		}

		//�t�@�C�������ɗ����ꍇ���[�v�t���O��ύX����
		if(inputc == EOF){
			break;
		}

		labyVector[pos.y * Laby_Width + pos.x] = atoi(&inputc);
		switch(labyVector[pos.y * Laby_Width + pos.x]){
			case Laby_Road:
				blockVector[pos.y * Laby_Width + pos.x] = std::shared_ptr<C_BaseBlock>(new C_Road(pos));
				break;
			case Laby_Wall:
				blockVector[pos.y * Laby_Width + pos.x] = std::shared_ptr<C_BaseBlock>(new C_Wall(pos));
				break;
			case Laby_Stairs:
				blockVector[pos.y * Laby_Width + pos.x] = std::shared_ptr<C_BaseBlock>(new C_Stairs(pos));
				break;
			case Laby_Door:
				door = new C_Door(pos);
				blockVector[pos.y * Laby_Width + pos.x] = std::shared_ptr<C_BaseBlock>(new C_Door(pos));
				break;
			case Laby_Key:
				keyList.push_back(new C_Key(pos));
				blockVector[pos.y * Laby_Width + pos.x] = std::shared_ptr<C_BaseBlock>(new C_Key(pos));
				keyNum++;
				break;
			case Laby_Block:
				breakWallList.push_back(new C_Block(pos));
				blockVector[pos.y * Laby_Width + pos.x] = std::shared_ptr<C_BaseBlock>(new C_Block(pos));
				break;
		}

		pos.x++;
		if(pos.x % Laby_Width == 0){
			pos.y++;
			pos.x = 0;
		}

	}

	//�������݂���Ȃ献�̍ő吔���Z�b�g
	if(door != NULL){
		door->SetMaxKeyNum(keyNum);
	}

	C_FileManager::GetInstance().FileClose();

}

void C_Laby::Update(){

	for(auto itr = blockVector.begin(); itr != blockVector.end();){

		(*itr)->Update();
		itr++;

	}

}

void C_Laby::Draw(){
	/*
	for(pos.y = 0; pos.y < Laby_Height; pos.y++){
		for(pos.x = 0; pos.x < Laby_Width; pos.x++){

			//�O��
			if(pos.y == 0 || pos.y == (Laby_Height - 1) || pos.x == 0 || pos.x == (Laby_Width - 1)){
				DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Laby_Wall], TRUE);
				continue;
			}

			//�^�񒆏�
			if(pos.y <= (Laby_Height / 2)){
				DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Laby_Road], TRUE);

				switch(labyVector[pos.y * Laby_Width + pos.x]){
					case Laby_Wall:
						DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Laby_Wall], TRUE);
						break;
				}
			}
			
			//�^��
			if(pos.y == (Laby_Height / 2)){
				switch(labyVector[pos.y * Laby_Width + pos.x]){
					case Laby_Wall:
						DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Laby_Wall], TRUE);
						break;
					case Laby_Stairs:
						DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Laby_Stairs], TRUE);
						break;
				}
			}

			//�^�񒆉�
			if(pos.y >= (Laby_Height / 2) + 1){
				DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Laby_Road], TRUE);

				switch(labyVector[pos.y * Laby_Width + pos.x]){
					case Laby_Stairs:
						DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Laby_Stairs], TRUE);
						break;
				}
			}

		}
	}

	for(auto itr = keyList.begin(); itr != keyList.end();){

		(*itr)->Draw();
		itr++;

	}

	if(door != NULL){
		door->Draw();
	}

	for(auto itr = breakWallList.begin(); itr != breakWallList.end();){

		(*itr)->Draw();
		itr++;

	}
	*/

	for(auto itr = blockVector.begin(); itr != blockVector.end();){

		(*itr)->Draw();
		itr++;

	}

}

bool C_Laby::MoveCheck(int argDire, C_Position<int> argPos){

	bool checkFlag = false;
	C_Position<int> tempPos;
	int vy[4] = { 1,0,0,-1 };		//y�ړ���
	int vx[4] = { 0,1,-1,0 };		//x�ړ���
	//int test[4] = { Laby_Height - 1,Laby_Width - 1,0,0 };		//�ړ��\�͈�

	tempPos.y = argPos.y / Block_Size + vy[argDire];
	tempPos.x = argPos.x / Block_Size + vx[argDire];

#pragma region �Q�ƃ`�F�b�N
	if(tempPos.x < 0){
		return false;
	}
	if(tempPos.x > Laby_Width - 1){
		return false;
	}
	if(tempPos.y < 0){
		return false;
	}
	if(tempPos.y > Laby_Height - 1){
		return false;
	}
#pragma endregion

	if(!blockVector[tempPos.y * Laby_Width + tempPos.x]->HitAction()){
		return false;
	}

	checkFlag = true;

	/*vectorPos = tempPos.y * Laby_Width + tempPos.x;

	if(labyVector[vectorPos] == Laby_Wall){
		checkFlag = false;
#ifdef _DEBUG
		//checkFlag = true;
#endif // _DEBUG

	} else{
		checkFlag = true;
	}

	if(labyVector[vectorPos] == Laby_Door){
		return door->GetDoorOpenFlag();
	}
		
	if(labyVector[vectorPos] == Laby_Key){
		for(auto itr = keyList.begin(); itr != keyList.end();){

			if((*itr)->KeyPosCheck(tempPos)){
				getKeyNum++;
				itr = keyList.erase(itr);
				continue;
			}
			
			itr++;

		}

		door->CheckDoorOpenFlag(getKeyNum);

	}
	
	if(labyVector[vectorPos] == Laby_Block){
		for(auto itr = breakWallList.begin(); itr != breakWallList.end();){

			if((*itr)->BlockPosCheck(tempPos)){
				(*itr)->SetWallDamage();
				if((*itr)->GetBreakFlag()){
					itr = breakWallList.erase(itr);
					continue;
				} else{
					return false;
				}
			}

			itr++;

		}
	}*/

	return checkFlag;
}

e_GameState C_Laby::GetGameState(C_Position<int> const argPos){

	C_Position<int> tempPos;

	tempPos.x = argPos.x / Block_Size;
	tempPos.y = argPos.y / Block_Size;

	if(labyVector[tempPos.y * Laby_Width + tempPos.x] != Laby_Stairs){
		return gameState;
	}

	gameState = State_StageClear;

	return gameState;
}