#include <iostream>

struct S{
    int a;
    int b;
    int c;
};

void sort(S array[], int n, bool (*compare) (S, S)){
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(compare(array[i], array[j])){
                S temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void print(S array[], int n){
    for(int i = 0; i < n; ++i){
        std::cout << array[i].a << ", " << array[i].b << ", " << array[i].c << "\n";
    }
}

bool compare1(S s1, S s2){
    return (s1.a > s2.a && s1.b > s2.b && s1.c > s2.c);
}

bool compare2(S s1, S s2){
    return (s1.a < s2.a && s1.b < s2.b && s1.c < s2.c);
}

bool compare3(S s1, S s2){
    return (s1.a > s2.a && s1.b < s2.b && s1.c > s2.c);
}

bool compare4(S s1, S s2){
    return (s1.a == s2.a && s1.b == s2.b && s1.c == s2.c);
}

bool compare5(S s1, S s2){
    return (s1.a == 10 && s1.b > s2.b && s1.c > s2.c);
}


int main(){
    S s1, s2, s3, s4, s5;
    s1.a = 1;
    s1.b = 2;
    s1.c = 3;

    s2.a = 10;
    s2.b = 20;
    s2.c = 30;

    s3.a = 100;
    s3.b = 200;
    s3.c = 300;

    s4.a = 1000;
    s4.b = 2000;
    s4.c = 3000;

    s5.a = 10000;
    s5.b = 20000;
    s5.c = 30000;

    int n = 5;
    S array[n] = {s1, s2, s3, s4, s5};

    sort(array, n, compare3);
    print(array, n);

    return 0;
}