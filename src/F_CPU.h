#ifndef F_CPU_
#define F_CPU_

#include <vector>
#include <utility>
#include <fstream>

class F_CPU {
public:
    F_CPU()
        :   m_keyword{"mov", "add", "sub", "div", "mul", "and", "or", "cmp", "jmp", "print", "inc" }
        ,   m_registers{{"reg_1",0}, {"reg_2", 0}, {"reg_3", 0}, {"reg_4", 0}, {"reg_5", 0},
                    {"reg_6", 0}, {"reg_7", 0}, {"reg_8",0}, {"reg_9", 0}, {"reg_10", 0}}
        ,   m_EFLAGS{{"je", 0}, {"jle",0}, {"jge",0}, {"jg",0}, {"jl",0}}
    {
        std::string path1 = "F_CPU.txt";
        fin.open(path1);
        if(fin.is_open() )
        {
            std::cout << "File is open." << std::endl ;   
        }
        else
        {
            std::cout << "ERROR!!!" << std::endl;
        }
    };
    void glob_function();
    void mov_function(std::vector<std::string>);
    void add_function(std::vector<std::string>);
    void sub_function(std::vector<std::string>);
    void div_function(std::vector<std::string>);
    void mul_function(std::vector<std::string>);
    bool and_function(std::vector<std::string>);
    bool or_function(std::vector<std::string>);
    void cmp_function(std::vector<std::string>);
    void jmp_function(std::vector<std::string>);
    void print_function(std::vector<std::string>);
    void inc_function(std::vector<std::string>);
    void je_function(std::vector<std::string>);

    ~F_CPU()
    {
        fin.close();
    };

private:
    std::vector<std::string> parsing(std::string);
    int stringToInteger(std::string);
    std::string comma_str(std::vector<std::string>);
    std::vector<std::string> label_name(std::vector<std::string>);
    std::vector<std::string> m_keyword;
    std::vector<std::pair<std::string, int> > m_registers;
    std::vector<std::pair<std::string, bool> > m_EFLAGS;
    std::fstream fin;
};

#endif // F_CPU_