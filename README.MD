# QLineSec
# 📂 Cron ve Otomatik Yedekleme Aracı

Bu proje, Açık Kaynak İşletim Sistemleri dersi kapsamında, Linux sistemlerdeki zamanlanmış görev (Cron) mantığını simüle eden ve dosya yedekleme işlemlerini otomatize eden bir C uygulamasıdır.

## Projenin Amacı
Kullanıcının belirlediği periyotlarda dosyaları yedeklemek, bu işlemleri tarih ve saat bilgisiyle kayıt (log) altına almak ve olası hataları (dosya bulunamaması gibi) otomatik olarak tespit etmektir.

##  Temel Özellikler
- **Cron Mantığı:** `sleep()` fonksiyonu kullanılarak görevlerin belirli aralıklarla tetiklenmesi sağlanmıştır.
- **Auto Control Ability:** Program, yedekleme yapmadan önce kaynak dosyayı kontrol eder; dosya eksikse hata logu oluşturur.
- **Zaman Damgalı Günlük (Logging):** Her işlem `log.txt` dosyasına tarih bilgisiyle kaydedilir.
- **Linux Uyumluluğu:** POSIX standartlarına (`unistd.h`) uygun şekilde geliştirilmiştir.

##  Kurulum ve Çalıştırma
Programın Linux (Ubuntu 22.04+) ortamında GCC ile derlenmesi önerilir:

1. Klasöre girin: `cd src`
2. Derleyin: `gcc main.c -o backup_tool`
3. Çalıştırın: `./backup_tool`

##  Derin Araştırma (Synthesis)
Bu proje geliştirilirken Gemini ve ChatGPT araçları kullanılarak işletim sistemi çağrıları ve C dili sistem kütüphaneleri araştırılmış, elde edilen verilerle hata yönetim mekanizması geliştirilmiştir.

