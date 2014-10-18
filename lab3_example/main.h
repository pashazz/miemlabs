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




void parseString(const  string &src, vector<set<string>> &dst);

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
void printVector(const vector<set<string>> &v);
/*
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
bool compareVectorElements(const set<string> &set1, const set<string> &set2)
{
    return caseInsensitiveCharCompareReversed(set1.begin()->at(0), set2.begin()->at(0));
}
