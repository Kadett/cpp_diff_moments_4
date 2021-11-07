#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

template<typename T, typename E>
void insert_sorted(T &cont, E val){
    auto it = upper_bound(cont.begin(), cont.end(), val);
    cont.insert(it, val);
}

double calc(vector<double> &vecD, vector<int> &vecI){
    auto it = vecI.begin();
    double sum{};
    for_each(vecD.begin(), vecD.end(), [&it, &sum](const auto &i){
        sum += (i - *it)*(i - *it);
        it = next(it);
    });
    return sum;
}
/*


В занятии у вас вышла заминка с for_each, вы пытались выполнить for_each(v1.begin(), v1.end(), [](const auto &i){return i * i;});,
а нужно было for_each(v1.begin(), v1.end(), [](auto &i){i *= i;});
Т.е. не возвращать значение, а напрямую присваивать его.
*/


int main() {



    vector<int> vec(10);
    list<int> list1(10);
    generate(vec.begin(), vec.end(), [](){return rand()%100;});
    generate(list1.begin(), list1.end(), [](){return rand()%100;});
    sort(vec.begin(), vec.end());
    list1.sort();

    cout << "First lesson:" << endl;
    for_each(vec.begin(), vec.end(), [](const auto &i){cout << i << " ";});
    cout << endl;
    insert_sorted(vec, 64);
    for_each(vec.begin(), vec.end(), [](const auto &i){cout << i << " ";});
    cout << endl << endl;

    for_each(list1.begin(), list1.end(), [](const auto &i){cout << i << " ";});
    insert_sorted(list1, 41);
    cout << endl;
    for_each(list1.begin(), list1.end(), [](const auto &i){cout << i << " ";});

    cout << "\n\n" << "Second lesson:" << endl;
    vector<double> vecDouble(100);
    vector<int> vecInt(100);
    generate(vecDouble.begin(), vecDouble.end(), [](){
        return rand()%10 + (double)(rand()%100)/100;
    });
    sort(vecDouble.begin(), vecDouble.end());
    for_each(vecDouble.begin(), vecDouble.end(), [](const auto &i){cout << i << " ";});
    copy(vecDouble.begin(), vecDouble.end(), vecInt.begin());
    cout << endl << endl;
    for_each(vecInt.begin(), vecInt.end(), [](const auto &i){cout << i << " ";});
    cout << endl;

    cout << "error rate = " << calc(vecDouble, vecInt);

    return 0;
}
