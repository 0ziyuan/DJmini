#pragma once

#include "acllib.h"

class Note
{
public:
    int nTopRect=0,nBottomRect=25;
	int nLeftRect, nRightRect;
	int style;
protected:
	int nWidth=10, nHeight=10;
public:
	void initNote();  //��ʼ��������Ϣ
	void movedown();  //��������
	void drawNote();  //��������
};