#include <string>
#include <iostream>
#include <itlib/small_vector.hpp>

class person
{
public:
    person()
        : m_name("<nobody>")
    {
        std::cout << "default construct\n";
    }

    explicit person(std::string name)
        : m_name(std::move(name))
    {
        std::cout << "name construct " << m_name << "\n";
    }

    person(const person& other)
        : m_name(other.m_name)
    {
        std::cout << "copy-constructed " << m_name << '\n';
    }

    person& operator=(const person& other)
    {
        m_name = other.m_name;
        std::cout << "copy-assigned " << m_name << '\n';
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
    itlib::small_vector<person, 3> vec;
    vec.emplace_back("alice");
    vec.emplace_back("bob");
    vec.emplace_back("charlie");
    vec.emplace_back("donna");
    return 0;
}
