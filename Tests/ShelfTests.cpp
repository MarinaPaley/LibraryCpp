#include "pch.h"
#include "CppUnitTest.h"
#include "../Library/Shelf.h"
#include "../Library/Book.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Library;

namespace Tests
{
	TEST_CLASS(ShelfTests)
	{
	public:
		TEST_METHOD(AddBook_ValidData_True)
		{
			// arrange
			auto shelf = Shelf::CreateShelf("Тестовая полка");
			auto book = Book::CreateBook("Тестовая книга");

			// act
			auto result = shelf.get()->AddBook(book);

			// assert
			Assert::IsTrue(result);
			Assert::IsTrue(1 == shelf.get()->BookCount());
		};

		TEST_METHOD(RemoveBook_ValidData_True)
		{
			// arrange
			auto shelf = Shelf::CreateShelf("Тестовая полка");
			auto book = Book::CreateBook("Тестовая книга");
			auto x = shelf.get()->AddBook(book);

			// act
			auto result = shelf.get()->RemoveBook(book);

			// assert
			Assert::IsTrue(result);
			Assert::IsTrue(0 == shelf.get()->BookCount());
		}
	};
}