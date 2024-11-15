#include <iostream>
#include <optional>
#include <chrono>
#include <locale>
#include "../Library/Author.h"
#include "../Library/Book.h"
#include "../Library/Shelf.h"

using namespace Library;
int main()
{
	setlocale(LC_ALL, "Russian");
	try {
		const std::string firstName{ "Лев" };
		const std::string familyName{ "Толстой" };
		const std::optional<std::string> patronymicName{ "Николаевич" };
		const std::chrono::year_month_day birthDay{ std::chrono::September / 9 / 1828 };
		const std::chrono::year_month_day deathDay{ std::chrono::November / 20 / 1910 };

		auto lev = Author::CreateAuthor(familyName, firstName, patronymicName, birthDay, deathDay);
		auto childhood = Book::CreateBook("Детство");
		auto shelf = Shelf::CreateShelf("Полка");

		auto result = lev->AddBook(childhood);
		result = shelf->AddBook(childhood);
		std::cout << lev->ToString() << "\n";
		std::cout << childhood->ToString() << "\n";
		std::cout << shelf->ToString();
	}
	catch (std::out_of_range& ex)
	{
		std::cerr << ex.what();
	}

	return 0;
}