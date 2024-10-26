// SqaureConfig.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>
#include <fstream>

#include "GetCPUInfo.h"
#include "GetSteamLib.h"
#include "ConfigCreator.h"
using namespace std;

int CPU = -1;

void GetCPU()
{
        string vendor = getCPUVendor();

    if (vendor == "GenuineIntel") {
        CPU = 1;
    }
    else if (vendor == "AuthenticAMD") {
        CPU = 2;
    }
    else {
        CPU = -1;
    }
}




int main()
{
	SetConsoleTitle(L"广场配置1.0安装器");
    cout << "欢迎使用广场配置1.0安装器，本程序承诺使用合法指令，拒绝作弊\n\n正在检测电脑信息";
    for (int i = 0; i < 3; i++)
    {
        system("color 9f");
        Sleep(800);
        cout << ".";
    }
    system("cls");
    system("color 9f");
    GetCPU();
    if (CPU == 1)
    {
        system("color ce");
        cout << "你使用的CPU供应商为：英特尔，已强制开启锁帧模式\n";
    }
    else if (CPU == 2)
    {
        system("color 2f");
        cout << "你使用的CPU供应商为：AMD，已强制开启正常模式\n";
    }
    else {
        cout << "杂牌CPU，你不配用CFG";
        Sleep(1000);
        exit(0);
        
    }

    string gameName = "Counter-Strike Global Offensive";
    string gamePath = findGameInstallPath(gameName);

    if (!gamePath.empty()) {
        cout << gameName << " 安装路径: " << gamePath << endl;
        cout << "配置文件路径: " << gamePath + "\\game\\csgo\\cfg" << endl;

        string configFilePath = gamePath + "\\game\\csgo\\cfg\\Sqaure.cfg";
        createConfigFileA(configFilePath);
        
        system("cls");
        cout << "CFG已创建，是否添加到autoexec（推荐），如果需要请输入Y，如不需要请输入N，如想要复原请输入R:";
        string autoexec;
        cin >> autoexec;
        ofstream autoexecfiles("\\game\\csgo\\cfg\\autoexec.cfg");
        if (autoexec == "Y" || autoexec == "y")
        {


           
            autoexecfiles << "alias +pwaswitchknife \"slot3\"\n";
            autoexecfiles << "alias -pwaswitchknife \"lastinv\"\n";
            autoexecfiles << "alias \"refundall\" \"sellback 0; sellback 1; sellback 2; sellback 3; sellback 4; sellback 5; sellback 6; sellback 8; sellback 9; sellback 10; sellback 11; sellback 12; sellback 13; sellback 14; sellback 15; sellback 16; sellback 17; sellback 18; sellback 26; sellback 26; sellback 27; sellback 28; sellback 29; sellback 30; sellback 32; sellback 33; sellback 34; sellback 35; play ui\\panorama\\itemtile_click_02.vsnd_c\"\n";
            autoexecfiles << "\n+exec Sqaure\n";
        }
        else if (autoexec == "R" || autoexec == "r")
        {
            autoexecfiles << "alias +pwaswitchknife \"slot3\"\n";
            autoexecfiles << "alias -pwaswitchknife \"lastinv\"\n";
            autoexecfiles << "alias \"refundall\" \"sellback 0; sellback 1; sellback 2; sellback 3; sellback 4; sellback 5; sellback 6; sellback 8; sellback 9; sellback 10; sellback 11; sellback 12; sellback 13; sellback 14; sellback 15; sellback 16; sellback 17; sellback 18; sellback 26; sellback 26; sellback 27; sellback 28; sellback 29; sellback 30; sellback 32; sellback 33; sellback 34; sellback 35; play ui\\panorama\\itemtile_click_02.vsnd_c\"\n";
            
        }
        autoexecfiles.close();
    }
    else {
        cout << "未找到 " << gameName << " 的安装路径。" << endl;
    }

    cout << "成功了！现在你可以添加启动项 +exec Sqaure 进行使用，如果你没有添加到autoexec的话\n程序将在10秒后自动关闭";
    Sleep(10000);
    return 0;

}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
