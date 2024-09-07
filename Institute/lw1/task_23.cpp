#include <fstream>
#include <iostream>
#include <optional>
#include <vector>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<Args> ParseArguments(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count" << std::endl
				  << "Usage: task_26.exe <inputFile> <outputFile>" << std::endl;
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];

	return args;
}

std::vector<std::string> GetLastString(std::ifstream& input)
{
	std::string word;
	std::vector<std::string> wordsList;

	while (input >> word)
	{
		wordsList.push_back(word);
		if (word[word.size() - 1] == '.' || word[word.size() - 1] == '!' || (word[word.size() - 1] == '?' && !input.eof()))
		{
			wordsList.clear();
		}
	}
	return wordsList;
}

void CreateAnswer(const std::vector<std::string>& wordsList, std::ofstream& output)
{
	std::string firstWord, lastWord;
	char lastChar;

	if (wordsList.empty())
	{
		output << "Спасибо за информацию";
	}
	else
	{
		firstWord = wordsList.front();
		lastWord = wordsList.back();
		lastChar = lastWord[lastWord.size() - 1];
		if (firstWord == lastWord)
		{
			output << "Конь в пальто!";
		}
		else
		{
			if (firstWord == "Кто" && lastChar == '?')
			{
				output << "Конь в пальто ";
				for (std::vector<int>::size_type i = 1; i < wordsList.size() - 1; i++)
				{
					output << wordsList.at(i) << ' ';
				}
				for (int i = 0; i < lastWord.size() - 1; i++)
				{
					output << lastWord[i];
				}
				output << '!';
			}
			else
			{
				output << "Спасибо за информацию";
			}
		}
	}
}

int CopyFileWithReplacement(const std::string& inputFileName, const std::string& outputFileName)
{
	std::vector<std::string> wordsList;

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

	wordsList = GetLastString(inputFile);
	CreateAnswer(wordsList, outputFile);

	return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
	auto args = ParseArguments(argc, argv);
	if (!args)
	{
		return EXIT_FAILURE;
	}
	if (!CopyFileWithReplacement(args->inputFileName, args->outputFileName))
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
