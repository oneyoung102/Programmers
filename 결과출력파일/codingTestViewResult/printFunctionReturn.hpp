#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>

#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)

class managingPrinting
{
    private : 
        const std::string AnswerEqualString = "answer : ";
        const std::string Blank             = std::string(AnswerEqualString.size(),' ');
        
        void PrintAnswer(int t)         {std::cout << t;}
        void PrintAnswer(char t)        {std::cout <<'\''<< t << '\'';}
        void PrintAnswer(std::string t) {std::cout <<'\"'<< t << '\"';}
        void PrintAnswer(long long t)   {std::cout << t;}
        void PrintAnswer(double t)      {std::cout << t;}
        void PrintAnswer(bool t)
        {
            if(t) std::cout << "true";
            else  std::cout << "false";
        }
        template<class T>
        void PrintVector(std::vector<T>& t)
        {
            size_t count = t.size();
            for(T e : t)
            {
                PrintAnswer(e);
                if(--count != 0) std::cout << ", ";
            }
        }
        void PrintAnswer(std::vector<int>& t)         {PrintVector<int>(t);}
        void PrintAnswer(std::vector<std::string>& t) {PrintVector<std::string>(t);}
        void PrintAnswer(std::vector<long long>& t)   {PrintVector<long long>(t);}
        void PrintAnswer(std::vector<double>& t)      {PrintVector<double>(t);}
        void PrintAnswer(std::vector<bool>& t)        {PrintVector<bool>(t);}
        template<class T>
        void PrintMatrix(std::vector<T>& t)
        {
            size_t count = t.size();
            for(T& v : t)
            {
                PrintAnswer(v); 
                if(--count != 0) std::cout << std::endl << Blank;
            }
        }
        void PrintAnswer(std::vector<std::vector<int>>& t)         {PrintMatrix<std::vector<int>>(t);}
        void PrintAnswer(std::vector<std::vector<std::string>>& t) {PrintMatrix<std::vector<std::string>>(t);}
        void PrintAnswer(std::vector<std::vector<long long>>& t)   {PrintMatrix<std::vector<long long>>(t);}
        void PrintAnswer(std::vector<std::vector<double>>& t)      {PrintMatrix<std::vector<double>>(t);}
        void PrintAnswer(std::vector<std::vector<bool>>& t)        {PrintMatrix<std::vector<bool>>(t);}  
    public :
        managingPrinting(){}
        ~managingPrinting(){}

