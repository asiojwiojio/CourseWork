#include <iostream>
#include <string>
using std::string;
#include <cmath>

// 函数声明，用于将不同单位的长度转换为厘米
float ToCentimeters(float length, const string& unit);

float ToCentimeters(float length, const string& unit) {
    if (unit == "m") {
        return length * 100; // 米转换为厘米
    }
    else if (unit == "dm") {
        return length * 10; // 分米转换为厘米
    }
    else if (unit == "cm") {
        return length; // 厘米保持不变
    }
    else {
        return -1; // 错误的单位返回-1
    }
}

int main() {
    float length1, length2, length3, len4, hig;
    string unit1, unit2;

    // 获取用户输入
    std::cout << "Enter the length and unit of the first side (m, cm, dm): ";
    std::cin >> length1 >> unit1;
    std::cout << "Enter the length and unit of the second side (m, cm, dm): ";
    std::cin >> length2 >> unit2;

    // 转换为厘米
    length1 = ToCentimeters(length1, unit1);
    length2 = ToCentimeters(length2, unit2);

    // 验证输入的有效性float
    if (length1 <= 0 || length2 <= 0) {
        std::cout << "Error! The value entered is less than 0!" << std::endl;
    }
    else if (unit1 != "m" && unit1 != "cm" && unit1 != "dm" || unit2 != "m" && unit2 != "cm" && unit2 != "dm") {
        std::cout << "Error! The unit entered is not supported by the program!" << std::endl;
    }
    else if (length1 < 10 || length2 < 10) {
        std::cout << "Error! The length is less than 10 cm!" << std::endl;
    }
    else if (length1 < length2 * 0.1 || length2 < length1 * 0.1) {
        std::cout << "Error! One length is less than 10% of the other!" << std::endl;
    }
    else {
        // 计算第三边范围
        float min_length = std::abs(length1 - length2);
        float max_length = length1 + length2;
        // 生成随机浮点数
        float length3 = min_length + static_cast<float>(std::rand()) / RAND_MAX * (max_length - min_length);
        // 输出长度
        std::cout << "Display1" << std::endl;
        std::cout << "Edge length 1 (input 1): " << length1 << " cm" << std::endl;
        std::cout << "Edge length 2 (input 2): " << length2 << " cm" << std::endl;
        std::cout << "Edge length 3 (rand): " << length3 << " cm" << std::endl;
        //输出面积
        std::cout << "The area of triangle is: " << std::sqrt((length1 + length2 + length3)*(length1 + length2 - length3)*(length1 + length3 - length2)*(length3 + length2 - length1))/4 << "cm2" << std::endl;
        std::cout << "The height of triangle is: " << (std::sqrt((length1 + length2 + length3)*(length1 + length2 - length3)*(length1 + length3 - length2)*(length3 + length2 - length1))/2) / std::max(std::max(length1, length2), std::max(length2, length3)) << "cm" << std::endl;
        //取最长边
        len4 = (std::max(std::max(length1, length2), std::max(length2, length3)))/2;
        hig = (std::sqrt((length1 + length2 + length3)*(length1 + length2 - length3)*(length1 + length3 - length2)*(length3 + length2 - length1))/2) / std::max(std::max(length1, length2), std::max(length2, length3));
        while (len4 >= 10) { 
            len4 /= 10;
        }
        while (hig >= 10) {
            hig /= 10;
        }
        for (int i = 1; i <= len4; ++i) {
            int stars_count = (hig * i) / len4;
            for (int j = 0; j < stars_count; ++j) {
            std::cout << "*";
            }
            std::cout << std::endl;
        }
    return 0;
}