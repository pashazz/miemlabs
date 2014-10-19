/** @file main.cpp
*
* @brief Реализация функций
*
* @author Pavel Borisov
* @date 15 Oct 2014
* @see
*/

#include "main.h"
using namespace std;

/**
* @brief проверка на то, является ли символ не буквой или цифрой
* @param [in] ch - символ
* @return true, если не буква или цифра
* false иначе
*/
bool isNotAlnum(const char &ch)
{
    return !isalnum(ch);
}



int main()
{
	string src;
	VectorOfStrings dst;

	cout << "Input text: " << endl;
	getline (cin,src);

	parseString(src, dst);
	printVector(dst);

	system ("pause");
	return 0;

}


void printSet(const MyStringSet &s)
{
	cout << '{';
    auto iter = s.cbegin();
	while(true)
	{
		cout << '"';
		cout << *iter;
		cout << '"';
		if(++iter!=s.cend())
            cout << ", ";
        else
            break;
	}
	cout << '}';
}

void printVector(const VectorOfStrings &v)
{
	cout << '{';
	VectorOfStrings::const_iterator iter = v.begin();
	while(true)
	{
		printSet(*iter);
		if(++iter!=v.end())
			cout << ", ";
		else
			break;
	}
	cout << '}' << endl;
}




void stringToSet(const string &src, set<string> &setStr)
{
	stringstream stream(src);                      //<поток из строки
	string s;
	while (stream >> s)                                //пока поток выводит в строку
	{
		//cout << s << endl;
		s.erase(remove_if(s.begin(), s.end(), isNotAlnum), s.end());      //убирает не буквы
		setStr.insert(s);                            //заполн¤ем множество этими словами
	}

}

/**
* @brief формирование вектора множеств dst из строки src по правилу
*
*  dst[i]  это множество слов из строки src,
* начинающихся на одну букву; множества отсортированы в обратном алфавитном пор¤дке букв, с которых начинаются их слова.
*
* Слова отсортированы в обратном алфавитном порядке букв.
*
* @param [in] src - строка, которую нужно обработать
* @param [out] dst - результирующий вектор (предполагается пустой на входе)
*
*
* <b>Пример</b>
* @code{cpp}
*     string src=”this is the malt that lay in the house that jack built”;
*     VectorOfStrings dst;
*     parseString(src,dst);
*     printVector(dst); //   dst = {{“this”,”the”,”that”}, {“malt”}, {“lay”}, {“jack”}, {“is”,”in”}, {“house”}, {“built”}}
* @endcode
*/
void parseString(const  string &src, VectorOfStrings &dst)
{
	set<string> setOfAllWords;            //множество всех слов
	stringToSet(src,setOfAllWords);

	for (set<string>::iterator itAllWords= setOfAllWords.begin(); itAllWords != setOfAllWords.end(); itAllWords++)
	{
		bool inserted = false;
		for (VectorOfStrings::iterator iDst = dst.begin(); iDst != dst.end(); iDst++)
		{
			if(itAllWords->at(0) == iDst->begin()->at(0))            //если слово, начинающеес¤ с такой буквы уже есть
            {
                iDst->insert(std::move(*itAllWords));                   //добавляем в уже существующее множесто это слово
                inserted = true;
                break;
			}
		}
		if (inserted)
			continue;

		MyStringSet newSet;
		newSet.insert(*itAllWords); // move value to newSet
		dst.push_back(std::move(newSet)); //move, not copy value to the dst
	}
    sort(dst.begin(), dst.end(), compareVectorElements);
}