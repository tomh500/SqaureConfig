#ifndef GETSTEAMLIB_H
#define GETSTEAMLIB_H

#include <string>
#include <vector>

// ��������
std::string getSteamInstallPath();
std::vector<std::string> getSteamLibraryFolders(const std::string& steamPath);
bool directoryExists(const std::string& path);
std::string findGameInstallPath(const std::string& gameName); // ȷ������������ȷ

#endif // GETSTEAMLIB_H
