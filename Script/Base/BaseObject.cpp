#include "BaseObject.h"

const int BaseObject::Block_Size = 32;

/// <summary>
/// �R���X�g���N�^
/// </summary>
BaseObject::BaseObject() : pos(){
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="argPos">���W</param>
BaseObject::BaseObject(Position<int> const argPos){

	//���W�̊i�[
	pos = argPos;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
BaseObject::~BaseObject(){
}
