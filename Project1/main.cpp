#include <memory>
int main()
{
	std::unique_ptr<int> i = std::make_unique<int>();
	std::unique_ptr<int[]> array = std::make_unique<int[]>(10);
	std::unique_ptr<int[]> array2 = std::move(array);

	std::shared_ptr<int> s = std::make_shared<int>(5);
	std::shared_ptr<int> a = s;

	std::weak_ptr<int> p(a);
	return 0;
}