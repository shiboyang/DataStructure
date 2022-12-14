//
// Created by shiby on 22-9-25.
//

#include "lib.h"

int main() {
    string filename = "../InputFile.txt";
    int input_base = 16;
    int output_base = 10;
    vector<int> num_list1, num_list2;
    vector<int> result_list;
    string tmp_str;

    ifstream ifs(filename, ios::in);

    if (!ifs.is_open()) {
        cout << "Cannot open file " << filename << endl;
        exit(-1);
    }

    getline(ifs, tmp_str);
    if (!verify_input_line(tmp_str, input_base)) {
        std::cout << "Convert to number failed: " << tmp_str << endl;
        exit(EXIT_FAILURE);
    }

    auto sign1 = (is_operator(tmp_str[0])) ? tmp_str[0] : '+';
    num_list1 = string2vector(tmp_str);

    getline(ifs, tmp_str);
    if (!verify_input_line(tmp_str, input_base)) {
        std::cout << "Convert to number failed: " << tmp_str << endl;
        exit(EXIT_FAILURE);
    }
    auto sign2 = (is_operator(tmp_str[0])) ? tmp_str[0] : '+';
    num_list2 = string2vector(tmp_str);

    auto sign = (num_list1.size() >= num_list2.size()) ? sign1 : sign2;
    auto ope = (sign1 == sign2 ? '+' : '-');
    result_list = operate_vector(num_list1, num_list2, input_base, ope);

    print_vector(result_list, sign, output_base, input_base);

    return 0;
}

