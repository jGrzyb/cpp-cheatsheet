#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <random>
#include <bitset>
#include <memory>
#include <fstream>
#include <thread>

// #include <functional>
// #include <iterator>
// #include <utility>
// #include <sstream>
// #include <iomanip>
// #include <limits>
// #include <chrono>
// #include <mutex>
// #include <condition_variable>
// #include <future>
// #include <atomic>
// #include <type_traits>
// #include <typeinfo>
// #include <cassert>
// #include <stdexcept>
// #include <exception>

class C1 {
public:
    int x;
    int y;
    C1(int x, int y) : x(x), y(y) {}
    C1(const C1& c) : x(c.x), y(c.y) {}
    C1(C1&& c) : x(c.x), y(c.y) {}

    bool operator<(const C1 &c) const { return x < c.x; }
    constexpr int square(int val) const noexcept {return val * val;}
    virtual void vprint() const { std::cout << "C1" << std::endl; }
    void print() const { std::cout << "C1" << std::endl; }
};

class C2 : public C1 {
    public:
    C2(int x, int y) : C1(x, y) {}
    void vprint() const override { std::cout << "C2" << std::endl; }
    void print() const { std::cout << "C2" << std::endl; }
};



void dataStructures();
void algorithms();
void maths();
void strings();
void casting();
void pointers();
void other();
void classes();
void files();
void exceptions();
void templates();
void threads();



int main(int, char**) {
    dataStructures();
    algorithms();
    maths();
    strings();
    casting();
    pointers();
    other();
    classes();
    files();
    exceptions();
    // templates();
    threads();

    return 0;
}



void dataStructures() {
    // Vector
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = std::vector<int>(5);
    std::vector<int> v3 = std::vector<int>(5, 0);
    std::vector<int> v4 = std::vector<int>(v1.begin(), v1.end());
    std::vector<int> v5 = std::vector<int>(v1);

    v1.push_back(6);
    v1.pop_back();
    v1.insert(v1.begin() + 2, 7);
    v1.erase(v1.begin() + 2);
    auto tv1 = v1.size();
    auto tv2 = v1.front();
    auto tv3 = v1.back();
    auto tv4 = v1.begin(); // iterator
    auto tv5 = v1.end(); // iterator
    v1.emplace_back(8);


    // List
    std::list<int> l1 = {1, 2, 3, 4, 5};

    l1.push_back(6);
    l1.pop_back();
    l1.push_front(0);
    l1.pop_front();
    l1.insert(l1.begin(), 7);
    l1.erase(l1.begin());
    auto tl1 = l1.size();

    
    // Map
    std::unordered_map<int, int> um1 = {{1, 2}, {3, 4}, {5, 6}};
    std::unordered_map<int, int> um2;
    for(int i=0; i<v1.size(); i++) {
        um2[v1[i]] = v2[i];
    }

    um1[7] = 8;
    um1.erase(7);
    um1.size();
    if(um1.find(1) != um1.end()) {
        int value = um1.at(1);
    }

    std::unordered_set<int> keys;
    for(const auto& pair : um1) {
        keys.insert(pair.first);
    }

    for(const auto& [key, value] : um1) {
        keys.insert(key);
    }


    // Set
    std::unordered_set<int> us1 = {1, 2, 3, 4, 5};
    std::unordered_set<int> us2;

    us1.insert(6);
    us1.erase(6);


    // Stack
    std::stack<int> s1;
    s1.push(1);
    auto ts1 = s1.top();
    s1.pop();
    auto ts2 = s1.size();


    // Queue
    std::queue<int> q1;
    q1.push(1); // back
    q1.pop(); // front
    auto tq1 = q1.front();
    auto tq2 = q1.back();
    auto tq3 = q1.size();
}

void algorithms() {
    std::vector<int> v = {2, 3, 1, 5, 4};

    // filter
    std::vector<int> v1;
    std::copy_if(v.begin(), v.end(), std::back_inserter(v1), [](int x) { return x > 2; });

    // map
    std::vector<C1> v2;
    std::transform(v.begin(), v.end(), std::back_inserter(v2), [](int x) { return C1(x, x); });

    // sort
    std::sort(v.begin(), v.end(), [](int x, int y) { return x < y;});
    
    // find
    auto it = std::find(v.begin(), v.end(), 3);
    int value = *it;
    auto ti1 = std::distance(v.begin(), it);

    std::find_if(v.begin(), v.end(), [](int x) { return x > 2; });

    // count
    std::count(v.begin(), v.end(), 3);
    std::count_if(v.begin(), v.end(), [](int x) { return x > 2; });

    // aggregate
    std::accumulate(v.begin(), v.end(), 0);
    std::accumulate(v.begin(), v.end(), 1, [](int x, int y) {return x * y; });

    // distinct
    std::unordered_set<int> unique(v.begin(), v.end());
    std::vector<int> v3(unique.begin(), unique.end());

    // min/max
    int min = *std::min_element(v.begin(), v.end(), [](int x, int y) { return x < y; });

    // upper_bound and lower_bound
    std::vector<int> sorted_v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;

    auto lower = std::lower_bound(sorted_v.begin(), sorted_v.end(), target);
    auto upper = std::upper_bound(sorted_v.begin(), sorted_v.end(), target);
}

