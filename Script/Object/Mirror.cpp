#include "Mirror.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/Animation.h"
#include "Player.h"
#include "../Define/Enum.h"

const int Reflect_Space = 14;
const int FlashLoopTime = 180;
const int AnimeChange_Time = 30;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="player">�v���C���[�̕ϐ����i�[�����|�C���^</param>
Mirror::Mirror(Player* player):BaseCharacter(){

	this->player = player;
	pos.SetPosition(player->GetPosition().GetX(), (Reflect_Space - (player->GetPosition().GetY() / Block_Size)) * Block_Size);
	dire = Dire_Down * Image_Width;
	flashTime = 0;
	willFlash = true;
	int animeOrder[4] = { 0,1,0,2 };
	int orderSize = sizeof(animeOrder) / sizeof(animeOrder[0]);
	animation = new Animation(animeOrder, orderSize, AnimeChange_Time, &imageNumber);

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Mirror::~Mirror(){

	delete animation;

}

/// <summary>
/// �X�V�������s��
/// </summary>
void Mirror::Update(){

	animation->Update();
	Fhashing();

}

/// <summary>
/// �`�揈�����s��
/// </summary>
void Mirror::Draw(){

	//�_�ł��Ă��Ȃ��Ƃ������\������
	if(willFlash){
		DrawRotaGraph((pos.GetDx() + 16), (pos.GetDy() + 16), (Block_Size / (double)Image_Size), 0.0, image[dire + imageNumber], TRUE);
	}

}

/// <summary>
/// �v���C���[�̍��W�ɑ΂���ꏊ�Ɉړ�����
/// </summary>
void Mirror::Move(){

	pos.SetPosition(player->GetPosition().GetX(), (Reflect_Space - (player->GetPosition().GetY() / Block_Size)) * Block_Size);

}

/// <summary>
/// �v���C���[�̌����ɑ΂�������ɕύX����
/// </summary>
void Mirror::Direction(){

	int arrDire[4]{ Dire_Up ,Dire_Right ,Dire_Left ,Dire_Down };
	dire = arrDire[player->GetDirection() / Image_Width] * Image_Width;

}

/// <summary>
/// �_�ł��Ă��邩�ǂ�����؂�ւ���
/// </summary>
void Mirror::Fhashing(){

	flashTime++;
	willFlash = flashTime < FlashLoopTime / 3;
	flashTime = flashTime % FlashLoopTime;

#ifdef _DEBUG
	//willFlash = true;
#endif //�_�Ŗ���

}