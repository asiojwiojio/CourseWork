#include <iostream>
#include <string>
using std::string;
#include <vector>

// 模拟数据库中的菜品和价格
struct Dish {
    string code;
    string name;
    float price;
};

// 菜品数据库
std::vector<Dish> dishes = {
    {"A1", "HAM AND EGG", 20},
    {"A2", "BACON AND CHEESE", 10},
    {"A3", "TUNA SALAD", 15},
    {"A4", "BEFF SOUP", 25},
    {"B1", "SPICY BEEF BARBECUE", 20},
    {"B2", "PPORK BARBCUE", 10},
    {"B3", "OVEN CHICKEN BARBECUE", 15},
    {"B4", "PULLED BEEF BARBECUE BURGER", 25},
    {"C1", "SPICY PORK BARBECUE", 20},
    {"C2", "VEGETABLE PORK BARBECUE", 10},
    {"C3", "OVEN PORK BARBECUE", 15},
    {"C4", "PULLED PORK BARBECUE", 25}
};

// 搜索菜品
Dish* search_dish_by_code(const string& code) {
    for (auto& dish : dishes) {
        if (dish.code == code) {
            return &dish;
        }
    }
    return nullptr;
}

int main() {
    // 输入密码
    string password;
    std::cout << "Enter password: ";
    std::cin >> password;
    // 验证密码，假设密码是20123456
    if (password != "20123456") {
        std::cout << "Wrong password!" << std::endl;
        return 1;
    }

    // 显示用户名
    std::cout << "Welcome John Doe" << std::endl;

    // 输入顾客数量
    int customer_count;
    std::cout << "Enter customer count(1-6): ";
    std::cin >> customer_count;
    if (customer_count < 1 || customer_count > 6) {
        std::cout << "Out of range !" << std::endl;
        return 1;
    }

    // 保存每位顾客的订单
    std::vector<std::vector<Dish>> orders(customer_count);

    // 输入菜品代码
    for (int i = 0; i < customer_count; ++i) {
        std::cout << "Customer number  " << (i + 1) << "'s dish code, press 'F' to finish." << std::endl;
        string code;
        while (std::cin >> code && code != "F") {
        Dish* dish = search_dish_by_code(code);
            if (dish) {
                orders[i].push_back(*dish);
            }
            else {
                std::cout << "This dish code does not exist! Try again! " << std::endl;
            }
        }
    }

    // 显示收据
    float total_cost = 0;
    std::cout << "THANK YOU FOR DINING HERE!" << std::endl;
    std::cout << "Here is your receipt:" << std::endl;
    for (int i = 0; i < customer_count; ++i) {
        std::cout << "Customer number " << (i + 1) << ": " << std::endl;
        for (auto& dish : orders[i]) {
            std::cout << dish.code << " " << dish.name << "  " << dish.price << std::endl;
            total_cost += dish.price;
        }
    }
    std::cout << "TOTAL COST: " << total_cost << std::endl;

    // 输入收款
    float cash_received;
    std::cout << "Cash Received: ";
    std::cin >> cash_received;
    while (cash_received < total_cost) {
        std::cout << "Not enough! Try again! ";
        std::cin >> cash_received;
    }

    // 显示找零
    double change = cash_received - total_cost;
    std::cout << "Change Given: " << change << std::endl;

    return 0;
}
