#include <iostream>
#include <random>

using namespace std;

/**
 * Generates a universally unique identifier (UUID) in the form of a 32-character hexadecimal string
 * divided by dashes at appropriate positions (8-4-4-4-12 format).
 *
 * This function creates a pseudo-random UUID using a random number generator. The generated UUID
 * does not guarantee strict uniqueness across invocations but is sufficiently random for general
 * non-critical use cases.
 *
 * @return A randomly generated UUID string.
 */
string get_uuid() {
    static random_device dev;
    static mt19937 rng(dev());

    uniform_int_distribution<int> dist(0, 15);

    const char *v = "0123456789abcdef";
    const bool dash[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };

    string res;
    for (int i = 0; i < 16; i++) {
        if (dash[i]) res += "-";
        res += v[dist(rng)];
        res += v[dist(rng)];
    }
    return res;
}

void print_help(){
    cout << "SENTINEL - program help: " << endl;
}

int main(int argc, char* argv[]){
    // TODO implementuj riešenie

    print_help();

    return 0;
}