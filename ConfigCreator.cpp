#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

#include "GetCPUInfo.h"
using namespace std;
void createConfigFileA(const string& path) {

    string bindCrossHairSwitch;
    string bunnyhop;
    string faststop;
    string faststopchanger;
    string jm;
    string autolookweapon;
    string shootcanceldef;
    string desubtick;
    string jumpthrow;
    string wjumpthrow;
    string duckjump;

    ofstream configFile(path);
   /*
    cout << "\n请输入跳投绑定键，留空为不启用：";
    getline(cin, jumpthrow);
    configFile << "alias +JT \"echo \"SqaureUtiles/jumpthrow\" | exec; \"\n";
    configFile << "bind " << jumpthrow << " +JT\n";

    cout << "\n请输入W+跳投绑定键，留空为不启用：";
    getline(cin, wjumpthrow);
    configFile << "alias +WJT \"echo \"SqaureUtiles/wjumpthrow\" | exec; \"\n";
    configFile << "alias -WJT \"echo \"SqaureUtiles/forward\" | exec; \"\n";
    configFile << "bind " << wjumpthrow << " +WJT\n";

    cout << "\n请输入大跳绑定键，留空为不启用：";
    getline(cin, duckjump);
    configFile << "alias \"+ag3\" \"echo SqaureUtiles/+duckjump | exec;\"\n";
    configFile << "alias \"-ag3\" \"echo SqaureUtiles/-duckjump | exec;\"\n";
    configFile << "bind " << duckjump << " +ag3\n\n";
   
   */
    cout << "\n\n请输入绑定跟随后坐力的按键（推荐CapsLock）：";
    getline(cin, bindCrossHairSwitch);

    cout << "\n请输入滚轮绑定模式（大写字母）\nA 全滚轮跳\nB 上滚轮跳下滚轮切枪\nC 下滚轮跳上滚轮切枪\nD 切枪模式\n\n你选择：";
    getline(cin, bunnyhop);

    if (configFile.is_open()) {
        string vendor = getCPUVendor();

        if (vendor == "GenuineIntel") {
             configFile << "fps_max 159\n";
        }
       

    //准星部分
        configFile << "alias active \"cl_crosshaircolor_r 255; cl_crosshaircolor_g 0; cl_crosshaircolor_b 0; cl_crosshair_recoil true\"\n";
        configFile << "alias passive \"cl_crosshaircolor_r 0; cl_crosshaircolor_g 255; cl_crosshaircolor_b 0; cl_crosshair_recoil false\"\n";
        configFile << "alias xhair \"xhair1\"\n";
        configFile << "alias xhair1 \"active; alias xhair xhair2\"\n";
        configFile << "alias xhair2 \"passive; alias xhair xhair1\"\n";
        configFile << "bind " << bindCrossHairSwitch << " xhair\n";

        //滚轮跳
        if (bunnyhop == "A"||bunnyhop == "a")
        {
            configFile << "bind MWHEELDOWN \"+jump\"\n";
             configFile << "bind MWHEELUP \"+jump\"\n";
        }
        else if (bunnyhop == "B" || bunnyhop=="b")
        {
            configFile << "bind MWHEELDOWN \"invnext\"\n";
            configFile << "bind MWHEELUP \"+jump\"\n";
        }
        else if (bunnyhop == "C"||bunnyhop=="c")
        {
            configFile << "bind MWHEELDOWN \"+jump\"\n";
            configFile << "bind MWHEELUP \"invprev\"\n";
        }
        else if (bunnyhop =="D"||bunnyhop=="d")
        {
            configFile << "bind MWHEELDOWN \"invnext\"\n";
            configFile << "bind MWHEELUP \"invprev\"\n";
        }
       // else if (bunnyhop == "E" || bunnyhop == "e")
     //   {
     //       configFile << "bind MWHEELDOWN \"+execjump\"\n";
      //      configFile << "bind MWHEELUP \"+execjump\"\n";
      //      configFile << "alias +execjump\"exec SqaureUtiles/desubtick\"\n";
      //      configFile << "alias -execjump \"-jump\"\n\n";
    //    }
        configFile << "\n";
        
        //急停部分
        cout << "\n\n是否启用急停CONFIG，如需使用请输入Y，否则输入N：";
        getline(cin, faststop);
        if (faststop == "Y" || faststop == "y")
        {
            configFile << "joy_response_move 1\n";
            configFile << "joy_forward_sensitivity 1\n";
            configFile << "joy_side_sensitivity 1\n";
            configFile << "forward -31200 0 0\n";
            configFile << "back -31200 0 0\n";
            configFile << "left -31200 0 0\n";
            configFile << "right -31200 0 0\n";
            configFile << "forwardback 0 0 0\n";
            configFile << "rightleft 0 0 0\n";
            configFile << "bind w +w\n";
            configFile << "bind a +a\n";
            configFile << "bind s +s\n";
            configFile << "bind d +d\n";
            configFile << "alias +w \"forwardback 1 0 0;joy_forward_sensitivity 1;joy_side_sensitivity 0;alias +s ws;alias +a wa;alias +d wd;alias -w w2;alias -s s2\"\n";
            configFile << "alias w1 \"forwardback 1 0 0;joy_forward_sensitivity 1;joy_side_sensitivity 0;alias +s ws;alias +a wa;alias +d wd;alias -w w2;alias -s s2\"\n";
            configFile << "alias +a \"rightleft -1 0 0;joy_side_sensitivity 1;joy_forward_sensitivity 0;alias +d ad;alias +w aw;alias +s as;alias -a a2;alias -d d2\"\n";
            configFile << "alias a1 \"rightleft -1 0 0;joy_side_sensitivity 1;joy_forward_sensitivity 0;alias +d ad;alias +w aw;alias +s as;alias -a a2;alias -d d2\"\n";
            configFile << "alias +s \"forwardback -1 0 0;joy_forward_sensitivity 1;joy_side_sensitivity 0;alias +w sw;alias +a sa;alias +d sd;alias -s s2;alias -w w2\"\n";
            configFile << "alias s1 \"forwardback -1 0 0;joy_forward_sensitivity 1;joy_side_sensitivity 0;alias +w sw;alias +a sa;alias +d sd;alias -s s2;alias -w w2\"\n";
            configFile << "alias +d \"rightleft 1 0 0;joy_side_sensitivity 1;joy_forward_sensitivity 0;alias +a da;alias +w dw;alias +s ds;alias -d d2;alias -a a2\"\n";
            configFile << "alias d1 \"rightleft 1 0 0;joy_side_sensitivity 1;joy_forward_sensitivity 0;alias +a da;alias +w dw;alias +s ds;alias -d d2;alias -a a2\"\n";
            configFile << "alias -w \"forwardback -0.000001 0 0;joy_side_sensitivity 0;alias +s s1;alias +a a1;alias +d d1;alias +w w1\"\n";
            configFile << "alias w2 \"forwardback -0.000001 0 0;joy_side_sensitivity 0;alias +s s1;alias +a a1;alias +d d1;alias +w w1\"\n";
            configFile << "alias -a \"rightleft 0.000001 0 0;joy_forward_sensitivity 0;alias +d d1;alias +w w1;alias +s s1;alias +a a1\"\n";
            configFile << "alias a2 \"rightleft 0.000001 0 0;joy_forward_sensitivity 0;alias +d d1;alias +w w1;alias +s s1;alias +a a1\"\n";
            configFile << "alias -s \"forwardback 0.000001 0 0;joy_side_sensitivity 0;alias +w w1;alias +a a1;alias +d d1;alias +s s1\"\n";
            configFile << "alias s2 \"forwardback 0.000001 0 0;joy_side_sensitivity 0;alias +w w1;alias +a a1;alias +d d1;alias +s s1\"\n";
            configFile << "alias -d \"rightleft -0.000001 0 0;joy_forward_sensitivity 0;alias +a a1;alias +w w1;alias +s s1;alias +d d1\"\n";
            configFile << "alias d2 \"rightleft -0.000001 0 0;joy_forward_sensitivity 0;alias +a a1;alias +w w1;alias +s s1;alias +d d1\"\n";
            configFile << "alias wasdall \"joy_forward_sensitivity 0;joy_side_sensitivity 0;alias -w rs;alias -a fd;alias -d fa;alias -s rw\"\n";
            configFile << "alias ws \"forwardback -0.000001 0 0;joy_side_sensitivity 0;alias -s w1;alias -w s1;alias +a fa;alias +d fd\"\n";
            configFile << "alias sw \"forwardback 0.000001 0 0;joy_side_sensitivity 0;alias -w s1;alias -s w1;alias +a fa;alias +d fd\"\n";
            configFile << "alias fa \"rightleft -1 0 0;joy_side_sensitivity 1;alias -a fa2;alias +d wasdall;alias -w as;alias -s aw\"\n";
            configFile << "alias fd \"rightleft 1 0 0;joy_side_sensitivity 1;alias -d fd2;alias +a wasdall;alias -w ds;alias -s dw\"\n";
            configFile << "alias fa2 \"rightleft 0.000001 0 0;joy_forward_sensitivity 0;alias -s w1;alias -w s1;alias +a fa;alias +d fd\"\n";
            configFile << "alias fd2 \"rightleft -0.000001 0 0;joy_forward_sensitivity 0;alias -s w1;alias -w s1;alias +a fa;alias +d fd\"\n";
            configFile << "alias ad \"rightleft 0.000001 0 0;joy_forward_sensitivity 0;alias -a d1;alias -d a1;alias +w rw;alias +s rs\"\n";
            configFile << "alias da \"rightleft -0.000001 0 0;joy_forward_sensitivity 0;alias -d a1;alias -a d1;alias +w rw;alias +s rs\"\n";
            configFile << "alias rw \"forwardback 1 0 0;joy_forward_sensitivity 1;alias -a wd;alias -d wa;alias -w rw2;alias +s wasdall\"\n";
            configFile << "alias rs \"forwardback -1 0 0;joy_forward_sensitivity 1;alias -a sd;alias -d sa;alias -s rs2;alias +w wasdall\"\n";
            configFile << "alias rw2 \"forwardback -0.000001 0 0;joy_side_sensitivity 0;alias -a d1;alias -d a1;alias +w rw;alias +s rs\"\n";
            configFile << "alias rs2 \"forwardback 0.000001 0 0;joy_side_sensitivity 0;alias -a d1;alias -d a1;alias +w rw;alias +s rs\"\n";
            configFile << "alias wa \"rightleft -1 0 0;joy_side_sensitivity 1;alias -a waa;alias -w waw;alias +d wad;alias +s was\"\n";
            configFile << "alias aw \"forwardback 1 0 0;joy_forward_sensitivity 1;alias -a waa;alias -w waw;alias +d wad;alias +s was\"\n";
            configFile << "alias was \"forwardback -0.000001 0 0;alias -s aw;alias -w as;alias +d wasdall;alias -a fa2\"\n";
            configFile << "alias wad \"rightleft 0.000001 0 0;alias -w rw2;alias +s wasdall;alias -d wa;alias -a wd\"\n";
            configFile << "alias wd \"rightleft 1 0 0;joy_side_sensitivity 1;alias -d wdd;alias -w wdw;alias +a wda;alias +s wds\"\n";
            configFile << "alias dw \"forwardback 1 0 0;joy_forward_sensitivity 1;alias -d wdd;alias -w wdw;alias +a wda;alias +s wds\"\n";
            configFile << "alias wda \"rightleft 0.000001 0 0;alias -a wd;alias -d wa;alias -w rw2;alias +s wasdall\"\n";
            configFile << "alias wds \"forwardback -0.000001 0 0;alias -w ds;alias -d fd2;alias -s dw;alias +a wasdall\"\n";
            configFile << "alias sa \"rightleft -1 0 0;joy_side_sensitivity 1;alias -a saa;alias -s sas;alias +d sad;alias +w saw\"\n";
            configFile << "alias as \"forwardback -1 0 0;joy_forward_sensitivity 1;alias -a saa;alias -s sas;alias +d sad;alias +w saw\"\n";
            configFile << "alias sad \"rightleft 0.000001 0 0;alias -a sd;alias -d sa;alias -s rs2;alias +w wasdall\"\n";
            configFile << "alias saw \"forwardback 0.000001 0 0;alias -w as;alias -a fa2;alias -s aw;alias +d wasdall\"\n";
            configFile << "alias sd \"rightleft 1 0 0;joy_side_sensitivity 1;alias -d sdd;alias -s sds;alias +a sda;alias +w sdw\"\n";
            configFile << "alias ds \"forwardback -1 0 0;joy_forward_sensitivity 1;alias -s sds;alias -d sdd;alias +a sda;alias +w sdw\"\n";
            configFile << "alias sda \"rightleft 0.000001 0 0;alias -a sd;alias -d sa;alias +w wasdall;alias -s rs2\"\n";
            configFile << "alias sdw \"forwardback 0.000001 0 0;alias -w sd;alias -d fd2;alias -s dw;alias +a wasdall\"\n";
            configFile << "alias waa \"rightleft 0.000001 0 0;alias +s ws;alias +a wa;alias +d wd;alias -w w2\"\n";
            configFile << "alias waw \"forwardback -0.000001 0 0;alias +d ad;alias +w aw;alias +s as;alias -a a2\"\n";
            configFile << "alias saa \"rightleft 0.000001 0 0;alias +w sw;alias +a sa;alias +d sd;alias -s s2\"\n";
            configFile << "alias sas \"forwardback 0.000001 0 0;alias +d ad;alias +w aw;alias +s as;alias -a a2\"\n";
            configFile << "alias wdd \"rightleft -0.000001 0 0;alias +s ws;alias +a wa;alias +d wd;alias -w w2\"\n";
            configFile << "alias wdw \"forwardback -0.000001 0 0;alias +a da;alias +w dw;alias +s ds;alias -d d2\"\n";
            configFile << "alias sdd \"rightleft -0.000001 0 0;alias +w sw;alias +a sa;alias +d sd;alias -s s2\"\n";
            configFile << "alias sds \"forwardback 0.000001 0 0;alias +a da;alias +w dw;alias +s ds;alias -d d2\"\n\n";
            configFile << "alias jton \"bind w +w; bind a +a; bind s +s; bind d +d\"\n";
            configFile << "alias jtoff \"bind w +forward; bind s +back; bind d +right; bind a +left\"\n";
            configFile << "alias jt1 \"jt2;\"\n";
            configFile << "alias jt2 \"jton; alias jt1 jt3\"\n";
            configFile << "alias jt3 \"jtoff; alias jt1 jt2\"\n";
            cout << "\n检测到你开启急停，请绑定一个临时急停开关键：";
            getline(cin, faststopchanger);
            configFile << "bind " << faststopchanger << " jt1\n\n";
        }
        else
        {
            configFile << "bind w +forward\n";
            configFile << "bind s +back\n";
            configFile << "bind d +right\n";
            configFile << "bind a +left\n\n";
        }
        configFile << "alias jmon \"viewmodel_fov 68; viewmodel_offset_x -5; viewmodel_offset_y 5; viewmodel_offset_z 5\"\n";
        configFile << "alias jmoff \"viewmodel_fov 68; viewmodel_offset_x 2.5; viewmodel_offset_y 2; viewmodel_offset_z -2\"\n";
        configFile << "alias jm1 \"jm2;\"\n";
        configFile << "alias jm2 \"jmon; alias jm1 jm3\"\n";
        configFile << "alias jm3 \"jmoff; alias jm1 jm2\"\n";
        cout << "\n请绑定机瞄按键（默认j）：";
        getline(cin, jm);
        if (jm.empty()) {
            jm = "j";
        }
        configFile << "bind " << jm << " jm1\n\n";
        cout << "\n\n";
        cout << "是否启用切刀自动检视，如需使用请输入Y，否则请输入N：";
        getline(cin, autolookweapon);
        if (autolookweapon == "Y" || autolookweapon == "y")
        {
            configFile << "bind \"3\" \"slot3; +lookatweapon; -lookatweapon\"\n";
        }
        else {
            configFile << "bind \"3\" slot3\n";
        }

        configFile.close();
        cout << "已创建配置文件: " << path << endl;
    }
    else {
        cout << "无法创建配置文件: " << path << endl;
    }
}