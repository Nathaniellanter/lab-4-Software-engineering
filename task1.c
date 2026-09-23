#include <stdio.h>
//brute force approach
int score_makeup() {
    int user_score =2 ;
    
    while (user_score>1)
{
    int combo_count=0;
printf("Enter the NFL score (Enter 1 to stop): ");
scanf("%i", &user_score);
//goes throught all the possible combinations by starting with the largest point value scorings and 
for (int td_2 = 0; td_2< (user_score / 8) +1; td_2++){
    for (int td_1 = 0; td_1< (user_score / 7) +1; td_1++){
        for (int td = 0; td< (user_score / 6) +1; td++){
            for (int fg = 0; fg< (user_score / 3) +1; fg++){
                for (int sf = 0; sf< (user_score / 2) +1; sf++){
                        int total= td_2*8 + td_1*7 + td*6 +fg*3 +sf*2;
                    if (total==user_score){
                        printf(" %i TD + 2pt, %i TD + FG, %i TD, %i 3pt FG, %i Saftey",td_2 , td_1 ,td , sf);
                        combo_count+=1;
                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
int main()

{
    score_makeup();
}
