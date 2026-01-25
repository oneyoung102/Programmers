#include <iostream>
#include <vector>
#include <string>
#include <tuple>

#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)

using namespace std;

class managingPrinting
{
    private : 
        const string AnswerEqualString = "answer : ";
        
        void PrintAnswer(int t){cout << t;}
        void PrintAnswer(char t){cout <<'\''<< t << '\'';}
        void PrintAnswer(string t){cout <<'\"'<< t << '\"';}
        void PrintAnswer(long long t){cout << t;}
        void PrintAnswer(double t){cout << t;}
        void PrintAnswer(bool t)
        {
            if(t) cout << "true";
            else cout << "false";
        }
        template<class T>
        void PrintVector(vector<T>& t)
        {
            size_t count = t.size();
            for(T e : t)
            {
                PrintAnswer(e);
                if(--count != 0) cout << ", ";
            }
        }
        void PrintAnswer(vector<int>& t){PrintVector<int>(t);}
        void PrintAnswer(vector<string>& t){PrintVector<string>(t);}
        void PrintAnswer(vector<long long>& t){PrintVector<long long>(t);}
        void PrintAnswer(vector<double>& t){PrintVector<double>(t);}
        void PrintAnswer(vector<bool>& t){PrintVector<bool>(t);}
        template<class T>
        void PrintMatrix(vector<T>& t)
        {
            size_t count = t.size();
            const string Blank = string(AnswerEqualString.size(),' ');
            for(T& v : t)
            {
                PrintAnswer(v); 
                if(--count != 0) cout << endl << Blank;
            }
        }
        void PrintAnswer(vector<vector<int>>& t){PrintMatrix<vector<int>>(t);}
        void PrintAnswer(vector<vector<string>>& t){PrintMatrix<vector<string>>(t);}
        void PrintAnswer(vector<vector<long long>>& t){PrintMatrix<vector<long long>>(t);}
        void PrintAnswer(vector<vector<double>>& t){PrintMatrix<vector<double>>(t);}
        void PrintAnswer(vector<vector<bool>>& t){PrintMatrix<vector<bool>>(t);}  
    public :
        managingPrinting(){}
        ~managingPrinting(){}

