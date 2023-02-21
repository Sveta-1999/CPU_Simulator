#include "F_CPU.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> F_CPU::parsing(std::string str)
{
    std::vector<std::string> vec_str;
    std::string tmp;
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] != ' ')
        {
            tmp.push_back(str[i]);
        }
        else
        {
            vec_str.push_back(tmp);
            tmp = "";
        }
    }
    return vec_str;
}

int F_CPU::stringToInteger(std::string str)
{
    int tmp = 0;
    for (int i = 0; i < str.length(); i++) 
    {
        tmp = tmp * 10 + (str[i] - '0');
    }
    return tmp;
}

std::string F_CPU::comma_str(std::vector<std::string> str1)
{
    std::string str = str1[1];
    if(str[str.size() - 1] == ',')
    {
        str.erase(str.size() - 1, 1);
    }
    return str;
}

void F_CPU::mov_function(std::vector<std::string> str1)
{
    std::string str = comma_str(str1);
    bool flag = false;
    for(int i = 0; i < m_registers.size(); ++i)
    {
        if(str == m_registers[i].first)
        {
            m_registers[i].second = stringToInteger(str1[2]);
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        std::cout << "ERROR!!!!!" << std::endl;
    }
}

void F_CPU::print_function(std::vector<std::string> str1)
{
    bool flag = false;
    for(int i = 0; i < m_registers.size(); ++i)
    {
        if(str1[1] == m_registers[i].first)
        {
            std::cout << m_registers[i].second << std::endl;
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void F_CPU::add_function(std::vector<std::string> str1)
{ 
    std::string str_ = str1[2];
    std::string str = comma_str(str1);
    bool flag = false;
    for(int i = 0; i < m_registers.size(); ++i)
    {
        for(int j = 0; j < m_registers.size(); ++j)
        {
            if(str == m_registers[i].first)
            {
                if(str_ == m_registers[j].first)
                {
                    m_registers[i].second += m_registers[j].second;
                    flag = true;
                }
                else
                {
                    m_registers[i].second += stringToInteger(str1[2]);
                    flag = true;
                    break;
                }
            }
        }
    }
    if(!flag)
    {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void F_CPU::sub_function(std::vector<std::string> str1)
{
    std::string str_ = str1[2];
    std::string str = comma_str(str1);
    bool flag = false;
    for(int i = 0; i < m_registers.size(); ++i)
    {
        for(int j = 0; j < m_registers.size(); ++j)
        {
            if(str == m_registers[i].first)
            {
                if(str_ == m_registers[j].first)
                {
                    m_registers[i].second -= m_registers[j].second;
                    flag = true;
                    break;
                }
                else
                {
                    m_registers[i].second -= stringToInteger(str1[2]);
                    flag = true;
                    break;
                }
            }
        }
    }
    if(!flag)
    {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void F_CPU::div_function(std::vector<std::string> str1)
{
    std::string str_ = str1[2];
    std::string str = comma_str(str1);
    bool flag = false;
    for(int i = 0; i < m_registers.size(); ++i)
    {
        for(int j = 0; j < m_registers.size(); ++j)
        {
            if(str == m_registers[i].first)
            {
                if(str_ == m_registers[j].first)
                {
                    m_registers[i].second /=  m_registers[j].second;
                    flag = true;
                    break;
                }
                else
                {
                    m_registers[i].second /=  stringToInteger(str1[2]);
                    flag = true;
                    break;
                }
            }
        }
    }
    if(!flag)
    {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void F_CPU::mul_function(std::vector<std::string> str1)
{   
    std::string str_ = str1[2];
    std::string str = comma_str(str1);
    bool flag = false;
    for(int i = 0; i < m_registers.size(); ++i)
    {
        for(int j = 0; j < m_registers.size(); ++j)
        {
            if(str == m_registers[i].first)
            {
                if(str_ == m_registers[j].first)
                {
                    m_registers[i].second *= m_registers[j].second;
                    flag = true;
                    break;
                }
                else
                {
                    m_registers[i].second *= stringToInteger(str1[2]);
                    flag = true;
                    break;
                }
            }
        }
    }
    if(!flag)
    {
        std::cout << "ERROR!!!" << std::endl;
    }
}

bool F_CPU::and_function(std::vector<std::string> str1)
{
    std::string str = comma_str(str1);
    for(int i = 0; i < m_registers.size(); ++i)
    {
        for(int j = 0; j < m_registers.size(); ++j)
        {
            if(str == m_registers[i].first)
            {
                if(str1[2] == m_registers[j].first)
                {
                    if((m_registers[i].second != 0) && (m_registers[j].second != 0))
                    {
                        return true;
                    }
                }
                else
                {
                    if((m_registers[i].second != 0) && (stringToInteger(str1[2]) != 0))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool F_CPU::or_function(std::vector<std::string> str1)
{
    std::string str = comma_str(str1);
    for(int i = 0; i < m_registers.size(); ++i)
    {
        for(int j = 0; j < m_registers.size(); ++j)
        {
            if(str == m_registers[i].first)
            {
                if(str1[2] == m_registers[j].first)
                {
                    if((m_registers[i].second == 0) && (m_registers[j].second == 0))
                    {
                        return false;
                    }
                }
                else
                {
                    if((m_registers[i].second == 0) && (stringToInteger(str1[2]) == 0))
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

std::vector<std::string> F_CPU::label_name(std::vector<std::string> vec)
{
    std::vector<std::string> label_vec;
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[i].size(); ++i)
        {
            if(vec[i][vec[i].size() - 1] == ':')
            {
                label_vec.push_back(vec[i]);
            }
        }
    }
    return label_vec;
}

void F_CPU::jmp_function(std::vector<std::string> str1)
{
    std::vector<std::string> vec;
    vec = label_name(str1);
    fin.close();
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
}

void F_CPU::cmp_function(std::vector<std::string> str1)
{
    //flagneri mej pahel nshani ev zro_falg@ u drancov haskanal inch jump kkatari
    std::string str = comma_str(str1);
    for(int i = 0; i < m_registers.size(); ++i)
    {
        if(str == m_registers[i].first)
        {
            if(str1[2] == m_registers[i].first)
            {
                if(m_registers[i].second == m_registers[i].second)
                {
                    je_function(str1);
                }
            }
        }
        // else if(str1[2] == m_registers[i].first)
        // {

        // }
        // else if()
        // if(stringToInteger(str1[1]) == stringToInteger(str1[2]))
        // {

        // }
    }
    
}

void F_CPU::je_function(std::vector<std::string> str1)
{
    fin.close();
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
}

void F_CPU::inc_function(std::vector<std::string> str1)
{
    bool flag = false;
    for(int i = 0; i < m_registers.size(); ++i)
    {
        if(str1[1] == m_registers[i].first)
        {
            m_registers[i].second += 1;
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void F_CPU::glob_function()
{
    std::string str1 {};
    while(!fin.eof())
    {
        std::getline(fin, str1);
        std::vector<std::string> vec_line;
        vec_line = parsing(str1);
        for(int i = 0; i < vec_line.size(); ++i)
        {
             if(vec_line[i] == m_keyword[0])
            {
                mov_function(vec_line);
                break;
            }
            else if(vec_line[i] == m_keyword[1])
            {
                add_function(vec_line);
                break;
            }
            else if(vec_line[i] == m_keyword[2])
            {
                sub_function(vec_line);
                break;
            }
            else if(vec_line[i] == m_keyword[3])
            {
                div_function(vec_line);
                break;
            }
            else if(vec_line[i] == m_keyword[4])
            {
                mul_function(vec_line);
                break;
            }
            else if(vec_line[i] == m_keyword[5])
            {
                std::cout << and_function(vec_line);
                break;
            }
            else if(vec_line[i] == m_keyword[6])
            {
                std::cout << or_function(vec_line);
                break;
            }
            else if(vec_line[i] == m_keyword[7])
            {
                cmp_function(vec_line);
            }
            else if(vec_line[i] == m_keyword[8])
            {
                jmp_function(vec_line);
            }
            else if(vec_line[i] == m_keyword[9])
            {
                print_function(vec_line);
            }
            else if(vec_line[i] == m_keyword[10])
            {
                inc_function(vec_line);
            }
            else
            {
                std::vector<std::string> vec1;
                vec1 = label_name(vec_line);
            }
        }
    }
}

