# Çalışma Süresi Hesaplayıcı (Work Duration Calculator)

## Açıklama
Bu proje, işçinin işe giriş ve çıkış tarihlerini alarak kaç gün çalıştığını hesaplayan bir C programıdır. Program, struct ve union veri yapıları kullanılarak geliştirilmiştir ve epoch zaman farkını baz alarak çalışmaktadır.

## Kullanılan Teknolojiler
- C Programlama Dili
- `struct` ve `union` veri yapıları
- `time.h` kütüphanesi

## Nasıl Çalışır?
1. Kullanıcıdan işçinin işe giriş ve çıkış tarihleri alınır.
2. Girilen tarihler `struct` içinde saklanır.
3. Tarih bilgileri epoch zamanına (`time_t`) dönüştürülür.
4. İki tarih arasındaki fark hesaplanarak kaç gün çalışıldığı ekrana yazdırılır.

## Kurulum ve Çalıştırma
1. C derleyicinizin yüklü olduğundan emin olun (GCC önerilir).
2. Terminal veya komut satırında aşağıdaki komutları çalıştırın:

```
gcc -o calisma_gunu hesaplama.c -Wall
./calisma_gunu
```

3. Program sizden giriş ve çıkış tarihlerini isteyecektir. Örneğin:

```
İşe giriş tarihini girin
Yıl: 2023
Ay: 5
Gün: 10
İşten çıkış tarihini girin
Yıl: 2024
Ay: 2
Gün: 1
Toplam çalışılan gün sayısı: 267 gün
```

## Gerçek Hayatta Kullanımı
Bu program aşağıdaki alanlarda kullanılabilir:
- **İnsan Kaynakları:** Çalışanların toplam çalışma günlerini hesaplamak için.
- **Bordro Hesaplama:** Maaş hesaplamalarında gün bazlı çalışma süresini belirlemek için.
- **Proje Yönetimi:** Bir projenin başlangıç ve bitiş tarihleri arasındaki süreyi hesaplamak için.

## Katkıda Bulunma
Projeye katkıda bulunmak için fork alabilir ve pull request gönderebilirsiniz.


