#include "Playarea.h"
#include<stdio.h>

Playarea::Playarea(int x, int y, int width, int height)
    :Area(x, y, width, height)
{}

void Playarea::createData()
{
	note[nowNum] = new Note;
	note[nowNum]->initNote();
	nowNum++;
}
void Playarea::move()
{
	for (int i = 0; i < nowNum; ++i)
		if (note[i])
		{
			note[i]->movedown();
			if (note[i]->nTopRect>=700)
			{
				delete(note[i]);
				note[i] = NULL;
			}
		}
}
void Playarea::judge(int key)
{
	ACL_Sound hit;
	loadSound("�û�.wav", &hit);//�����û�����
	switch (key)
	{
	case 'A':
		for (int i = 0; i < nowNum; ++i)
			if (note[i]&& note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 0&& note[i]->style == 0)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//�����û��������ڶ�����������ʱ�����ֽ�ѭ�����š�����ֻ����һ��
				}
			}
		break;
	case 'S':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 150 && note[i]->style == 0)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//�����û��������ڶ�����������ʱ�����ֽ�ѭ�����š�����ֻ����һ��
				}
			}
		break;
	case 'D':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 300 && note[i]->style == 0)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//�����û��������ڶ�����������ʱ�����ֽ�ѭ�����š�����ֻ����һ��
				}
			}
		break;
	case 'F':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 450 && note[i]->style == 0)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//�����û��������ڶ�����������ʱ�����ֽ�ѭ�����š�����ֻ����һ��
				}
			}
		break;
	case 'J':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 0 && note[i]->style == 1)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//�����û��������ڶ�����������ʱ�����ֽ�ѭ�����š�����ֻ����һ��
				}
			}
		break;
	case 'K':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 150 && note[i]->style == 1)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//�����û��������ڶ�����������ʱ�����ֽ�ѭ�����š�����ֻ����һ��
				}
			}
		break;
	case 'L':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 300 && note[i]->style == 1)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//�����û��������ڶ�����������ʱ�����ֽ�ѭ�����š�����ֻ����һ��
				}
			}
		break;
	case VK_OEM_1:
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 450 && note[i]->style == 1)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//�����û��������ڶ�����������ʱ�����ֽ�ѭ�����š�����ֻ����һ��
				}
			}
		break;
	}
}
void Playarea::drawArea()
{
	loadImage("ë��������.jpg", &img);
	putImageScale(&img, x, y, width, height);
	//���廭�ʻ�ˢΪ����ɫ
	setPenColor(RGB(255, 218, 185));
	setBrushColor(RGB(255, 218, 185));
	line(0, 600, 600, 600);
	for (int i = 0; i < nowNum; ++i)
	{
		if (note[i])
		{
			note[i]->drawNote();
		}
	}
	//����ǰ��Ϊ��ɫ
	setTextBkColor(RGB(238, 229, 222));
	setTextColor(RGB(255, 127, 0));
	setTextFont("΢���ź�");
	char txt1[16];
	rightrate = score / (nowNum+0.00001)*100;
	sprintf_s(txt1,"������:%0.2f%%", rightrate);
	setTextSize(25);
	paintText(450, 20, txt1);
	//����ǰ��Ϊ��ɫ
	setTextColor(RGB(139, 87, 66));
	char txt2[15];
	sprintf_s(txt2, "����:%d%%", percent);
	setTextSize(25);
	paintText(450, 50, txt2);
}