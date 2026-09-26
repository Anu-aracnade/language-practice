#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

class FizzBuzz {
private:
    int n;
    int counter;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->counter = 1;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return counter > n || (counter % 3 == 0 && counter % 5 != 0); });
            if (counter > n) return;
            printFizz();
            counter++;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return counter > n || (counter % 5 == 0 && counter % 3 != 0); });
            if (counter > n) return;
            printBuzz();
            counter++;
            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return counter > n || (counter % 15 == 0); });
            if (counter > n) return;
            printFizzBuzz();
            counter++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return counter > n || (counter % 3 != 0 && counter % 5 != 0); });
            if (counter > n) return;
            printNumber(counter);
            counter++;
            cv.notify_all();
        }
    }
};

int main() {
    int n = 15;
    FizzBuzz fizzBuzzObj(n);

    auto printFizz = []() { cout << "fizz\n"; };
    auto printBuzz = []() { cout << "buzz\n"; };
    auto printFizzBuzz = []() { cout << "fizzbuzz\n"; };
    auto printNumber = [](int x) { cout << x << "\n"; };

    thread t1(&FizzBuzz::fizz, &fizzBuzzObj, printFizz);
    thread t2(&FizzBuzz::buzz, &fizzBuzzObj, printBuzz);
    thread t3(&FizzBuzz::fizzbuzz, &fizzBuzzObj, printFizzBuzz);
    thread t4(&FizzBuzz::number, &fizzBuzzObj, printNumber);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
