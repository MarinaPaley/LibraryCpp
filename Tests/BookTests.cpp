#include "pch.h"
#include "CppUnitTest.h"
#include "../Library/Shelf.h"
#include "../Library/Book.h"
#include "../Library/Author.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Library;

namespace Tests
{
	TEST_CLASS(BookTests)
	{
		TEST_METHOD(Ctor_ValidData_Success)
		{
			// arrange
			auto book = Book::CreateBook("Тестовая книга");

			// act & assert
			Assert::IsNotNull(book.get());
		}
	};
}