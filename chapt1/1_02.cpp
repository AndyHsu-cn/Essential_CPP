#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string user_name;
    int user_guess;
    int num_tries;              // 总的猜测数
    int num_right;              // 总的正确数
    double user_score = 0.0;
    char user_rsp;
    char try_again;
    bool next_seq = true;       // 显示下一组数列 
    bool go_for_it = true;      // 用户想继续猜一次
    bool got_it = false;         // 用户是否猜对 
    const int max_tries = 3;

    const int seq_size = 18;
    const int max_seq = 6;
    int elem_seq[seq_size] = {
        1, 2, 3,    // Fibonacci
        3, 4, 7,    // Lucas
        2, 5, 12,   // Pell
        3, 6, 10,   // Triangular
        4, 9, 16,   // Square
        5, 12, 22   // Pentagonal
    };
    string seq_names[max_seq] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Square",
        "Pentagonal"
    };
    int cur_index = 0;


    // 用户想要继续猜某个数列
    while (next_seq == true && cur_index < seq_size)
    {
        // 显示数列的前两个数字
        std::cout << "The first 2 elements of the sequence are: "
                    << elem_seq[cur_index] << ", " << elem_seq[cur_index+1] << endl;
        std::cout << "What is the next element?";
        int tries_cnt = 0;
        next_seq = true;
        go_for_it = true;
        got_it = false;
        // 用户所猜不正确 && 用户想要再猜一次
        while(!got_it && go_for_it && (++tries_cnt <= max_tries))
        {
            std::cin >> user_guess;
            ++num_tries;
            //  如果答案正确
            if(user_guess == elem_seq[cur_index+2])
            {
                ++num_right;
                std::cout << "Very good, yes, " << elem_seq[cur_index+2]
                            << " is the next element in the "
                            << seq_names[cur_index/3] << "  sequence." << endl;
                got_it = true;
            }else{
            // 如果答案错误
                switch (tries_cnt)
                {
                case 1:
                    std::cout << "Oops, Nice guess but not quite it." << endl;
                    break;
                case 2:
                    std::cout << "Sorry, Wrong a second time!" << endl;
                    break;
                case 3:
                    std::cout << "Ah, this is harder than it looks, isn't it?" << endl;
                    break;
                default:
                    std::cout << "It must be getting pretty frustrating by now!!!" << endl;
                    break;
                }

                std::cout << "do you want to continue?(y/n):" << endl;
                std::cin >> user_rsp;
                if(user_rsp == 'N' || user_rsp == 'n')
                    go_for_it = false;
            } 
        } // 内层while结束
        std::cout  << "Want to try another sequence? (y/n)?" << endl;
        std::cin >> try_again;
        if(try_again == 'N' || try_again == 'n')
            next_seq = false;
        else
            cur_index += 3;
    }   // 外层while结束
    
    return 0;
}