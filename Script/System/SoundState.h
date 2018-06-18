#pragma once

class C_SoundState{

protected:

public:
	C_SoundState();
	~C_SoundState();

	virtual void PlayBGM();
	virtual void StopBGM();

};

class C_Play : public C_SoundState{

	

};

class C_Stop : public  C_SoundState{



};

class C_FadeIn : public C_SoundState{



};

class C_FadeOut : public C_SoundState{



};