#include "Laby.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "Door.h"
#include "Key.h"
#include "BreakWall.h"
#include "Wall.h"

const int C_Laby::Laby_Height = 15;
const int C_Laby::Laby_Width = 20;
const int Image_X_Num = 5;
const int Image_Y_Num = 3;
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

	blockMaterialImage = new int[Image_X_Num * Image_Y_Num];
	LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_X_Num * Image_Y_Num, Image_X_Num, Image_Y_Num, Block_Size, Block_Size, blockMaterialImage);

	labyVector.resize(Laby_Height * Laby_Width);
	//wall.resize(0);

	gameState = State_GamePlay;
	getKeyNum = 0;

	StageCreate(argNowStageNum);

	//扉が存在するなら鍵の最大数をセット
	if(door != NULL){
		door->SetMaxKeyNum(keyList.size());
	}

}

C_Laby::~C_Laby(){
	
	std::vector<int>().swap(labyVector);
	keyList.clear();
	delete door;
	breakWallList.clear();
	delete[] blockMaterialImage;

}

void C_Laby::StageCreate(int argNowStageNum){

	char fileName[64];
	sprintf_s(fileName, sizeof(fileName), "Stage/Stage%d.csv", argNowStageNum);

	int fp;
	char inputc;
	pos.x = 0;
	pos.y = 0;

	fp = FileRead_open(fileName);

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

		//ドアと鍵を生成する
		labyVector[pos.y * Laby_Width + pos.x] = atoi(&inputc);

		switch(labyVector[pos.y * Laby_Width + pos.x]){
			case Laby_Wall:
				//wall.push_back(C_Wall(pos));
				break;
			case Laby_Door:
				door = new C_Door(pos);
				break;
			case Laby_Key:
				keyList.push_back(C_Key(pos));
				break;
			case Laby_BreakWall:
				breakWallList.push_back(C_BreakWall(pos));
				break;
		}

		pos.x++;
		if(pos.x % Laby_Width == 0){
			pos.y++;
			pos.x = 0;
		}

	}

	FileRead_close(fp);

}

void C_Laby::Update(){



}

void C_Laby::Draw(){

	for(pos.y = 0; pos.y < Laby_Height; pos.y++){
		for(pos.x = 0; pos.x < Laby_Width; pos.x++){

			//外壁
			if(pos.y == 0 || pos.y == (Laby_Height - 1) || pos.x == 0 || pos.x == (Laby_Width - 1)){
				DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Laby_Wall], TRUE);
				continue;
			}

			//真ん中上
			if(pos.y <= (Laby_Height / 2)){
				DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Laby_Road], TRUE);

				switch(labyVector[pos.y * Laby_Width + pos.x]){
					case Laby_Wall:
						DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Laby_Wall], TRUE);
						break;
				}
			}
			
			//真ん中
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

			//真ん中下
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

		itr->Draw();
		itr++;

	}

	if(door != NULL){
		door->Draw();
	}

	for(auto itr = breakWallList.begin(); itr != breakWallList.end();){

		itr->Draw();
		itr++;

	}

}

bool C_Laby::MoveCheck(int argDire, C_Position<int> argPos){

	bool checkFlag = false;
	C_Position<int> tempPos;
	int vectorPos;

	tempPos.x = argPos.x / Block_Size;
	tempPos.y = argPos.y / Block_Size;

	switch(argDire){
		case Dire_Down:
			tempPos.y++;
			break;
		case Dire_Left:
			tempPos.x--;
			break;
		case Dire_Right:
			tempPos.x++;
			break;
		case Dire_Up:
			tempPos.y--;
			break;
	}

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

	vectorPos = tempPos.y * Laby_Width + tempPos.x;

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

			if(itr->KeyPosCheck(tempPos)){
				getKeyNum++;
				itr = keyList.erase(itr);
				continue;
			}
			
			itr++;

		}

		door->CheckDoorOpenFlag(getKeyNum);

	}
	
	if(labyVector[vectorPos] == Laby_BreakWall){
		for(auto itr = breakWallList.begin(); itr != breakWallList.end();){

			if(itr->BWallPosCheck(tempPos)){
				itr->SetWallDamage();
				if(itr->GetBreakFlag()){
					itr = breakWallList.erase(itr);
					continue;
				} else{
					return false;
				}
			}

			itr++;

		}
	}

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