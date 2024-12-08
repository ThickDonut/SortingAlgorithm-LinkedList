#include <iostream>
#include <string>
#include <stdlib.h>

struct infos{ // Chứa thông tin SV

    std::string name;
    std::string yOB;
    std::string phone;
    std::string majors[10]{"CNTT", "Chan nuoi", "Ke toan", 
    "Cong nghe Oto", "Sua chua", "lap rap may tinh",
    "Bao ve thuc vat", "Quan tri kinh Doanh", "Ky thuat Co Khi"};
    int major_confirm;

};

bool isInt(std::string str) { // Kiểm tra đầu vào, nếu là số nguyên, kết quả = true
    for (char c : str) {
        if (isdigit(c)){
            return true;
        } else {

        }
    }
    
    return false;

}

void isValid(infos& strct, int type, bool glitch) { /*Kiểm tra đầu vào cho inputs và infoFix, glitch để tạo thêm 1 lệnh
cin vì dùng hàm trong block if trong vòng lặp for làm cho 1 cin bị mất*/
    for (int i{0}; i < 1; i++) {
        std::string temp{};
        if (glitch) {
        std::getline(std::cin, temp);
        }
        std::getline(std::cin, temp);
        if(type == 0) {
            if (!isInt(temp)) {
                strct.name = temp; 
            } else {
                std::cout << "Cu phap khong hop le, moi nhap lai: ";
                i--;
                glitch = false;
            }
        } else 
        if(type == 1) {
            if (isInt(temp) && stoi(temp) <= 2008) {
                strct.yOB = temp;
            } else {
                std::cout << "Cu phap khong hop le, moi nhap lai: ";
                i--;
                glitch = false;
            }
        } else 
        if(type == 2) {
            if (isInt(temp) && temp.length() == 10) {
                strct.phone = temp; 
            } else {
                std::cout << "Cu phap khong hop le, moi nhap lai: ";
                i--;
                glitch = false;
            }
        }
        if(type == 3) {
            if (isInt(temp) && stoi(temp) < 10 && stoi(temp) > 0) {
                strct.major_confirm = stoi(temp); 
            } else {
                std::cout << "Cu phap khong hop le, moi nhap lai: ";
                i--;
                glitch = false;
            }
        }
    }

}

void displayInfos(infos& strct) { // Hiển thị thông tin SV

    std::cout << "Nhap thong tin thanh cong \n";

    std::cout << "Ho va ten: " << strct.name << std::endl <<
    "Nam sinh: " << strct.yOB << std::endl <<
    "So dien thoai: " << strct.phone << std::endl <<
    "Nganh hoc: " << strct.majors[strct.major_confirm - 1] << std::endl;
    
    std::cout << "Nhap lai thong tin, go 'N' \n"<<
    "Xoa thong tin, go 'X' \n" <<
    "Ket thuc, go 'K' \n";
}

void majorsDisplay(infos& strct) { // Hiển thị ngành
    std::cout << "| STT\t| Nganh hoc \n \n";
    for (int i{1}; i <= sizeof(strct.majors) / sizeof(strct.majors[0]) - 1; i++) {

        std::cout << "| " << i << "  \t| "  << strct.majors[i - 1] << std::endl;

    }
}

void inputs(infos& strct, bool glitch) { // Nhập thông tin
    system("cls");

    std::cout << "Moi ban nhap thong in SV \n";
    std::cout << "Nhap ho va ten: ";

    if(glitch) {

    std::getline(std::cin, strct.name);

    }
    isValid(strct, 0, false);
    std::cout << "Nhap nam sinh: ";
    isValid(strct, 1, false);
    std::cout << "Nhap so dien thoai: ";
    isValid(strct, 2, false);
    std::cout << "Nhap nganh hoc cua ban: \n";

    majorsDisplay(strct);

    std::cout << "Nhap so thu tu tu 1 - 9: \n";
    isValid(strct, 3, false);

    system("cls");

}

void infoFix(infos& input, std::string name, int type, bool glitch) { // Sửa thông tin
    system("cls");
    std::cout << name;
    isValid(input, type, glitch);
    
}

void infoDelete(std::string& input) { // Xoá thông tin

    input = "";
    system("cls");
}



int main() {
    infos inf;
    int test {1};
    
    inputs(inf, false);

    for (int j{}; j < 1; j++) {

        system("cls");

        displayInfos(inf);

        char p{};
        std::cin >> p;

        if (p == 'N') {

            system("cls");

            for (int i{}; i < 1; i++) {
            
            char p02{};
            std::cout << "Ban muon nhap lai thong tin nao? \n" <<
            "Ho va ten, go 'H' \n" <<
            "Nam sinh, go 'N' \n" <<
            "So dien thoai, go S \n" <<
            "Nganh hoc, go 'M' \n" <<
            "Nhap lai tat ca, go 'A' \n" <<
            "De quay lai, go 'R' \n";
            std::cin >> p02;

            if(p02 == 'H'){

                infoFix(inf, "Nhap ho va ten: ", 0, true);
                j--;

            } else
            if(p02 == 'N'){

                infoFix(inf, "Nhap nam sinh: ", 1, true);
                j--;

            } else
            if(p02 == 'S'){

                infoFix(inf, "Nhap so dien thoai: ", 2, true);
                j--;

            } else
            if(p02 == 'M'){
                system("cls");
                majorsDisplay(inf);
                infoFix(inf, "Nhap nganh hoc 1 - 9: ", 3, true);
                j--;

            } else
            if(p02 == 'A'){

                inputs(inf, true);
                j--;

            } else
            if(p02 == 'R'){

                j--;
                
            } else {
                std::cout << "Cu phap khong hop le \n";
                i--;
                system("cls");
            }
            }

        } else 
        if (p == 'X') {
            for (int i{0}; i < 1; i++) {
            system("cls");
            char p03{};
            std::cout << "Ban muon xoa thong tin nao? \n" <<
            "Ho va ten, go 'H' \n" <<
            "Nam sinh, go 'N' \n" <<
            "So dien thoai, go S \n" <<
            "Nganh hoc, go 'M' \n" <<
            "xoa tat ca, go 'A' \n" <<
            "De quay lai, go 'R' \n";
            std::cin >> p03;
            
                if(p03 == 'H'){
                    inf.name = "";
                    j--;
                    system("cls");
                } else
                if(p03 == 'N'){
                    inf.yOB = "";
                    j--;
                    system("cls");
                } else
                if(p03 == 'S'){
                    inf.phone = "";
                    j--;
                    system("cls");
                } else
                if(p03 == 'M'){
                    inf.major_confirm = 10;
                    j--;
                    system("cls");
                } else
                if(p03 == 'A'){
                    inf.name = "";
                    inf.yOB = "";
                    inf.phone = "";
                    inf.major_confirm = 10;
                    j--;
                    system("cls");
                } else
                if(p03 == 'R'){
                    j--;
                    system("cls");
                } else {
                    std::cout << "Cu phap khong hop le \n \n";
                    i--;
                }
            }

        } else 
        if (p == 'K') {

            system("cls");

        } else {
            std::cout << "Cu phap khong hop le \n \n";
            j--;
        }
    }
    return 0;

}