#include <windows.h>
#include <iostream>

#define SERVICE_NAME  TEXT("MyService")

void CreateService()
{
    // Получаем дескриптор для менеджера служб
    SC_HANDLE hSCManager = OpenSCManager(nullptr, nullptr, SC_MANAGER_ALL_ACCESS);
    if (!hSCManager)
    {
        std::cerr << "OpenSCManager failed: " << GetLastError() << std::endl;
        return;
    }

    // Создаем службу
    SC_HANDLE hService = CreateService(
        hSCManager,
        SERVICE_NAME,
        SERVICE_NAME,
        SERVICE_ALL_ACCESS,
        SERVICE_WIN32_OWN_PROCESS,
        SERVICE_AUTO_START,
        SERVICE_ERROR_NORMAL,
        TEXT("C:\\Users\\ghost\\OneDrive\\Документы\\service\\build\\Debug\\empty.exe"), // Укажите путь к вашему исполняемому файлу
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    );

    if (!hService)
    {
        std::cerr << "CreateService failed: " << GetLastError() << std::endl;
        CloseServiceHandle(hSCManager);
        return;
    }

    std::cout << "Service created successfully!" << std::endl;

    // Запускаем службу
    if (StartService(hService, 0, nullptr))
    {
        std::cout << "Service started successfully!" << std::endl;
    }
    else
    {
        std::cerr << "StartService failed: " << GetLastError() << std::endl;
    }

    // Закрываем дескрипторы
    CloseServiceHandle(hService);
    CloseServiceHandle(hSCManager);
}

int main()
{
    CreateService();
    return 0;
}

