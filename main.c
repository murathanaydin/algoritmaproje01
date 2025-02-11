#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisini kaydetmek icin bir struct olusturuyoruz
struct TarihSaat {
    int yil, ay, gun;
};

// Tarih ve epoch zamanini ayni hafizada saklamak icin union kullaniyoruz
union Zaman {
    struct TarihSaat ts; // Yapi icinde tarih ve saat verilerini sakliyoruz
    time_t epoch; // Ayni alanda epoch zamanini da sakliyoruz
};

// struct TarihSaat turundeki bir degiskeni epoch zamanina donusturen fonksiyon
time_t epochZamaninaCevir(struct TarihSaat ts) {
    struct tm zamanYapisi = {0};
    zamanYapisi.tm_year = ts.yil - 1900; // C dilinde yil 1900'den basladigi icin 1900 cikariyoruz
    zamanYapisi.tm_mon = ts.ay - 1;    // Ay 0'dan basladigi icin 1 eksiltiyoruz
    zamanYapisi.tm_mday = ts.gun;
    return mktime(&zamanYapisi); // struct tm'yi epoch zamanina ceviriyoruz
}

int main() {
    union Zaman giris, cikis;
    
    // Kullanýcýdan isçinin ise giris tarihini aliyoruz
    printf("Ise giris tarihini girin\n");
    printf("Yil: "); scanf("%d", &giris.ts.yil);
    printf("Ay: "); scanf("%d", &giris.ts.ay);
    printf("Gun: "); scanf("%d", &giris.ts.gun);
    
    // Kullanýcýdan isçinin isten cikis tarihini aliyoruz
    printf("Isten cikis tarihini girin\n");
    printf("Yil: "); scanf("%d", &cikis.ts.yil);
    printf("Ay: "); scanf("%d", &cikis.ts.ay);
    printf("Gun: "); scanf("%d", &cikis.ts.gun);
    
    // Girilen tarihleri epoch zamanina donusturuyoruz
    giris.epoch = epochZamaninaCevir(giris.ts);
    cikis.epoch = epochZamaninaCevir(cikis.ts);
    
    // Epoch zamani hesaplanamazsa hata mesaji veriyoruz
    if (giris.epoch == -1 || cikis.epoch == -1) {
        printf("Hata: Epoch zaman hesaplanamadi!\n");
        return 1;
    }
    
    // Iki tarih arasindaki gun farkini hesaplayip ekrana yazdiriyoruz
    double fark = difftime(cikis.epoch, giris.epoch) / (60 * 60 * 24);
    printf("Toplam calisilan gun sayisi: %.0f gun\n", fark);
    
    return 0;
}

