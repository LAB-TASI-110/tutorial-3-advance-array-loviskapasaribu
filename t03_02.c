#include <stdio.h>
#include <stdlib.h> // Diperlukan untuk malloc dan free

int main() {
    int n, i;
    int *scores; // Menggunakan array dinamis untuk menyimpan nilai
    long long sum = 0;
    double average;
    int count_above_average = 0;

    // Membaca jumlah nilai (n)
    scanf("%d", &n);

    // Mengalokasikan memori untuk menyimpan nilai-nilai
    scores = (int *)malloc(n * sizeof(int));
    if (scores == NULL) {
        // Penanganan error jika alokasi memori gagal
        return 1;
    }

    // Membaca n nilai dan menghitung jumlahnya
    for (i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
        sum += scores[i];
    }

    // Menghitung rata-rata
    if (n > 0) {
        average = (double)sum / n;
    } else {
        average = 0.0; // Menghindari pembagian dengan nol jika n adalah 0
    }

    // Menampilkan jumlah seluruh nilai
    printf("%lld\n", sum);

    // Menampilkan nilai rata-rata dengan 2 digit presisi
    printf("%.2f\n", average);

    // Menghitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    for (i = 0; i < n; i++) {
        if (scores[i] >= average) {
            count_above_average++;
        }
    }

    // Menampilkan banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    printf("%d\n", count_above_average);

    // Membebaskan memori yang dialokasikan
    free(scores);

    return 0;
}
