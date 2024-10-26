#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
bool directoryExists(const string& path) {
    DWORD ftyp = GetFileAttributesA(path.c_str());
    return (ftyp != INVALID_FILE_ATTRIBUTES && (ftyp & FILE_ATTRIBUTE_DIRECTORY));
}


string findGameInstallPath(const string& gameName) {
    // 遍历所有驱动器
    for (char drive = 'C'; drive <= 'Z'; ++drive) {
        string drivePath(1, drive);
        drivePath += ":\\SteamLibrary\\steamapps\\common\\" + gameName;

        if (directoryExists(drivePath)) {
            return drivePath;  
        }
    }
    return ""; 
}


