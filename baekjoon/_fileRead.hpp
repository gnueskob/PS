#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

namespace GNUES
{
    class FileRead
    {
    public:
        FileRead() = delete;
        FileRead(const std::string &filename)
        {
            auto path = makeInputFilePath(filename);

            //prepare f to throw if failbit gets set
            std::ios_base::iostate exceptionMask = _file.exceptions() | std::ios::failbit;
            _file.exceptions(exceptionMask);

            try
            {
                _file.open(path);
            }
            catch (std::ios_base::failure &e)
            {
                std::cerr << e.what() << '\n';
            }

            if (_file.is_open() == false)
            {
                std::cout << "File read fail.. err[" << strerror(errno) << "], path[" << path << "]";
                return;
            }

            // std::ifstream 객체가 계속 살아있어야 함
            _cin_buf = std::cin.rdbuf(_file.rdbuf()); // swap
        }

        virtual ~FileRead()
        {
            if (_cin_buf)
                std::cin.rdbuf(_cin_buf);
        }

    private:
        std::string makeInputFilePath(const std::string &filename)
        {
            // 현재는 baekjoon/input/_.txt 형식으로 input text 파일 존재
            // _fileRead 위치에서 ./input/_.txt 전환

            // 지금.. working dir 설정이 vs code 연 폴더 기준으로 되어있기 때문에
            // baekjoon 폴더 기준으로 열었을 때와 PS 기준으로 열었을 때가 달라야함
            // (1) .\\PS\\baekjoon\\input\\___.txt
            // (2) .\\baekjoon\\input\\___.txt

            // 어차피 폴더설정은 내가 직접 하는거니까 여기에 직접 핸들링해주기
            std::string cwd = std::filesystem::current_path().string();
            std::vector cwd_split = split(cwd, '\\');
            if (*cwd_split.rbegin() == "PS")
                cwd += "\\baekjoon";

            return cwd + "\\input\\" + filename;
        }

        std::vector<std::string> split(std::string input, char delimiter)
        {
            std::vector<std::string> answer;
            std::stringstream ss(input);
            std::string temp;

            while (getline(ss, temp, delimiter))
            {
                answer.push_back(temp);
            }

            return answer;
        }

    private:
        std::ifstream _file;
        std::streambuf *_cin_buf = nullptr;
    };
} // namespace GNUES
