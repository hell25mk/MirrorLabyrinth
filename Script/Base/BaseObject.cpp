#include "BaseObject.h"

const int BaseObject::Block_Size = 32;

/// <summary>
/// �����o������������
/// </summary>
BaseObject::BaseObject() : pos(){
}

/// <summary>
/// �����o������������
/// </summary>
/// <param name="argPos">���W</param>
BaseObject::BaseObject(Position<int> const argPos){

	//���W�̊i�[
	pos = argPos;

}

/// <summary>
/// ���������m�ۂ��Ă����ꍇ�͉������
/// </summary>
BaseObject::~BaseObject(){
}
