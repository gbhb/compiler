#include <iostream>
#include <unordered_map>

using namespace std;

struct Person
{
    string name;
    int age;

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

/* the object of hash function */
struct PersonHash
{
    size_t operator()(const Person &per) const
    {
        return hash<string>()(per.name) ^ hash<int>()(per.age);
    }
};

/* the object of compare */
struct PersonCmp
{
    bool operator()(const Person &pera, const Person &perb) const
    {
        return pera.name == perb.name && pera.age == perb.age;
    }
};

/* define the unordered_map type */
typedef unordered_map<Person, int, PersonHash, PersonCmp> umap;

int main()
{

    umap m;

    Person p1("Tom1", 20);
    Person p2("Tom2", 22);
    Person p3("Tom3", 22);
    Person p4("Tom4", 23);
    Person p5("Tom5", 24);
    m.insert(umap::value_type(p3, 100));
    m.insert(umap::value_type(p4, 100));
    m.insert(umap::value_type(p5, 100));
    m.insert(umap::value_type(p1, 100));
    m.insert(umap::value_type(p2, 100));

    /* 這裡打印出來的順序於插入順序並不相同，確切的說是完全無序的 */
    for (umap::iterator iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first.name << "\t" << iter->first.age << endl;
    }

    return 0;
}