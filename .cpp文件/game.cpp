
/*Ԥ����ָ���ȡͷ�ļ�*/
#include <iostream>
#include "acllib.h"
#include"Playarea.h"
#include"GifArea.h"

using namespace std;

/*�궨����*/
//��Ϸ������
#define WinWidth 1300
//��Ϸ����߶�
#define WinHeight 700
//Gif��������x
#define GifX 600
//Gif��������y
#define GifY 0
//Gif������
#define GifWidth 700
//Gif����߶�
#define GifHeight 700
//GIF��ͼƬ��
#define Num 35
//Play��������x
#define PlayX 0
//Play��������y
#define PlayY 0
//Play������
#define PlayWidth 600
//Play����߶�
#define PlayHeight 700

/*ȫ�ֱ�������*/
ACL_Sound winsound;
ACL_Image backimg;
//����ʱ֡��
int ZhenCountdown[2] = {25,25};
//����ʱÿ֡���ʱ��
int DtCountdown[2] = { 200,200 };
//����ʱ�Ƿ����
bool countdown_end = FALSE;
//GIF������GIF֡��
int Zhen[Num + 1];
//GIF������GIFÿ֡���ʱ��
int Dt[Num + 1];
//���岢��ʼ��GifArea�����countdown
GifArea countdown(0, 0, 600, 600,1, ZhenCountdown, DtCountdown, 0);
//���岢��ʼ��GifArea�����gifarea
GifArea gifarea(GifX, GifY, GifWidth, GifHeight,Num, Zhen, Dt, 1);
//���岢��ʼ��Playarea�����playarea
Playarea playarea(PlayX, PlayY, PlayWidth, PlayHeight);

/*��������*/
void loadzhen(int* zhen);
void loaddt(int* dt);
void timerEvent(int id);
void keyEvent(int key, int event);

/*������*/
int Setup()
{
	//srand�����������
	srand((unsigned)time(NULL));
	//���ظ���GIF֡��
	loadzhen(Zhen);
	//����ÿ֡���ʱ��
	loaddt(Dt);
	//���ɴ���
	initWindow("DJmini", 0, 0, WinWidth, WinHeight);
	//��������
	loadSound("FirstKiss.mp3", &winsound);//���ر�������
	playSound(winsound, 0);//���ű����������ڶ�����������ʱ�����ֽ�ѭ�����š�����ֻ����һ��
	//ע�ᶨʱ���ж�
	registerTimerEvent(timerEvent);
	//ע������ж�
	registerKeyboardEvent(keyEvent);
	//������ʱ��
	startTimer(0, gifarea.dt[gifarea.gifindex]);
	startTimer(1, 7500);
	startTimer(2, countdown.dt[countdown.gifindex]);
	startTimer(3, 5000);
	startTimer(4, 800);//��������
	startTimer(5, 2480);//����+1
	startTimer(6, 10);//��������
	startTimer(7, 262500);//����
	return 0;
}
//���ظ���GIF֡��
void loadzhen(int* zhen)
{
	zhen[1] = 135;zhen[2] = 9;zhen[3] = 24;zhen[4] = 240;zhen[5] = 18;
	zhen[6] = 5;zhen[7] = 19;zhen[8] = 54;zhen[9] = 15;zhen[10] = 20;
    zhen[11] = 48;zhen[12] = 82;zhen[13] = 36;zhen[14] = 7;zhen[15] = 26;
	zhen[16] = 96;zhen[17] = 61;zhen[18] = 100;zhen[19] = 7;zhen[20] = 32;
	zhen[21] = 33;zhen[22] = 28;zhen[23] = 30;zhen[24] = 20;zhen[25] = 160;
	zhen[26] = 94;zhen[27] = 47;zhen[28] = 24;zhen[29] = 120;zhen[30] = 72;
	zhen[31] = 52;zhen[32] = 24;zhen[33] = 180;zhen[34] = 32;zhen[35] = 37;
}
//����ÿ֡���ʱ��
void loaddt(int* dt)
{
	dt[1] = 40;dt[2] = 20;dt[3] = 30;dt[4] = 30;dt[5] = 30;
	dt[6] = 20;dt[7] = 80;dt[8] = 10;dt[9] = 30;dt[10] = 30;
	dt[11] = 20;dt[12] = 10;dt[13] = 30;dt[14] = 10;dt[15] = 30;
	dt[16] = 50;dt[17] = 30;dt[18] = 30;dt[19] = 10;dt[20] = 30;
	dt[21] = 10;dt[22] = 30;dt[23] = 20;dt[24] = 10;dt[25] = 30;
	dt[26] = 30;dt[27] = 40;dt[28] = 30;dt[29] = 30;dt[30] = 30;
	dt[31] = 10;dt[32] = 30;dt[33] = 30;dt[34] = 30;dt[35] = 40;
}
void timerEvent(int id) 
{
	switch (id)
	{
	case 0:
		beginPaint();
		gifarea.drawArea();
		endPaint();
		break;
	case 1:
		gifarea.next();
		break;
	case 2:
		beginPaint();
		countdown.drawArea();
		endPaint();
		break;
	case 3:
		countdown.next();
		countdown_end = TRUE;
		break;
	case 4:
		if (countdown_end == TRUE && playarea.percent < 99)
		{
			int shu= rand() % 5;
			switch (shu)
			{
			case 0:

				break;
			case 1:
			case 2:
			case 3:
                playarea.createData();
				break;
			case 4:
				playarea.createData();
				playarea.createData();
				break;
			}
			beginPaint();
			playarea.drawArea();
			endPaint();
		}
		break;
	case 5:
		if (countdown_end == TRUE && playarea.percent < 100)
		{
			playarea.percent++;
		}
		break;
	case 6:
		if (countdown_end == TRUE)
		{
			playarea.move();
			beginPaint();
			playarea.drawArea();
			endPaint();
		}
		break;
	case 7:
		ACL_Sound givesc;
		loadSound("����.wav", &givesc);//�����û�����
		playSound(givesc, 0);//�����û��������ڶ�����������ʱ�����ֽ�ѭ�����š�����ֻ����һ��
		beginPaint();
		//����ǰ��Ϊ��ɫ
		setTextColor(RGB(139, 78, 85));
		setTextBkColor(RGB(26, 18, 33));
		char txt3[15];
		int level=playarea.rightrate / 10;
		switch (level)
		{
		case 10:
		case 9:
			sprintf_s(txt3, "Perfect!");
			break;
		case 8:
			sprintf_s(txt3, "Excellent!");
			break;
		case 7:
			sprintf_s(txt3, "Nice job!");
			break;
		case 6:
			sprintf_s(txt3, "Not bad!");
			break;
		default:
			sprintf_s(txt3, "Cheer up!");
			break;
		}
		setTextSize(50);
		paintText(860, 50, txt3);
		endPaint();
		break;//end switch
	}
}

void keyEvent(int key, int event)
{
	if (event != KEY_DOWN)return;
	playarea.judge(key);
}



