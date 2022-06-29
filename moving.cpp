#include <vector>
#include <string>
#include <iostream>

class person
{
public:
    explicit person(std::string name)
        : m_name(std::move(name))
    {}

    person(const person& other)
        : m_name(other.m_name)
    {
        std::cout << "COPY-constructed " << m_name << '\n';
    }

    person& operator=(const person& other)
    {
        m_name = other.m_name;
        std::cout << "COPY-assigned " << m_name << '\n';
        return *this;
    }

    person(person&& other) noexcept
        : m_name(std::move(other.m_name))
    {
        std::cout << "move-constructed " << m_name << '\n';
    }

    person& operator=(person&& other) noexcept
    {
        m_name = std::move(other.m_name);
        std::cout << "move-assigned " << m_name << '\n';
        return *this;
    }

    void speak() const
    {
        std::cout << "I am " << m_name << '\n';
    }

private:
    std::string m_name;
};

int main()
{
    std::vector<person> people;
    people.emplace_back("alice");

    std::cout << "Pushing bob to front:\n";
    person bob("bob");
    people.insert(people.begin(), std::move(bob));

    std::vector<person> people2;
    people2.reserve(10);
    people2.emplace_back("charlie");
    people2.insert(people2.begin(), people.begin(), people.end());

    return 0;
}