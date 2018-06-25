#pragma once

typedef enum{
	Dire_Down,
	Dire_Right,
	Dire_Left,
	Dire_Up,

	Dire_Nore,
}e_Direction;

typedef enum{
	Laby_Road,
	Laby_Wall,
	Laby_Stairs,
	Laby_Nore1,
	Laby_Nore2,
	Laby_CloseDoor,
	Laby_OpenDoor,
	Laby_RubyKey,
	Laby_DiaKey,
	Laby_Nore3,
	Laby_Block,
	Laby_Nore4 = 14,
}e_BlockKind;

typedef enum{
	State_ModeSelect,
	State_GameStart,
	State_GamePlay,
	State_StageClear,
	State_GameClear,
	State_GameOver,
	State_Result,

	State_Nore,
}e_GameState;

enum e_GameLevel{
	Level_Easy,
	Level_Normal,
	Level_Hard,
	Level_Expert,

	Level_Num,
};