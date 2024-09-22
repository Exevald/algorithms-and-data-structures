/*
	Задано  некоторое  слово.  Требуется  составить из букв
	этого  слова  максимальное  количество  других  слов,  которые
	имеются  в  словаре.  Каждая  буква  заданного   слова   может
	использоваться  только  один  раз.  Например,  если в заданном
	слове  имеется 2 буквы 'а', то слова словаря, в которых больше
	двух  букв 'а', не подходят. Каждое найденное слово из словаря
	оценивается  количеством очков, равным  длине слова. Результат
	игры определяется суммой  очков. Первая  строка входного файла
	содержит  заданное  слово. Далее  находятся слова словаря. Все
	слова  состоят   из   строчных  (маленьких)  латинских   букв.
	Количество слов словаря  не  превышает 100. В каждом  слове не
	более 20  букв. Длина  заданного  слова  также  не  больше  20
	символов. В первой строке выводится количество набранных очков.
	Начиная со второй строки, следуют найденные слова. Они  должны
	выводиться  по  одному  в  строке по убыванию количества букв.
	Слова  с  одинаковым  количеством  букв  должны  следовать  по
	алфавиту

	Автор: Калинин Константин, ПС-21
	Среда выполнения: JetBrains Clion 2023.3.4
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count" << std::endl
				  << "Usage: task_28.exe <inputFile> <outputFile>" << std::endl;
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

void AssertWordIsValid(const std::string& word)
{
	const int maxLettersCount = 20;
	if (word.size() > maxLettersCount)
	{
		throw std::invalid_argument("Word size is too large. Max size of word: 20 letters");
	}
}

bool IsWordsSimilar(const std::string& dictWord, const std::string& searchWord)
{
	for (char c = 'a'; c <= 'z'; ++c)
	{
		if (std::count(dictWord.begin(), dictWord.end(), c) > std::count(searchWord.begin(), searchWord.end(), c))
			return false;
	}
	return true;
}

void SortSimilarWordsByWordLength(std::vector<std::string>& similarWords)
{
	std::sort(similarWords.begin(), similarWords.end(), [](const std::string& a, const std::string& b) {
		if (a.size() == b.size())
			return a < b;
		return a.size() > b.size();
	});
}

void FillDictionary(std::vector<std::string>& dictionary, std::ifstream& inputFile)
{
	const int maxDictionarySize = 100;
	std::string line;

	while (inputFile >> line)
	{
		dictionary.push_back(line);
		if (dictionary.size() > maxDictionarySize)
		{
			throw std::invalid_argument("Dictionary size is too large. Max size of dictionary: 100 words");
		}
	}
	if (!inputFile.eof())
	{
		throw std::runtime_error("Failed to read text from dictionary file");
	}
}

void TransformToLowerCase(std::string& word)
{
	std::transform(word.begin(), word.end(), word.begin(), [](unsigned char ch) {
		return std::tolower(ch);
	});
}

std::vector<std::string> SortDictionary(const std::vector<std::string>& dictionary)
{
	std::vector<std::string> sortedDictionary;
	for (const std::string& dictItem : dictionary)
	{
		AssertWordIsValid(dictItem);
		std::string sortedDictItem = dictItem;
		std::sort(sortedDictItem.begin(), sortedDictItem.end());
		sortedDictionary.push_back(sortedDictItem);
	}
	return sortedDictionary;
}

std::vector<std::string> GetSimilarWordsFromDictionary(const std::vector<std::string>& dictionary, const std::string& searchWord)
{
	std::vector<std::string> similarWords;
	std::string sortedSearchWord = searchWord;
	std::sort(sortedSearchWord.begin(), sortedSearchWord.end());
	TransformToLowerCase(sortedSearchWord);
	std::vector sortedDictionary = SortDictionary(dictionary);

	for (size_t i = 0; i < sortedDictionary.size(); ++i)
	{
		std::string lowerDictWord = sortedDictionary[i];
		TransformToLowerCase(lowerDictWord);
		if (IsWordsSimilar(lowerDictWord, sortedSearchWord))
		{
			similarWords.emplace_back(dictionary[i]);
		}
	}
	SortSimilarWordsByWordLength(similarWords);
	return similarWords;
}

size_t CountFinalScore(const std::vector<std::string>& similarWords)
{
	size_t score = 0;
	for (const std::string& word : similarWords)
	{
		score += word.size();
	}
	return score;
}

void WriteSimilarWordsInfo(std::ofstream& outputFile, const std::vector<std::string>& similarWords, size_t finalScore)
{
	outputFile << finalScore << std::endl;
	for (const auto& word : similarWords)
	{
		outputFile << word << std::endl;
	}
}

void ListSimilarWordsFromDictionary(const std::string& inputFileName, const std::string& outputFileName)
{
	std::string searchWord;
	std::vector<std::string> dictionary;

	std::ifstream inputFile;
	inputFile.open(inputFileName);
	std::ofstream outputFile;
	outputFile.open(outputFileName);

	if (!inputFile.is_open())
	{
		throw std::runtime_error("Failed to open " + inputFileName + " for reading");
	}
	if (!outputFile.is_open())
	{
		throw std::runtime_error("Failed to open " + outputFileName + " for writing");
	}

	inputFile >> searchWord;
	AssertWordIsValid(searchWord);

	FillDictionary(dictionary, inputFile);
	std::vector<std::string> similarWords = GetSimilarWordsFromDictionary(dictionary, searchWord);
	size_t finalScore = CountFinalScore(similarWords);
	WriteSimilarWordsInfo(outputFile, similarWords, finalScore);

	if (!outputFile.flush())
	{
		throw std::runtime_error("Failed to save data on disk");
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return EXIT_FAILURE;
	}
	try
	{
		ListSimilarWordsFromDictionary(args->inputFileName, args->outputFileName);
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}