#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cout << "Введите n: ";
    cin >> n;

    vector<vector<int>>matrix(n, vector<int>(n));
    int up = 0;
    int down = n-1;
    int right = n-1;
    int left = 0;
    int num = 1;

    while (up <= down && left <= right){
        //заполение верхней строки
        for (int i = left; i <= right; ++i){
            matrix[up][i] = num++;
        }
        up += 1;

        //заполнение правого столбца
        for (int i = up; i <= down; ++i){
            matrix[i][right] = num++;
        }
        right-=1;

        //заполнение нижней строки
        if (up <= down){
            for (int i = right; i >= left; --i){
                matrix[down][i] = num++;
            }
            down -= 1;
        }

        //заполнение левого столбца
        if (left <= right){
            for(int i = down; i >= up; --i){
                matrix[i][left] = num++;
            }
            left += 1;
        }
    }


    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

