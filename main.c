#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan data login
typedef struct {
    char username[50];
    char password[50];
} Login;

// Fungsi untuk mendaftarkan user
void registerUser() {
    FILE *file = fopen("database/login.bin", "ab");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    Login newUser;
    printf("=== Register ===\n");
    printf("Masukkan username: ");
    scanf("%s", newUser.username);
    printf("Masukkan password: ");
    scanf("%s", newUser.password);

    fwrite(&newUser, sizeof(Login), 1, file);
    fclose(file);

    printf("Registrasi berhasil! Silakan login.\n");
}

// Fungsi untuk login user
int loginUser() {
    FILE *file = fopen("database/login.bin", "rb");
    if (file == NULL) {
        printf("Belum ada user yang terdaftar. Silakan register terlebih dahulu.\n");
        return 0;
    }

    char username[50], password[50];
    Login user;
    int loginSuccess = 0;

    printf("=== Login ===\n");
    printf("Masukkan username: ");
    scanf("%s", username);
    printf("Masukkan password: ");
    scanf("%s", password);

    while (fread(&user, sizeof(Login), 1, file)) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            loginSuccess = 1;
            break;
        }
    }

    fclose(file);

    if (loginSuccess) {
        printf("Login berhasil! Selamat datang, %s.\n", username);
        return 1;
    } else {
        printf("Username atau password salah.\n");
        return 0;
    }
}
int peraturan(){
    printf("============== Peraturan Quiz Who Wants to Be Millionaire ==============\n");
    printf("1.Quiz ini terdiri dari 2 tipe soal dimana user bebas memilih jenis soal\n");
    printf("2.Setiap soal memiliki bobot hadiah yang meningkat, diiringi dengan soal yang semakin susah\n");
    printf("3.Jika pemain salah dalam menjawab soal, maka ia tidak bisa melanjutkan soal berikutnya dan hanya membawa pulang hadiah sesuai jumlah soal yang dijawab\n");
    printf("4. Tidak ada fitur bantuan dalam game ini, pemain hanya bergantung pada pengetahuannya\n");
    printf("========================================================================\n");

    return 0;
}

// Fungsi untuk memulai kuis
void startQuiz() {
    int score = 0;
    int answer;

    printf("=== Kuis Dimulai ===\n");
    printf("Soal jenis apa yang hendak anda ikuti?\n");
    int soal;
    printf("1) Soal Geografi\n");
    printf("2) Soal kewarganegaraan\n");
    scanf("%d",&soal);

    switch(soal){
        case 1 :
            printf("1. (soal nomor 1)?\n");
            printf("1) 3\n2) 4\n3) 5\n");
            printf("Jawaban Anda: ");
            scanf("%d", &answer);
            if (answer == 2)score++;
            else if( answer != 2 )
            {
                printf("\nKuis selesai! Skor Anda: %d/3\n", score);
                break;
            }

            printf("2. (Soal nomor 2)?\n");
            printf("1) Thomas Edison\n2) Albert Einstein\n3) Nikola Tesla\n");
            printf("Jawaban Anda: ");
            scanf("%d", &answer);
            if (answer == 1) score++;
            else if( answer != 1 )
            {
                printf("\nKuis selesai! Skor Anda: %d/3\n", score);
                break;
            }
            printf("\nKuis selesai! Skor Anda: %d/3\n", score);
            break;

        case 2 :

            printf("3. (soal nomor 3)?\n");
            printf("1) Jakarta\n2) Bandung\n3) Surabaya\n");
            printf("Jawaban Anda: ");
            scanf("%d", &answer);
            if (answer == 1) score++;
            else if( answer != 2 )
            {
                printf("\nKuis selesai! Skor Anda: %d/3\n", score);
                break;
            }
            printf("\nKuis selesai! Skor Anda: %d/3\n", score);
            break;

        default :
            printf("Pilih salah satu diantara keduanya!");
            break;

    }
    
}

// Fungsi utama
int main() {
    int choice;
    int loggedIn = 0;

        do {
            printf("\n=== Menu ===\n");
            printf("1. Register\n");
            printf("2. Login\n");
            printf("3. Peraturan Kuis\n");
            printf("4. Mulai Kuis\n");
            printf("5. Keluar\n");
            printf("Pilihan Anda: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    registerUser();
                    break;
                case 2:
                    loggedIn = loginUser();
                    break;
                case 3:
                    peraturan();
                    break;    
                case 4:
                    if (loggedIn) {
                        startQuiz();
                    } else {
                        printf("Silakan login terlebih dahulu.\n");
                    }
                    break;
                case 5:
                    printf("Terima kasih telah menggunakan program ini!\n");
                    break;
                default:
                    printf("Pilihan tidak valid.\n");
            }
        } while (choice != 5);
    

    return 0;
}
