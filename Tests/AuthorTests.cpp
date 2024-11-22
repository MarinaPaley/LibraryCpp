#include "pch.h"
#include "CppUnitTest.h"
#include <optional>
#include <chrono>
#include "../Library/Author.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Library;

namespace Tests
{
	TEST_CLASS(AuthorTests)
	{
	public:
		
		TEST_METHOD(Ctor_ValidKnownData_Success)
		{
			// Arrange
			const std::string firstName{ "Лев" };
			const std::string familyName{ "Толстой" };
			const std::optional<std::string> patronymicName{ "Николаевич" };
			const std::string fullName{ "Толстой Лев Николаевич" };
			const std::chrono::year_month_day birthDay{ std::chrono::September / 9 / 1828 };
			const std::chrono::year_month_day deathDay{ std::chrono::November / 20 / 1910 };

			// Act
			auto authorTemp = Author::CreateAuthor(familyName , firstName, patronymicName, birthDay, deathDay );
			auto& author = *authorTemp.get();
			const auto actualFamilyName = author.FamilyName();
			const auto actualFirstName = author.FirstName();
			const auto actualPatronymicName = author.PatronymicName();
			const auto actualFullname = author.FullName();

			// Assert
			Assert::AreEqual(firstName, actualFirstName, L"firstName");
			Assert::AreEqual(familyName, actualFamilyName, L"familyName");
			Assert::AreEqual(patronymicName.value(), actualPatronymicName, L"patronymicName");
			Assert::AreEqual(fullName, actualFullname, L"fullName");
		}

		TEST_METHOD(AddBook_ValidData_True)
		{
			// Arrange
			const std::string firstName{ "Лев" };
			const std::string familyName{ "Толстой" };
			auto author = Author::CreateAuthor(familyName, firstName);
			auto book = Book::CreateBook("Тестовая книга");

			// Act
			auto result = author.get()->AddBook(book);

			// Assert
			Assert::IsTrue(result);
		}
	};
}
