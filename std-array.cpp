#include <string>
#include <iostream>
#include <array>

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
    {}

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
    std::array<person, 5> ar;
    ar[0] = person("alice");
    ar[1] = person("bob");
    auto ar2 = ar;
    return 0;
}
