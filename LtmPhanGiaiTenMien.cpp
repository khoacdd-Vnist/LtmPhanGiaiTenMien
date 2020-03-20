// LTM-Phân giải tên miền.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <regex>
#include <string>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32")



using namespace std;
int main()
{
    string a ;
    cin >> a;
    regex b("^[a-z0-9]+([\-\.]{1}[a-z0-9]+)*\.[a-z]{2,6}$");//Regular expression để validate 1 tên miền
    if (regex_match(a, b))
        cout << "Input string is an valid domain name  \n";
    else cout << "input string is NOT an valid domain name ";

    //Phân giải tên miền
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    addrinfo* info;
    SOCKADDR_IN addr;
    int ret = getaddrinfo((PCSTR)a.c_str(), "http", NULL, &info);
    if (ret == 0)
    {
        memcpy(&addr, info->ai_addr, info->ai_addrlen);
        cout << "\nPhan giai thanh cong !";
        cout << "\nDia chi IP:" << inet_ntoa(addr.sin_addr);
    }
    else cout << "Phan giai khong thanh cong ";
}

