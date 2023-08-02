/**
 @file       timer.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-08-02
 @brief     실행시간을 측정하는 timer 를 만들어보자.
            앞으로 해당 클래스 계속 사용하면 돼
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include <iostream>
#include <chrono> // 시간 관련 STL
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

class Timer 
{
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
    void elapsed()
    {
        std::chrono::time_point<clock_t> end_time = clock_t::now();
        std::cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << std::endl;
    }
};

int main()
{
    random_device rnd_device;
    mt19937 mersenne_engine{ rnd_device() };

    vector<int> vec(21345678);
    // for (unsigned int i = 0; i < vec.size(); i++){
    //     vec[i] = i;
    // }

    std::shuffle(begin(vec), end(vec), mersenne_engine);

    // for (auto &e : vec) cout << e << " ";
    // cout << endl;

    Timer timer;

    std::sort(begin(vec), end(vec));
    timer.elapsed();

    // for (auto &e : vec) cout << e << " ";
    // cout << endl;

    return 0;
}
