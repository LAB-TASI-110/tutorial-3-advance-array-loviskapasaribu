#include <stdio.h>
#include <stdlib.h> // Diperlukan untuk malloc dan free
#include <limits.h> // Diperlukan untuk INT_MIN dan INT_MAX

int main() {
    int n, i;
    int *scores; // Menggunakan array dinamis untuk menyimpan nilai
    long long sum = 0;
    double average;
    int count_above_average = 0;
    int min_val = INT_MAX; // Inisialisasi dengan nilai maksimum integer
    int max_val = INT_MIN; // Inisialisasi dengan nilai minimum integer

    // Membaca jumlah nilai (n)
    scanf("%d", &n);

    // Mengalokasikan memori untuk menyimpan nilai-nilai
    scores = (int *)malloc(n * sizeof(int));
    if (scores == NULL) {
        // Penanganan error jika alokasi memori gagal
        fprintf(stderr, "Gagal mengalokasikan memori\n");
        return 1;
    }

    // Membaca n nilai, menghitung jumlahnya, serta mencari nilai min dan max
    for (i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
        sum += scores[i];

        if (scores[i] < min_val) {
            min_val = scores[i];
        }
        if (scores[i] > max_val) {
            max_val = scores[i];
        }
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

    // Menampilkan rentang nilai (maksimum - minimum)
    if (n > 0) { // Pastikan ada nilai yang dibaca sebelum menghitung rentang
        printf("%d\n", max_val - min_val);
    } else {
        printf("0\n"); // Atau penanganan lain jika tidak ada nilai
    }

    // Membebaskan memori yang dialokasikan
    free(scores);

    return 0;
}
