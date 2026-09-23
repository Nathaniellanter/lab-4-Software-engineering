#include <stdio.h>

int score_makeup(void) {
    while (1) {
        printf("\nEnter the NFL score (Enter 1 to stop): ");

        int user_score;
        int result = scanf("%d", &user_score);

        if (result == EOF) {
            break;  // Ctrl-D / end of input
        }

        // Discard the rest of the line so bad input can't repeat forever
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (result != 1 || user_score < 1) {
            printf("Input must be an integer greater than 1\n");
            continue;
        }

        if (user_score == 1) {
            break;
        }

        int combo_count = 0;

        for (int td_2 = 0; td_2 <= user_score / 8; td_2++) {
            for (int td_1 = 0; td_1 <= user_score / 7; td_1++) {
                for (int td = 0; td <= user_score / 6; td++) {
                    for (int fg = 0; fg <= user_score / 3; fg++) {
                        for (int sf = 0; sf <= user_score / 2; sf++) {
                            int total = td_2 * 8 + td_1 * 7 + td * 6 + fg * 3 + sf * 2;

                            if (total == user_score) {
                                printf("\n%i TD + 2pt, %i TD + 1pt, %i TD, %i FG, %i Safety",
                                       td_2, td_1, td, fg, sf);
                                combo_count++;
                            }
                        }
                    }
                }
            }
        }
        printf("\nTotal combinations found: %i\n", combo_count);
    }
    return 0;
}

int main(void) {
    score_makeup();
    return 0;
}