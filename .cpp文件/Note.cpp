#include "Note.h"
#include <time.h>

void Note::initNote()
{
	//rand���������
	style = rand() % 2;
	nLeftRect =(rand() % 4)*150;
	nRightRect = nLeftRect + 150;
}
void Note::movedown()
{
	nTopRect = nTopRect + 5;
	nBottomRect = nBottomRect + 5;
}
void Note::drawNote()
{
	if (style==0)
	{
		//���廭�ʻ�ˢΪ��ɫ
		setPenColor(RGB(172, 224, 249));
		setBrushColor(RGB(172, 224, 249));
	}
	else
	{
		//���廭�ʻ�ˢΪ��ɫ
		setPenColor(RGB(230, 230, 250));
		setBrushColor(RGB(230, 230, 250));
	}
	roundrect(nLeftRect,nTopRect,nRightRect,nBottomRect,nWidth,nHeight);
}