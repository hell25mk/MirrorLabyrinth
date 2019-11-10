#include "Player.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Manager/KeyboardManager.h"
#include "../System/GameInfo.h"
#include "../System/Animation.h"

const int AnimeChange_Time = 30;

/// <summary>
/// �����o������������
/// </summary>
/// <param name="argPos">���W</param>
Player::Player(Position<int> argPos):BaseCharacter(argPos){

	pos.SetPosition(argPos.GetX() * Block_Size, argPos.GetY() * Block_Size);
	dire = Dire_Up * Image_Width;
	imageNumber = 0;
	int animeOrder[4] = { 0,1,0,2 };
	int orderSize = sizeof(animeOrder) / sizeof(animeOrder[0]);
	animation = new Animation(animeOrder, orderSize, AnimeChange_Time, &imageNumber);

}

/// <summary>
/// ���������m�ۂ��Ă����ꍇ�͉������
/// </summary>
Player::~Player(){

	delete animation;

}

/// <summary>
/// 1���[�v���ŕK�v�ȍX�V�������s��
/// </summary>
void Player::Update(){

	animation->Update();

}

/// <summary>
/// 1���[�v���ŕK�v�ȕ`�揈�����s��
/// </summary>
void Player::Draw(){
	
	DrawRotaGraph(pos.GetDx() + 16, pos.GetDy() + 16, (Block_Size / (double)Image_Size), 0.0, image[dire + imageNumber], TRUE);

}

/// <summary>
/// ���W���X�V����
/// </summary>
/// <param name="argMoveDire">�ړ��������</param>
void Player::Move(int argMoveDire){

	int vy[4] = { Block_Size,0,0,-Block_Size };		//y�ړ���
	int vx[4] = { 0,Block_Size,-Block_Size,0 };		//x�ړ���

	pos.SetPosition(pos.GetX() + vx[argMoveDire], pos.GetY() + vy[argMoveDire]);

}

/// <summary>
/// �������X�V����
/// </summary>
/// <param name="argMoveDire">�ړ��������</param>
void Player::Direction(int argMoveDire){

	dire = argMoveDire * Image_Width;

}

/// <summary>
/// ���W���擾����
/// </summary>
/// <returns>�v���C���[�̍��W</returns>
Position<int> Player::GetPosition(){

	return pos;
}

/// <summary>
/// �������擾����
/// </summary>
/// <returns>�v���C���[�̌���</returns>
int Player::GetDirection(){

	return dire;
}