void maths() {
    int v = std::pow(2, 3);

    v = std::sqrt(4);

    // log
    v = std::log2(16);
    v = std::log(2.71828);
    int b=3, c=4;
    v = std::log(c) / std::log(b); // = log_b(c)

    // abs
    v = std::abs(-5.);

    // max/min
    v = std::min(1, 2);
}

void strings() {
    std::string s = "Hello world";
    s = s + "!";
    s = std::string(s.begin(), s.end());
    int ts1 = s.size();
    int ts2 = s.length();
    char ts3 = s[0];
    std::string ts4 = s.substr(0, 5);
    int ts5 = s.find("world");
    int ts6 = s.find("world", 7) == -1;
    int ts7 = s.find_first_of("lo");
    int ts8 = s.find_last_of("lo");
    int ts9 = s.find_first_not_of("lo");
    int ts10 = s.find_last_not_of("lo");
    const char* charArray = s.c_str();
    bool ts11 = s == s;
    s.erase(1, 3);
    s.replace(3, 3, "AAAA");
    s.insert(2,"BB");
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}


void casting() {
    std::string s = std::to_string(5);

    int i = std::stoi("123");
    float f = std::stof("432.1");
    double d = std::stod("4.9876543");


    // char to int and int to char
    char c = '1';
    i = c - '0';
    c = i + '0';

    // int to char 
    i = 1;
    c = static_cast<char>(i);
    c = (char)i;
    i = static_cast<int>(c);
    i = (int)c;

    // number to binary string
    std::bitset<8> binary(4); // for 8 bits
    int num = std::bitset<8>("00000100").to_ulong();

    C1* c1 = new C1(1, 2);
    C2* c2 = dynamic_cast<C2*>(c1);

}

void pointers() {
    int* nullable = nullptr; // remember to instialize with nullptr
    int a = 5; // remember to initialize with default value
    int* p1 = &a;
    *p1;
    
    std::shared_ptr<int> sp1 = std::make_shared<int>(a);
    *sp1;
    *sp1 = 10;
    // cannot use make_shared with raw pointers
    // std::shared_ptr<int> sp2 = std::make_shared<int*>(p);
    // std::shared_ptr<int> sp2 = std::make_shared<int>(p2);
    int* p2 = new int(5);
    std::shared_ptr<int> sp2(p2);

    std::unique_ptr<int>up1 = std::make_unique<int>(5);
    std::unique_ptr<int> up2 = std::move(up1);
}

void other() {
    // access elements
    std::vector<C1> v = {C1(1, 2), C1(3, 4), C1(5, 6)};
    C1 f = *std::find_if(v.begin(), v.end(), [](C1 c) { return c.x == 3; });
    f.x = 100; // Doesn't change in the vector
    C1& r = *std::find_if(v.begin(), v.end(), [](C1 c) { return c.x == 3; });
    r.x = 100; // Changes in the vector

    // random
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(1, 6); // inclusive
    int dice = dis(gen);
    float prob = std::uniform_real_distribution<float>(0, 1)(gen);
}

void classes() {
    const C1 &c1 = C2(1, 2);
    C1 *c2 = new C2(1, 2);
    c2->vprint();
    c2->print();
    (typeid(*c2) == typeid(C2));
    typeid(*c2).name();
    C2* c3 = dynamic_cast<C2*>(c2);
    c3->print();
    (*c3).x = 101;
    delete c2;
}

void files() {
    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.txt", std::ios::app);

    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    }

    if (outFile.is_open()) {
        outFile << "Hello, World!" << std::endl;
        outFile.close();
    }
}

void exceptions() {
    try {
        throw std::runtime_error("Error");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown error" << std::endl;
    }
}

template<typename T>
void templates(const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void threadExample() {
    std::cout << "Thread example" << std::endl;
}

void threads() {
    std::thread t1(threadExample);
    t1.join();
}