        template<class T>
        void printReturn(T& t)
        {
            std::cout << AnswerEqualString;
            PrintAnswer(t);
            std::cout << std::endl;
            return;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class parsingArguments
{
    private :
        template<class T>
        std::tuple<T> oneArgumentToTuple(std::string&& arguments){
            return make_tuple(T{});
        }
        template<> std::tuple<int>         oneArgumentToTuple<int>         (std::string&& arguments){return std::make_tuple(stoi(std::move(arguments)));}
        template<> std::tuple<long long>   oneArgumentToTuple<long long>   (std::string&& arguments){return std::make_tuple(stoll(std::move(arguments)));}
        template<> std::tuple<double>      oneArgumentToTuple<double>      (std::string&& arguments){return std::make_tuple(stod(std::move(arguments)));}
        template<> std::tuple<char>        oneArgumentToTuple<char>        (std::string&& arguments){return std::make_tuple(arguments[1]);}
        template<> std::tuple<std::string> oneArgumentToTuple<std::string> (std::string&& arguments){return std::make_tuple(arguments.substr(1,arguments.size()-2));}
        template<> std::tuple<bool>        oneArgumentToTuple<bool>        (std::string&& arguments)
        {
            if(arguments == "true")
                return std::make_tuple(true);
            return std::make_tuple(false);
        }

        template<class T>
        std::vector<T> stringToVector(std::string&& str)
        {
            std::vector<T> v;
            int commaPos = 0;
            for(int i = 1 ; i < str.size() ; ++i)
                if(str[i] == ',' || i == str.size()-1)
                {
                    v.push_back(get<0>(oneArgumentToTuple<T>(str.substr(commaPos+1,i-commaPos-1))));
                    commaPos = i;
                }
            return v;
        }
        template<> std::tuple<std::vector<int>>         oneArgumentToTuple<std::vector<int>>         (std::string&& arguments){return make_tuple(stringToVector<int>         (std::move(arguments)));}
        template<> std::tuple<std::vector<long long>>   oneArgumentToTuple<std::vector<long long>>   (std::string&& arguments){return make_tuple(stringToVector<long long>   (std::move(arguments)));}
        template<> std::tuple<std::vector<double>>      oneArgumentToTuple<std::vector<double>>      (std::string&& arguments){return make_tuple(stringToVector<double>      (std::move(arguments)));}
        template<> std::tuple<std::vector<std::string>> oneArgumentToTuple<std::vector<std::string>> (std::string&& arguments){return make_tuple(stringToVector<std::string> (std::move(arguments)));}
        template<> std::tuple<std::vector<bool>>        oneArgumentToTuple<std::vector<bool>>        (std::string&& arguments){return make_tuple(stringToVector<bool>        (std::move(arguments)));}

        template<class T>
        std::vector<std::vector<T>> stringToMatrix(std::string&& str)
        {
            std::vector<std::vector<T>> v;
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
        template<> std::tuple<std::vector<std::vector<int>>>         oneArgumentToTuple<std::vector<std::vector<int>>>         (std::string&& arguments){return make_tuple(stringToMatrix<int>         (std::move(arguments)));}
        template<> std::tuple<std::vector<std::vector<long long>>>   oneArgumentToTuple<std::vector<std::vector<long long>>>   (std::string&& arguments){return make_tuple(stringToMatrix<long long>   (std::move(arguments)));}
        template<> std::tuple<std::vector<std::vector<double>>>      oneArgumentToTuple<std::vector<std::vector<double>>>      (std::string&& arguments){return make_tuple(stringToMatrix<double>      (std::move(arguments)));}
        template<> std::tuple<std::vector<std::vector<std::string>>> oneArgumentToTuple<std::vector<std::vector<std::string>>> (std::string&& arguments){return make_tuple(stringToMatrix<std::string> (std::move(arguments)));}
        template<> std::tuple<std::vector<std::vector<bool>>>        oneArgumentToTuple<std::vector<std::vector<bool>>>        (std::string&& arguments){return make_tuple(stringToMatrix<bool>        (std::move(arguments)));}
        
    public :
        parsingArguments(){}
        ~parsingArguments(){}

        template<class T, class ...Q>
        std::tuple<T, Q...> argumentsToTuple(std::string&& arguments)
        {
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
                    isString ^= true;
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
                    oneArgumentToTuple<T>    (arguments.substr(0,commaPos)),
                    oneArgumentToTuple<Q...> (arguments.substr(commaPos+1))
                );
            else if constexpr (sizeof ...(Q) > 1)
                return tuple_cat(
                    oneArgumentToTuple<T>  (arguments.substr(0,commaPos)),
                    argumentsToTuple<Q...> (arguments.substr(commaPos+1))
                );
        }

        std::string parse(std::string&& str)
        {
            bool isString = false;
            std::string newStr = "";
            for(int i = 0 ; i < str.size() ; ++i)
            {
                if(isString && str[i] == ' ' || str[i] != ' ')
                    newStr.push_back(str[i]);
                if(str[i] == '\"' || str[i] == '\'')
                    isString ^= true;
            }
            return newStr;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class... ARG, class FUNC>
void printFunctionReturn(FUNC&& f, std::string&& args)
{
    managingPrinting MP;
    parsingArguments MA;
    try
    {
        auto answer = apply(f,MA.argumentsToTuple<ARG...>(MA.parse(std::move(args))));//2abcdede//
        MP.printReturn(answer);
    }
    catch(const std::exception& e)
    {
        std::cout << "Typed arguments caused Error : " << std::endl;
        std::cout << "Review your arguments" << std::endl;
    }
    return;
}
