#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Рекурсивна функція для перевірки наявності пар "no" або "on"
bool CheckPair(const char* str, int i) {
    if (str[i + 1] == '\0') {
        return false;
    }
    if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n')) {
        return true;
    }
    return CheckPair(str, i + 1);
}

// Рекурсивна функція для заміни кожної пари "no" на "***"
char* ReplaceNoWithStars(char* dest, const char* str, int i, char* t) {
    if (str[i] == '\0') {
        *t = '\0';
        return dest;
    }
    if (str[i] == 'n' && str[i + 1] == 'o') {
        strcat(t, "***");
        t += 3;
        return ReplaceNoWithStars(dest, str, i + 2, t);
    }
    else {
        *t++ = str[i];
        *t = '\0';
        return ReplaceNoWithStars(dest, str, i + 1, t);
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Викликаємо функцію перевірки наявності пар
    bool hasPair = CheckPair(str, 0);
    cout << "String contains pairs 'no' or 'on': " << (hasPair ? "Yes" : "No") << endl;

    // Викликаємо функцію заміни пар "no"
    char* dest = new char[strlen(str) * 3 + 1];
    dest[0] = '\0';
    ReplaceNoWithStars(dest, str, 0, dest);

    cout << "Modified string: " << dest << endl;

    delete[] dest; // Звільняємо пам'ять
    return 0;
}

