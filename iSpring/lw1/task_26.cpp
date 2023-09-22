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

struct Args
{
    std::string inputFileName;
    std::string outputFileName;
};

std::optional<Args> ParseArguments(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Invalid argumant count" << std::endl
                  << "Usage: task_26.exe <inputFile> <outputFile>" << std::endl;
        return std::nullopt;
    }
    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];

    return args;
}

void CopyStringWithReplacement(std::ifstream &input, std::ofstream &output)
{
    std::string line, replacedLine;
    size_t itemPosition;

    while (std::getline(input, line))
    {
    }
    output << line << std::endl;
    itemPosition = line.find("Кто", 0, 3);
    if (itemPosition == 0)
    {
        if (line[-1] == '?')
        {
            output << "Конь в пальто!" << std::endl;
        } else
        {
            output << "Спасибо за информацию" << std::endl;
        }
    }
}

int CopyFileWithReplacement(std::string &inputFileName, std::string &outputFileName)
{
    std::ifstream inputFile;
    inputFile.open(inputFileName);

    std::ofstream outputFile;
    outputFile.open(outputFileName);

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open " << inputFileName << " for reading" << std::endl;
        return EXIT_FAILURE;
    }

    if (!outputFile.is_open())
    {
        std::cout << "Failed to open " << outputFileName << " for writing" << std::endl;
        return EXIT_FAILURE;
    }

    CopyStringWithReplacement(inputFile, outputFile);

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    auto args = ParseArguments(argc, argv);
    if (!args)
    {
        return EXIT_FAILURE;
    }

    CopyFileWithReplacement(args->inputFileName, args->outputFileName);

    return EXIT_SUCCESS;
}