#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <unistd.h>

void log_yaz(char *mesaj) {     // Yapılacak işleri kayıt edecek fonksiyon başlangıcı.
    FILE *dosya = fopen("log.txt", "a"); 
    time_t simdi = time(NULL);    // Bilgisayarımızın zaman bilgisini saniye olarak alır.
    char *zaman_metni = ctime(&simdi);
    
    zaman_metni[24] = '\0'; 
    
    fprintf(dosya, "[%s] %s\n", zaman_metni, mesaj);
    fclose(dosya);   // Hafızada yer kaplamasın diye dosyayı kapatır.
}

int main() {
    printf("Sistem calisiyor... Her 60 saniyede bir yedekleme yapilacak.\n");
    printf("Durdurmak icin Ctrl+C basin.\n\n");

    while(1) { 
        printf("Yedekleme kontrol ediliyor...\n");
        
        
        FILE *dosya_kontrol = fopen("kaynak.txt", "r");
        
        if (dosya_kontrol == NULL) {
            // Hata tespit etme
            log_yaz("HATA: Kaynak dosya bulunamadi! Yedekleme yapilamadi.");
            printf("Uyari: Kaynak dosya eksik. Bir sonraki dongu bekleniyor...\n");
        } else {
            fclose(dosya_kontrol);
            
            // Linux kopyalama komutu
            system("cp kaynak.txt yedek.txt"); 
            log_yaz("BASARILI: Otomatik yedekleme tamamlandi.");
            printf("Islem tamamlandi.\n");
        }
        
        printf("60 saniye bekleniyor...\n");
        sleep(60); 
    }

    return 0;
}
