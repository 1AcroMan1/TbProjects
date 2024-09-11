//#include <iostream>
//#include <fstream>
//#include <string> 
//void Solution()
//{
//    const char operations[4]{ '+','-','*','/' };
//    int count = 0;
//    std::string line;
//    //объявление переменной потокового класса для ввода из файла
//    std::ifstream symb;
//    symb.open("C:/Users/1/Desktop/Лабораторки/АИП/symb.txt");
//    //проверка открыт ли поток ввода
//    if (symb.is_open())
//    {
//        //getline считывает файл полинейно
//        while (std::getline(symb, line))
//        {
//            //классический перебор
//            std::cout << line << std::endl;
//            for (int i = 0; i < std::size(line); i++)
//            {
//                for (int b = 0; b < std::size(operations); b++)
//                {
//                    if (line[i] == operations[b])
//                    {
//                        count++;
//                        break;
//                    }
//                }                
//            }
//            std::cout<<count<<std::endl;
//            count = 0;
//        }
//    }
//    //закрытие потока ввода
//    symb.close();
//    using namespace std;
//    const int len = 80;
//    int main() {
//        //откртие файла для чтения
//        ifstream fin("C:/Users/1/Desktop/Лабораторки/АИП/text.txt", ios::in);
//        if (!fin) {
//            cout << "open error";
//            return 1;
//        }
//        //откртия файла для записи
//        ofstream fout("C:/Users/1/Desktop/Лабораторки/АИП/out.txt", ios::out | ios::app);
//        if (!fout) {
//            cout << "open error";
//            return 1;
//        }        
//        //цикл записи в файл
//            char s[len];
//        while (1) {
//            fin.getline(s, len);
//            if (fin.eof()) break;
//            fout << s << endl;
//        }
//        //закртие обоих файлов
//        fin.close();
//        fout.close();
//    }
//
//int main()
//{
//    Solution();
//    return 0;
//}
