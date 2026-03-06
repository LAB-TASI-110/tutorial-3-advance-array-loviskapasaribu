//12S25016 - Loviska Astria Pasaribu

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Membaca jumlah nilai (n)

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score); // Membaca setiap nilai
        sum += score;        // Menambahkan nilai ke total
    }

    double average = (double)sum / n; // Menghitung rata-rata
                                      // Casting sum ke double untuk presisi
    printf("%d\n", sum);
    printf("%.2f\n", average); // Menampilkan rata-rata dengan 2 digit presisi

    return 0;
}

