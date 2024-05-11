/* CCD - An implementation of the XXD hex dump tool in stdlib C.
 * Theo Addis <theocaddis@gmail.com>
 * 11/05/2024
 */

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main() {
    char ch;                // Char buffer
    char buf[16];           // Line buffer
    unsigned int count = 0; // Byte count
    int rem;                // Remainder for final translation

    while (read(STDIN_FILENO, &ch, 1) > 0) {
        if (count == 0) {
            // Print line number for first line and continue
            printf("%.8x: ", count);
        } else if (count % 16 == 0) {
            // Print end of line ASCII translation
            printf("  ");
            for (int i = 0; i < 16; i++) {
                // isprint checks for printable ASCII characters incl. space
                if (isprint(buf[i])) {
                    printf("%c", buf[i]);
                } else {
                    printf(".");
                }
            }
            printf("\n%.8x: ", count);
        } else if (count % 2 == 0) {
            printf(" "); // Spacing
        }
        // Store in buffer for ASCII translation
        buf[count % 16] = ch;
        printf("%02x", (unsigned char) ch);
        count++;
    }

    // Final translation - find whatever is remaining and print out the ASCII
    rem = count % 16;
    if (rem == 0) rem = 16;
    int pad = (16 - rem) / 2 + (16 - rem) * 2 + 2;
    for (int i = 0; i < pad; i++) printf(" ");
    for (int i = 0; i < rem; i++) {
        if (isprint(buf[i])) {
            printf("%c", buf[i]);
        } else {
            printf(".");
        }
    }
    printf("\n");
}
