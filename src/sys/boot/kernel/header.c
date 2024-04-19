// Tiedosto: header.c

void OSmain() {
    // Avaa konsoli ja tulosta viesti "Hei, maailma!"
    __asm__ volatile (
        "mov $0x1, %%rax\n"   // Lataa järjestelmäkutsun numero konsolin avaamiseksi rax-rekisteriin
        "mov $0x1, %%rdi\n"   // Stdout-tiedoston kuvaaja (tavallinen tuloste) rdi-rekisteriin
        "lea hello_message, %%rsi\n" // Lataa merkkijonon osoite rsi-rekisteriin
        "mov $13, %%rdx\n"    // Merkkijonon pituus rdx-rekisteriin (13 tavua "Hei, maailma!\n")
        "syscall\n"           // Kutsu järjestelmäkutsua
        "hlt\n"               // Pysäytä prosessori
        :
        :
        : "rax", "rdi", "rsi", "rdx" // Käytetyt rekisterit
    );

    // Päättymätön silmukka odottamaan tapahtumia
    while (1) {
        // Voit lisätä keskeytyskäsittelyä tai muita tapahtumia
        // Tässä on ydinohjelmanne pääsilmukka
    }
}

// Tulostettava merkkijono
char hello_message[] = "Hei, maailma!\n";
