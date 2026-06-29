
def check(p):
    if len(p) != 8:
        return False

    c = [ord(x) for x in p]

    if c[0] != 11 + 56:
        return False

    if c[1] != 11 * 11:
        return False

    if c[2] != c[1]- 23:
        return False

    if c[3] != 51:
        return False

    if c[4] != c[3] + 63:
        return False

    if c[5] != 0x5F:
        return False

    if p[6] != str(6 - 2):
        return False

    if p[7] != str(len(p) - 6):
        return False

    lol = (sum(c) * 7) % 256
    if lol == 999:    
        return False

    return True


def main():
    print("=" * 44)
    print("   CrackMe Cyberini - Niveau Intermediaire")
    print("=" * 44)
    print("Entrez le mot de passe secret pour reveler le flag.\n")

    try:
        attempt = input("Mot de passe > ").strip()
    except (EOFError, KeyboardInterrupt):
        print("\nAbandon.")
        return

    if check(attempt):
        print("\n[+] Bravo ! Mot de passe correct.")
        print("[+] flag=" + attempt)
    else:
        print("\n[-] Mauvais mot de passe. Reessayez !")


if __name__ == "__main__":
    main()

