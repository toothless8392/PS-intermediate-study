#include<iostream>
#include<map>

int N, M;
std::map<std::string, int> stoi;
std::map<int, std::string> itos;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;
    for(int i = 0; i < N; ++i){
        std::string str;

        std::cin >> str;
        stoi.insert({str, i + 1});
        itos.insert({i + 1, str});
    }
    for(int i = 0; i < M; ++i){
        std::string str;

        std::cin >> str;
        if(str[0] >= '0' && str[0] <= '9')
            std::cout << itos[std::stoi(str)] << "\n";
        else 
            std::cout << stoi[str] << "\n";
    }

    return 0;
}
