/*
    Условие задачи:
    В текстовом  файле  имеется  некоторое   информационнное
    письмо. Требуется сформировать ответ на письмо. Если  последнее
    предложение письма является  вопросом,  начинающимся  со  слова
    "кто", то слово "кто"  заменяется  словами  "конь в пальто",  а
    знак вопроса заменяется на знак восклицания. В противном случае
    нужно дать ответ: "Спасибо за информацию"

    Автор: Калинин Константин, ПС-12
*/

#include <iostream>
#include <fstream>
#include <optional>
#include <string>

struct Args {
    std::string inputFileName;
    std::string outputFileName;
};

std::optional<Args> ParseArguments(int argc, char* argv[])
{

}

int main(int argc, char* argv[]) {
    system("chcp 65001");
    std::cout << "Hello alabama!";
    return 0;
}