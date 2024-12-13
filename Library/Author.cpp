#include <sstream>
#include "Author.h"

Library::Author::Author(const std::string& familyName,
	const std::string& firstName,
	const std::optional<std::string>& patronymicName,
	const std::optional<std::chrono::year_month_day>& birthDate,
	const std::optional<std::chrono::year_month_day>& deathDate) :
		familyName{ familyName },
		firstName{ firstName },
		patronymicName{ patronymicName },
		birthDate{ birthDate },
		deathDate{ deathDate }
{
	const auto now = std::chrono::system_clock::now();
	const std::chrono::year_month_day ymd{ std::chrono::floor<std::chrono::days>(now) };

	if (this->birthDate.has_value() && (this->birthDate.value().year() >= ymd.year()))
	{
		throw std::out_of_range("Неправильная дата рождения");
	}

	if (this->deathDate.has_value() && (this->deathDate.value().year() >= ymd.year()))
	{
		throw std::out_of_range("Неправильная дата смерти");
	}

	std::stringstream buffer{};
	if (this->patronymicName.has_value())
	{
		buffer << this->familyName << " " << this->firstName << " " << this->patronymicName.value();
	}
	else
	{
		buffer << this->familyName << " " << this->firstName;
	}

	this->fullName = buffer.str();
}

std::shared_ptr<Library::Author> Library::Author::CreateAuthor(
	const std::string& familyName,
	const std::string& firstName,
	const std::optional<std::string>& patronymicName,
	const std::optional<std::chrono::year_month_day>& birthDate,
	const std::optional<std::chrono::year_month_day>& deathDate)
{
	return std::make_shared<Author>(Author{ familyName , firstName, patronymicName, birthDate , deathDate });
}

bool Library::Author::AddBook(std::shared_ptr<Book>& book)
{
	this->books.push_back(book);
	book->GetAuthors().push_back(shared_from_this());
	return true;
}

std::string Library::Author::ToString() const
{
	std::stringstream buffer{};
	buffer << this->FullName();

	if (this->birthDate)
	{
		buffer << " " << this->birthDate.value();
	}

	if (this->deathDate)
	{
		buffer << " " << this->deathDate.value();
	}

	return buffer.str();
}

std::string Library::Author::FamilyName() const noexcept
{
	return this->familyName;
}

std::string Library::Author::FirstName() const noexcept
{
	return this->firstName;
}

std::string Library::Author::PatronymicName() const noexcept
{
	return this->patronymicName.has_value()
		? this->patronymicName.value()
		: "Неизвестно";
}

std::string Library::Author::FullName() const noexcept
{
	return this->fullName;
}

bool Library::operator==(const Author& lha, const Author& rha)
{
	return lha.ToString() == rha.ToString();
}

std::wstring Library::ToString(const Author& author)
{
	auto temp = author.ToString();
	return std::wstring{ temp.cbegin(), temp.cend()};
}
