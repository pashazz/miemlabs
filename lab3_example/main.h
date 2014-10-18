/**
* @file main.h
* @author Pavel Borisov
* @brief essential functions for coding this lab
*
* Вспомогательные функции для выполнения лабораторной работы
*
*/

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>

using std::string;
using std::set;
using std::vector;

/**
* @class SetComparisonPredicate
* Устанавливает обратный порядок сортировки в алфавитном порядке для множества set<string> (case-insensitive)
*
*/
struct SetComparisonPredicate
{
    /**
    * Осуществяет сравнение двух строк по признаку: если первая лексикографически больше второй, то возврат true. Иначе false.
    *  (обратный порядок сортировки)
    */
    bool operator() (const string &str1, const string &str2)
    {
        string str1_lower, str2_lower;
        /* Transform ТРЕБУЕТ, чтобы место для вывода
         результирующих элементов уже было выделено, поэтому выделяем его в конструкторе объектов: http://www.cplusplus.com/reference/algorithm/transform/?kw=transform
         поэтому делаем вызов resize для соотв. строк
         */
        str1_lower.resize(str1.size());
        str2_lower.resize(str2.size());
        transform(str1.begin(), str1.end(), str1_lower.begin(), tolower); //конвертация в нижний регистр
        transform(str2.begin(), str2.end(), str2_lower.begin(), tolower);
        return  str1_lower > str2_lower;
    }
};

typedef set<string, SetComparisonPredicate> MyStringSet;
typedef vector<MyStringSet> VectorOfStrings;


void parseString(const  string &src, VectorOfStrings &dst);

/**
*  @brief формирование множества всех слов строки, исключая все символы, которые не являются буквами/цифрами
*
* @param [in] src - строка, которую нужно обработать
* @param [out] setStr - множество всех слов строки (предполагается пустое множество на входе)
 */
void stringToSet(const string &src, set<string> &setStr);

/**
* @brief печать множества строк на экран
*
* Формат вывода {"строка1", "строка2"}
* @param [in] s - множество, которое нужно напечатать
*
*/
void printSet(const set<string> &s);

/**
* @brief печать вектора множеств строк на экран
*
* Формат вывода {{Множество}, {Множество}}
*/
void printVector(const VectorOfStrings &v);

/**
* @brief сравнение двух символов в порядке, обратном алфавитному
*
* Сравнение не зависит от регистра
*
* @param ch1 - первый символ
* @param ch2 - второй символ
* @return
* true, если ch1 ближе к концу алфавита, чем ch2
* false в обратном случае
 */
bool caseInsensitiveCharCompareReversed(const char &ch1, const char &ch2)
{
    return tolower(ch1) > tolower(ch2);
}

/**
 * сравнивает два вектора s  по следующему правилу
 * если вектор содержит множества, начинающиеся с буквы, которая стоит ближе к концу алфавита, возвращает true
 * иначе false
 * @param set1 - первое множество
 * @param set2 - второе множество
 */
bool compareVectorElements(const MyStringSet &set1, const MyStringSet &set2)
{
    return caseInsensitiveCharCompareReversed(set1.begin()->at(0), set2.begin()->at(0));
}

