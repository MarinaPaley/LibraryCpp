#include <iostream>
#include <optional>
#include <chrono>
#include "../Library/Author.h"

using namespace Library;
int main()
{
	const std::string firstName{ "Лев" };
	const std::string familyName{ "Толстой" };
	const std::optional<std::string> patronymicName{ "Николаевич" };
	const std::chrono::year_month_day birthDay{ std::chrono::September / 9 / 1828 };
	const std::chrono::year_month_day deathDay{ std::chrono::November / 20 / 1910 };

	Author author{ familyName , firstName, patronymicName, birthDay, deathDay };

	std::cout << author.ToString();

	return 0;
}