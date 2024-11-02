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
    cout << "\n��������Ͷ�󶨼�������Ϊ�����ã�";
    getline(cin, jumpthrow);
    configFile << "alias +JT \"echo \"SqaureUtiles/jumpthrow\" | exec; \"\n";
    configFile << "bind " << jumpthrow << " +JT\n";

    cout << "\n������W+��Ͷ�󶨼�������Ϊ�����ã�";
    getline(cin, wjumpthrow);
    configFile << "alias +WJT \"echo \"SqaureUtiles/wjumpthrow\" | exec; \"\n";
    configFile << "alias -WJT \"echo \"SqaureUtiles/forward\" | exec; \"\n";
    configFile << "bind " << wjumpthrow << " +WJT\n";

    cout << "\n����������󶨼�������Ϊ�����ã�";
    getline(cin, duckjump);
    configFile << "alias \"+ag3\" \"echo SqaureUtiles/+duckjump | exec;\"\n";
    configFile << "alias \"-ag3\" \"echo SqaureUtiles/-duckjump | exec;\"\n";
    configFile << "bind " << duckjump << " +ag3\n\n";
   
   */
    cout << "\n\n������󶨸���������İ������Ƽ�CapsLock����";
    getline(cin, bindCrossHairSwitch);

    cout << "\n��������ְ�ģʽ����д��ĸ��\nA ȫ������\nB �Ϲ������¹�����ǹ\nC �¹������Ϲ�����ǹ\nD ��ǹģʽ\n\n��ѡ��";
    getline(cin, bunnyhop);

    if (configFile.is_open()) {
        string vendor = getCPUVendor();

        if (vendor == "GenuineIntel") {
             configFile << "fps_max 159\n";
        }
       

    //׼�ǲ���
        configFile << "alias active \"cl_crosshaircolor_r 255; cl_crosshaircolor_g 0; cl_crosshaircolor_b 0; cl_crosshair_recoil true\"\n";
        configFile << "alias passive \"cl_crosshaircolor_r 0; cl_crosshaircolor_g 255; cl_crosshaircolor_b 0; cl_crosshair_recoil false\"\n";
        configFile << "alias xhair \"xhair1\"\n";
        configFile << "alias xhair1 \"active; alias xhair xhair2\"\n";
        configFile << "alias xhair2 \"passive; alias xhair xhair1\"\n";
        configFile << "bind " << bindCrossHairSwitch << " xhair\n";

        //������
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
        
        //��ͣ����
        cout << "\n\n�Ƿ����ü�ͣCONFIG������ʹ��������Y����������N��";
        getline(cin, faststop);
        if (faststop == "Y" || faststop == "y")
        {
            configFile << "alias SetupMv \"Mv.True\"\n";
            configFile << "alias Mv.True \"alias +AS_FMethod +AS_Forward;alias +AS_BMethod +AS_Back;alias +AS_LMethod +AS_Left;alias +AS_RMethod +AS_Right; alias -AS_FMethod -AS_Forward;alias -AS_BMethod -AS_Back;alias -AS_LMethod -AS_Left;alias -AS_RMethod -AS_Right; ResetJoy\"\n";
            configFile << "alias LoadMv \"bind W +actf;bind S +acts;bind A +acta;bind D +actr\"\n";
            configFile << "alias MvFuse \"alias MvFuse; setinfo MvFuse 0; alias DoLoadMv DefaultMovement; alias sv_shutdown_requested alias DoLoadMv LoadMv; status_json | alias; sv_shutdown_requested; SetupMv\"\n";
            configFile << "MvFuse\n";
            configFile << "DoLoadMv\n";
            configFile << "skill 1\n";
            configFile << "joy_response_move 1\n";
            configFile << "joy_side_sensitivity 1\n";
            configFile << "joy_forward_sensitivity 1\n";
            configFile << "ResetJoy\n";
            configFile << "forward -31200 0 0\n";
            configFile << "back -31200 0 0\n";
            configFile << "left -31200 0 0\n";
            configFile << "right -31200 0 0\n";
            configFile << "alias \"+AS_Forward\" \"+forward;joy_forward_sensitivity 0.0001;joy_side_sensitivity 0\"\n";
            configFile << "alias \"-AS_Forward\" \"-forward;joy_forward_sensitivity -0.0001;joy_side_sensitivity 0\"\n";
            configFile << "alias \"+AS_Back\" \"+back;joy_forward_sensitivity -0.0001;joy_side_sensitivity 0\"\n";
            configFile << "alias \"-AS_Back\" \"-back;joy_forward_sensitivity 0.0001;joy_side_sensitivity 0\"\n";
            configFile << "alias \"+AS_Left\" \"+left;joy_side_sensitivity -0.0001;joy_forward_sensitivity 0\"\n";
            configFile << "alias \"-AS_Left\" \"-left;joy_side_sensitivity 0.0001;joy_forward_sensitivity 0\"\n";
            configFile << "alias \"+AS_Right\" \"+right;joy_side_sensitivity 0.0001;joy_forward_sensitivity 0\"\n";
            configFile << "alias \"-AS_Right\" \"-right;joy_side_sensitivity -0.0001;joy_forward_sensitivity 0\"\n";
            configFile << "alias +actf \"forwardback 1 0 0;bind W +AS_FMethod;bind S +AS_BMethod\"\n";
            configFile << "alias +acts \"forwardback 1 0 0;joy_forward_sensitivity -1;bind W +AS_FMethod;bind S +AS_BMethod\"\n";
            configFile << "alias +actr \"rightleft 1 0 0;bind A +AS_LMethod;bind D +AS_RMethod\"\n";
            configFile << "alias +acta \"rightleft 1 0 0;joy_side_sensitivity -1;bind A +AS_LMethod;bind D +AS_RMethod\"\n";
            configFile << "alias \"+AS_Forwardb\" \"+forward;joy_forward_sensitivity 0.0001;joy_side_sensitivity 0\"\n";
            configFile << "alias \"-AS_Forwardb\" \"-forward;joy_forward_sensitivity 0;joy_side_sensitivity 0\"\n";
            configFile << "alias \"+AS_Backb\" \"+back;joy_forward_sensitivity -0.0001;joy_side_sensitivity 0\"\n";
            configFile << "alias \"-AS_Backb\" \"-back;joy_forward_sensitivity 0;joy_side_sensitivity 0\"\n";
            configFile << "alias \"+AS_Leftb\" \"+left;joy_side_sensitivity -0.0001;joy_forward_sensitivity 0\"\n";
            configFile << "alias \"-AS_Leftb\" \"-left;joy_side_sensitivity 0;joy_forward_sensitivity 0\"\n";
            configFile << "alias \"+AS_Rightb\" \"+right;joy_side_sensitivity 0.0001;joy_forward_sensitivity 0\"\n";
            configFile << "alias \"-AS_Rightb\" \"-right;joy_side_sensitivity 0;joy_forward_sensitivity 0\"\n";
            configFile << "alias \"+AS_Forwards\" \"+forward;joy_forward_sensitivity 0.0001;joy_side_sensitivity 0\"\n";
            configFile << "alias \"-AS_Forwards\" \"-forward;joy_forward_sensitivity 0;joy_side_sensitivity 0\"\n";
            configFile << "alias \"+AS_Backs\" \"+back;joy_forward_sensitivity -0.0001;joy_side_sensitivity 0\"\n";
            configFile << "alias \"-AS_Backs\" \"-back;joy_forward_sensitivity 0;joy_side_sensitivity 0\"\n";
            configFile << "alias \"+AS_Lefts\" \"+left;joy_side_sensitivity -0.0001;joy_forward_sensitivity 0\"\n";
            configFile << "alias \"-AS_Lefts\" \"-left;joy_side_sensitivity 0;joy_forward_sensitivity 0\"\n";
            configFile << "alias \"+AS_Rights\" \"+right;joy_side_sensitivity 0.0001;joy_forward_sensitivity 0\"\n";
            configFile << "alias \"-AS_Rights\" \"-right;joy_side_sensitivity 0;joy_forward_sensitivity 0\"\n";
            configFile << "alias +space \"+sprint;alias +AS_FMethod +AS_Forwardb;alias +AS_LMethod +AS_Leftb;alias +AS_BMethod +AS_Backb;alias +AS_RMethod +AS_Rightb;alias -AS_FMethod -AS_Forwardb;alias -AS_LMethod -AS_Leftb;alias -AS_BMethod -AS_Backb;alias -AS_RMethod -AS_Rightb\"\n";
            configFile << "alias -space \"-sprint;alias +AS_FMethod +AS_Forward;alias +AS_LMethod +AS_Left;alias +AS_BMethod +AS_Back;alias +AS_RMethod +AS_Right;alias -AS_FMethod -AS_Forward;alias -AS_LMethod -AS_Left;alias -AS_BMethod -AS_Back;alias -AS_RMethod -AS_Right\"\n";
            configFile << "bind shift \"+space\"\n";
            configFile << "alias both \"alias +AS_FMethod +AS_Forwardb;alias +AS_LMethod +AS_Leftb;alias +AS_BMethod +AS_Backb;alias +AS_RMethod +AS_Rightb;alias -AS_FMethod -AS_Forwardb;alias -AS_LMethod -AS_Leftb;alias -AS_BMethod -AS_Backb;alias -AS_RMethod -AS_Rightb;alias both single\"\n";
            configFile << "alias single \"alias +AS_FMethod +AS_Forward;alias +AS_LMethod +AS_Left;alias +AS_BMethod +AS_Back;alias +AS_RMethod +AS_Right;alias -AS_FMethod -AS_Forward;alias -AS_LMethod -AS_Left;alias -AS_BMethod -AS_Back;alias -AS_RMethod -AS_Right;alias both both1\"\n";
            configFile << "alias both1 \"alias +AS_FMethod +AS_Forwardb;alias +AS_LMethod +AS_Leftb;alias +AS_BMethod +AS_Backb;alias +AS_RMethod +AS_Rightb;alias -AS_FMethod -AS_Forwardb;alias -AS_LMethod -AS_Leftb;alias -AS_BMethod -AS_Backb;alias -AS_RMethod -AS_Rightb;alias both single\"\n";

            configFile << "alias jton \"bind w +actf; bind s +acts; bind d +actr; bind a +acta\"\n";
            configFile << "alias jtoff \"bind w +forward; bind s +back; bind d +right; bind a +left\"\n";
            configFile << "alias jt1 \"jt2;\"\n";
            configFile << "alias jt2 \"jton; alias jt1 jt3\"\n";
            configFile << "alias jt3 \"jtoff; alias jt1 jt2\"\n";
            cout << "\n��⵽�㿪����ͣ�����һ����ʱ��ͣ���ؼ���";
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
        cout << "\n��󶨻��鰴����Ĭ��j����";
        getline(cin, jm);
        if (jm.empty()) {
            jm = "j";
        }
        configFile << "bind " << jm << " jm1\n\n";
        cout << "\n\n";
        cout << "�Ƿ������е��Զ����ӣ�����ʹ��������Y������������N��";
        getline(cin, autolookweapon);
        if (autolookweapon == "Y" || autolookweapon == "y")
        {
            configFile << "bind \"3\" \"slot3; +lookatweapon; -lookatweapon\"\n";
        }
        else {
            configFile << "bind \"3\" slot3\n";
        }

        configFile.close();
        cout << "�Ѵ��������ļ�: " << path << endl;
    }
    else {
        cout << "�޷����������ļ�: " << path << endl;
    }
}