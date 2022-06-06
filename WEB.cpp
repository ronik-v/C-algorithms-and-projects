#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>
#include <uwebsockets/App.h>

struct userConnect {
    unsigned long int ID;
    std :: string* UserName;

};

int main()
{
    std :: atomic_ulong latest_user_ID = 10;

    // Создание нескольких потоков обработки сервера...
    std :: vector<std::thread*> threads (std::thread::hardware_concurrency());
    std::transform(threads.begin(), threads.end(), threads.begin(), [&latest_user_ID](auto* thr) {

        return new std::thread([&latest_user_ID]() {
            uWS::App().ws<userConnect>("/*", {
                .open = [&latest_user_ID](auto* ws) {
                    userConnect* data = (userConnect*)ws->getUserData();
                    data->ID = latest_user_ID++;
                    std::cout << "new latest_user_ID:" << data->ID << std::endl;
                },
                 .message = [](auto* ws, std::string_view message, uWS::OpCode) {
                    userConnect* data = (userConnect*)ws->getUserData();
                    std::cout << "New user message:" << message << "user ID:" << data->ID <<'\n';
                    auto begin = message.substr(0, 9);
                    // Пользователь прислал свое имя 
                    if (begin.compare("SET_NAME=") == 0) {
                        auto name = message.substr(9);
                        data->UserName = new std::string(name);
                        std::cout << "User set their name ID = " << data->ID << "Name = " << (*data->UserName) << '\n';
                    }
                 }
                    // Прослушивание порта...
                }).listen(9999,
                    [](auto* token) {
                        if (token) {
                            std::cout << "Server is working and listening 9999..."<<'\n' << std::endl;
                        }
                        else
                        {
                            std::cout << "Server is not working" << '\n' << std::endl;
                        }
                    }).run();
            });
        });
    // Ситуация с закрытием потока...

    for_each(threads.begin(), threads.end(), [](auto* thr) {thr->join(); });
}