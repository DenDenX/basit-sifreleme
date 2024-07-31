# Basit Dosya Şifreleme Programı

Bu program, basit bir dosya şifreleme ve çözme işlemi gerçekleştirir. Kullanıcıdan alınan metin veya dosyayı verilen parola ile şifreler ve şifreyi çözer.

## Özellikler

- Kullanıcıdan alınan kısa metinleri şifreleme ve çözme
- Dosya bazlı şifreleme ve çözme
- Komut satırı argümanları ile veya interaktif olarak çalışabilir

## Gereksinimler

- C++ derleyicisi

## Kurulum

1. Bu projeyi klonlayın veya indirin:
    ```sh
    git clone https://github.com/kullanici_adi/basit-sifreleme.git
    ```
2. `main.cpp` dosyasını derleyin:
    ```sh
    g++ main.cpp -o dosya_sifreleme
    ```

## Kullanım

### İnteraktif Kullanım

1. Programı çalıştırın:
    ```sh
    ./dosya_sifreleme
    ```

2. Program çalıştığında, aşağıdaki seçeneklerden birini seçin:
    ```
    1. Encrypt a short text from terminal.
    2. Decrypt a short text from terminal.
    3. Encrypt a file.
    4. Decrypt a file.
    ```

3. Seçenekleri takip ederek metni veya dosyayı şifreleyin veya çözün.

### Komut Satırı Argümanları ile Kullanım

1. Programı komut satırı argümanları ile çalıştırın:
    ```sh
    ./dosya_sifreleme <operation> <file_name> <password>
    ```

    - `<operation>`: 1 şifrelemek için, 2 çözmek için kullanılır.
    - `<file_name>`: Şifrelenecek veya çözülecek dosyanın adı.
    - `<password>`: Şifreleme veya çözme işlemi için kullanılacak parola.

2. Örnek kullanım:
    ```sh
    ./dosya_sifreleme 1 myfile.txt mypassword
    ./dosya_sifreleme 2 enc_myfile.txt mypassword
    ```

## Kod Açıklaması

### Ana Fonksiyonlar

- `bolumundenKalan`: Verilen iki sayının bölümünden kalanını hesaplar.
- `sifreBoz`: Parolayı belirli bir algoritmaya göre işler ve yeni bir şifre oluşturur.
- `sifrele`: Verilen metni ve parolayı kullanarak metni şifreler.
- `coz`: Verilen metni ve parolayı kullanarak metnin şifresini çözer.
- `dosyaSifrele`: Verilen dosyayı parolayı kullanarak şifreler.
- `dosyaCozumle`: Verilen dosyanın şifresini parolayı kullanarak çözer.

### Kod Akışı

1. Kullanıcıdan metin veya dosya ve parola alınır.
2. Şifreleme veya çözme işlemi seçilir.
3. Seçilen işlem gerçekleştirilir ve sonuç ekrana yazdırılır veya dosya olarak kaydedilir.

## Katkıda Bulunma

Katkıda bulunmak isterseniz, lütfen bir fork yapın ve pull request gönderin. Her türlü katkıya açığız!
