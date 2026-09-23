#include <stdio.h>

// Discard the rest of the current line
static void clear_line(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Reads a number; returns 1 on success, 0 on EOF
static int read_temperature(double *out) {
    while (1) {
        printf("Enter the temperature value: ");

        double v;
        int r = scanf("%lf", &v);

        if (r == EOF) {
            return 0;
        }

        if (r == 1) {
            // Make sure nothing but whitespace follows the number
            int extra = 0;
            int c = getchar();
            while (c != '\n' && c != EOF) {
                if (c != ' ' && c != '\t' && c != '\r') {
                    extra = 1;
                }
                c = getchar();
            }
            if (!extra) {
                *out = v;
                return 1;
            }
        } else {
            clear_line();
        }

        printf("Input must be a number.\n");
    }
}

// Reads C, F, or K (case-insensitive); returns the uppercase letter or EOF
static int read_scale(const char *prompt) {
    while (1) {
        printf("%s", prompt);

        int c = getchar();
        while (c == ' ' || c == '\t') {
            c = getchar();
        }
        if (c == EOF) {
            return EOF;
        }

        int scale = c;
        if (scale >= 'a' && scale <= 'z') {
            scale -= 'a' - 'A';
        }

        // Anything besides whitespace after the letter makes it invalid
        int extra = 0;
        if (c != '\n') {
            c = getchar();
            while (c != '\n' && c != EOF) {
                if (c != ' ' && c != '\t' && c != '\r') {
                    extra = 1;
                }
                c = getchar();
            }
        }

        if (!extra && (scale == 'C' || scale == 'F' || scale == 'K')) {
            return scale;
        }
        printf("Invalid scale. Enter C, F, or K.\n");
    }
}

static double to_celsius(double value, char scale) {
    if (scale == 'F') {
        return (value - 32.0) * 5.0 / 9.0;
    }
    if (scale == 'K') {
        return value - 273.15;
    }
    return value;
}

static double from_celsius(double celsius, char scale) {
    if (scale == 'F') {
        return celsius * 9.0 / 5.0 + 32.0;
    }
    if (scale == 'K') {
        return celsius + 273.15;
    }
    return celsius;
}

int main(void) {
    double value;
    if (!read_temperature(&value)) {
        return 1;
    }

    int from = read_scale("Enter the original scale (C, F, or K): ");
    if (from == EOF) {
        return 1;
    }

    int to = read_scale("Enter the scale to convert to (C, F, or K): ");
    if (to == EOF) {
        return 1;
    }

    double celsius = to_celsius(value, (char)from);

    if (celsius < -273.15) {
        printf("Invalid temperature: below absolute zero.\n");
        return 1;
    }

    double converted = from_celsius(celsius, (char)to);

    // Categories are defined in Celsius, so classify using the Celsius value
    const char *category;
    const char *advisory;

    if (celsius < 0) {
        category = "Freezing";
        advisory = "Bundle up and watch for ice!";
    } else if (celsius < 10) {
        category = "Cold";
        advisory = "Wear a jacket.";
    } else if (celsius < 25) {
        category = "Comfortable";
        advisory = "Enjoy the weather!";
    } else if (celsius < 35) {
        category = "Hot";
        advisory = "Drink lots of water!";
    } else {
        category = "Extreme Heat";
        advisory = "Stay indoors and stay hydrated.";
    }

    printf("Converted temperature: %.2f %c\n", converted, (char)to);
    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory);

    return 0;
}