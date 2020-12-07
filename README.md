# DJmini

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201120213405.png)

音乐游戏，大二C++结课作业，依赖于acllib库实现，仅支持Windows环境下运行。

#### 项目描述

DJmini是一款音乐游戏，提供了流畅的节奏游戏体验，目前仅包含一个曲目及相应的音乐背景。创作灵感来源于室友最近在玩的一款音乐游戏— [DJMAX RESPECT V](https://store.steampowered.com/app/960170/DJMAX_RESPECT_V/)，游戏名“DJmini”正是为了致敬该游戏，而“mini”意在表明这只是一个卑微学习者的练手项目，十分简陋😅

## 软件说明

###   游戏使用说明

#### 下载及运行

1. 访问https://gitee.com/wanli-0ziyuan/DJmini-release，下载压缩包：

   ![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207140113.png)

2. 下载完成并解压后，双击DJmini文件夹中的“DJmini.exe”文件运行游戏：

   ![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207141028.png)

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207141048.png)

#### 玩法说明

##### 音轨

即下落轨道数，共四个。对应键位有左手区和右手区之分，字母键均为大写，故需将键盘大写锁定：

左手区：A﹑S﹑D﹑F		

右手区：J﹑K﹑L﹑; 

##### 音符（Note）

有样式之分，蓝色音符的音轨对应左手区键位，粉色音符的音轨对应右手区键位。击中时附有音效，随即消失。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207142827.png)

##### 判定

1. 敲击音符所在音轨对应键位击打。蓝色音符的音轨对应左手区键位，粉色音符的音轨对应右手区键位。
2. 音符刚到达判定线，到其完全从窗口底部消失的这段时间，击打相应键位，视为击中。其他时刻（如音符还未到达判定线﹑音符已消失等）击打，视为击打无效。

##### 计分与评级

###### 计分

不显示具体得分，只实时显示命中率🙃。

命中率=击中音符数/已生成音符数*100%

###### 评级

| 命中率 |  小于60%  | 60%~70%  |  70%~80%  |  80%~90%   | 90%~100% |
| :----: | :-------: | :------: | :-------: | :--------: | :------: |
|  评级  | Cheer up! | Not bad! | Nice job! | Excellent! | Perfect! |

##### 完整过程

1. 5秒倒计时，倒计时结束，游戏开始；

   ![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207142402.png)

2. 音符下落，玩家按键击打。同时游戏区右上角实时显示命中率和游戏进度；

3. 游戏进度到达100%，游戏结束。片刻后在动画播放区显示评级。

   ![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207150329.png)

### 源码编译说明

#### 示例环境

Windows10家庭版中文版，系统类型为64位，选用Visual Studio 2019 Community 作为开发环境。

#### 所需文件下载

https://gitee.com/wanli-0ziyuan/DJmini-resourse

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207151526.png)

#### 创建项目

##### Step1

打开Visual Studio 2019，点击创建新项目。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207154836.png)

##### Step2

选择windows桌面向导，然后选择下一步。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155000.png)

##### Step3

填写名称，选择项目创建位置。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155215.png)

##### Step4

###### 应用程序类型

桌面应用程序（.exe）

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155404.png)

###### 其他选项

空项目，然后创建。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155731.png)

#### 拷贝文件

##### Step1

根据创建项目的位置找到项目文件夹

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155745.png)

##### Step2

将下载的压缩包解压，然后把.cpp文件,.h文件和资源文件三个文件夹下的所有文件拷贝到刚才的项目文件夹中。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155915.png)

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207160411.png)

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207160428.png)

#### 添加文件

##### 头文件

右键单击头文件，选择“添加”->“现有项”

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207160513.png)

选中项目文件夹下所有的.h文件，然后点击添加。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207160749.png)

##### 源文件和资源文件

添加步骤同头文件，源文件为所有的.cpp文件，资源文件为所有Jpg文件以及两个wav文件，一个Mp3文件。

#### 编译运行

1.选择“开始执行（不调试）”

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207162520.jpg)

2.在项目文件夹下找到“Debug”文件夹，进入。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207162307.png)

3.在“Debug”文件夹下找到生成的.exe文件，拷贝到最初下载解压得到的文件夹中的“资源文件”下，双击.exe文件即可运行游戏。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207162319.png)

## 系统设计

### 概要

#### 窗体

#### 定时器

#### 键盘

### Note类

#### 成员

##### 变量

##### 函数

#### 类间关系

### Area类

#### 成员

##### 变量

##### 函数

#### 类间关系

### GifArea类

#### 成员

##### 变量

##### 函数

#### 类间关系

### Playarea类

#### 成员

##### 变量

##### 函数

#### 类间关系

## 程序实现

## 测试报告

### 测试方法

### 测试过程

### 测试结果

未完待续。。。