        template<class T>
        void printReturn(T& t)
        {
            cout << AnswerEqualString;
            PrintAnswer(t);
            cout << endl;
            return;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class managingArgument
{
    private :
        template<class T>
        tuple<T> oneArgumentToTuple(string&& arguments){
            return make_tuple(T{});
        }
        template<> tuple<int> oneArgumentToTuple<int>(string&& arguments){return make_tuple(stoi(arguments));}
        template<> tuple<long long> oneArgumentToTuple<long long>(string&& arguments){return make_tuple(stoll(arguments));}
        template<> tuple<double> oneArgumentToTuple<double>(string&& arguments){return make_tuple(stod(arguments));}
        template<> tuple<char> oneArgumentToTuple<char>(string&& arguments){return make_tuple(arguments[1]);}
        template<> tuple<string> oneArgumentToTuple<string>(string&& arguments){return make_tuple(arguments.substr(1,arguments.size()-2));}
        template<> tuple<bool> oneArgumentToTuple<bool>(string&& arguments)
        {
            if(arguments == "true")
                return make_tuple(true);
            return make_tuple(false);
        }

        template<class T>
        vector<T> stringToVector(string&& str)
        {
            vector<T> v;
            int commaPos = 0;
            for(int i = 1 ; i < str.size() ; ++i)
                if(str[i] == ',' || i == str.size()-1)
                {
                    v.push_back(get<0>(oneArgumentToTuple<T>(str.substr(commaPos+1,i-commaPos-1))));
                    commaPos = i;
                }
            return v;
        }
        template<> tuple<vector<int>> oneArgumentToTuple<vector<int>>(string&& arguments){return make_tuple(stringToVector<int>(std::move(arguments)));}
        template<> tuple<vector<long long>> oneArgumentToTuple<vector<long long>>(string&& arguments){return make_tuple(stringToVector<long long>(std::move(arguments)));}
        template<> tuple<vector<double>> oneArgumentToTuple<vector<double>>(string&& arguments){return make_tuple(stringToVector<double>(std::move(arguments)));}
        template<> tuple<vector<string>> oneArgumentToTuple<vector<string>>(string&& arguments){return make_tuple(stringToVector<string>(std::move(arguments)));}
        template<> tuple<vector<bool>> oneArgumentToTuple<vector<bool>>(string&& arguments){return make_tuple(stringToVector<bool>(std::move(arguments)));}

        template<class T>
        vector<vector<T>> stringToMatrix(string&& str)
        {
            vector<vector<T>> v;
            int bucketCount = 0, commaPos = 0;
            for(int i = 1 ; i < str.size() ; ++i)
                if(bucketCount == 0 && (str[i] == ',' || i == str.size()-1))
                {
                    v.push_back(stringToVector<T>(str.substr(commaPos+1,i-commaPos-1)));
                    commaPos = i;
                }
                else if(str[i] == '{' || str[i] == '[')
                    ++bucketCount;
                else if(str[i] == '}' || str[i] == ']')
                    --bucketCount;
            return v;
        }
        template<> tuple<vector<vector<int>>> oneArgumentToTuple<vector<vector<int>>>(string&& arguments){return make_tuple(stringToMatrix<int>(std::move(arguments)));}
        template<> tuple<vector<vector<long long>>> oneArgumentToTuple<vector<vector<long long>>>(string&& arguments){return make_tuple(stringToMatrix<long long>(std::move(arguments)));}
        template<> tuple<vector<vector<double>>> oneArgumentToTuple<vector<vector<double>>>(string&& arguments){return make_tuple(stringToMatrix<double>(std::move(arguments)));}
        template<> tuple<vector<vector<string>>> oneArgumentToTuple<vector<vector<string>>>(string&& arguments){return make_tuple(stringToMatrix<string>(std::move(arguments)));}
        template<> tuple<vector<vector<bool>>> oneArgumentToTuple<vector<vector<bool>>>(string&& arguments){return make_tuple(stringToMatrix<bool>(std::move(arguments)));}
        
    public :
        managingArgument(){}
        ~managingArgument(){}

        template<class T, class ...Q>
        tuple<T, Q...> argumentsToTuple(string&& arguments){
            if constexpr (sizeof ...(Q) == 0)
                return tuple_cat(
                    oneArgumentToTuple<T>(std::move(arguments)),
                    tuple<Q...>()
                );
            int bucketCount = 0, commaPos = -1;
            bool isString = false;
            for(int i = 0 ; i < arguments.size() ; ++i)
            {
                if(arguments[i] == '"' || arguments[i] == '\'')
                    isString = (isString) ? false : true;
                if(isString)
                    continue;
                if(arguments[i] == '{' || arguments[i] == '[')
                    ++bucketCount;
                else if(arguments[i] == '}' || arguments[i] == ']')
                    --bucketCount;
                else if(bucketCount == 0 && arguments[i] == ',')
                {
                    commaPos = i;
                    break;
                }
            }
            if constexpr (sizeof ...(Q) == 1)
                return tuple_cat(
                    oneArgumentToTuple<T>(arguments.substr(0,commaPos)),
                    oneArgumentToTuple<Q...>(arguments.substr(commaPos+1))
                );
            else if constexpr (sizeof ...(Q) > 1)
                return tuple_cat(
                    oneArgumentToTuple<T>(arguments.substr(0,commaPos)),
                    argumentsToTuple<Q...>(arguments.substr(commaPos+1))
                );
        }

        string stringArgParsing(string&& str)
        {
            bool isString = false;
            string newStr = "";
            for(int i = 2 ; i < str.size()-2 ; ++i)
            {
                if(isString && str[i] == ' ' || str[i] != ' ')
                    newStr.push_back(str[i]);
                if(str[i] == '\"' || str[i] == '\'')
                    isString = (isString) ? false : true;
            }
            return newStr;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class... ARG, class FUNC>
void FunctionReturnPrint(FUNC&& f, string&& args)
{
    managingPrinting MP;
    managingArgument MA;
    auto answer = apply(f,MA.argumentsToTuple<ARG...>(MA.stringArgParsing(std::move(args))));//2abcdede//
    /*const 절대 금지*/
    MP.printReturn(answer);
    return;
}
