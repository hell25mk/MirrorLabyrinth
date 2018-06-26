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

//読み込まれなかった場合のテストマップ
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
	StageCreate(argNowStageNum);

}

C_Laby::~C_Laby(){
	
	std::vector<int>().swap(labyVector);

}

void C_Laby::StageCreate(int argNowStageNum){

	char fileName[64];
	sprintf_s(fileName, sizeof(fileName), "Stage/Stage%d.csv", argNowStageNum);

	int fp;
	char inputc;
	maxKeyNum = 0;
	getKeyNum = 0;
	pos.x = 0;
	pos.y = 0;

	fp = C_FileManager::GetInstance().FileOpen(fileName);

	if(fp == NULL){
		labyVector = LabySampleVector;
		return;
	}

	while(1){

		//一文字取得
		inputc = FileRead_getc(fp);

		//スラッシュはコメントなので読み飛ばす
		if(inputc == '/'){
			while(FileRead_getc(fp) != '\n');
			continue;
		}

		//区切りを飛ばす
		if(inputc == ',' || inputc == '\n' || inputc == '\r'){
			continue;
		}

		//ファイル末尾に来た場合ループフラグを変更する
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
				blockVector[pos.y * Laby_Width + pos.x] = std::shared_ptr<C_BaseBlock>(new C_Door(pos, &maxKeyNum, &getKeyNum));
				break;
			case Laby_Key:
				blockVector[pos.y * Laby_Width + pos.x] = std::shared_ptr<C_BaseBlock>(new C_Key(pos,&getKeyNum));
				maxKeyNum++;
				break;
			case Laby_Block:
				blockVector[pos.y * Laby_Width + pos.x] = std::shared_ptr<C_BaseBlock>(new C_Block(pos));
				break;
		}

		pos.x++;
		if(pos.x % Laby_Width == 0){
			pos.y++;
			pos.x = 0;
		}

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

	for(auto itr = blockVector.begin(); itr != blockVector.end();){

		(*itr)->Draw();
		itr++;

	}

}

bool C_Laby::MoveCheck(int argDire, C_Position<int> argPos){

	bool checkFlag = false;
	C_Position<int> tempPos;
	int vy[4] = { 1,0,0,-1 };		//y移動量
	int vx[4] = { 0,1,-1,0 };		//x移動量
	//int test[4] = { Laby_Height - 1,Laby_Width - 1,0,0 };		//移動可能範囲

	tempPos.y = argPos.y / Block_Size + vy[argDire];
	tempPos.x = argPos.x / Block_Size + vx[argDire];

#pragma region 参照チェック
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