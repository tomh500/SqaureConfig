#ifndef GETSTEAMLIB_H
#define GETSTEAMLIB_H

#include <string>
#include <vector>

// 函数声明
std::string getSteamInstallPath();
std::vector<std::string> getSteamLibraryFolders(const std::string& steamPath);
bool directoryExists(const std::string& path);
std::string findGameInstallPath(const std::string& gameName); // 确保参数类型正确

#endif // GETSTEAMLIB_H
